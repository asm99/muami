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
        acc->fetch_emails_list(10, 1);  // get 10 last e-mails

//         debug("nb of emails: " + to_string(acc->cur_mbox()->emails().size()));

        // Dump e-mails
// 		for (auto em : acc->cur_mbox()->emails()) {
// 			em->dump();
// 		}

        // Fetch one e-mail bodystructure
        int idx = 3;

        // Populate E-mail* parts map
        acc->fetch_email_parts(idx);

        // Dump an e-mail parts
        acc->cur_mbox()->emails()[idx]->dump_parts();

        // Get an e-mail part
        string s = acc->fetch_email_text(idx);
        cout << "Email part: " + qp::from_qp(s) << endl;

        // Logout user from the server
        acc->logout();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
