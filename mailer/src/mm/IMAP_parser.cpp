/*
 * MELKONIAN Marc - 13410425
 * IMAP_parser.cpp - parsing functions for IMAP server responses
 * Date: 04 May 2015
 */

#include "IMAP_parser.hpp"

/*
 * Check if server supports IMAP4rev1 in its CAPABILITY on its greeting
 * doc: https://tools.ietf.org/html/rfc3501#section-6.1.1
 * - Mandatory -
 */
bool
IMAP_parser::check_server_imap_capability(std::string s)
{
    for (auto& c : s) c = toupper(c);
//     std::cout << "s: " + s << std::endl;

    if (s.find("* OK [CAPABILITY") != std::string::npos
        && s.find("IMAP4REV1") != std::string::npos) {
        return true;
    }
    return false;
}

// From string "1.2.3" to vector of ints (1, 2, 3)
std::vector<int>
IMAP_parser::explode_to_ints(std::string s, std::string delim)
{
    std::string token;
    std::size_t pos;
    std::vector<int> vec {};

    while ((pos = s.find(delim)) != std::string::npos) {
        token = s.substr(0, pos);
        vec.push_back(stoi(token));
        s.erase(0, pos + delim.length());
    }
    vec.push_back(stoi(s));
    return vec;
}

/* Strip occurences of characters in a set off a string */
std::string
IMAP_parser::strip_chars(std::string src, std::string set)
{
    std::string dst = src;
    char c;
    for (unsigned int i = 0; i < set.length(); i++) {
        c = set[i];
        std::size_t pos = 0;
        while ((pos = dst.find(c)) != std::string::npos) {
            dst.erase(pos, 1);
        }
    }

    return dst;
}

/* Get bits flag according to a string of flags */
unsigned char
IMAP_parser::parse_flags(std::string s)
{
    std::string token;
    std::stringstream ss;
    ss << s;
    unsigned char flags = 0;

    while (getline(ss, token, ' ')) {
        if      (token == "\\Seen")     { flags |= FL_SEEN; }
        else if (token == "\\Answered") { flags |= FL_ANSWERED; }
        else if (token == "\\Flagged")  { flags |= FL_FLAGGED; }
        else if (token == "$Forwarded") { flags |= FL_FORWARDED; }
        else if (token == "\\Deleted")  { flags |= FL_DELETED; }
        else if (token == "\\Drafts")   { flags |= FL_DRAFT; }
    }

    return flags;
}

/*
 * Parse a BODYSTRUCTURE response into a bodystructure struct
 * doc: https://tools.ietf.org/html/rfc3501#page-73
 * ("type" "subtype" (parameters) "id" "description" "encoding" size (ext_prms))
 * (string string parenthesized-list string string string number
 * parenthesized-list)
 * FIXME: treating all messages as RFC822 messages
 */
Bodystructure*
IMAP_parser::parse_bodystructure(std::string s)
{
//     std::cout << s << std::endl;
    Bodystructure* bs = new Bodystructure();

    /* treating all messages as RFC822 messages */
    std::string rfc822msg = "(\"message\" ";

    int i = BS_TYPE;
    std::string s_cpy = s;
    int spacepos, parenpos;
    int max_bs_field;
    if (s_cpy.compare(0, 7, "(\"text\"") == 0) {
        max_bs_field = BS_TEXT_EXTENSION_PARAMETERS;
    } else if (s_cpy.compare(rfc822msg) == 0) {
        max_bs_field = BS_MESSAGE_RFC822_LINES_SIZE;
    } else {
        max_bs_field = BS_EXTENSION_PARAMETERS;
    }

    int k;
    std::string token, cl_token;
    while(s_cpy[0] && i < max_bs_field) {
        spacepos = s_cpy.find(" ");
        if (s_cpy[0] == '(' && i != BS_TYPE) {
            parenpos = s_cpy.find(") ");
            s_cpy = s_cpy.substr(parenpos + 2, s_cpy.length()-parenpos -2);
            i++;
            continue;
        }

        k = s_cpy.find(" ");
        if (k <= 0) {
            i++;
            break;
        }

        token = s_cpy.substr(0, k-1);
        cl_token = this->strip_chars(token, "(\"");

        if (i == BS_TYPE) {
            bs->type = cl_token;
        }
        if (i == BS_SUBTYPE) {
            bs->subtype = cl_token;
        }

        s_cpy = s_cpy.substr(spacepos+1, s_cpy.length() - spacepos - 1);
        i++;
    }

    return bs;
}

