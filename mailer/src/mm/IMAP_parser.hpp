#ifndef IMAP_PARSER_H
#define IMAP_PARSER_H

/*
 * MELKONIAN Marc - 13410425
 * IMAP_parser.hpp - parsing functions for IMAP server responses
 * Date: 04 May 2015
 */

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include "Email.hpp"
#include "RFC822_header.hpp"
#include "Bodystructure.hpp"
#include "Bodypart.hpp"
#include "Date_formatter.hpp"

/*
 * IMAP server responses status
 * https://tools.ietf.org/html/rfc3501#section-7
 */
enum class IMAP_Responses_Status : char {
    IMAP_RESPONSE_OK = 0,
    IMAP_RESPONSE_NO,
    IMAP_RESPONSE_BAD,
    IMAP_RESPONSE_PREAUTH,
    IMAP_RESPONSE_BYE,
    IMAP_RESPONSE_UNKNOWN = 999,
};

/*
 * Body part types
 * doc: https://tools.ietf.org/html/rfc1341#page-29
 */
//enum Multiparts {
//        MULTIPART_MIXED = 0,
//        MULTIPART_ALTERNATIVE,
//        MULTIPART_DIGEST,
//        MULTIPART_PARALLEL,
//};
//
/*
 * Message Content-Type
 * doc: https://tools.ietf.org/html/rfc1341#page-36
 */
//enum Content_types {
//        MESSAGE_RFC822 = 0,
//        MESSAGE_PARTIAL,
//        MESSAGE_EXTERNAL_BODY,
//}
//
///* Content-Disposition header field values
// * doc: https://tools.ietf.org/html/rfc2183#page-2
// */
//enum Disposition_types {
//        DISPOSITION_INLINE = 0,
//        DISPOSITION_ATTACHMENT,
//        DISPOSITION_EXTENSION_TOKEN,
//};

/*
 * Bodypart types
 * doc: https://tools.ietf.org/html/rfc3501#page-76
 */
enum class BP_TYPES : char {
    BP_TYPE_TEXT = 0,
    BP_TYPE_MESSSAGE_RFC822,
    BP_TYPE_OTHER,
};

/*
 * Bodystructure fields
 * All bodystructures contain the basic fields, the other fields depends
 * on the type of bodystructure (text, rfc822 message…)
 * doc: https://tools.ietf.org/html/rfc3501#page-74
 */
enum class BS_BASIC_FIELDS : char {
    BS_TYPE        = 0,
    BS_SUBTYPE     = 1,
    BS_PARAMETERS  = 2,
    BS_ID          = 3,
    BS_DESCRIPTION = 4,
    BS_ENCODING    = 5,
    BS_SIZE        = 6,
};

enum class BS_MESSAGE_RFC822_FIELDS : char {
    BS_ENVELOPE                  = 7,
    BS_BODYSTRUCTURE             = 8,
    BS_MESSAGE_RFC822_LINES_SIZE = 9,
};

enum class BS_TEXT_FIELDS : char {
    BS_TEXT_LINES_SIZE = 7,
    BS_TEXT_MD5        = 8,
    BS_TEXT_DISPOSITON = 9,
    BS_TEXT_LANGUAGE   = 10,
    BS_TEXT_LOCATION   = 11,
    BS_TEXT_EXTENSION_PARAMETERS = 12,
};

enum class BS_OTHER_FIELDS : char {
    BS_EXTENSION_PARAMETERS = 7,
};
//
///* Bodystructure type */
//enum BS_TYPE {
//        BS_TYPE_TEXT,
//        BS_TYPE_IMAGE,
//        BS_TYPE_AUDIO,
//        BS_TYPE_VIDEO,
//        BS_TYPE_APPLICATION,
//        BS_TYPE_EXTENSION_TOKEN,
//}
//
///* Bodystructure encoding */
//enum BS_ENCODING {
//        BS_ENC_7BIT = 0,
//        BS_ENC_8BIT,
//        BS_ENC_BINARY,
//        BS_ENC_QUOTED_PRINTABLE,
//        BS_ENC_BASE64,
//        BS_ENC_IETF_TOKEN,
//        BS_ENC_X-TOKEN,
//}


class IMAP_parser {
    private:
        unsigned char parse_flags(std::string s);

