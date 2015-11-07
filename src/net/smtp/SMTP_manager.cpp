#include "SMTP_manager.hpp"

/* static constants */
const string SMTP_manager::Mime_version = "1.0";
const string SMTP_manager::User_agent   = "MuaMi/0.1.1";

// Constructor
SMTP_manager::SMTP_manager(Account* acc)
{
    account = acc;
}

/* Write a command to a socket and read the server response */
string
SMTP_manager::rw_socket(int sockfd, const string cmd)
{
    debug("command: " + cmd);
    int t = write(sockfd, cmd.c_str(), cmd.length());
    if (t < 0) {
        perror("ERROR writing to socket");
        return NULL;
    }

    char buffer[256];
    memset(buffer, 0, sizeof buffer);
    t = read(sockfd, buffer, sizeof(buffer)-1);
    if (t < 0) {
        perror("ERROR reading from socket");
        return NULL;
    }

    debug(buffer);
    return buffer;
}

/* Write a command to a SSL socket layer and read the server response */
string
SMTP_manager::rw_ssl(SSL* ssl, string cmd)
{
    debug("command: " + cmd);
    int t = SSL_write(ssl, cmd.c_str(), cmd.length());
    if (t < 0) {
        perror("ERROR writing to socket");
        return NULL;
    }

    char buffer[512];
    memset(buffer, 0, sizeof buffer);
    t = SSL_read(ssl, buffer, sizeof(buffer)-1);
    if (t < 0) {
        perror("ERROR reading from socket");
        return NULL;
    }

    debug("SMTP response: " + (string)buffer);
    return buffer;
}

/* Get SMTP HELO command with user name */
string
SMTP_manager::get_helo_cmd()
{
    return "HELO " + account->conf().user() + "\r\n";
}

/*
 * Connect to a SMTP server with a non secure socket
 * Returns 0 on success, -1 on failure
 */
int
SMTP_manager::smtp_connect(int* fd)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    string server_name = account->conf().smtp_server();
    struct hostent* server = gethostbyname(server_name.c_str());
    if (!server) {
        perror("gethostbyname");
        return -1;
    }

    struct sockaddr_in serv_addr;
    memset((char*)&serv_addr, 0, sizeof serv_addr);
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr,
          (char*)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(atoi(account->conf().smtp_port().c_str()));

    int t = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (t < 0) {
        perror("connect");
        return -1;
    }

    char buffer[512];
    memset(buffer, 0, sizeof(buffer));
    /* read server greeting on connection */
    t = read(sockfd, buffer, sizeof(buffer) - 1);
    if (t < 0) {
        perror("ERROR reading from socket");
        return -1;
    }

    debug(buffer);

    *fd = sockfd;
    return 0;
}

/*
 * Execute SMTP HELO and STARTTLS commands on a non secure socket
 * Returns 0 on success, -1 on failure
 */
int
SMTP_manager::smtp_starttls(int sockfd)
{
    string resp; /* server response */
    unsigned short rc;
    int retval = 0;

    string helo = get_helo_cmd();
    if (helo.empty()) {
        return -1;
    }

    vector<string> cmds = { helo, "STARTTLS\r\n" };

    for (auto cmd : cmds) {
        resp = rw_socket(sockfd, cmd);
        rc = SMTP_parser::parse_resp_status(resp);
        if (!(rc & SMTP_CODE_SUCCESS)) {
            cerr << "Error executing SMTP command: " + cmd << endl;
            cout << resp << endl;
            retval = -1;
        }
    }

    return retval;
}

/*
 * Generate a Message-ID header field
 * Process:
 *   1. Get the current time in ns (a)
 *   2. Generate a 64 bits random number (b)
 *   3. Encode these numbers (a and b) to their base36 representations A and B
 *   4. Concatenate A and B
 *   5. Encode the result to a MD5 hash string
 *   6. Return the following ID: <md5_hash@mail_domain_name>
 *   ie: <e957cbf3ea0579354498ac1898fb8137@foad.iedparis8.net>
 */
string
SMTP_manager::gen_msg_id()
{
    struct timespec tp;
    tp.tv_sec = 0;
    tp.tv_nsec = 0;

    string pre_md5, md5, mdn;

    /* get current time */
    int t = clock_gettime(CLOCK_REALTIME, &tp);
    if (t < 0) { /* clock_gettime failure */
        return nullptr;
    }

    /* generate a 64 bits random number */
    unsigned long rand_num = random();
    debug("clock, rand: "
            + to_string(tp.tv_nsec) + ", " + to_string(rand_num));

    /* convert these numbers to their base36 representation */
    string b36_time = base36::encode(tp.tv_nsec);
    string b36_rand = base36::encode(rand_num);
    debug("b36_time, b36_rand: " + b36_time + ", " + b36_rand);

    pre_md5 = b36_time + b36_rand;
    debug("pre_md5: " + pre_md5);

    md5 = md5_encode(pre_md5);
    debug("md5: " + md5);

    mdn = account->conf().in_server();
    debug("mdn: " + mdn);

    string msgid = "<" + md5 + "@" + mdn + ">";
    debug("msgid: " + msgid);

    return msgid;
}