/*
 * Count a bodypart length
 * Note: by definition a bodypart is contained inside parenthesis but fields
 * can also have parenthesis so we delimit a bodypart only by the first and
 * last parenthesis (toplevel parenthesis)
 */
int
IMAP_parser::get_bodypart_length(std::string s)
{
    int level = 0;
    unsigned int count;
    for (count = 0; count < s.length(); count++) {
        if (count != 0 && level == 0) {
            break;
        }

        if (s[count] == '(') {
            level++;
        } else if (s[count] == ')') {
            level--;
        }
    }
    return count+1;
}

/*
 * Parse BODYSTRUCTURE response into a prefix tree of bodyparts
 * examples of responses structures:
 * 46 (bp)
 * 56 ((bp) (bp) "alternative" extp…)
 * 43 (((bp) (bp) "alternative" extp…) (bp) "mixed" extp…)
 * 89 ((bp) (bp) (bp) (bp) "mixed" extp…)
 * TODO: parse mutipart/alternative types and params
 */
void
IMAP_parser::imap_parse_bodystructure(
        std::string s,
        Bodypart* tree,
        std::string section,
        bool is_child)
{
//     std::cout << "bs s: " << s << "\n";
    if (s.length() <= 0) {
        return;
    }

    if (s[0] == '(') {
        int start = (s[1] == '(') ? 1 : 0;
        int bp_len = get_bodypart_length(s.substr(start, s.length()- start));
        std::string car = s.substr(start, s.length() - start);

        Bodypart *bp_child = new Bodypart();
//         bp_child->child = nullptr;
//         bp_child->sibling = nullptr;
        Bodypart *bp_sib = new Bodypart();
//         bp_sib->child = nullptr;
//         bp_sib->sibling = nullptr;

        if (!bp_child || !bp_sib) {
            return;
        }

        std::string ns_chd = this->get_new_section(section, true);
        std::string ns_sbg;
        if (is_child) {
            ns_sbg = this->get_new_section(ns_chd, false);
        } else {
            ns_sbg = this->get_new_section(section, false);
        }

        if (s[1] == '(') { /* nested bodypart(s) */
            tree->section = section;
            tree->child = bp_child;
            tree->sibling = bp_sib;

            imap_parse_bodystructure(car,
                    tree->child, ns_chd, true);
//             imap_parse_bodystructure(s + bp_len,
//                     tree->sibling, ns_sbg, false);
            imap_parse_bodystructure(s.substr(bp_len, s.length()-bp_len),
                    tree->sibling, ns_sbg, false);
        } else {
            tree->section = section;
            tree->bodystructure = parse_bodystructure(s);
            tree->sibling = bp_sib;

//             imap_parse_bodystructure(s + bp_len-1,
//                     tree->sibling, ns_sbg, false);
            imap_parse_bodystructure(s.substr(bp_len, s.length() -(bp_len-1)),
                    tree->sibling, ns_sbg, false);
        }
    } else {  /* multipart trailing fields: "mixed"… / "alternative"… */
        return;
    }
}

/* Parse a RFC822.HEADER response into a header struct
 * Only most common fields are looked up for
 */
