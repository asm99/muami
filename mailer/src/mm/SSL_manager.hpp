/*
 * MELKONIAN Marc - 13410425
 * SSL_manager.hpp - OpenSSL related things
 * Date: 04 May 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
// #include "debug.hpp"
#include "err.h"
#include "error.hpp"
#include "IMAP_parser.hpp"

class SSL_manager {
    private:
        BIO* bio;
        SSL_CTX* ctx;

        void setup_ssl();

    public:
        SSL_manager();
        ~SSL_manager() {};

        void myconnect(const std::string machine_port);
        void mydisconnect();
        std::string fetch_response(std::string cmd);
        std::string authenticate();
};
