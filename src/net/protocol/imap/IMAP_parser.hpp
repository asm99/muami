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
#include "../../email/Body.hpp"
#include "../../email/Email.hpp"
#include "../../email/Envelope.hpp"
#include "../../email/Mailbox.hpp"
#include "../../email/RFC822_header.hpp"
#include "../../util/date.hpp"
#include "../../util/util.hpp"
#include "../../debug/debug.hpp"

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

namespace IMAP_parser
{
        bool check_server_imap_capability(string s);

        /* Mailbox parsing functions */
        void parse_list(map<string, Mailbox*>& mboxes, const string& s);
        void parse_select(Mailbox* mb, const string& s);

        RFC822_header* parse_header(string s);
        Body* parse_bodystructure(stringstream& ss);
        vector<Email*> parse_emails(string s);
        void parse_emails_infos(vector<Email*>& emails, string s);

        void add_sections(Body* body,
                          bool is_first_subpart=false,
                          int depth=0,
                          string section="0");
}

#endif /* end of include guard: IMAP_PARSER_H */