RFC822_header*
IMAP_parser::parse_header(std::string s)
{
	RFC822_header* hdr = new RFC822_header();

//     std::cout << s << std::endl;

	const std::string delim = "\r\n";
	std::string s_cpy = s;
	std::string token;
	std::size_t pos;  /* position */
	std::size_t tlen; /* token length */
	std::size_t clen; /* colon position in token */

	const std::string return_path   = "Return-path";
	const std::string envelope_to   = "Envelope-to";
	const std::string delivery_date = "Delivery-date";
	const std::string message_id    = "Message-ID";
	const std::string date          = "Date";
	const std::string subject       = "Subject";
	const std::string from          = "From";
	const std::string to            = "To";
	const std::string user_agent    = "User-Agent";
	const std::string mime_version  = "MIME-Version";
	const std::string content_type  = "Content-Type";

	while ((pos = s_cpy.find(delim)) != std::string::npos) {
        token = s_cpy.substr(0, pos);
		tlen = token.length();
		if (tlen <= 1)
			continue;

		clen = token.find(":");

//         std::cout << token << std::endl;

        if (token == return_path) {
            hdr->return_path = token.substr(clen+2, tlen-clen);
        } else if (token == envelope_to) {
            hdr->envelope_to = token.substr(clen+2, tlen-clen);
        } else if (token == delivery_date) {
            hdr->delivery_date = token.substr(clen+2, tlen-clen);
        } else if (token == message_id) {
            hdr->message_id = token.substr(clen+2, tlen-clen);
        } else if (token == date) {
            hdr->date = token.substr(clen+2, tlen-clen);
        } else if (token == subject) {
            hdr->subject = token.substr(clen+2, tlen-clen);
        } else if (token == from) {
            hdr->from = token.substr(clen+2, tlen-clen);
        } else if (token == to) {
            hdr->to = token.substr(clen+2, tlen-clen);
        } else if (token == user_agent) {
            hdr->user_agent = token.substr(clen+2, tlen-clen);
        } else if (token == mime_version) {
            hdr->mime_version = token.substr(clen+2, tlen-clen);
        } else if (token == content_type) {
            hdr->content_type = token.substr(clen+2, tlen-clen);
        }

        s_cpy.erase(0, pos + delim.length());
	}

	return hdr;
}

//         int uid;
//         int size;
//         unsigned char flags;
//         std::string date;
//         std::string subject;
//         std::string from;
/* Get an email list in a subject* linked list from a FETCH emails response */
std::vector<Email*>
IMAP_parser::parse_emails(std::string s)
{
    std::vector<Email*> emails;

    const std::string delim = "\r\n";
    std::stringstream s_cpy;
    s_cpy << s;
    std::string token;
    int uid = 0, size = 0;
    std::string subj_s;
    std::string flags_s;
    std::string internaldate_s;
    std::string date_s;
    std::string from_s;
    std::size_t uid_pos, flags_pos, internaldate_pos, body_pos, size_pos;

    std::string decoded;

    Date_formatter *df {};

    while (getline(s_cpy, token, '\n'))
    {
        if (token[0] == '*')    // beginning of an email block
        {
            std::cout << "token: " << token << std::endl;
            uid_pos = token.find("UID ");
            flags_pos = token.find("FLAGS (");
            internaldate_pos = token.find(") INTERNALDATE \"");
            body_pos = token.find("BODY");
            size_pos = token.find("{");

            uid = stoi(token.substr(uid_pos + 4, flags_pos));
            flags_s.assign(token.substr(
                flags_pos + 7,
                internaldate_pos - flags_pos - 7));
            internaldate_s.assign(token.substr(
                internaldate_pos + 16, body_pos - internaldate_pos - 16 - 2));
            size = stoi(token.substr(size_pos +1));
        }
        else if (token[0] == ')')  // end of an email block
        {
            Email_infos* infos = new Email_infos();

            infos->uid = uid;
            infos->size = size;
            infos->flags = this->parse_flags(flags_s);
            infos->internaldate = df->format_date(internaldate_s);
            infos->date = df->format_date(date_s);
            infos->subject = subj_s;
            infos->from = from_s;

            Email* em = new Email();
            em->infos = infos;

            emails.push_back(em);
//             decoded = qp_decode(subj_s, true);
        } else {
            std::size_t colon_pos, bracket_pos;
            colon_pos = token.find_first_of(':');

            if (token.compare(0, 7, "Subject") == 0) {
                subj_s.assign(
                    token.substr(colon_pos + 1, std::string::npos - 1)
                );
            } else if (token.compare(0, 4, "From") == 0) {
                // If a sender name is mentioned, extract it.
                // Otherwise, just get the email address.
                if ((bracket_pos = token.find('<')) != std::string::npos) {
                    from_s.assign(
                        token.substr(
                            colon_pos + 1, bracket_pos - (colon_pos + 1)
                        ));
                } else {
                    from_s.assign(token.substr(colon_pos + 1));
                }
            } else if (token.compare(0, 4, "Date") == 0) {
                date_s.assign(
                    token.substr(colon_pos + 1, std::string::npos - 1)
                );
            }
        }
    }

    return emails;
}

