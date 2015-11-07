/*
 * MELKONIAN Marc - 13410425
 * SMTP_manager.hpp - Communication with SMTP server and related things
 * Date: 04 May 2015
 */

#include <cstdio>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include "../debug/debug.hpp"
#include "../config/Account.hpp"
#include "../crypto/md5.hpp"
#include "../coding/base36.hpp"
#include "../coding/base64.hpp"
#include "Out_email.hpp"
#include "SMTP_parser.hpp"

using namespace std;

class SMTP_manager
{
    private:
        static const string Mime_version;
        static const string User_agent;

        Account* account;

        string build_email_body(Out_email em);
        string get_helo_cmd();
        int smtp_connect(int* fd);
        int smtp_starttls(int sockfd);
        string rw_socket(int sockfd, const string cmd);
        string rw_ssl(SSL* ssl, string cmd);
        string gen_msg_id();

    public:
        SMTP_manager(Account* acc);
        ~SMTP_manager() {};

        int send_email(Out_email em);
};
