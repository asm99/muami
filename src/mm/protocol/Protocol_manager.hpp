#ifndef PROTOCOL_MANAGER_H
#define PROTOCOL_MANAGER_H

#include <map>
#include "../email/Email.hpp"
#include "../email/Mailbox.hpp"
#include "../ssl/SSL_manager.hpp"
#include "protocols.hpp"

using namespace std;

class Protocol_manager
{
    protected:
        SSL_manager* ssl_mgr;

        virtual string server_fetch_emails_list(int start, int end);
        virtual string server_fetch_bodystructure(unsigned int uid);
        virtual string server_fetch_email_part(
                const unsigned int uid,
                const string section);

    public:
        virtual ~Protocol_manager() {};

        // General
        virtual int check_response_status(const string& s);
        virtual int connect(const string& address, const string& port);
        virtual string login(const string& user, const string& pass);
        virtual string logout();
//         virtual int noop();

        // Mailboxes
        virtual string list(map<string, Mailbox*>& mbxes,
                const string& reference, const string& name);
        virtual string select_mbox(Mailbox* mb, const string& nm);
//         virtual int create_mbox(string nm);
        virtual string rename_mbox(const string& old_nm, const string& new_nm);
//         virtual int close_mbox();

        // Emails
        virtual void fetch_emails_list(
                vector<Email*>& emails, const int start, const int end);
        virtual void fetch_email_parts(Email* em);
        virtual string fetch_email_part(
                Email* const em, const string section);
};

#endif /* end of include guard: PROTOCOL_MANAGER_H */