// Parse a FETCH (RFC822.HEADER BODYSTRUCTURE) response into an Email object
Email*
IMAP_parser::parse_email(std::string s)
{
	std::string b_start_str = "BODYSTRUCTURE ";
	std::string b_end_str = "\r\nABCD";
	std::size_t b_spos = s.find(b_start_str);
	std::size_t b_epos = s.find(b_end_str);
	std::string hdr_s = s.substr(0, b_spos-1);
	std::size_t bs_start = b_spos + b_start_str.length();
	std::string bs = s.substr(bs_start, b_epos - bs_start);

//     std::cout << s << std::endl;
//     std::cout << "hdr_s: " + hdr_s << std::endl;
//     std::cout << "bs: " + bs << std::endl;

// 	RFC822_header* hdr = this->parse_header(hdr_s);
//     hdr->Dump_header(hdr);

	Bodypart* bp = new Bodypart();
	Bodystructure* bodyst = new Bodystructure();

	bodyst->type = "/";
	bodyst->subtype = "/";
	bp->bodystructure = bodyst;

    std::string base_section;
//     std::cout << "str: " << s << std::endl;
//     std::cout << "bs: " << bs << std::endl;
	if (strncmp(bs.c_str(), "(\"", 2) == 0) { /* no child or sibling */
		base_section = "1";
	} else {
		base_section = "0";
	}

	imap_parse_bodystructure(bs, bp, base_section, true);

	Email* em = new Email();

// 	em->rfc822_hdr = hdr;
	em->bodypart = bp;
// 	em->text = NULL;
	return em;
}

/*
 * Compute the next section of a bodypart based on wether its a child or a
 * sibling within a bodyparts prefix tree
 * Children/Siblings scheme (nested = child):
 * (((bp) (bp)) (bp))
 * |||    |     |
 * R12    3     4
 * R: root, 1:child of R, 2/3: siblings, 1/4: siblings
 */
std::string
IMAP_parser::get_new_section(std::string section, bool is_child)
{
    if (section == "0") {
        return "1";
    }

    if (is_child) {
        return section + ".1";
    }

    /* top level sibling, no dot in section */
    if (!is_child
        && section.find(".") != std::string::npos) {
        std::string num = std::to_string(stoi(section) + 1);
        return num;
    }

    std::vector<int> arr = explode_to_ints(section, ".");
    arr[arr.size()-1] = arr[arr.size()-1] + 1; // increment last section number

	std::stringstream ss;
	for (unsigned int i = 0; i < arr.size(); i++) {
		ss << arr[i];
        if (i != arr.size() -1)
            ss << ".";
	}
	std::string new_section = ss.str();
    new_section[new_section.length()-1] = '\0'; /* delete trailing dot */
    return new_section;
}

/* Dump a prefix tree of bodyparts */
void
dump_bodypart_tree(Bodypart* bp)
{
    if (!bp) {
        return;
    }

    if (bp->bodystructure) {
        std::cout << "type/subtype [section]: "
            << bp->bodystructure->type << "/"
            << bp->bodystructure->subtype
            << " [" << bp->section << "]" << std::endl;
    }

    dump_bodypart_tree(bp->child);
    dump_bodypart_tree(bp->sibling);
}

#ifdef IMAP_PARSER_DEBUG
// DEBUG
void
print_before_after_section(bool is_child, std::string old)
{
    IMAP_parser* imap_prsr = new IMAP_parser();
	std::string new_s = imap_prsr->get_new_section(old, is_child);
	std::cout << "section old, new => " << old << ", " << new_s << ", ";
	if (is_child) std::cout << "CHILD";
	else          std::cout << "SIBLING";
	std::cout << std::endl;
}

