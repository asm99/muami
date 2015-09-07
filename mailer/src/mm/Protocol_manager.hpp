#ifndef PROTOCOL_MANAGER_H
#define PROTOCOL_MANAGER_H

#include <vector>
#include "Email.hpp"
#include "SSL_manager.hpp"

class Protocol_manager {
    protected:
        SSL_manager* ssl_mgr;

        virtual std::string server_fetch_emails_list(int start, int end);
        virtual int check_response_status(std::string s);

    public:
        virtual ~Protocol_manager() {};

        // General
        virtual int login(const std::string user, const std::string pass);
        virtual int logout();
//         virtual int noop();

        // Mailboxes
        virtual int select_mbox(std::string nm);
//         virtual int create_mbox(std::string nm);
        virtual int rename_mbox(std::string old_nm, std::string new_nm);
//         virtual int close_mbox();

        // Emails
        virtual std::vector<Email*> fetch_emails_list(int start, int end);
//         virtual std::string fetch_email_infos(int uid);
//         virtual std::string fetch_email_part(int uid, std::string section);
};

#endif /* end of include guard: PROTOCOL_MANAGER_H */
