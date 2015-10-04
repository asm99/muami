/*
 * MELKONIAN Marc - 13410425
 * IMAP_parser.hpp - parsing functions for IMAP server responses
 * Date: 04 May 2015
 */

#ifndef IMAP_PARSER_H
#define IMAP_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include "../../email/Email.hpp"
#include "../../email/RFC822_header.hpp"
#include "../../email/Envelope.hpp"
// #include "../email/Bodystructure.hpp"
// #include "../email/Bodypart.hpp"
#include "../../utils/Date_formatter.hpp"
#include "../../utils/util.hpp"
#include "../../email/Mailbox.hpp"

using namespace std;

/*
 * IMAP server responses status
 * https://tools.ietf.org/html/rfc3501#section-7
 */
enum class IMAP_Responses_Status : char {
    IMAP_RESPONSE_STATUS_OK = 0,
    IMAP_RESPONSE_STATUS_NO,
    IMAP_RESPONSE_STATUS_BAD,
    IMAP_RESPONSE_STATUS_PREAUTH,
    IMAP_RESPONSE_STATUS_BYE,
    IMAP_RESPONSE_STATUS_UNKNOWN
};

class IMAP_parser
{
    private:
        unsigned char parse_flags(const string& s);

        /* Mailbox parsing functions */
        unsigned int parse_mbox_flags(const string& s);
        unsigned int parse_mbox_perm_flags(const string& s);
        unsigned int parse_mbox_exists(const string& s);
        unsigned int parse_mbox_recent(const string& s);
        unsigned int parse_mbox_star_line(const string& s, const string& token);
        unsigned int parse_mbox_ok_line(const string& s, const string& token);
        unsigned int parse_mbox_unseen(const string& s);
        unsigned int parse_mbox_uidvalidity(const string& s);
        unsigned int parse_mbox_uidnext(const string& s);
        int parse_mbox_permissions(const string& s);

    public:
        IMAP_parser() {};
        ~IMAP_parser() {};

        bool check_server_imap_capability(string s);

        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // !!!!!!! to make private after tests !!!!!!!!
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        /* Mailbox parsing functions */
        void parse_mailbox_infos(Mailbox& mb, const string& s);

        RFC822_header* parse_header(string s);
//         void imap_parse_bodystructure(
//                 string s, Bodypart* tree, string section, bool is_child);
//         Bodystructure* parse_bodystructure(string s);
        vector<Email*> parse_emails(string s);
        void parse_emails_infos(vector<Email*>& emails, string s);
        Email* parse_email(string s);
};

#endif /* end of include guard: IMAP_PARSER_H */
