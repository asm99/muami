/*
 * MELKONIAN Marc - 13410425
 * SSL_manager.cpp - OpenSSL related things
 * Date: 08 Aug 2015
 */

#include "SSL_manager.hpp"

SSL_manager::SSL_manager()
{
    this->setup_ssl();
}

/* Load and init OpenSSL */
void
SSL_manager::setup_ssl()
{
    ERR_load_BIO_strings();
    SSL_load_error_strings();
    SSL_library_init(); /* replaces OpenSSL_add_all_algorithms() */
    //OpenSSL_add_all_algorithms();
}

/* Get a (SSL) BIO to communicate with the IMAP server */
void
SSL_manager::myconnect(const std::string machine_port)
{
    SSL* ssl;
    int t;

    ctx = SSL_CTX_new(SSLv23_client_method());

    // bio = BIO_new_connect("pop.163.com:110"); // unsecured way
    this->bio = BIO_new_ssl_connect(ctx);
    if (!this->bio) {   /* handle the failure */
        std::cerr << ERR_error_string(ERR_get_error(), NULL) << std::endl;
    }

    BIO_get_ssl(this->bio, &ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    BIO_set_conn_hostname(this->bio, machine_port.c_str());
    t = BIO_do_handshake(this->bio);
    if (t <= 0) {
        std::cerr << "Cannot establish SSL connection." << std::endl;
        ERR_print_errors_fp(stderr);
    }
}

// Connect to server securely with SSL and perform IMAP pre-authentication
std::string
SSL_manager::authenticate()
{
    int t = BIO_do_connect(this->bio);
    if (t <= 0) {
        ERR_print_errors_fp(stderr);
        error("Cannot connect to server", 1);
    }

    // Get server greeting by reading the socket buffer filled during the
    // connect process with an empty command
    std::string auth_resp = this->fetch_response("");
    return auth_resp;
}

// Get IMAP server response to a command
// returns a buffer that must be free'd manually
// FIXME: treating BIO_read error as fatal, should use BIO_should_retry before
std::string
SSL_manager::fetch_response(std::string cmd)
{
    int t;
    int chunk_sz = 1024;
    char chunk[chunk_sz];
//     int bytes_read = 0;  // DEBUG
    std::ostringstream oss;

    t = BIO_write(this->bio, cmd.c_str(), cmd.length());
    if (t == -1) {
        perror("BIO_write");
        return nullptr;
    }

    int fd;
    int ready;
    BIO_get_fd(this->bio, &fd);
    fd_set rd_fds;        /* writable fds set */
    struct timeval tv;    /* struct for timeout */

    FD_ZERO(&rd_fds);
    FD_SET(fd, &rd_fds);  /* add socket to write fds set */
    tv.tv_sec  = 0;
    tv.tv_usec = 200000;

    while (1) {
        ready = select(fd+1, &rd_fds, NULL, NULL, &tv);
        if (ready == -1) {
            perror("select");
        }
        else if (ready == 0) { /* timeout reached */
            break;
        }

        if (!FD_ISSET(fd, &rd_fds)) {
            std::cerr << "NOT FD_ISSET" << std::endl;
            continue;
        }

        t = BIO_read(this->bio, chunk, chunk_sz);
        if (t < 0) {
            perror("BIO_read");
            return nullptr; // !!! treating this case as an error for now !!!
        }
        else if (t == 0) {
            t = BIO_set_close(this->bio, BIO_CLOSE);
            if (t <= 0)
                error("Error closing BIO", 1);
            break;
        }

        oss << chunk;
//         bytes_read += t;  // DEBUG
    }

#ifdef DEBUG
    std::cout << "--- DEBUG: server response: " << oss.str() << std::endl;
#endif
    return oss.str();
}

/* Clean things up when connecting */
void
SSL_manager::mydisconnect()
{
    //BIO_set_close(bio, BIO_CLOSE);
    //SSL_CTX_free(ctx);
    //SSL* ssl;
    //BIO_get_ssl(bio, ssl);
    BIO_ssl_shutdown(this->bio);
    //BIO_reset(bio);         // To reuse the connection, use this line
    BIO_free_all(this->bio);  // To free it from memory, use this line
}

#ifdef SSL_MANAGER_DEBUG
#include "Config_manager.hpp"
// #include "imap.h"
// #include "imap_parser.h"
#include "Date_formatter.hpp"

int
main()
{
    Config_manager* cm = new Config_manager();
    std::vector<Account*> accounts = cm->get_accounts();
    Account* acc = accounts[1];

    SSL_manager* ssl_mgr = new SSL_manager();
    ssl_mgr->myconnect(acc->imap + ":" + acc->iport);

    std::string auth_resp = ssl_mgr->authenticate();

    IMAP_parser* imap_p = new IMAP_parser();
    if (!imap_p->check_server_imap_capability(auth_resp)) {
        error("Error: this server does not support IMAP4rev1", 1);
    }

    char* login_resp = login(bio, acc->user, acc->pass);
    int k = imap_parse_resp_status(login_resp);
    printf("status code: %d\n", k);
    if (k != IMAP_RESPONSE_OK) {
        fprintf(stderr, "Error with login command: %s\n", login_resp);
        return 1;
    }
    //         puts(login_resp);
    //         free(login_resp);
    //
    //         char* sel = select_mbox(bio, "INBOX");
    //         puts(sel);
    //         free(sel);
    //
    //         char* list_resp = list(bio);
    //         puts(list_resp);
    //         free(list_resp);
    //
    //         char* emails_resp = fetch_emails_list(bio, 1, 2);
    //         puts(emails_resp);
    //         free(emails_resp);
    //
    //         char* logout_resp = logout(bio);
    //         puts(logout_resp);
    //         free(logout_resp);
    return 0;
}
#endif
