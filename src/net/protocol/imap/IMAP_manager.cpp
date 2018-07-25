/*
 * MELKONIAN Marc - 13410425
 * IMAP_manager.cpp - communication with IMAP server related things
 * Date: 04 May 2015
 */

#include "IMAP_manager.hpp"

/* Constructor */
IMAP_manager::IMAP_manager()
{
	ssl_mgr = new SSL_manager();
}

/* Destructor */
IMAP_manager::~IMAP_manager()
{
	delete ssl_mgr;
}

/* Connect to server */
int
Protocol_manager::connect(const string& address, const string& port)
{
	return ssl_mgr->mm_connect(address, port);
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
#ifdef DEBUG
	debug("status line: " + token);
#endif

            string mystr;
            int k;
            ss >> mystr >> k;
#ifdef DEBUG
            ostringstream oss;
            oss << k;
            debug("check resp, code: " + mystr + ", " + oss.str());
#endif
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
	debug("Prepared command: " + pr_cmd );
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

/*
 * LIST command
 * Doc: https://tools.ietf.org/html/rfc3501#section-6.3.8
 */
string
Protocol_manager::list(
        map<string, Mailbox*>& mboxes,
        const string& reference, const string& name)
{
	string cmd = "LIST \"" + reference + "\" \"" + name + "\"";
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    IMAP_parser::parse_list(mboxes, resp);
	return resp;
}

// Select a mailbox
string
Protocol_manager::select_mbox(Mailbox* mb, const string& nm)
{
	string cmd = "SELECT " + nm;
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    IMAP_parser::parse_select(mb, resp);
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
Protocol_manager::server_fetch_emails_list(const int start, const int end)
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
void
Protocol_manager::fetch_emails_list(
        vector<Email*>& emails, const int start, const int end)
{
    cout << start << endl;
    cout << end << endl;
    string resp = server_fetch_emails_list(start, end);
    IMAP_parser::parse_emails_infos(emails, resp);
}

string
Protocol_manager::rename_mbox(const string& old_nm, const string& new_nm)
{
	string cmd = "SELECT \"" + old_nm + "\" \"" + new_nm + "\"";
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}

/*
 * Flatten a Body* object into a map <section, Bodypart*>.
 */
void
flatten_body(Body* body, Email* em)
{
    if (body->type == Body_type_mpart) {
        for (Body* b : body->subparts) {
            flatten_body(b, em);
        }
    } else {
        em->add_part(body->section, body->bodypart);
    }
}

/*
 * Get an email parts
 * Right now, parts are flatten with their section into the Email* parts map
 * for convenience use, specially iteration, in the GUI part.
 * NOTE: An alternative would be to populate the Body* object of the Email*
 * object and keep the structure of the bodystructure (see commented lines).
 */
void
Protocol_manager::fetch_email_parts(Email* em)
{
    string resp = server_fetch_bodystructure(em->uid());

    // Extract BODYSTRUCTURE string inside the server response
    string needle = "BODYSTRUCTURE ";
    size_t pos = resp.find(needle);

    stringstream ss;

    if (pos != string::npos) {
        string bs = resp.substr(pos + needle.length());
        ss.str(bs);
    }

    Body* body = IMAP_parser::parse_bodystructure(ss);
    IMAP_parser::add_sections(body);
#ifdef DEBUG
    body->dump();
#endif

    // Flatten body into Email* object subparts
    flatten_body(body, em);
}

// Fetch an email BODYSTRUCTURE
string
Protocol_manager::server_fetch_bodystructure(unsigned int uid)
{
	string cmd = "UID FETCH " + to_string(uid) + " BODYSTRUCTURE";
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}

// Fetch an email BODY[section]
string
Protocol_manager::server_fetch_email_part(
        const unsigned int uid,
        const string section)
{
    string cmd = "UID FETCH " + to_string(uid) + " BODY[" + section + "]";
	string pr_cmd = prepare_cmd(cmd);
	string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}

string
Protocol_manager::fetch_email_part(
        Email* const em,
        const string section)
{
    string resp = server_fetch_email_part(em->uid(), section);
    return resp;
}

