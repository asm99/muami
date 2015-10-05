/*
 * MELKONIAN Marc - 13410425
 * smtp.c - Communication with SMTP server and related things
 * Date: 04 May 2015
 */

#include "smtp.h"

#define MIME_VERSION "1.0"
#define USER_AGENT   "MuaMi/0.1.1"

/* static functions */
static int   smtp_connect(account* acc, int* fd);
static int   smtp_starttls(account* acc, int sockfd);
static char* rw_socket(int sockfd, char* cmd);
static char* rw_ssl(SSL* ssl, char* cmd);
static char* get_helo_cmd(account* acc);
static char* build_email_body(account* acc, newmessage* new_msg);
static char* gen_msg_id(account* acc);
static char* extract_mdn(account* acc);
static char* get_mime_version();
static char* get_user_agent();
static char* extract_email_address(char* user);

/* Write a command to a socket and read the server response */
static char*
rw_socket(int sockfd, char* cmd)
{
        int t;
        int sz = 1024;
        char* buffer = calloc(sz, 1);
        if (!buffer) {
                puts("Can't malloc");
                return NULL;
        }

        t = write(sockfd, cmd, strlen(cmd));
        if (t < 0) {
                perror("ERROR writing to socket");
                return NULL;
        }

        t = read(sockfd, buffer, sz-1);
        if (t < 0) {
                perror("ERROR reading from socket");
                return NULL;
        }
        ttydebug("%s\n", buffer);

        return buffer;
}

/* Write a command to a SSL socket layer and read the server response */
static char*
rw_ssl(SSL* ssl, char* cmd)
{
        int t;
        int sz = 1024;
        char* buffer = calloc(sz, 1);
        if (!buffer) {
                puts("Can't malloc");
                return NULL;
        }

        t = SSL_write(ssl, cmd, strlen(cmd));
        if (t < 0) {
                perror("ERROR writing to socket");
                return NULL;
        }

        t = SSL_read(ssl, buffer, sz-1);
        if (t < 0) {
                perror("ERROR reading from socket");
                return NULL;
        }
        ttydebug("%s\n", buffer);

        return buffer;
}

/* Get SMTP HELO command with user e-mail address */
static char*
get_helo_cmd(account* acc)
{
        char* helo = malloc(strlen(acc->user) + 7);
        if (!helo) {
                return NULL;
        }
        sprintf(helo, "HELO %s\r\n", acc->user);
        return helo;
}

/*
 * Connect to a SMTP server with a non secure socket
 * Returns 0 on success, -1 on failure
 */
static int
smtp_connect(account* acc, int* fd)
{
        int sockfd, t;
        struct sockaddr_in serv_addr;
        struct hostent *server;
        char buffer[256];

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
                perror("socket");
                return -1;
        }

        server = gethostbyname(acc->smtp);
        if (!server) {
                perror("gethostbyname");
                return -1;
        }

        memset((char*)&serv_addr, 0, sizeof serv_addr);
        serv_addr.sin_family = AF_INET;
        bcopy((char*)server->h_addr,
              (char*)&serv_addr.sin_addr.s_addr,
              server->h_length);
        serv_addr.sin_port = htons(atoi(acc->sport));

        t = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
        if (t < 0) {
                perror("connect");
                return -1;
        }
        memset(buffer, 0, sizeof(buffer));
        /* read server greeting on connection */
        t = read(sockfd, buffer, sizeof(buffer) - 1);
        if (t < 0) {
                perror("ERROR reading from socket");
                return -1;
        }
        ttydebug("%s\n",buffer);

        *fd = sockfd;
        return 0;
}

/*
 * Execute SMTP HELO and STARTTLS commands on a non secure socket
 * Returns 0 on success, -1 on failure
 */
static int
smtp_starttls(account* acc, int sockfd)
{
        char* helo; /* HELO command */
        char* resp; /* server response */
        unsigned short rc;
        unsigned int i;
        int retval = 0;

        helo = get_helo_cmd(acc);
        if (!helo) {
                return -1;
        }

        char* cmds[] = { helo, "STARTTLS\r\n", NULL };

        for (i = 0; cmds[i]; i++) {
                resp = rw_socket(sockfd, cmds[i]);
                ttydebug("CMD: %s\nSMTP: %s\n", cmds[i], resp);
                rc = smtp_parse_resp_status(resp);
                if (!(rc & SMTP_CODE_SUCCESS)) {
                        printf("Error SMTP - cmd: %s\n", cmds[i]);
                        puts(resp);
                        retval = -1;
                }
                free(resp);
        }

        return retval;
}

/* Return the user agent name and version */
static char*
get_user_agent()
{
        return USER_AGENT;
}

/*
 * Return the MIME version for a SMTP header field
 * Currently, only version 1.0 is used and mentioning the version is
 * mandatory
 */
