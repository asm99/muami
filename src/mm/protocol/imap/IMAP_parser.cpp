#include "IMAP_parser.hpp"

namespace { /* Mailbox parsing functions */

/* Get bits flag according to a string of flags */
unsigned char
parse_flags(const string& s)
{
    string token;
    istringstream iss(s);
    unsigned char flags = 0;

    while (iss >> token) {
        if      (token == "\\Seen")     { flags |= FL_SEEN;      }
        else if (token == "\\Answered") { flags |= FL_ANSWERED;  }
        else if (token == "\\Flagged")  { flags |= FL_FLAGGED;   }
        else if (token == "$Forwarded") { flags |= FL_FORWARDED; }
        else if (token == "\\Deleted")  { flags |= FL_DELETED;   }
        else if (token == "\\Drafts")   { flags |= FL_DRAFT;     }
    }

    return flags;
}

unsigned int
parse_mbox_flags(const string& s)
{
    return parse_flags(s);
}

unsigned int
parse_mbox_perm_flags(const string& s)
{
    return parse_flags(s);
}

unsigned long
parse_mbox_star_line(const string& s, const string& token)
{
    istringstream iss(s);
    long k;
    string star, word;

    iss >> star >> k >> word;
    if (star == "*" && iss.good() && word == token) {
        return k;
    }

    return 0;
}

/*
 * Get the number of emails in the mailbox
 * Returns 0 on failure
 */
unsigned long
parse_mbox_exists(const string& s)
{
    return parse_mbox_star_line(s, "EXISTS");
}

/*
 * Get the number of recent emails in the mailbox
 * Returns 0 on failure
 */
unsigned long
parse_mbox_recent(const string& s)
{
    return parse_mbox_star_line(s, "RECENT");
}

/*
 * Helper to extract a numeric value from an "OK" line in a
 * select mailbox response
 * Returns 0 on failure
 * FIXME: istringstream good() not working?!?!
 */
unsigned long
parse_mbox_ok_line(const string& s, const string& token)
{
    size_t tok_pos, cl_bracket_pos;
    tok_pos = s.find(token);
    cl_bracket_pos = s.find("]");

    if (tok_pos == string::npos
        || cl_bracket_pos == string::npos) {
        return 0;
    }

    string num_s = s.substr(tok_pos + token.length(),
            cl_bracket_pos - (tok_pos + token.length()));

    istringstream num_iss(num_s);
    unsigned long k;
    num_iss >> k;

//     if (num_iss.good()) {
        return k;
//     }

    return 0;
}

unsigned long
parse_mbox_unseen(const string& s)
{
    return parse_mbox_ok_line(s, "UNSEEN");
}

unsigned long
parse_mbox_uidvalidity(const string& s)
{
    return parse_mbox_ok_line(s, "UIDVALIDITY");
}

unsigned long
parse_mbox_uidnext(const string& s)
{
    return parse_mbox_ok_line(s, "UIDNEXT");
}

int
parse_mbox_permissions(const string& s)
{
    size_t pos = s.find("READ-WRITE");

    if (pos != string::npos) {
        return PERMISSION_READ_WRITE;
    }

    return PERMISSION_READ_ONLY;
}

} /* namespace  */

void
IMAP_parser::add_sections(
        Body* body,
        bool is_first_subpart,
        int depth,
        string section)
{
    if (body->type == Body_type_mpart) {
        for (unsigned int i = 0; i < body->subparts.size(); i++) {
            if (i == 0) {
                ++depth;
                is_first_subpart = true;
            } else {
                is_first_subpart = false;
            }

            section = util::get_section(section, is_first_subpart, depth);
            add_sections(body->subparts[i], is_first_subpart, depth, section);
        }
    }
    else {
        if (!is_first_subpart    // BODY has only one body-type-1part
            && depth == 0) {
            body->section = "1";
        } else {
            body->section = section;
        }
    }
}

// * LIST (\HasNoChildren \Drafts) "." Drafts
// * LIST (\HasNoChildren \Trash) "." Trash
// * LIST (\HasNoChildren \Sent) "." Sent
// * LIST (\HasNoChildren) "." INBOX
// a OK List completed.
/*
 * FIXME: remove the '(' and ')' in the attributes
 */
void
IMAP_parser::parse_list(map<string, Mailbox*>& mboxes, const string& s)
{
    istringstream iss(s);
    string line, token;
    string star, list, attributes, separator, name;
    while (getline(iss, line)) {
        attributes.clear();

        istringstream liss(line);
        liss >> star >> list;
        while (liss >> token) {
            attributes += token + " ";
            if (token.back() == ')')
                break;
        }
        liss >> separator >> name;
        string stripped_separator = util::strip_chars(separator, "\"");
        string stripped_name = util::strip_chars(name, "\"");

        Mailbox* mb = new Mailbox();
        mb->set_attributes(attributes);
        mb->set_separator(stripped_separator);
        mboxes[stripped_name] = mb;
    }
}

