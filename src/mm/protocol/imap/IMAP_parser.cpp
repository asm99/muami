#include "IMAP_parser.hpp"

namespace {
/* Mailbox parsing functions */

/* Get bits flag according to a string of flags */
unsigned char
parse_flags(const string& s)
{
    string token;
    stringstream ss(s);
    unsigned char flags = 0;

    while (getline(ss, token, ' ')) {
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

} // unnamed namespace

// * LIST (\HasNoChildren \Drafts) "." Drafts
// * LIST (\HasNoChildren \Trash) "." Trash
// * LIST (\HasNoChildren \Sent) "." Sent
// * LIST (\HasNoChildren) "." INBOX
// a OK List completed.
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
 * Parse a BODYSTRUCTURE response into a bodystructure struct
 * doc: https://tools.ietf.org/html/rfc3501#page-73
 * ("type" "subtype" (parameters) "id" "description" "encoding" size (ext_prms))
 * (string string parenthesized-list string string string number
 * parenthesized-list)
 * FIXME: treating all messages as RFC822 messages
 */
// Bodystructure*
// IMAP_parser::parse_bodystructure(string s)
// {
// //     cout << s << endl;
//     Bodystructure* bs = new Bodystructure();
//
//     /* treating all messages as RFC822 messages */
//     string rfc822msg = "(\"message\" ";
//
//     int i = BS_TYPE;
//     string s_cpy = s;
//     int spacepos, parenpos;
//     int max_bs_field;
//     if (s_cpy.compare(0, 7, "(\"text\"") == 0) {
//         max_bs_field = BS_TEXT_EXTENSION_PARAMETERS;
//     } else if (s_cpy.compare(rfc822msg) == 0) {
//         max_bs_field = BS_MESSAGE_RFC822_LINES_SIZE;
//     } else {
//         max_bs_field = BS_EXTENSION_PARAMETERS;
//     }
//
//     int k;
//     string token, cl_token;
//     while(s_cpy[0] && i < max_bs_field) {
//         spacepos = s_cpy.find(" ");
//         if (s_cpy[0] == '(' && i != BS_TYPE) {
//             parenpos = s_cpy.find(") ");
//             s_cpy = s_cpy.substr(parenpos + 2, s_cpy.length()-parenpos -2);
//             i++;
//             continue;
//         }
//
//         k = s_cpy.find(" ");
//         if (k <= 0) {
//             i++;
//             break;
//         }
//
//         token = s_cpy.substr(0, k-1);
//         cl_token = util::strip_chars(token, "(\"");
//
//         if (i == BS_TYPE) {
//             bs->type = cl_token;
//         }
//         if (i == BS_SUBTYPE) {
//             bs->subtype = cl_token;
//         }
//
//         s_cpy = s_cpy.substr(spacepos+1, s_cpy.length() - spacepos - 1);
//         i++;
//     }
//
//     return bs;
// }
//
// /*
//  * Parse BODYSTRUCTURE response into a prefix tree of bodyparts
//  * examples of responses structures:
//  * 46 (bp)
//  * 56 ((bp) (bp) "alternative" extp…)
//  * 43 (((bp) (bp) "alternative" extp…) (bp) "mixed" extp…)
//  * 89 ((bp) (bp) (bp) (bp) "mixed" extp…)
//  * TODO: parse mutipart/alternative types and params
//  */
// void
// IMAP_parser::imap_parse_bodystructure(
//         string s,
//         Bodypart* tree,
//         string section,
//         bool is_child)
// {
// //     cout << "bs s: " << s << "\n";
//     if (s.length() <= 0) {
//         return;
//     }
//
//     if (s[0] == '(') {
//         int start = (s[1] == '(') ? 1 : 0;
//         int bp_len = util::get_bodypart_length(
//                 s.substr(start, s.length()- start));
//         string car = s.substr(start, s.length() - start);
//
//         Bodypart *bp_child = new Bodypart();
// //         bp_child->child = nullptr;
// //         bp_child->sibling = nullptr;
//         Bodypart *bp_sib = new Bodypart();
// //         bp_sib->child = nullptr;
// //         bp_sib->sibling = nullptr;
//
//         if (!bp_child || !bp_sib) {
//             return;
//         }
//
//         string ns_chd = util::get_new_section(section, true);
//         string ns_sbg;
//         if (is_child) {
//             ns_sbg = util::get_new_section(ns_chd, false);
//         } else {
//             ns_sbg = util::get_new_section(section, false);
//         }
//
//         if (s[1] == '(') { /* nested bodypart(s) */
//             tree->section = section;
//             tree->child = bp_child;
//             tree->sibling = bp_sib;
//
//             imap_parse_bodystructure(car,
//                     tree->child, ns_chd, true);
// //             imap_parse_bodystructure(s + bp_len,
// //                     tree->sibling, ns_sbg, false);
//             imap_parse_bodystructure(s.substr(bp_len, s.length()-bp_len),
//                     tree->sibling, ns_sbg, false);
//         } else {
//             tree->section = section;
//             tree->bodystructure = parse_bodystructure(s);
//             tree->sibling = bp_sib;
//
// //             imap_parse_bodystructure(s + bp_len-1,
// //                     tree->sibling, ns_sbg, false);
//             imap_parse_bodystructure(s.substr(bp_len, s.length() -(bp_len-1)),
//                     tree->sibling, ns_sbg, false);
//         }
//     } else {  /* multipart trailing fields: "mixed"… / "alternative"… */
//         return;
//     }
// }
//
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

    Date_formatter *df {};

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
            df->format_date(util::strip_chars(idate_tok, "\"")));
	debug("size tok       : " + size_tok );
	debug("env tok        : " + env_tok );
#endif

