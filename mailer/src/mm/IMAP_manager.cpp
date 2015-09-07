/*
 * MELKONIAN Marc - 13410425
 * IMAP_manager.cpp - communication with IMAP server related things
 * Date: 04 May 2015
 */

#include "IMAP_manager.hpp"

IMAP_manager::IMAP_manager(const std::string machine_port)
{
	this->ssl_mgr = new SSL_manager();
	this->ssl_mgr->myconnect(machine_port);
	this->ssl_mgr->authenticate();
}

IMAP_manager::~IMAP_manager()
{
	delete this->ssl_mgr;
}

/*
 * Create TAG for IMAP command
 * we use the following scheme for TAG: ABCDX* with X in [0-9]
 */
std::string
get_next_tag()
{
	static int counter {0};

	std::stringstream ss;
	ss << "ABCD" << counter++;

	return ss.str();
}

int
Protocol_manager::check_response_status(std::string s)
{
    std::string token;
    std::stringstream ss;
    ss << s;

    while (getline(ss, token, ' ')) {
        if (token.compare(0, 4, "ABCD") == 0) {
            std::cout << "status line: " << token << std::endl;

            std::string mystr;
            int k;
            ss >> mystr >> k;
            std::cout << mystr << "\n" << k << std::endl;
        }
    }
    return 1;
}

/*
 * Add tag and CRLF around a command string to be sent to an IMAP server
 */
std::string
prepare_cmd(const std::string cmd)
{
	std::string tag = get_next_tag();
	std::string pr_cmd = tag + " " + cmd + "\r\n";
#ifdef DEBUG
    std::cout << "--- DEBUG: Prepared command: " << pr_cmd << std::endl;
#endif
	return pr_cmd;
}

// IMAP command to log an user in
int
Protocol_manager::login(const std::string user, const std::string pass)
{
	std::string cmd = "LOGIN " + user + " " + pass;
	std::string pr_cmd = prepare_cmd(cmd);
	std::string resp = this->ssl_mgr->fetch_response(pr_cmd);
	return 1;
// 	return resp;
}

// Select a mailbox
int
Protocol_manager::select_mbox(std::string nm)
{
	std::string cmd = "SELECT " + nm;
	std::string pr_cmd = prepare_cmd(cmd);
	std::string resp = this->ssl_mgr->fetch_response(pr_cmd);
	return 1;
}