/*
 * FIXME: no default values when keywords are not found!!!!
 */
void
IMAP_parser::parse_select(Mailbox* mb, const string& s)
{
    istringstream iss(s);
    string line;
    size_t pos;

    while (getline(iss, line)) {
        if (line.compare(0, 7, "* FLAGS") == 0) {
            mb->set_flags(parse_mbox_flags(line));
        }
        else if (line.compare(0, 20, "* OK [PERMANENTFLAGS") == 0) {
            mb->set_perm_flags(parse_mbox_perm_flags(line));
        }
        else if ((pos = line.find("EXISTS")) != string::npos) {
            mb->set_exists(parse_mbox_exists(line));
        }
        else if ((pos = line.find("RECENT")) != string::npos) {
            mb->set_recent(parse_mbox_recent(line));
        }
        else if (line.compare(0, 12, "* OK [UNSEEN") == 0) {
            mb->set_unseen(parse_mbox_unseen(line));
        }
        else if (line.compare(0, 17, "* OK [UIDVALIDITY") == 0) {
            mb->set_uidvalidity(parse_mbox_uidvalidity(line));
        }
        else if (line.compare(0, 13, "* OK [UIDNEXT") == 0) {
            mb->set_uidnext(parse_mbox_uidnext(line));
        }
        else if (line.compare(0, 10, "* OK [READ") == 0) {
            mb->set_permissions(parse_mbox_permissions(line));
        }
    }
}

/*
 * Check if server supports IMAP4rev1 in its CAPABILITY on its greeting
 * doc: https://tools.ietf.org/html/rfc3501#section-6.1.1
 * - Mandatory -
 */
bool
IMAP_parser::check_server_imap_capability(string s)
{
    for (auto& c : s) c = toupper(c);

    if (s.find("* OK [CAPABILITY") != string::npos
        && s.find("IMAP4REV1") != string::npos) {
        return true;
    }
    return false;
}

/*
 * Parse BODYSTRUCTURE response into a prefix tree of bodys
 * examples of responses structures:
 * 46 (bp)
 * 56 ((bp) (bp) "alternative" extp…)
 * 43 (((bp) (bp) "alternative" extp…) (bp) "mixed" extp…)
 * 89 ((bp) (bp) (bp) (bp) "mixed" extp…)
 * mpart
 *   |-> 1part -> 1part -> mpart -> 1part
 *                           |-> 1part -> 1part
 * TODO: parse message/rfc822
 */
Body*
IMAP_parser::parse_bodystructure(stringstream& ss)
{
    Body* node = nullptr;
    if (!node) {
        node = new Body();
    }

    char c;

    if (ss.get(c)) {
        if (c == '(') {                 // body
            if (ss.peek() == '(') {     // multipart body (body-type-mpart)

                node->type = Body_type_mpart;

                while (ss.peek() == '(') {
                    node->subparts.push_back(
                        IMAP_parser::parse_bodystructure(ss));
                }

                /* multipart params (body-ext-mpart) */
                ss >> node->mbody_subtype;
                ss >> node->bodypart->ext_mpart();
            }
            else {              // single part body (body-type-1part)
                node->type = Body_type_1part;
                ss >> node->bodypart;
           }
        }
    }

    return node;
}

// /* Parse a RFC822.HEADER response into a header struct
//  * Only most common fields are looked up for
//  */
// RFC822_header*
// IMAP_parser::parse_header(string s)
// {
// 	RFC822_header* hdr = new RFC822_header();
//
// 	const string delim = "\r\n";
// 	string s_cpy = s;
// 	string token;
// 	size_t pos;  /* position */
// 	size_t tlen; /* token length */
// 	size_t clen; /* colon position in token */
//
// 	const string return_path   = "Return-path";
// 	const string envelope_to   = "Envelope-to";
// 	const string delivery_date = "Delivery-date";
// 	const string message_id    = "Message-ID";
// 	const string date          = "Date";
// 	const string subject       = "Subject";
// 	const string from          = "From";
// 	const string to            = "To";
// 	const string user_agent    = "User-Agent";
// 	const string mime_version  = "MIME-Version";
// 	const string content_type  = "Content-Type";
//
// 	while ((pos = s_cpy.find(delim)) != string::npos) {
//         token = s_cpy.substr(0, pos);
// 		tlen = token.length();
// 		if (tlen <= 1)
// 			continue;
//
// 		clen = token.find(":");
//         string txt = token.substr(clen+2, tlen-clen);
//
// //         cout << token << endl;
//
//         if      (token  ==  return_path)  { hdr->return_path   = txt; }
//         else if (token  == envelope_to)   { hdr->envelope_to   = txt; }
//         else if (token  == delivery_date) { hdr->delivery_date = txt; }
//         else if (token  == message_id)    { hdr->message_id    = txt; }
//         else if (token  == date)          { hdr->date          = txt; }
//         else if (token  == subject)       { hdr->subject       = txt; }
//         else if (token  == from)          { hdr->from          = txt; }
//         else if (token  == to)            { hdr->to            = txt; }
//         else if (token  == user_agent)    { hdr->user_agent    = txt; }
//         else if (token  == mime_version)  { hdr->mime_version  = txt; }
//         else if (token  == content_type)  { hdr->content_type  = txt; }
//
//         s_cpy.erase(0, pos + delim.length());
// 	}
//
// 	return hdr;
// }