    public:
        IMAP_parser() {};
        ~IMAP_parser() {};

        bool check_server_imap_capability(std::string s);

        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        // !!!!!!! to make private after tests !!!!!!!!
        // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        RFC822_header* parse_header(std::string s);
        void imap_parse_bodystructure(
            std::string s, Bodypart* tree, std::string section, bool is_child);
        Bodystructure* parse_bodystructure(std::string s);
        std::vector<int> explode_to_ints(std::string s, std::string delim);
        std::string strip_chars(std::string src, std::string set);
        int get_bodypart_length(std::string s);
        std::string get_new_section(std::string section, bool is_child);
        std::vector<Email*> parse_emails(std::string s);
        Email* parse_email(std::string s);
};

// #ifndef IMAP_PARSER_H
// #define IMAP_PARSER_H
//
// #define _GNU_SOURCE
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <regex.h>
// #include <stdbool.h>
// #include "debug.h"
// #include "dateformat.h"
// #include "coding.h"
// #include <unistd.h>
// #include "imap.h"
//
// /*
//  * Messages flags
//  * https://tools.ietf.org/html/rfc3501#section-2.3.2
//  */
// enum Flags {
//         FL_ANSWERED  = 0x01,
//         FL_FLAGGED   = 0x02,
//         FL_DELETED   = 0x04,
//         FL_SEEN      = 0x08,
//         FL_DRAFT     = 0x10,
//         FL_FORWARDED = 0x20,
// };
//
// /*
//  * IMAP server responses status
//  * https://tools.ietf.org/html/rfc3501#section-7
//  */
// enum IMAP_Responses_Status {
//         IMAP_RESPONSE_OK = 0,
//         IMAP_RESPONSE_NO,
//         IMAP_RESPONSE_BAD,
//         IMAP_RESPONSE_PREAUTH,
//         IMAP_RESPONSE_BYE,
//         IMAP_RESPONSE_UNKNOWN = 999,
// };
//
// /*
//  * Body part types
//  * doc: https://tools.ietf.org/html/rfc1341#page-29
//  */
// //enum Multiparts {
// //        MULTIPART_MIXED = 0,
// //        MULTIPART_ALTERNATIVE,
// //        MULTIPART_DIGEST,
// //        MULTIPART_PARALLEL,
// //};
//
// /*
//  * Message Content-Type
//  * doc: https://tools.ietf.org/html/rfc1341#page-36
//  */
// //enum Content_types {
// //        MESSAGE_RFC822 = 0,
// //        MESSAGE_PARTIAL,
// //        MESSAGE_EXTERNAL_BODY,
// //}
//
// ///* Content-Disposition header field values
// // * doc: https://tools.ietf.org/html/rfc2183#page-2
// // */
// //enum Disposition_types {
// //        DISPOSITION_INLINE = 0,
// //        DISPOSITION_ATTACHMENT,
// //        DISPOSITION_EXTENSION_TOKEN,
// //};
//
// /*
//  * Bodypart types
//  * doc: https://tools.ietf.org/html/rfc3501#page-76
//  */
// enum BP_TYPES {
//         BP_TYPE_TEXT = 0,
//         BP_TYPE_MESSSAGE_RFC822,
//         BP_TYPE_OTHER,
// };
//
// /*
//  * Bodystructure fields
//  * All bodystructures contain the basic fields, the other fields depends
//  * on the type of bodystructure (text, rfc822 message…)
//  * doc: https://tools.ietf.org/html/rfc3501#page-74
//  */
// enum BS_BASIC_FIELDS {
//         BS_TYPE        = 0,
//         BS_SUBTYPE     = 1,
//         BS_PARAMETERS  = 2,
//         BS_ID          = 3,
//         BS_DESCRIPTION = 4,
//         BS_ENCODING    = 5,
//         BS_SIZE        = 6,
// };
//
// enum BS_MESSAGE_RFC822_FIELDS {
//         BS_ENVELOPE                  = 7,
//         BS_BODYSTRUCTURE             = 8,
//         BS_MESSAGE_RFC822_LINES_SIZE = 9,
// };
//
// enum BS_TEXT_FIELDS {
//         BS_TEXT_LINES_SIZE = 7,
//         BS_TEXT_MD5        = 8,
//         BS_TEXT_DISPOSITON = 9,
//         BS_TEXT_LANGUAGE   = 10,
//         BS_TEXT_LOCATION   = 11,
//         BS_TEXT_EXTENSION_PARAMETERS = 12,
// };
//
// enum BS_OTHER_FIELDS {
//         BS_EXTENSION_PARAMETERS = 7,
// };
//
// ///* Bodystructure type */
// //enum BS_TYPE {
// //        BS_TYPE_TEXT,
// //        BS_TYPE_IMAGE,
// //        BS_TYPE_AUDIO,
// //        BS_TYPE_VIDEO,
// //        BS_TYPE_APPLICATION,
// //        BS_TYPE_EXTENSION_TOKEN,
// //}
// //
// ///* Bodystructure encoding */
// //enum BS_ENCODING {
// //        BS_ENC_7BIT = 0,
// //        BS_ENC_8BIT,
// //        BS_ENC_BINARY,
// //        BS_ENC_QUOTED_PRINTABLE,
// //        BS_ENC_BASE64,
// //        BS_ENC_IETF_TOKEN,
// //        BS_ENC_X-TOKEN,
// //}
//
// /* Email header info */
// typedef struct subject {
//         int uid;
//         int size;
//         unsigned char flags;
//         char* date;
//         char* subject;
//         char* from;
// } subject;
//
// /* Mailbox folders */
// typedef struct mailbox {
//         char* name;
//         char separator;
//         struct mailbox* prev;
//         struct mailbox* next;
// } mailbox;
//
// /*
//  * Content-Disposition header field in a BODYSTRUCTURE
//  * doc: https://tools.ietf.org/html/rfc2183
//  */
// typedef struct content_disposition {
//         int disposition_type;
//         char* filename_parm;
//         char* creation_date_parm;
//         char* modification_date_parm;
//         char* read_date_parm;
//         char* size_parm;
// } content_disposition;
//
// /*
//  * Extension data header field in a BODYSTRUCTURE
//  * doc: http://tools.ietf.org/html/rfc3501#page-74
//  */
// typedef struct extension_parameters {
//         char* parameters;
//         content_disposition* disposition;
//         char* language;
//         char* location;  /* https://tools.ietf.org/html/rfc2557 */
// } extension_parameters;
//
// /*
//  * struct for a bodystructure
//  * doc: http://tools.ietf.org/html/rfc3501#page-73
//  */
// typedef struct bodystructure {
//         char* type;
//         char* subtype;
//         char** parameters;
//         char* id;
//         char* description;
//         char* encoding;
//         int size;
//         extension_parameters* extension_parameters;
// } bodystructure;
//
// /* E-mail rfc822 header */
// typedef struct header {
//         char* return_path;
//         char* envelope_to;
//         char* delivery_date;
//         char* message_id;
//         char* date;
//         char* subject;
//         char* from;
//         char* to;
//         char* user_agent;
//         char* mime_version;
//         char* content_type;
// } header;
//
// /* E-mail body part */
// typedef struct bodypart {
//         char* section;
//         bodystructure* bodystructure;
//         struct bodypart* sibling;
//         struct bodypart* child;
// } bodypart;
//
// /* E-mail */
// typedef struct email {
//         header* header;      /* e-mail RFC822 header */
//         bodypart* bodypart;  /* BODYSTRUCTURE bodyparts */
//         char* text;          /* first text part content */
// } email;
//
// subject* parse_emails(char*, int);
// bool     check_server_imap_capability(char*);
// int      imap_parse_nb_msgs(char*, int*, int*);
// int      imap_parse_resp_status(char*);
// mailbox* imap_parse_mboxes_names(char*);
// unsigned char imap_parse_mbox_perm_flags(char*);
// int      imap_parse_msgs_count(char*, int*, int*);
// email*   parse_email(char*);
// void     imap_parse_bodystructure(char*, bodypart*, char*, bool);
// void     imap_dump_subjects(subject*, int);
// void     dump_tree(bodypart*);
// void     dump_bodystructure(bodystructure*);
// void     dump_header(header*);
// void     find_email_first_section(bodypart*, char*, char*, char*);
// char*    clean_response(char* s);
//
// void free_email(email* em);
//
// #endif /* end of include guard: IMAP_PARSER_H */

#endif /* end of include guard: IMAP_PARSER_H */
