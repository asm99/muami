/*
 * MELKONIAN Marc - 13410425
 * SSL_manager.cpp - OpenSSL related things
 * Date: 08 Aug 2015
 */

#include "SSL_manager.hpp"

SSL_manager::SSL_manager()
{
    setup_ssl();
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

/* Write data on a SSL socket */
int
SSL_manager::wr_sockdata(const string& cmd)
{
    int t;
    int fd;
    int ready;
    BIO_get_fd(bio, &fd);
    fd_set wr_fds;        /* writable fds set */
    struct timeval tv;    /* struct for timeout */

    FD_ZERO(&wr_fds);
    FD_SET(fd, &wr_fds);  /* add socket to write fds set */
    tv.tv_sec  = 1;
    tv.tv_usec = 500000;

    ready = select(fd+1, NULL, &wr_fds, NULL, &tv);
    if (ready == -1) {
        perror("WR select");
        return -1;
    }
    else if (ready == 0) { /* timeout reached */
        cerr << "select WR timeout" << endl;
        return -1;
    }

    if (!FD_ISSET(fd, &wr_fds)) {
        cerr << "NOT WR FD_ISSET" << endl;
    }

    t = BIO_write(bio, cmd.c_str(), cmd.length());
    if (t == -1) {
        perror("BIO_write");
    }

    return t;
}

/* Read data from a SSL socket */
string
SSL_manager::rd_sockdata()
{
    int t;
    int fd;
    int ready;
    int chunk_sz = 1024;
    char chunk[chunk_sz];
    int bytes_read = 0;
    char* buf = (char*)malloc(chunk_sz);
    if (!buf) {
        cerr << "Cannot malloc buf." << endl;
        return "";
    }

    BIO_get_fd(bio, &fd);
    fd_set rd_fds;        /* writable fds set */
    struct timeval tv;    /* struct for timeout */

    FD_ZERO(&rd_fds);
    FD_SET(fd, &rd_fds);  /* add socket to read fds set */
    tv.tv_sec  = 1;
    tv.tv_usec = 200000;

    char* newbuf;

    while (1) {
        ready = select(fd+1, &rd_fds, NULL, NULL, &tv);
        if (ready == -1) {
            perror("select");
        }
        else if (ready == 0) { /* timeout reached */
            break;
        }

        if (!FD_ISSET(fd, &rd_fds)) {
            fprintf(stderr, "%s\n", "NOT FD_ISSET");
            continue;
        }

        t = BIO_read(bio, chunk, chunk_sz);
        if (t < 0) {
            cerr << "Error reading socket." << endl;
            return "";
        }
        else if (t == 0) {
            t = BIO_set_close(bio, BIO_CLOSE);
            if (t != 1) {
                cerr << "error: BIO_set_close should always return 1."
                     << "Returned " << t << endl;
            }
#ifdef DEBUG
            cout << "Reached the end of the data stream." << endl;
#endif
            break;
        }

        memcpy(buf + bytes_read, chunk, t);
        bytes_read += t;

        newbuf = (char*)realloc(buf, bytes_read + chunk_sz*2+1);
        if (!newbuf) {
            cerr <<  "error: cannot realloc BIO_read buffer size" << endl;
            return "";
        }
        buf = newbuf;
    }
    buf[bytes_read] = '\0';

#ifdef DEBUG
    cout << "rd_sockdata: " << buf << endl;
#endif

    return buf;
}

/* Establish a secure connection to an IMAP server with OpenSSL */
void
SSL_manager::myconnect(const string& machine_port)
{
    SSL* ssl;
    int t;

    ctx = SSL_CTX_new(SSLv23_client_method());
    SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);

    // bio = BIO_new_connect("pop.163.com:110"); // unsecured way
    bio = BIO_new_ssl_connect(ctx);
    if (!bio) {   /* handle the failure */
        cerr << ERR_error_string(ERR_get_error(), NULL) << endl;
    }

    BIO_get_ssl(bio, &ssl);

    BIO_set_conn_hostname(bio, machine_port.c_str());
    t = BIO_do_connect(bio);
    if (t <= 0) {
        ERR_print_errors_fp(stderr);
        error("Cannot connect to server", 1);
    }

    t = BIO_do_handshake(bio);
    if (t <= 0) {
        cerr << "Cannot establish SSL connection: failed handshake." << endl;
        ERR_print_errors_fp(stderr);
    }
}

/* Send an IMAP command to the server and return the response */
string
SSL_manager::fetch_response(const string& cmd)
{
    int t = wr_sockdata(cmd);
    int cmdlen = cmd.length();

    if (t != cmdlen) {
        cerr << "error: only " << t << " bytes out of " << cmdlen
             << " have been written on the socket."
             << endl;
    }

    string resp = rd_sockdata();
    return resp;
}

/* Clean things up when connecting */
void
SSL_manager::mydisconnect()
{
    //BIO_set_close(bio, BIO_CLOSE);
    //SSL_CTX_free(ctx);
    //SSL* ssl;
    //BIO_get_ssl(bio, ssl);
    BIO_ssl_shutdown(bio);
    //BIO_reset(bio);         // To reuse the connection, use this line
    BIO_free_all(bio);  // To free it from memory, use this line
}
