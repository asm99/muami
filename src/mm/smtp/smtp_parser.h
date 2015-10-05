/*
 * MELKONIAN Marc - 13410425
 * smtp_parser.h - parsing functions for SMTP server responses
 * Date: 04 May 2015
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helper.h"

#define EMAIL_COMPOSE_SEPARATOR "---------"

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

/* A new composed e-mail to send */
typedef struct newmessage {
        char* to;
        char* subject;
        char* content;
} newmessage;

unsigned short smtp_parse_resp_status(char*);
newmessage* parse_composed_msg(char*);
bool is_valid_message(newmessage* new_msg);
void dump_newmessage(newmessage* new_msg);
void free_newmessage(newmessage* new_msg);
