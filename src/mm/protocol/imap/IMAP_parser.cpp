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

// /*
//  * Parse a BODYSTRUCTURE response into a bodystructure struct
//  * doc: https://tools.ietf.org/html/rfc3501#page-73
//  * ("type" "subtype" (parameters) "id" "description" "encoding" size (ext_prms))
//  * (string string parenthesized-list string string string number
//  * parenthesized-list)
//  * FIXME: treating all messages as RFC822 messages
//  */
// Bodystructure*
// IMAP_parser::parse_bodystructure(string s)
// {
//     cout << s << endl;
//     Bodystructure* bs = new Bodystructure();
//
//     /* treating all messages as RFC822 messages */
//     string rfc822msg = "(\"message\" ";
//
// //     int i = BS_TYPE;
//     int i = 0;
//     string s_cpy = s;
//     int spacepos, parenpos;
//     int max_bs_field;
// //     if (s_cpy.compare(0, 7, "(\"text\"") == 0) {
// //         max_bs_field = BS_TEXT_EXTENSION_PARAMETERS;
// //     } else if (s_cpy.compare(rfc822msg) == 0) {
// //         max_bs_field = BS_MESSAGE_RFC822_LINES_SIZE;
// //     } else {
// //         max_bs_field = BS_EXTENSION_PARAMETERS;
// //     }
//
// //     int k;
// //     string token, cl_token;
// //     while(s_cpy[0] && i < max_bs_field) {
// //         spacepos = s_cpy.find(" ");
// //         if (s_cpy[0] == '(' && i != BS_TYPE) {
// //             parenpos = s_cpy.find(") ");
// //             s_cpy = s_cpy.substr(parenpos + 2, s_cpy.length()-parenpos -2);
// //             i++;
// //             continue;
// //         }
// //
// //         k = s_cpy.find(" ");
// //         if (k <= 0) {
// //             i++;
// //             break;
// //         }
// //
// //         token = s_cpy.substr(0, k-1);
// //         cl_token = util::strip_chars(token, "(\"");
// //
// //         if (i == BS_TYPE) {
// //             bs->type = cl_token;
// //         }
// //         if (i == BS_SUBTYPE) {
// //             bs->subtype = cl_token;
// //         }
// //
// //         s_cpy = s_cpy.substr(spacepos+1, s_cpy.length() - spacepos - 1);
// //         i++;
// //     }
//
//     return bs;
// }

/*
 * Parse BODYSTRUCTURE response into a prefix tree of bodys
 * examples of responses structures:
 * 46 (bp)
 * 56 ((bp) (bp) "alternative" extp…)
 * 43 (((bp) (bp) "alternative" extp…) (bp) "mixed" extp…)
 * 89 ((bp) (bp) (bp) (bp) "mixed" extp…)
 * TODO: parse mutipart/alternative types and params
 */
// mpart
//   |-> 1part -> 1part -> mpart -> 1part
//                           |-> 1part -> 1part
// (((bp)(bp) "alternative" bem)(bp)(bp)(bp)(bp) "mixed" bem)
//
//                  /
//                  |
//                mixed
//                  |
//               alternative - bp - bp - bp - bp
//                  |
//               t/plain - t/html
Body*
IMAP_parser::imap_parse_bodystructure(stringstream& ss)
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
                        IMAP_parser::imap_parse_bodystructure(ss));
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

// Parse a FETCH (RFC822.HEADER BODYSTRUCTURE) response into an Email object
Email*
IMAP_parser::parse_email(string s)
{
//     string b_start_str = "BODYSTRUCTURE ";
//     string b_end_str = "\r\nABCD";
//     size_t b_spos = s.find(b_start_str);
//     size_t b_epos = s.find(b_end_str);
//     string hdr_s = s.substr(0, b_spos-1);
//     size_t bs_start = b_spos + b_start_str.length();
//     string bs = s.substr(bs_start, b_epos - bs_start);
//
//     //     cout << s << endl;
//     //     cout << "hdr_s: " + hdr_s << endl;
//     //     cout << "bs: " + bs << endl;
//
//     // 	RFC822_header* hdr = this->parse_header(hdr_s);
//     //     hdr->Dump_header(hdr);
//
//     Body* bp = new Body();
//     Bodystructure* bodyst = new Bodystructure();
//
//     bodyst->type = "/";
//     bodyst->subtype = "/";
//     bp->bodystructure = bodyst;
//
//     string base_section;
//     //     cout << "str: " << s << endl;
//     //     cout << "bs: " << bs << endl;
//     if (strncmp(bs.c_str(), "(\"", 2) == 0) { /* no child or sibling */
//         base_section = "1";
//     } else {
//         base_section = "0";
//     }
//
//     stringstream ss(bs);
//     imap_parse_bodystructure(ss, bp, base_section, true);

    Email* em = new Email();

    // 	em->rfc822_hdr = hdr;
//     em->body = bp;
    // 	em->text = NULL;
    return em;
}

#ifdef IMAP_PARSER_DEBUG

// DEBUG
void
print_before_after_section(bool is_child, string old)
{
    string new_s = util::get_new_section(old, is_child);
    debug("section old, new => " + old + ", " + new_s);
    if (is_child) debug("CHILD");
    else          debug("SIBLING");
}

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