// List of emails with infos (UID FLAGS INTERNALDATE RFC822.SIZE ENVELOPE)
void
IMAP_parser::parse_emails_infos(vector<Email*>& emails, string s)
{
    const string delim = "))\r\n"; // email block delimiter
    istringstream iss(s);
    string token;
    size_t delim_pos;
    long int to_pos;
    long int offset;     // used to compute substrings lengths
    size_t uid_pos, flags_pos, idate_pos, size_pos, env_pos;
    const string uid_s = "UID ";
    const string flags_s = "FLAGS ";
    const string idate_s = "INTERNALDATE ";
    const string size_s = "RFC822.SIZE ";
    const string env_s = "ENVELOPE ";

    string uid_tok, flags_tok, idate_tok, size_tok, env_tok;

    while ((delim_pos = s.find(delim)) != string::npos) {
        to_pos = delim_pos + delim.length();
        token = s.substr(0, to_pos); // token holds an email info block
#ifdef IMAP_PARSER_DEBUG
        debug("token: " + token);
#endif

        uid_pos = token.find(uid_s);
        flags_pos = token.find(flags_s);
        idate_pos = token.find(idate_s);
        size_pos = token.find(size_s);
        env_pos = token.find(env_s);

        offset = uid_pos + uid_s.length();
        uid_tok = token.substr(offset, flags_pos - offset);

        offset = flags_pos + flags_s.length();
        flags_tok = token.substr(offset, idate_pos - offset);

        offset = idate_pos + idate_s.length();
        idate_tok = token.substr(offset, size_pos - offset);

        offset = size_pos + size_s.length();
        size_tok = token.substr(offset, env_pos - offset);

        offset = env_pos + env_s.length();
        env_tok = token.substr(offset, token.length() - offset);

#ifdef IMAP_PARSER_DEBUG
        debug("uid tok        : " + uid_tok );
        debug("flags tok      : " + flags_tok );
        debug("idate tok      : " + idate_tok );
        debug("formatted idate: " +
                Date::format_date(util::strip_chars(idate_tok, "\"")));
        debug("size tok       : " + size_tok );
        debug("env tok        : " + env_tok );
#endif

        Email* em = new Email();
        em->set_uid(stol(uid_tok));
        em->set_rfc822_size(stol(size_tok));
        em->set_flags(parse_flags(util::strip_chars(flags_tok, "()")));
        string stripped_date = util::strip_chars(idate_tok, "\"");
        em->set_internaldate(stripped_date);
        em->set_friendly_time(Date::format_date(stripped_date));

        istringstream iss(env_tok);
        Envelope env {};
        iss >> env;
        em->set_envelope(env);

        //         em->set_rfc822_header(RFC822_header* const hdr);

        emails.push_back(em);

        s.erase(0, to_pos);
    }
}

#ifdef IMAP_PARSER_DEBUG

