#include "config/Config_manager.hpp"

using namespace std;

int main()
{
    try {
		Config_manager* cm = new Config_manager();
        Account* acc = cm->get_account_at_index(0); // first account

        acc->connect();
        acc->login();
        acc->list_mboxes();
        acc->select_mbox("INBOX");
        acc->fetch_emails_list(10, 1);

        cout << "nb of emails: " << acc->cur_mbox()->emails().size() << endl;

		for (auto em : acc->cur_mbox()->emails()) {
			em->dump();
		}

        acc->logout();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