static char*
get_mime_version()
{
        return MIME_VERSION;
}

/*
 * Extract e-mail address from an account "from" field
 * Returns the e-mail address on success, the "from" field as it on failure
 */
static char*
extract_email_address(char* user)
{
        int lbracket = strpos(user, "<");
        if (lbracket < 0) {
                return strdup(user);
        }

        char* res = NULL;

        int rbracket = strpos(user, ">");
        if (rbracket < 0) {
                res = substr(user, lbracket + 1, strlen(user));
        } else {
                res = substr(user, lbracket + 1, rbracket - (lbracket + 1));
        }
        return res;
}

/*
 * Extract a mail domain name from an e-mail address
 * If the account user string doesn't contain any @,
 * then use the account smtp string
 */
static char*
extract_mdn(account* acc)
{
        char* user = strdup(acc->user);
        int arobpos = strpos(user, "@");
        if (arobpos < 0) {
                free(user);
                return strdup(acc->smtp);
        }
        char* domain_nm = substr(user, arobpos+1, (int)strlen(user));
        free(user);
        return domain_nm;
}

/*
 * Generate a Message-ID header field
 * Process:
 *   1. Get the current time in ns
 *   2. Generate a 64 bits random number
 *   3. Encode these numbers to base36 representations A and B
 *   4. Concatenate A and B
 *   5. Encode the result to a MD5 hash string
 *   6. Return the following ID: <md5_hash@mail_domain_name>
 *   ie: <e957cbf3ea0579354498ac1898fb8137@foad.iedparis8.net>
 */
static char*
gen_msg_id(account* acc)
{
        int t;
        unsigned long rand_num = 0;
        struct timespec tp = {0};
        char* pre_md5 = NULL;
        char* md5 = NULL;
        char* mdn = NULL;

        /* get current time */
        t = clock_gettime(CLOCK_REALTIME, &tp);
        if (t < 0) { /* clock_gettime failure */
                return NULL;
        }

        /* generate a 64 bits random number */
        rand_num = random();
        ttydebug("clock, rand: %li, %li\n", tp.tv_nsec, rand_num);

        /* convert these numbers to their base36 representation */
        char* b36_time = to_base36(tp.tv_nsec);
        char* b36_rand = to_base36(rand_num);
        ttydebug("b36_time, b36_rand: %s, %s\n", b36_time, b36_rand);

        pre_md5 = malloc(strlen(b36_time) + strlen(b36_rand) + 1);
        if (!pre_md5) {
                return NULL;
        }
        sprintf(pre_md5, "%s%s", b36_time, b36_rand);
        ttydebug("pre_md5: %s\n", pre_md5);

        md5 = md5_encode(pre_md5);
        free(pre_md5);

        ttydebug("md5: %s\n", md5);

        mdn = extract_mdn(acc);
        ttydebug("mdn: %s\n", mdn);

        char* msgid = malloc(strlen(md5) + strlen(mdn) + 4);
        if (!msgid) {
                return NULL;
        }
        sprintf(msgid, "<%s@%s>", md5, mdn);
        free(md5);
        free(mdn);
        ttydebug("msgid: %s\n", msgid);

        return msgid;
}

/*
 * Build the body of an e-mail message (header + content)
 * Doc: https://tools.ietf.org/html/rfc2822#page-18 (header fields)
 */
static char*
build_email_body(account* acc, newmessage* new_msg)
{
        int sz = 4096;
        char* body = calloc(sz, 1);
        if (!body) {
                return NULL;
        }

        char* date = get_current_date();
        char* msgid = gen_msg_id(acc);
        char* sender = extract_email_address(acc->from);
        char* mime_ver = get_mime_version();
        char* user_agent = get_user_agent();

        snprintf(body,
                 sz - 1,
                 "To: %s\r\n"
                 "From: %s\r\n"
                 "Date: %s\r\n"
                 "Message-ID: %s\r\n"
                 "Sender: %s\r\n"
                 "MIME-Version: %s\r\n"
                 "User-Agent: %s\r\n"
                 "Content-Type: text/plain; charset=UTF-8\r\n"
                 "Subject: %s\r\n"
                 "\r\n%s\r\n.\r\n",
                 new_msg->to,
                 acc->from,
                 date,
                 msgid,
                 sender,
                 mime_ver,
                 user_agent,
                 new_msg->subject,
                 new_msg->content);

        free(date);
        free(msgid);
        free(sender);

        printf("BODY:\n%s\n", body);
        return body;
}

/*
 * Send an e-mail with an account
 * Returns 0 on success, -1 on error
 * Process :
 *   1. First open a non-secure connection with a socket and send HELO
 *      and STARTTLS commands
 *   2. Set SSL with this socket
 *   3. Send commands one by one
 *   4. Check responses
 * Doc: https://tools.ietf.org/html/rfc4021         (e-mail header fields)
 *      https://tools.ietf.org/html/rfc2822#page-18 (e-mail header fields)
 * FIXME: e-mail content body size is fixed (4096 for now)
 */
