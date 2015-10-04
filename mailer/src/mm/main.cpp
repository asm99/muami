#include "config/Config_manager.hpp"
#include "protocol/Protocol_manager.hpp"
#include "protocol/imap/IMAP_manager.hpp"

using namespace std;

int main()
{
    try {
		Config_manager* cm = new Config_manager();
        Account* acc = cm->get_account_at_index(0); // first account

        Protocol_manager* p_mgr =
            new IMAP_manager(acc->imap() + ":" + acc->iport());
        p_mgr->login(acc->user(), acc->pass());
        p_mgr->select_mbox("INBOX");

        vector<Email*> emails {};
        p_mgr->fetch_emails_list(emails, 10, 1);

        cout << "nb of emails: " << emails.size() << endl;

		for (auto em : emails) {
			em->dump();
		}

        p_mgr->logout();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
