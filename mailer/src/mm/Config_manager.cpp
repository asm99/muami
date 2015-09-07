#include "Config_manager.hpp"

// Global configuration filename
const std::string Config_manager::Config_Filename = "muamirc";

std::string
Config_manager::get_config_file_path()
{
    struct passwd *pw = getpwuid(getuid());
    const std::string homedir = pw->pw_dir;
    return homedir + "/" + Config_Filename;
}

std::string
Config_manager::read_config_file()
{
    std::string config_path = get_config_file_path();

    std::ifstream ifs(config_path);
    if (!ifs.is_open())
        error("config file not found", 1);

    std::stringstream ss;
    ss << ifs.rdbuf();

    return ss.str();
}

Account*
Config_manager::get_account_from_string(std::string s)
{
    std::stringstream iss(s);
    std::string line;
    std::string field, colon, val;
    Account* acc = new Account();
    while (std::getline(iss, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        ss >> field >> colon >> val;

        if      (field == "id")    { acc->id = val; }
        else if (field == "imap")  { acc->imap = val; }
        else if (field == "iport") { acc->iport = val; }
        else if (field == "smtp")  { acc->smtp = val; }
        else if (field == "sport") { acc->sport = val; }
        else if (field == "from")  { acc->from = val; }
        else if (field == "user")  { acc->user = val; }
        else if (field == "pass")  { acc->pass = val; }
        else if (field == "sport") { acc->sport = val; }
    }
    return acc;
}

std::vector<Account*>
Config_manager::get_accounts()
{
    std::string content = read_config_file();
    const std::string delim = "[";
    std::string token;
    std::size_t pos;

    std::vector<Account*> accs {};

    while ((pos = content.find(delim)) != std::string::npos) {
        token = content.substr(0, pos);
        if (!token.length() == 0) {
            accs.push_back(get_account_from_string(token));
        }
        content.erase(0, pos + delim.length());
    }
    accs.push_back(get_account_from_string(content));
    return accs;
}


#ifdef CONFIG_MANAGER_DEBUG
void
dump_accounts(std::vector<Account*> accounts)
{
    for (unsigned int i = 0; i < accounts.size(); ++i) {
        Account* acc = accounts[i];
        if (!acc) continue;

        std::cout << "--- Account info ---" << std::endl;
        std::cout << acc->id    << std::endl;
        std::cout << acc->imap  << std::endl;
        std::cout << acc->iport << std::endl;
        std::cout << acc->smtp  << std::endl;
        std::cout << acc->sport << std::endl;
        std::cout << acc->from  << std::endl;
        std::cout << acc->user  << std::endl;
        std::cout << acc->pass  << std::endl;
    }
}

int main()
{
    Config_manager* cm {};
    std::vector<Account*> accounts = cm->get_accounts();
    dump_accounts(accounts);
    return 0;
}
#endif
