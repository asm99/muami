/*
 * MELKONIAN Marc
 * IED 13410425
 * Account.hpp: each account is loaded from a config file in the config
 *              directory of in the user $HOME directory
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <map>
#include "Conf.hpp"
#include "../protocol/Protocol_manager.hpp"
#include "../protocol/imap/IMAP_manager.hpp"
#include "../email/Mailbox.hpp"
#include "../debug/debug.hpp"

using namespace std;

class Account
{
    private:
        Conf acc_conf;
        Protocol_manager* prtcl_mgr;
        map<string, Mailbox*> mboxes;
        string cur_mbox_name;

    public:
        Account(const Conf& cf);
        ~Account() {};

        // Getters
        Conf& conf();
        Mailbox* cur_mbox();

        // DEBUG
        void dump() const;

        // Network related functions
        int connect();
        int login();
        int list_mboxes();
        int select_mbox(const string& nm);
        int logout();
        int fetch_emails_list(int number, int offset);
};

#endif /* end of include guard: ACCOUNT_H */