        Email* em = new Email();
        em->set_uid(stol(uid_tok));
        em->set_rfc822_size(stol(uid_tok));
        em->set_flags(parse_flags(util::strip_chars(flags_tok, "()")));
        string stripped_date = util::strip_chars(idate_tok, "\"");
        em->set_internaldate(stripped_date);
        em->set_friendly_time(df->format_date(stripped_date));

        istringstream iss(env_tok);
        Envelope env {};
        iss >> env;
        em->set_envelope(env);

        //         em->set_rfc822_header(RFC822_header* const hdr);

        emails.push_back(em);

        s.erase(0, to_pos);
    }
}

// // Parse a FETCH (RFC822.HEADER BODYSTRUCTURE) response into an Email object
// Email*
// IMAP_parser::parse_email(string s)
// {
// 	string b_start_str = "BODYSTRUCTURE ";
// 	string b_end_str = "\r\nABCD";
// 	size_t b_spos = s.find(b_start_str);
// 	size_t b_epos = s.find(b_end_str);
// 	string hdr_s = s.substr(0, b_spos-1);
// 	size_t bs_start = b_spos + b_start_str.length();
// 	string bs = s.substr(bs_start, b_epos - bs_start);
//
// //     cout << s << endl;
// //     cout << "hdr_s: " + hdr_s << endl;
// //     cout << "bs: " + bs << endl;
//
// // 	RFC822_header* hdr = this->parse_header(hdr_s);
// //     hdr->Dump_header(hdr);
//
// 	Bodypart* bp = new Bodypart();
// 	Bodystructure* bodyst = new Bodystructure();
//
// 	bodyst->type = "/";
// 	bodyst->subtype = "/";
// 	bp->bodystructure = bodyst;
//
//     string base_section;
// //     cout << "str: " << s << endl;
// //     cout << "bs: " << bs << endl;
// 	if (strncmp(bs.c_str(), "(\"", 2) == 0) { /* no child or sibling */
// 		base_section = "1";
// 	} else {
// 		base_section = "0";
// 	}
//
// 	imap_parse_bodystructure(bs, bp, base_section, true);
//
// 	Email* em = new Email();
//
// // 	em->rfc822_hdr = hdr;
// 	em->bodypart = bp;
// // 	em->text = NULL;
// 	return em;
// }
//
// /* Dump a prefix tree of bodyparts */
// void
// dump_bodypart_tree(Bodypart* bp)
// {
//     if (!bp) {
//         return;
//     }
//
//     if (bp->bodystructure) {
//         cout << "type/subtype [section]: "
//             << bp->bodystructure->type << "/"
//             << bp->bodystructure->subtype
//             << " [" << bp->section << "]" << endl;
//     }
//
//     dump_bodypart_tree(bp->child);
//     dump_bodypart_tree(bp->sibling);
// }

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
    string sel_resp =
        " * FLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft $MDNSent)\r\n * OK [PERMANENTFLAGS (\\Answered \\Flagged \\Deleted \\Seen \\Draft $MDNSent \\*)] Flags permitted.\r\n * 156 EXISTS\r\n * 3 RECENT\r\n * OK [UNSEEN 140] First unseen.\r\n * OK [UIDVALIDITY 1428093624] UIDs valid\r\n * OK [UIDNEXT 410] Predicted next UID\r\n a OK [READ-WRITE] Select completed (0.000 secs).\r\n DONE";
//  * FLAGS (\Answered \Flagged \Deleted \Seen \Draft $MDNSent)
//  * OK [PERMANENTFLAGS (\Answered \Flagged \Deleted \Seen \Draft $MDNSent \*)] Flags permitted.
//  * 156 EXISTS
//  * 3 RECENT
//  * OK [UNSEEN 140] First unseen.
//  * OK [UIDVALIDITY 1428093624] UIDs valid
//  * OK [UIDNEXT 410] Predicted next UID
//  a OK [READ-WRITE] Select completed (0.000 secs).
//  DONE";

    Mailbox mb {};
    IMAP_parser::parse_mailbox_infos(mb, sel_resp);
    mb.dump();

    return 0;
}

#endif