// Test various cases of sections labelling and nesting
int
main()
{
    //     string sel_resp =
    //         " * FLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft $MDNSent)\r\n * OK [PERMANENTFLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft $MDNSent \\*)] Flags permitted.\r\n * 156 EXISTS\r\n * 3 RECENT\r\n * OK [UNSEEN 140] First unseen.\r\n * OK [UIDVALIDITY 1428093624] UIDs valid\r\n * OK [UIDNEXT 410] Predicted next UID\r\n a OK [READ-WRITE] Select completed (0.000 secs).\r\n DONE";
    //  * FLAGS (\Answered \Flagged \Deleted \Seen \Draft $MDNSent)
    //  * OK [PERMANENTFLAGS (\Answered \Flagged \Deleted \Seen \Draft $MDNSent \*)] Flags permitted.
    //  * 156 EXISTS
    //  * 3 RECENT
    //  * OK [UNSEEN 140] First unseen.
    //  * OK [UIDVALIDITY 1428093624] UIDs valid
    //  * OK [UIDNEXT 410] Predicted next UID
    //  a OK [READ-WRITE] Select completed (0.000 secs).
    //  DONE";

    //     Mailbox* mb = new Mailbox();
    //     IMAP_parser::parse_select(mb, sel_resp);
    //     mb->dump();

    vector<string> bodysts = {
        "(\"text\" \"plain\" (\"charset\" \"utf-8\") NIL NIL \"quoted-printable\" 218 9 NIL NIL NIL NIL)", //         "((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 571 12 NIL NIL NIL NIL)(\"text\" \"html\" (\"charset\" \"UTF-8\") NIL NIL \"base64\" 10184 130 NIL NIL NIL NIL) \"alternative\" (\"boundary\" \"----=_NextPart_000_4597_4CAB1C23.F3651148\") NIL NIL NIL)",
//        "(bp)"

        "((\"text\" \"plain\" (\"charset\" \"utf-8\") NIL NIL \"base64\" 5202 67 NIL NIL NIL NIL)(\"application\" \"x-zip-compressed\" (\"name\" \"Scan-pdf.zip\") NIL \"Scan-pdf.zip\" \"base64\" 21212 NIL (\"attachment\" (\"filename\" \"Scan-pdf.zip\" \"size\" \"15499\" \"creation-date\" \"Wed, 14 Oct 2015 15:07:56 GMT\" \"modification-date\" \"Wed, 14 Oct 2015 15:07:56 GMT\")) NIL NIL) \"mixed\" (\"boundary\" \"_002_9CBB4CB9F48C1B4391E6A6622FB5256711874E0BIBXHBE11dom801i_\") NIL (\"fr-FR\") NIL))",
//         "((bp)(bp) \"mixed\" bem)",

        "((\"text\" \"plain\" (\"charset\" \"windows-1252\" \"format\" \"flowed\") NIL NIL \"8bit\" 2016 56 NIL NIL NIL NIL)(\"text\" \"html\" (\"charset\" \"windows-1252\") NIL NIL \"8bit\" 2917 68 NIL NIL NIL NIL) \"alternative\" (\"boundary\" \"------------010607070702040103050603\") NIL NIL NIL)",
//         "((bp)(bp) \"alternative\" bem)",

        "(((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 12612 287 NIL NIL NIL NIL) \"related\" (\"boundary\" \"----=_Part_27208_12532565.1436873335089\") NIL NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_27207_22265220.1436873335089\") NIL NIL NIL)",
//        "(((bp) \"related\" bem) \"mixed\" bem)",

        "(((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"7bit\" 0 0 NIL NIL NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_3932646_1390009111.1438932541709\") NIL NIL NIL)(\"application\" \"octet-stream\" (\"name\" \"76339561.pdf\") NIL NIL \"base64\" 14022 NIL (\"attachment\" (\"filename\" \"76339561.pdf\")) NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_3932645_770043819.1438932541709\") NIL NIL NIL)",
//         "(((bp) \"mixed\" bem)(bp) \"mixed\" bem)",

        "(((\"text\" \"plain\" (\"charset\" \"iso-8859-1\") NIL NIL \"quoted-printable\" 1091 31 NIL NIL NIL NIL)(\"text\" \"html\" (\"charset\" \"iso-8859-1\") NIL NIL \"quoted-printable\" 4040 99 NIL NIL NIL NIL) \"alternative\" (\"boundary\" \"0907-1346-31-03-PART_BREAK\") NIL NIL NIL)(\"application\" \"pdf\" NIL NIL NIL \"base64\" 27540 NIL (\"attachment\" (\"filename\" \"NOTICE    2015.pdf\")) NIL NIL)(\"application\" \"pdf\" NIL NIL NIL \"base64\" 133762 NIL (\"attachment\" (\"filename\" \"CONTRAT SEPTEMBRE	2015.pdf\")) NIL NIL)(\"application\" \"pdf\" NIL NIL NIL \"base64\" 91438 NIL (\"attachment\" (\"filename\" \"FICHE.pdf\")) NIL NIL)(\"application\" \"pdf\" NIL NIL NIL \"base64\" 167816 NIL (\"attachment\" (\"filename\" \"Info.pdf\")) NIL NIL) \"mixed\" (\"boundary\" \"0907-1346-31-01-PART_BREAK\") NIL NIL NIL)",
//         "(((bp)(bp) \"alternative\" bem)(bp)(bp)(bp)(bp) \"mixed\" bem)",
    };

    stringstream ss;
    int count = 0;
    for (auto s : bodysts) {
        vector<Body*> bps {};
        ss.str(s);
        cout << "\n" << count++ << ". string: \n" << s << endl;
        Email *em = new Email();
        em->body = IMAP_parser::imap_parse_bodystructure(ss);
        IMAP_parser::add_sections(em->body, false);

        cout << "\n\n============= Body dump ================\n";
        em->body->dump();
        cout <<     "========================================\n";

        delete em;
        ss.str("");
        ss.clear();
    }

    return 0;
}
#endif
