#include "config/Config_manager.hpp"
#include "debug/debug.hpp"

using namespace std;

int main()
{
    try {
        // Create a Config_manager
		Config_manager* cm = new Config_manager();
        // Switch to an account
        Account* acc = cm->get_account_at_index(1); // first account

        acc->connect();         // connect to server
        acc->login();           // login user
        acc->list_mboxes();     // get user mailboxes

        // Dump account infos
//         acc->dump();

        acc->select_mbox("INBOX");      // switch to main inbox
        acc->fetch_emails_list(1, 30);  // get 10 last e-mails
                                        // get the message/rfc822, n°168

        // Dump one e-mail
//         acc->cur_mbox()->emails()[0]->dump();

        debug("nb of emails: " + to_string(acc->cur_mbox()->emails().size()));

        // Dump all e-mails
// 		for (auto em : acc->cur_mbox()->emails()) {
// 			em->dump();
// 		}

        // Fetch one e-mail bodystructure
        int idx = 0;

        for (unsigned int i = 0; i < acc->cur_mbox()->emails().size(); i++) {
            acc->fetch_email_parts(i);
            acc->cur_mbox()->emails()[i]->dump_parts();
        }

//         // Populate E-mail* parts map
//         acc->fetch_email_parts(idx);
//
//         // Dump an e-mail parts
//         acc->cur_mbox()->emails()[idx]->dump_parts();

        // Get an e-mail part
//         string s = acc->fetch_email_text(idx);
//         cout << "Email part: " + qp::decode(s) << endl;

        // Logout user from the server
        acc->logout();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
