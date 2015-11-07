/*
 * MELKONIAN Marc - 13410425
 * smtp_parser.h - parsing functions for SMTP server responses
 * Date: 04 May 2015
 */

#ifndef SMTP_PARSER_H
#define SMTP_PARSER_H

#include "Out_email.hpp"

/*
 * SMTP server responses status codes
 * https://tools.ietf.org/html/rfc3463#page-3
 * TODO: handle all status codes
 */
enum SMTP_Status_Codes {
        SMTP_CODE_SUCCESS                   = 0x001,  /* 2.X.X */
        SMTP_CODE_PERSISTENT_FAILURE        = 0x002,  /* 4.X.X */
        SMTP_CODE_PERMANENT_FAILURE         = 0x004,  /* 5.X.X */
};

enum SMTP_Status_Subcodes {
        SMTP_SUBCODE_UNDEFINED              = 0x008,  /* X.0.X */
        SMTP_SUBCODE_ADDRESSING             = 0x010,  /* X.1.X */
        SMTP_SUBCODE_MAILBOX                = 0x020,  /* X.2.X */
        SMTP_SUBCODE_MAIL_SYSTEM            = 0x040,  /* X.3.X */
        SMTP_SUBCODE_NETWORK                = 0x080,  /* X.4.X */
        SMTP_SUBCODE_MAIL_DELIVERY_PROTOCOL = 0x100,  /* X.5.X */
        SMTP_SUBCODE_MESSAGE_CONTENT        = 0x200,  /* X.6.X */
        SMTP_SUBCODE_SECURITY               = 0x400,  /* X.7.X */
};

namespace SMTP_parser {

    unsigned short parse_resp_status(const string& s);
//     newmessage* parse_composed_msg(string);
//     bool is_valid_message(Out_email& em);
//     void dump_newmessage(Out_email& em);
//     void free_newmessage(Out_email& em);

} /* namespace SMTP_parser */

#endif /* end of include guard: SMTP_PARSER_H */
