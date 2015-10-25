#include "Account.hpp"

// Constructor
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
    prtcl_mgr->select_mbox(cur_mbox(), nm);
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
    int start = mboxes[cur_mbox_name]->exists() - number - offset + 1;
    int end = mboxes[cur_mbox_name]->exists() - offset;
    prtcl_mgr->fetch_emails_list(mboxes[cur_mbox_name]->emails(), start, end);
    return 1;
}

int
Account::fetch_email_parts(int idx)
{
    prtcl_mgr->fetch_email_parts(mboxes[cur_mbox_name]->emails()[idx]);
    return 1;
}

string
Account::fetch_email_part(int idx, string section)
{
    return prtcl_mgr->fetch_email_part(
            mboxes[cur_mbox_name]->emails()[idx],
            section);
}

/*
 * Fetch the text of an e-mail to show at selection.
 * By default, this text is in the first "text/plain" bodypart.
 */
string
Account::fetch_email_text(int idx)
{
    string section = "1"; // Default value

    // First find the first bodypart of type/subtype "text/plain"
    map<string, Bodypart*> bps = cur_mbox()->emails()[idx]->parts();
    map<string, Bodypart*>::const_iterator it;
    for (it = bps.begin(); it != bps.end(); ++it) {
        if (it->second->type() == "text"
            && it->second->subtype() == "plain") {
            section = it->first;
        }
    }

#ifdef DEBUG
    debug("Section of first \"text/plain\" bodypart: " + section);
#endif

    return fetch_email_part(idx, section);
}

// DEBUG
void
Account::dump() const
{
    /* Dump config */
    acc_conf.dump();

    /* Dump mailboxes names */
    map<string, Mailbox*>::const_iterator it;
    for (it = mboxes.begin(); it != mboxes.end(); ++it) {
        debug("mailbox: " + it->first);
    }
}
