/*
 * MELKONIAN Marc - 13410425
 * IMAP_manager.cpp - communication with IMAP server related things
 * Date: 04 May 2015
 */

#include "IMAP_manager.hpp"

IMAP_manager::IMAP_manager(const string machine_port)
{
	this->ssl_mgr = new SSL_manager();
	this->ssl_mgr->myconnect(machine_port);
}

IMAP_manager::~IMAP_manager()
{
	delete this->ssl_mgr;
}

/*
 * Create TAG for IMAP command
 * we use the following scheme for TAG: ABCDX* with X in [0-9]
 */
string
get_next_tag()
{
	static int counter {0};

	stringstream ss;
	ss << "ABCD" << counter++;

	return ss.str();
}

int
Protocol_manager::check_response_status(const string& s)
{
    string token;
    stringstream ss(s);

    while (getline(ss, token, ' ')) {
        if (token.compare(0, 4, "ABCD") == 0) {
            cout << "status line: " << token << endl;

            string mystr;
            int k;
            ss >> mystr >> k;
            cout << "check resp, code: " << mystr << ", " << k << endl;
        }
    }
    return 1;
}

/*
 * Add tag and CRLF around a command string to be sent to an IMAP server
 */
string
prepare_cmd(const string cmd)
{
	string tag = get_next_tag();
	string pr_cmd = tag + " " + cmd + "\r\n";
#ifdef DEBUG
    cout << "--- DEBUG: Prepared command: " << pr_cmd << endl;
#endif
	return pr_cmd;
}

// IMAP command to log an user in
string
Protocol_manager::login(const string& user, const string& pass)
{
	string cmd = "LOGIN " + user + " " + pass;
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
	return resp;
}

// Select a mailbox
string
Protocol_manager::select_mbox(const string& nm)
{
	string cmd = "SELECT " + nm;
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
	return resp;
}

// IMAP command to logout an user
string
Protocol_manager::logout()
{
	string cmd = "LOGOUT";
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}

// /* All States */
//
// /* IMAP command NOOP */
// char*
// noop(BIO* bio)
// {
//         char* resp = exec_cmd(bio, "NOOP", 0);
//         return resp;
// }
//
// /* IMAP command to logout an user */
// char*
// logout(BIO* bio)
// {
//         char* resp = exec_cmd(bio, "LOGOUT", 0);
//         return resp;
// }
//
// /* Not Authenticated State */
//
// /* IMAP command to log in an user */
// char*
// login(BIO* bio, const char* user, const char* pass)
// {
//         char* resp = exec_cmd(bio, "LOGIN %s %s", 2, user, pass);
//         return resp;
// }
//
// /* IMAP command to list folders */
// char*
// list(BIO* bio)
// {
//         char* resp = exec_cmd(bio, "LIST \"\" *", 0);
//         return resp;
// }
//
// /* Authenticated State */
//
// /* IMAP command to get the status of a folder */
// char*
// status_mbox(BIO* bio, char* nm)
// {
//         char* resp = exec_cmd(bio, "STATUS \"%s\" (MESSAGES UNSEEN)", 1, nm);
//         return resp;
// }
//
// /* IMAP command to create a new folder */
// char*
// create_mbox(BIO* bio, char* nm)
// {
//         char* resp = exec_cmd(bio, "CREATE \"%s\"", 1, nm);
//         return resp;
// }
//
// /* IMAP command to rename a folder */
// char*
// rename_mbox(BIO* bio, char* old_nm, char* new_nm)
// {
//         char* resp = exec_cmd(bio, "RENAME \"%s\" \"%s\"", 2, old_nm, new_nm);
//         return resp;
// }
//
//
// /* Selected State */
// char*
// close_mbox(BIO* bio)
// {
//         char* resp = exec_cmd(bio, "CLOSE", 0);
//         return resp;
// }

/* Fetch selected mailbox n emails infos */
string
Protocol_manager::server_fetch_emails_list(int start, int end)
{
    stringstream ss;
    ss  << "FETCH "
        << start << ":" << end
        << " (UID FLAGS INTERNALDATE RFC822.SIZE ENVELOPE)";

    string cmd = ss.str();
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}

/* Fetch emails list */
vector<Email*>
Protocol_manager::fetch_emails_list(int start, int end)
{
    string resp = server_fetch_emails_list(start, end);
    IMAP_parser* prsr = new IMAP_parser();
    vector<Email*> emails = prsr->parse_emails_infos(resp);
    delete prsr;
    return emails;
}

string
Protocol_manager::rename_mbox(const string& old_nm, const string& new_nm)
{
	string cmd = "SELECT \"" + old_nm + "\" \"" + new_nm + "\"";
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}


// /* Fetch an email IMAP RFC822.HEADER and BODYSTRUCTURE */
// char*
// fetch_email_infos(BIO* bio, int uid)
// {
//         char* uid_s = int_to_str(uid);
//         char* resp = exec_cmd(bio, "UID FETCH %s (RFC822.HEADER BODYSTRUCTURE)",
//                               1, uid_s);
//         free(uid_s);
//         return resp;
// }
//
// /* Fetch an email bodypart */
// char*
// fetch_email_part(BIO* bio, int uid, char* section)
// {
//         int uid_count_digits = count_digits(uid);
//
//         char* uid_s = malloc(uid_count_digits + 1);
//         if (uid_s == NULL) {
//                 return NULL;
//         }
//         sprintf(uid_s, "%d", uid);
//
//         char* resp = exec_cmd(bio, "UID FETCH %s BODY[%s]", 2, uid_s, section);
//         free(uid_s);
//
//         return resp;
// }
//
#ifdef IMAP_MANAGER_DEBUG

#include "../../config/Config_manager.hpp"
#include "IMAP_parser.hpp"

// Connect to server and test various IMAP commands and parsing functions
int
main()
{
    Config_manager* cm = new Config_manager();
    Account* acc = cm->get_account_at_index(0); // first account

    Protocol_manager* p_mgr =
        new IMAP_manager(acc->imap() + ":" + acc->iport());
    string login_resp = p_mgr->login(acc->user(), acc->pass());
    p_mgr->check_response_status(login_resp);

    string selmb_resp = p_mgr->select_mbox("INBOX");
    p_mgr->check_response_status(selmb_resp);

    vector<Email*> emails = p_mgr->fetch_emails_list(10, 15);
    cout << "nb of emails: " << emails.size() << endl;
    for (auto em : emails) {
        em->dump();
    }

    string logout_resp = p_mgr->logout();
    p_mgr->check_response_status(logout_resp);
}
#endif
