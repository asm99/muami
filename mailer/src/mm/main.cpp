#include "Config_manager.hpp"
#include "Protocol_manager.hpp"
#include "IMAP_manager.hpp"

int main()
{
    try {
		Config_manager* cm {};
        std::vector<Account*> accounts = cm->get_accounts();
        Account* acc = accounts[0];

        Protocol_manager* p_mgr =
            new IMAP_manager(acc->imap + ":" + acc->iport);
        p_mgr->login(acc->user, acc->pass);
        p_mgr->select_mbox("INBOX");

        std::vector<Email*> emails = p_mgr->fetch_emails_list(1, 3);

        std::cout << "nb of emails: " << emails.size() << std::endl;

		for (auto em : emails) {
			em->dump();
		}

        p_mgr->logout();


    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