/*
 * Build the body of an e-mail message (header + content)
 * Doc: https://tools.ietf.org/html/rfc2822#page-18 (header fields)
 */
string
SMTP_manager::build_email_body(Out_email em)
{
    string date = Date::smtp_current_date();
    string msgid = gen_msg_id();
    string from = account->conf().usermail();
    string sender = account->conf().email();

    string to = em.to().usermail();
    string subject = em.subject();
    string content = em.content();

    string body =
        "To: " + to + "\r\n"
        + "From: " + from + "\r\n"
        + "Date: " + date + "\r\n"
        + "Message-ID: " + msgid + "\r\n"
        + "Sender: " + sender + "\r\n";

    Addresses& cc = em.cc();
    unsigned int ccsz = cc.size();
    if (ccsz > 0) {
        body += "Cc: ";
        for (unsigned int i = 0; i < ccsz; i++) {
            body += cc.at(i)->usermail();
            if (i < ccsz - 1) {
                body += ", ";
            }
        }
        body += "\r\n";
    }

    body +=
        "MIME-Version: " + Mime_version + "\r\n"
        + "User-Agent: " + User_agent + "\r\n"
        + "Content-Type: text/plain; charset=UTF-8\r\n"
        + "Subject: " + subject + "\r\n"
        + "\r\n"
        + content
        + "\r\n.\r\n";

    debug("BODY: \n" + body);
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
SMTP_manager::send_email(Out_email em)
{
    unsigned short rc;
    int t, sockfd;
    t = smtp_connect(&sockfd);
    if (t < 0) { /* smtp_connect failure */
        cerr << "Error smtp_connect." << endl;
        return -1;
    }

    t = smtp_starttls(sockfd);
    if (t < 0) { /* HELO and/or STARTTLS failure */
        cerr << "Error smtp_starttls." << endl;
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

    string helo = get_helo_cmd();
    string body = build_email_body(em);
    string data = "DATA\r\n";
    string quit = "QUIT\r\n";
    string login = "AUTH LOGIN\r\n";
    string user = base64::encode(account->conf().user()) + "\r\n";
    string pass = base64::encode(account->conf().pass()) + "\r\n";
    debug("\nb64_user: " + user + "b64_pass: " + pass);

    string mail_from = "MAIL FROM:<" + account->conf().email() + ">\r\n";

    string rcpt_to = "RCPT TO:<" + em.to().email() + ">\r\n";

    vector<string> cmds = { helo, login, user, pass, mail_from, rcpt_to, };

    Addresses& cc = em.cc();
    if (cc.size() > 0) {
        for (unsigned int i = 0; i < cc.size(); i++) {
            cmds.push_back("RCPT TO:<" + cc.at(i)->email() + ">\r\n");
        }
    }

    Addresses& bcc = em.bcc();
    if (bcc.size() > 0) {
        for (unsigned int i = 0; i < bcc.size(); i++) {
            cmds.push_back("RCPT TO:<" + em.bcc().at(i)->email() + ">\r\n");
        }
    }

    cmds.push_back(data);
    cmds.push_back(body);
    cmds.push_back(quit);

    string resp;
    int retval = 0;
    for (auto cmd : cmds) {
        resp = rw_ssl(myssl, cmd);
        rc = SMTP_parser::parse_resp_status(resp);
        if (!(rc & SMTP_CODE_SUCCESS)) {
            cerr << "Error executing SMTP command: " + cmd << endl;
            cerr << resp << endl;
            retval = -1;
            break;
        }
    }

    return retval;
}

#ifdef SMTP_MANAGER_DEBUG

#include "../config/Config_manager.hpp"

int
main()
{
    // Get an user account
    Config_manager* cm = new Config_manager();
    Account* acc = cm->get_account_at_index(1); // first account

    // Create a SMTP manager
    SMTP_manager smtp_mgr(acc);

    // Create an e-mail to send
    Out_email em {};
    Address to("Me", "", "13410425", "foad.iedparis8.net");
    em.set_to(to);
    em.set_subject("Test blah blah");
    em.set_content("Ceci est un texte de test.");

    Address cc1("This man", "", "mm", "asm35.info");
    Address cc2("This man", "", "mm", "asm35.info");
    em.add_cc(&cc1);
    em.add_bcc(&cc2);

    // Send the e-mail
    smtp_mgr.send_email(em);

    return 0;
}

#endif
