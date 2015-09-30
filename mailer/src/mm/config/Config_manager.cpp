#include "Config_manager.hpp"

// Global configuration filename
const string Config_manager::Conf_dir_rel_path = ".config/muami/accounts";

// Constructor
Config_manager::Config_manager()
    : accounts()
{
    load_accounts(accounts);
}

/* Get accounts config files absolute path (in user $HOME dir) */
string
Config_manager::get_conf_dir_abs_path()
{
    struct passwd *pw = getpwuid(getuid());
    const string homedir = pw->pw_dir;
    return homedir + "/" + Conf_dir_rel_path;
}

/* List the filenames in the config dir */
vector<string>
Config_manager::list_conf_dir(const string& path)
{
    vector<string> vec {};

    DIR *dp = opendir(path.c_str());
    if (!dp) {
        cerr << "Error opening directory: " << path
             << " (" << errno << ")"
             << endl;
        return vec;
    }

    struct dirent *dirp;

    while ((dirp = readdir(dp))) {
        string fname = dirp->d_name;
        if (fname != "." && fname != "..")
            vec.push_back(fname);
    }
    closedir(dp);

    return vec;
}

/* Read the content of an account config file */
string
Config_manager::read_conf_file(const string& path, const string& filename)
{
    ifstream ifs(path + "/" + filename);
    if (!ifs.is_open())
        error("error opening file: " + path, 1);

    stringstream ss;
    ss << ifs.rdbuf();

    return ss.str();
}

/* Load an account from a config file content */
Account*
Config_manager::get_account_from_string(string s, const string& fname)
{
    stringstream iss(s);
    string line;
    string field, colon, val;
    stringstream ss;

    Account* acc = new Account();
    acc->set_id(fname);

    while (getline(iss, line)) {
        if (line.empty()) continue;
        ss.clear();
        ss << line;
        ss >> field >> colon >> val;

        if      (field == "imap")  { acc->set_imap(val);  }
        else if (field == "iport") { acc->set_iport(val); }
        else if (field == "smtp")  { acc->set_smtp(val);  }
        else if (field == "sport") { acc->set_sport(val); }
        else if (field == "from")  { acc->set_from(val);  }
        else if (field == "user")  { acc->set_user(val);  }
        else if (field == "pass")  { acc->set_pass(val);  }
        else if (field == "sport") { acc->set_sport(val); }
    }
    return acc;
}

/* Get all the accounts from the config dir */
void
Config_manager::load_accounts(vector<Account*>& accs)
{
    string path = get_conf_dir_abs_path();
    vector<string> files = list_conf_dir(path);

    for (auto fname : files) {
        string content = read_conf_file(path, fname);
        Account* acc = get_account_from_string(content, fname);
        accs.push_back(acc);
    }
}

/* Return the number of accounts */
unsigned int
Config_manager::get_accounts_count()
{
    return accounts.size();
}

/* Access to an account based on its index */
Account*
Config_manager::get_account_at_index(unsigned int idx)
{
    if (idx >= accounts.size()) {
        cerr << "error: index >= accounts count." << endl;
        return nullptr;
    }

    return accounts[idx];
}

void
Config_manager::dump_accounts()
{
    for (unsigned int i = 0; i < accounts.size(); ++i) {
        accounts[i]->dump();
    }
}

#ifdef CONFIG_MANAGER_DEBUG

int main()
{
    Config_manager* cm = new Config_manager();
    cm->dump_accounts();

    cout << "\nFirst account dump: " << endl;
    Account* acc = cm->get_account_at_index(0);
    acc->dump();

    return 0;
}

#endif