// IMAP command to logout an user
int
Protocol_manager::logout()
{
	std::string cmd = "LOGOUT";
	std::string pr_cmd = prepare_cmd(cmd);
	std::cout << pr_cmd << std::endl;
	std::string resp = ssl_mgr->fetch_response(pr_cmd);
	return 1;
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
std::string
Protocol_manager::server_fetch_emails_list(int start, int end)
{
    std::stringstream ss;
    ss  << "FETCH "
        << start << ":" << end
        << " (UID FLAGS INTERNALDATE "
        << "BODY.PEEK[HEADER.FIELDS (SUBJECT DATE FROM)])";

    std::string cmd = ss.str();
	std::string pr_cmd = prepare_cmd(cmd);
	std::string resp = ssl_mgr->fetch_response(pr_cmd);
    return resp;
}

std::vector<Email*>
Protocol_manager::fetch_emails_list(int start, int end)
{
    std::string resp = this->server_fetch_emails_list(start, end);
    IMAP_parser* prsr = new IMAP_parser();
    return prsr->parse_emails(resp);
}

int
Protocol_manager::rename_mbox(std::string old_nm, std::string new_nm)
{
	std::string cmd = "SELECT \"" + old_nm + "\" \"" + new_nm + "\"";
	std::string pr_cmd = prepare_cmd(cmd);
	std::string resp = this->ssl_mgr->fetch_response(pr_cmd);
	return 1;
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
// #include "config.h"
#include "IMAP_parser.hpp"

// Connect to server and test various IMAP commands and parsing functions
int
main()
{
    std::string list_resp = "* 1 FETCH (UID 15 FLAGS (\\Seen) INTERNALDATE \"22-Apr-2015 15:05:42 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {187}\r\n\
Date: Wed, 22 Apr 2015 15:05:41 +0200 (CEST)\r\n\
From: =?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?= <mail-auto@em2.fitnessboutique.fr>\r\n\
Subject: Confirmation de commande  BFN721693\r\n\
\r\n\
)\r\n\
* 2 FETCH (UID 16 FLAGS (\\Seen) INTERNALDATE \"22-Apr-2015 16:00:27 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {220}\r\n\
Date: Wed, 22 Apr 2015 16:00:26 +0200 (CEST)\r\n\
From: =?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?= <mail-auto@em2.fitnessboutique.fr>\r\n\
Subject: =?UTF-8?Q?Votre_compte_FitnessBoutique.fr__-_Mail_=C3=A0_conserver?=\r\n\
\r\n\
)\r\n\
* 3 FETCH (UID 17 FLAGS (\\Seen) INTERNALDATE \"22-Apr-2015 21:03:03 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {222}\r\n\
Date: Wed, 22 Apr 2015 21:03:02 +0200 (CEST)\r\n\
From: =?UTF-8?Q?Service_client=C3=A8le_Fitnessboutique?= <mail-auto@em2.fitnessboutique.fr>\r\n\
Subject: =?UTF-8?Q?FitnessBoutique_-_BFN721693_-_Commande_en_pr=C3=A9paration?=\r\n\
\r\n\
)\r\n\
* 4 FETCH (UID 21 FLAGS (\\Seen \\Answered) INTERNALDATE \"24-Apr-2015 16:37:05 +0200\" BODY[HEADER.FIELDS (SUBJECT DATE FROM)] {126}\r\n\
Date: Fri, 24 Apr 2015 16:37:03 +0200\r\n\
Subject: Confirmation de votre inscription\r\n\
From: UBALDI<service-client@ubaldi.com>\r\n\
\r\n\
)\r\n\
A OK Fetch completed.";

    Protocol_manager* imap_mgr = new IMAP_manager();
    imap_mgr->check_response_status(list_resp);

//         account* acc = load_config();
//         if (!acc) {
//                 fprintf(stderr, "%s\n", "Error loading config");
//                 return 1;
//         }
//
//         setup_ssl();
//
//         char* todial = malloc(strlen(acc->imap) + strlen(acc->iport) + 2);
//         if (!todial) {
//                 fprintf(stderr, "%s\n", "Cannot malloc todial.");
//                 return 1;
//         }
//         sprintf(todial, "%s:%s", acc->imap, acc->iport);
//         printf("todial: %s\n", todial);
//         BIO* bio = myconnect(todial);
//         free(todial);
//
//         char* auth_resp = authenticate(bio);
//         printf("Auth resp:\n%s\n", auth_resp);
//         if (check_server_imap_capability(auth_resp)) {
//                 printf("%s\n", "Server supports IMAP4rev1.");
//         } else {
//                 printf("%s\n", "Error : server does not supports IMAP4rev1.");
//                 return 1;
//         }
//         free(auth_resp);
//
//         char* login_resp = login(bio, acc->user, acc->pass);
//         printf("%s\n", login_resp);
//         free(login_resp);
//
//         char* list_resp = list(bio);
//         printf("List code, resp: %d, \n%s\n",
//                  imap_parse_resp_status(list_resp), list_resp);
//         mailbox* mb = imap_parse_mboxes_names(list_resp);
//         while(mb) {
//                 printf("%s\n", mb->name);
//                 mb = mb->next;
//         }
//         free(list_resp);
//
//         char* status_resp = status_mbox(bio, "INBOX");
//         printf("status resp:\n%s\n", status_resp);
//         free(status_resp);
//
//         char* select_mbox_resp = select_mbox(bio, "INBOX");
//         printf("Select INBOX resp:\n%s\n", select_mbox_resp);
//         unsigned char mbox_perm_flags =
//                 imap_parse_mbox_perm_flags(select_mbox_resp);
//         printf("INBOX permanent flags: %d\n", mbox_perm_flags);
//
//         int total, recent;
//         imap_parse_nb_msgs(select_mbox_resp, &total, &recent);
//         printf("Nb msgs total, recent: %d, %d\n", total, recent);
//         free(select_mbox_resp);
//
//         char* fetch_emails_resp = fetch_emails_list(bio, 1, 2);
//         printf("Fetch emails list resp:\n%s\n", fetch_emails_resp);
//         free(fetch_emails_resp);
//
//         int uid = 48;
//
//         char *ei_resp = fetch_email_infos(bio, uid);
//         printf("email infos resp:\n%s\n", ei_resp);
//         email* em = imap_parse_email(ei_resp);
//         free(ei_resp);
//         dump_tree(em->bodypart);
//         dump_header(em->header);
//
//         char* section = calloc(128, 1);
//         find_email_first_section(em->bodypart, "text", "plain", section);
//         printf("email plain txt:\n%s\n", section);
//
//         char* text = fetch_email_part(bio, uid, section, false);
//         free(section);
//         printf("email part %s:\n%s\n", "1", text);
//         char* cleaned = clean_response(text);
//         free(text);
//         printf("cleaned response:\n%s\n", cleaned);
//         free(cleaned);
//
//         char* noop_resp = noop(bio);
//         printf("noop resp: %d\n%s\n",
//                imap_parse_resp_status(noop_resp), noop_resp);
//         free(noop_resp);
//
//         char* logout_resp = logout(bio);
//         printf("logout resp: %d\n%s\n",
//               imap_parse_resp_status(logout_resp), logout_resp);
//         free(logout_resp);
//
//         return 0;
}
#endif
