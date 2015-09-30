#ifndef PROTOCOL_MANAGER_H
#define PROTOCOL_MANAGER_H

#include "../email/Email.hpp"
#include "../ssl/SSL_manager.hpp"

using namespace std;

class Protocol_manager
{
    protected:
        SSL_manager* ssl_mgr;

        virtual string server_fetch_emails_list(int start, int end);

    public:
        virtual ~Protocol_manager() {};

        // General
        virtual int check_response_status(const string& s);
        virtual string login(const string& user, const string& pass);
        virtual string logout();
//         virtual int noop();

        // Mailboxes
        virtual string select_mbox(const string& nm);
//         virtual int create_mbox(string nm);
        virtual string rename_mbox(const string& old_nm, const string& new_nm);
//         virtual int close_mbox();

        // Emails
        virtual vector<Email*> fetch_emails_list(int start, int end);
//         virtual string fetch_email_infos(int uid);
//         virtual string fetch_email_part(int uid, string section);
};

#endif /* end of include guard: PROTOCOL_MANAGER_H */
