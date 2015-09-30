/*
 * MELKONIAN Marc - 13410425
 * SSL_manager.hpp - OpenSSL related things
 * Date: 04 May 2015
 */

#ifndef SSL_MANAGER_H
#define SSL_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "../utils/error.hpp"
#include "../protocol/imap/IMAP_parser.hpp"

using namespace std;

class SSL_manager
{
    private:
        BIO* bio;
        SSL_CTX* ctx;

        void setup_ssl();
        int wr_sockdata(const string& cmd);
        string rd_sockdata();

    public:
        SSL_manager();
        ~SSL_manager() {};

        void myconnect(const string& machine_port);
        void mydisconnect();
        string fetch_response(const string& cmd);
};

#endif /* end of include guard: SSL_MANAGER_H */