// Test various cases of sections labelling and nesting
int
main()
{
	IMAP_parser* imap_prsr = new IMAP_parser();

//     std::string s = "1.2.3";
//     std::vector<int> ints = imap_prsr->explode_to_ints(s, ".");
//     std::cout << "explode_to_ints \"" << s << "\" =>\n";
//
//     for (unsigned int i = 0; i < ints.size(); i++) {
//         std::cout << ints[i] << std::endl;
//     }
//
// 	print_before_after_section(true, "1");
// 	print_before_after_section(true, "1.2");
// 	print_before_after_section(false, "1");
// 	print_before_after_section(false, "1.2");
// 	print_before_after_section(false, "1.2.3");

// A FETCH 1:4 (UID FLAGS INTERNALDATE BODY.PEEK[HEADER.FIELDS (SUBJECT DATE FROM)])
    std::string list_resp = "* 1 FETCH (UID 15 FLAGS (\\Seen) INTERNALDATE \"22-Apr-2015 15:05:42 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {187}\r\n\
Date: Wed, 22 Apr 2015 15:05:41 +0200 (CEST)\r\n\
From: =?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?= <mail-auto@em2.fitnessboutique.fr>\r\n\
Subject: Confirmation de commande  BFN721693\r\n\
\r\n\
)\r\n\
* 2 FETCH (UID 16 FLAGS (\\Seen) INTERNALDATE \"22-Apr-2015 16:00:27 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {220}\r\n\
Date: Wed, 22 Apr 2015 16:00:26 +0200 (CEST)\r\n\
From: =?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?= <mail-auto@em2.fitnessboutique.fr>\r\n\
Subject: =?UTF-8?Q?Votre_compte_FitnessBoutique.fr__-_Mail_=C3=A0_conserver?=\r\n\
\r\n\
)\r\n\
* 3 FETCH (UID 17 FLAGS (\\Seen) INTERNALDATE \"22-Apr-2015 21:03:03 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {222}\r\n\
Date: Wed, 22 Apr 2015 21:03:02 +0200 (CEST)\r\n\
From: =?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?= <mail-auto@em2.fitnessboutique.fr>\r\n\
Subject: =?UTF-8?Q?FitnessBoutique_-_BFN721693_-_Commande_en_pr=C3=A9paration?=\r\n\
\r\n\
)\r\n\
* 4 FETCH (UID 21 FLAGS (\\Seen \\Answered) INTERNALDATE \"24-Apr-2015 16:37:05 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {126}\r\n\
Date: Fri, 24 Apr 2015 16:37:03 +0200\r\n\
Subject: Confirmation de votre inscription\r\n\
From: UBALDI<service-client@ubaldi.com>\r\n\
\r\n\
)\r\n\
A OK Fetch completed.";

    std::vector<Email*> emails = imap_prsr->parse_emails(list_resp);

    for (auto em : emails) {
        em->dump();
    }

    return 0;

    std::vector<std::string> resp = {
//         "* 80 FETCH (BODYSTRUCTURE (\"text\" \"html\" (\"charset\" \"windows-1252\") NIL NIL \"quoted-printable\" 96278 1919 NIL NIL NIL NIL))\r\nABCD005",
        "* 19 FETCH (BODYSTRUCTURE ((\"text\" \"plain\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 2651 56 NIL NIL NIL NIL)(\"text\" \"html\" (\"charset\" \"UTF-8\") NIL NIL \"quoted-printable\" 6156 94 NIL NIL NIL NIL) \"alternative\" (\"boundary\" \"----=_Part_1088573_1111472050.1426796638059\") NIL NIL NIL))\r\nABCD005"
    };

// 	std::string sect;
// 	for (unsigned int i = 0; i < resp.size(); i++) {
//         Email* em = imap_prsr->parse_email(resp[i]);
//         Dump_header(em->rfc822_hdr);
// 		std::cout << "=======\n"
// 				  << "e-mail date: " << em->rfc822_hdr->date
// 				  << std::endl;
// 		dump_bodypart_tree(em->bodypart);
// 		find_email_first_section(em->bodypart, "text", "plain", sect);
// 		ttydebug("plain text section: %s\n\n", sect);
// 		free(sect);
// 		free_email(em);
// 	}
    return 0;
}
#endif