int
send_email(account* acc, newmessage* new_msg)
{
        unsigned short rc;
        int t, sockfd;
        t = smtp_connect(acc, &sockfd);
        if (t < 0) { /* smtp_connect failure */
                printf("%s\n", "Error smtp_connect");
                return -1;
        }

        t = smtp_starttls(acc, sockfd);
        if (t < 0) { /* HELO and/or STARTTLS failure */
                printf("%s\n", "Error smtp_starttls");
                return -1;
        }

        /* no need to init SSL, at this point, it's already been done at
         * the program start */
//         SSL_library_init();
//         SSL_load_error_strings();

        SSL_CTX* myctx = SSL_CTX_new(SSLv23_client_method());
        if (!myctx) {
                ERR_print_errors_fp(stderr);
                return -1;
        }
//         SSL_CTX_set_options(myctx, SSL_OP_NO_SSLv2);
        SSL* myssl = SSL_new(myctx);
        if (!myssl) {
                ERR_print_errors_fp(stderr);
                return -1;
        }

        t = SSL_set_fd(myssl, sockfd);
        if (t == 0) {  /* SSL_set_fd failure */
                ERR_print_errors_fp(stderr);
                return -1;
        }

        t = SSL_connect(myssl);
        if (t < 1) {
                ERR_print_errors_fp(stderr);
        }

        char* helo = get_helo_cmd(acc);
        char* mail_from = malloc(strlen("MAIL FROM:<>\r\n")
                                 + strlen(acc->user) + 1);
        char* rcpt_to = malloc(strlen("RCPT TO:<>\r\n")
                               + strlen(new_msg->to) + 1);
        char* body = build_email_body(acc, new_msg);

        if (!helo || !mail_from || !rcpt_to || !body) {
                return -1;
        }

        char* data = "DATA\r\n";
        char* quit = "QUIT\r\n";
        char* login = "AUTH LOGIN\r\n";
        char* b64_user = to_base64(acc->user);
        char* b64_pass = to_base64(acc->pass);
        sprintf(mail_from, "MAIL FROM:<%s>\r\n", acc->user);
        if (strchr(new_msg->to, '<')) {
                char* em_addr = extract_email_address(new_msg->to);
                sprintf(rcpt_to, "RCPT TO:<%s>\r\n", em_addr);
                free(em_addr);
        } else {
                sprintf(rcpt_to, "RCPT TO:<%s>\r\n", new_msg->to);
        }

        char* user = malloc(strlen(b64_user) + 3);
        char* pass = malloc(strlen(b64_pass) + 3);
        sprintf(user, "%s\r\n", b64_user);
        sprintf(pass, "%s\r\n", b64_pass);
        free(b64_user);
        free(b64_pass);

        ttydebug("b64_user, b64_pass: %s, %s\n", b64_user, b64_pass);

        char* msgs[] = {
                helo, login, user, pass,
                mail_from, rcpt_to, data, body,
                quit, NULL
        };

        char* resp;
        int j, retval = 0;
        for (j = 0; msgs[j]; j++) {
                resp = rw_ssl(myssl, msgs[j]);
                rc = smtp_parse_resp_status(resp);
                ttydebug("CMD: %s\nSMTP: %s\n", msgs[j], resp);
                if (!(rc & SMTP_CODE_SUCCESS)) {
                        printf("Error SMTP - cmd: %s\n", msgs[j]);
                        puts(resp);
                        retval = -1;
                        break;
                }
                free(resp);
        }

        return retval;
}

#ifdef DEBUG
#include "editor.h"

/* Test static functions and send a dummy e-mail with SMTP over SSL */
int
main()
{
        account* acc;
        int t;

        acc = load_config();
        acc = get_account_at_index(acc, 1);
        if (!acc) {
                fprintf(stderr, "%s\n", "Error loading config");
                return 1;
        }

        char* mdn = extract_mdn(acc);
        printf("extract_mdn: %s => %s\n", acc->user, mdn);
        free(mdn);

        char* emailaddr = extract_email_address(acc->from);
        printf("extract_email_address: %s => %s\n", acc->from, emailaddr);
        free(emailaddr);

        char* m = compose_message(NULL);
        if (!m) {
                return 1;
        }

        newmessage* new_msg = parse_composed_msg(m);
        free(m);
        if (!is_valid_message(new_msg)) {
                fprintf(stderr, "%s\n", "Empty new message");
                return 0;
        }
        dump_newmessage(new_msg);
        t = send_email(acc, new_msg);
        if (t < 0) {
                fprintf(stderr, "%s\n", "Error sending e-mail");
                return 1;
        }
        free(new_msg);

        return 0;
}
#endif
