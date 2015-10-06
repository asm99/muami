#include "config/Config_manager.hpp"
#include "debug/debug.hpp"

using namespace std;

int main()
{
    try {
		Config_manager* cm = new Config_manager();
        Account* acc = cm->get_account_at_index(0); // first account

        acc->connect();
        acc->login();
        acc->list_mboxes();
#ifdef DEBUG
        acc->dump();
#endif
        acc->select_mbox("INBOX");
        acc->fetch_emails_list(10, 1);

        debug("nb of emails: " + acc->cur_mbox()->emails().size());

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