//         "(((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 7058 150 NIL NIL NIL NIL) \"related\" (\"boundary\" \"----=_Part_184312_21033572.1438499366814\") NIL NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_184311_19245088.1438499366814\") NIL NIL NIL)",
//         "((\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 4 2 NIL NIL NIL NIL)(\"image\" \"jpeg\" (\"name\" \"IMG_2022.JPG\" \"x-apple-part-url\" \"51B8DB1C-5597-434B-A040-3F60D93C5A0C\") NIL NIL \"base64\" 1296668 NIL (\"inline\" (\"filename\" \"IMG_2022.JPG\")) NIL NIL)(\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 6 3 NIL NIL NIL NIL)(\"image\" \"jpeg\" (\"name\" \"IMG_2023.JPG\" \"x-apple-part-url\" \"6E6937C2-2458-4AA1-A784-E1AFD2650D5C\") NIL NIL \"base64\" 1265448 NIL (\"inline\" (\"filename\" \"IMG_2023.JPG\")) NIL NIL)(\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 6 3 NIL NIL NIL NIL)(\"image\" \"jpeg\" (\"name\" \"IMG_2024.JPG\" \"x-apple-part-url\" \"AAAB5971-8A83-4B3D-A682-2CD41B83AE00\") NIL NIL \"base64\" 1090466 NIL (\"inline\" (\"filename\" \"IMG_2024.JPG\")) NIL NIL)(\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 6 3 NIL NIL NIL NIL)(\"image\" \"jpeg\" (\"name\" \"IMG_2025.JPG\" \"x-apple-part-url\" \"CB30D6AF-6F41-4544-BAF2-51F81308F968\") NIL NIL \"base64\" 1201580 NIL (\"inline\" (\"filename\" \"IMG_2025.JPG\")) NIL NIL)(\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 6 3 NIL NIL NIL NIL)(\"image\" \"jpeg\" (\"name\" \"IMG_2026.JPG\" \"x-apple-part-url\" \"980376C3-182A-4AEE-A76B-6B90A6AE68E2\") NIL NIL \"base64\" 1523752 NIL (\"inline\" (\"filename\" \"IMG_2026.JPG\")) NIL NIL)(\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 6 3 NIL NIL NIL NIL) \"mixed\" (\"boundary\" \"Apple-Mail-7E918C0D-DD6B-4A28-A18C-971836443E43\") NIL NIL NIL)",
//         "((\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 4 2 NIL NIL NIL NIL)(\"image\" \"jpeg\" (\"name\" \"IMG_4910.JPG\" \"x-apple-part-url\" \"4394C10A-20BB-4097-BED0-E3B7E94BC186\") NIL NIL \"base64\" 3606478 NIL (\"inline\" (\"filename\" \"IMG_4910.JPG\")) NIL NIL)(\"text\" \"plain\" (\"charset\" \"us-ascii\") NIL NIL \"7bit\" 25 3 NIL NIL NIL NIL) \"mixed\" (\"boundary\" \"Apple-Mail-1FF01B5E-D972-4C9D-9D9B-88D1BC5F8375\") NIL NIL NIL)",
//         "(((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"7bit\" 0 0 NIL NIL NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_3932646_1390009111.1438932541709\") NIL NIL NIL)(\"application\" \"octet-stream\" (\"name\" \"76339561.pdf\") NIL NIL \"base64\" 14022 NIL (\"attachment\" (\"filename\" \"76339561.pdf\")) NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_3932645_770043819.1438932541709\") NIL NIL NIL)",
//         "((\"text\" \"html\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 38150 640 NIL NIL NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_3982017_1506491351.1438932567608\") NIL NIL NIL)",
//         "((\"text\" \"html\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 6732 95 NIL NIL NIL NIL)(\"application\" \"octet-stream\" (\"name\" \"=?utf-8?B?UmVtcGxhY2VtZW50cyBBb8O7dCBNw6lkZWNpbnMgRy5wZGY=?=\") NIL NIL \"base64\" 300020 NIL NIL NIL NIL) \"mixed\" (\"boundary\" \"--boundary_15_c748b171-3050-408a-b256-c74d9cbd9f3c\") NIL NIL NIL)",
//         "(((\"text\" \"html\" (\"charset\" \"UTF-8\") NIL NIL \"7bit\" 11142 141 NIL NIL NIL NIL) \"alternative\" (\"charset\" \"UTF-8\" \"Boundary\" \"Askia-MI4C--63476056-e2d1-4797-9a6f-b4ff295576ef\") NIL NIL NIL) \"mixed\" (\"boundary\" \"Askia-MI4C--aa245807-d537-48ff-b041-193b12c4669d\") NIL NIL NIL)",
//         "((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 546 16 NIL NIL NIL NIL)(\"text\" \"html\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 1247 21 NIL NIL NIL NIL) \"alternative\" (\"boundary\" \"001a113d31bc65dcc5051d38ad5c\") NIL NIL NIL)",
//         "(((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 6448 145 NIL NIL NIL NIL) \"related\" (\"boundary\" \"----=_Part_90290_14190963.1440066396251\") NIL NIL NIL) \"mixed\" (\"boundary\" \"----=_Part_90289_8705391.1440066396251\") NIL NIL NIL)",
//     };

    stringstream ss;
    int count = 0;
    for (auto s : bodysts) {
        vector<Body*> bps {};
        ss.str(s);
        cout << "\n" << count++ << ". string: \n" << s << endl;
        Email *em = new Email();
        em->body = IMAP_parser::imap_parse_bodystructure(ss);

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
