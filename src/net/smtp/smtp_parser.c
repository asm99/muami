/*
 * MELKONIAN Marc - 13410425
 * smtp_parser.c - parsing functions for SMTP server responses
 * Date: 04 May 2015
 */

#include "smtp_parser.h"

/* static functions */
static newmessage* new_newmessage();

/* Create a newmessage */
static newmessage*
new_newmessage()
{
        newmessage *new_msg, tmp = {0};
        new_msg = malloc(sizeof(struct newmessage));
        if (!new_msg) {
                return NULL;
        }
        *new_msg = tmp;
        return new_msg;
}

/* Return status code flags of a SMTP server response */
unsigned short
smtp_parse_resp_status(char* s)
{
        int t;
        int fst, snd; /* first and second digits of the 3-digit code */
        unsigned short flags = 0;

        t = sscanf(s, "%1d%1d%*1d ", &fst, &snd);
        if (t != 2) {
                return 0;
        }

        switch (fst) {
                case 2:
                        flags |= SMTP_CODE_SUCCESS;
                        break;
                case 4:
                        flags |= SMTP_CODE_PERSISTENT_FAILURE;
                        break;
                case 5:
                        flags |= SMTP_CODE_PERMANENT_FAILURE;
                        break;
                default:
                        flags |= SMTP_CODE_SUCCESS; /* case 3 means success */
                        break;
        }

        switch (snd) {
                case 0:
                        flags |= SMTP_SUBCODE_UNDEFINED;
                        break;
                case 1:
                        flags |= SMTP_SUBCODE_ADDRESSING;
                        break;
                case 2:
                        flags |= SMTP_SUBCODE_MAILBOX;
                        break;
                case 3:
                        flags |= SMTP_SUBCODE_MAIL_SYSTEM;
                        break;
                case 4:
                        flags |= SMTP_SUBCODE_NETWORK;
                        break;
                case 5:
                        flags |= SMTP_SUBCODE_MAIL_DELIVERY_PROTOCOL;
                        break;
                case 6:
                        flags |= SMTP_SUBCODE_MESSAGE_CONTENT;
                        break;
                case 7:
                        flags |= SMTP_SUBCODE_SECURITY;
                        break;
                default:
                        break;
        }

        return flags;
}

/* Get a newmessage* from a raw composed message string */
newmessage*
parse_composed_msg(char* s)
{
        newmessage* new_msg = new_newmessage();
        if (!new_msg) {
                return NULL;
        }

        /* split message header info and content body */
        int seppos = strpos(s, EMAIL_COMPOSE_SEPARATOR);
        char* info = substr(s, 0, seppos);

        /* set content */
        char* content = substr(s,
                               seppos + strlen(EMAIL_COMPOSE_SEPARATOR) + 1,
                               strlen(s));
        if (!content || strlen(content) == 0) {
                return NULL;
        }

        /* bare LFs are not allowed so replace LFs by CRLFs */
        char* corr_content = str_replace(content, "\n", "\r\n");
        free(content);
        new_msg->content = strdup(corr_content);
        free(corr_content);

        /* parse header info */
        const char* delim = "\n";
        char* s_cpy = strdup(info);
        char* running = s_cpy;
        char* token;

        char basket[128];
        memset(basket, 0, sizeof basket);

        int t;
        while ((token = strsep(&running, delim)) != NULL) {
                if ((t = sscanf(token, "RECIPIENT:%[^\r\n]\n", basket)) == 1) {
                        new_msg->to = strdup(basket);
                } else if ((t=sscanf(token, "SUBJECT:%[^\r\n]\n", basket)) == 1) {
                        new_msg->subject = strdup(basket);
                }
        }

        free(s_cpy);
        free(info);
        return new_msg;
}

/* Dump all fields of a newmessage */
void
dump_newmessage(newmessage* new_msg)
{
        if (!new_msg) {
                printf("%s\n", "Empty newmessage");
                return;
        }
        ttydebug("new_msg->to: %s\n", new_msg->to);
        ttydebug("new_msg->subject: %s\n", new_msg->subject);
        ttydebug("new_msg->content: %s\n", new_msg->content);
}

/* Release the memory allocated for a newmessage struct */
void
free_newmessage(newmessage *new_msg)
{
        if (!new_msg) {
                return;
        }

        if (new_msg->to)      { free(new_msg->to); }
        if (new_msg->subject) { free(new_msg->subject); }
        if (new_msg->content) { free(new_msg->content); }

        new_msg = NULL;
}

/*
 * Check if composed message is valid :
 *   - recipient(s) field is not empty,
 *   - content is not empty.
 * TODO: better validity check
 */
bool
is_valid_message(newmessage* new_msg)
{
        dump_newmessage(new_msg);
        bool is_valid = true;
        if (!new_msg
            || !new_msg->content
            || strlen(new_msg->content) == 0
            || !new_msg->to
            || strlen(new_msg->to) == 0
            || strpos(new_msg->to, "@") < 0) {
                is_valid = false;
        }
        return is_valid;
}
