#include "Account.hpp"

Account::Account(const Conf& cf)
{
    acc_conf = cf;
    mboxes = {};

    if (acc_conf.protocol() == PROTOCOL_IMAP) {
        prtcl_mgr = new IMAP_manager();
    } else {
        cerr << "Error: unsupported protocol." << endl;
        exit(1);
    }
}

// Getters

Conf&
Account::conf()
{
    return acc_conf;
}

Mailbox*
Account::cur_mbox()
{
    return mboxes[cur_mbox_name];
}

/* Network related functions */
int
Account::connect()
{
    prtcl_mgr->connect(acc_conf.in_server(), acc_conf.in_port());
    return 1;
}

int
Account::login()
{
    prtcl_mgr->login(acc_conf.user(), acc_conf.pass());
    return 1;
}

/*
 * List root level mailboxes. We're ignoring other arguments for now
 * FIXME: Add support for finer listing
 */
int
Account::list_mboxes()
{
    prtcl_mgr->list(mboxes, "%", "%");
    return 1;
}

int
Account::select_mbox(const string& nm)
{
    if (nm == cur_mbox_name) {
        return 0;
    }

    cur_mbox_name = nm;
    prtcl_mgr->select_mbox(nm);
    return 1;
}

int
Account::logout()
{
    prtcl_mgr->logout();
    return 1;
}

int
Account::fetch_emails_list(int number, int offset)
{
    prtcl_mgr->fetch_emails_list(
            mboxes[cur_mbox_name]->emails(),
            number, offset);
    return 1;
}

// DEBUG

void
Account::dump() const
{
    acc_conf.dump();
}
