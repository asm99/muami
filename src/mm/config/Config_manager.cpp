#include "Config_manager.hpp"

/* Global configuration filename */
const string Config_manager::Conf_dir_rel_path = ".config/muami/accounts";

/* Get accounts config files absolute path (in user $HOME dir) */
string
Config_manager::get_conf_dir_abs_path()
{
    struct passwd *pw = getpwuid(getuid());
    const string homedir = pw->pw_dir;
    return homedir + "/" + Conf_dir_rel_path;
}


/* Constructor */
Config_manager::Config_manager()
    : accounts()
{
    load_accounts();
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

/* Create an account from a configuration object */
Account*
Config_manager::create_account_from_conf(const Conf& conf)
{
    if (!conf.is_complete()) {
        throw Config_manager::Conf_Invalid();
    }

    Account* acc = new Account(conf);
    return acc;
}

/* Load a Conf object from a configuration file content */
Conf
Config_manager::get_conf_from_string(const string& s, const string& fname)
{
    stringstream iss(s);
    string line;
    string field, colon, tmp, val;
    stringstream ss;
    Conf conf {};
    conf.set_fname(fname);

    while (getline(iss, line)) {
        val.clear();

        if (line.empty())
            continue;

        ss.clear();
        ss << line;
        ss >> field >> colon;

        while (ss >> tmp) {
            val += tmp;
        }

        if      (field == "in_server")   { conf.set_in_server(val);   }
        else if (field == "in_port")     { conf.set_in_port(val);     }
        else if (field == "smtp_server") { conf.set_smtp_server(val); }
        else if (field == "smtp_port")   { conf.set_smtp_port(val);   }
        else if (field == "from")        { conf.set_from(val);        }
        else if (field == "user")        { conf.set_user(val);        }
        else if (field == "pass")        { conf.set_pass(val);        }
        else if (field == "protocol") {
            if      (val == "IMAP") { conf.set_protocol(PROTOCOL_IMAP);      }
            else if (val == "POP3") { conf.set_protocol(PROTOCOL_POP3);      }
            else                    { conf.set_protocol(PROTOCOL_UNDEFINED); }
        }
    }

    return conf;
}

/* Get all the accounts from the config dir */
void
Config_manager::load_accounts()
{
    string path = get_conf_dir_abs_path();
    vector<string> files = list_conf_dir(path);

    for (auto fname : files) {
        string content = read_conf_file(path, fname);
        Conf cfg = get_conf_from_string(content, fname);
        Account* acc = create_account_from_conf(cfg);
        add_account(acc);
    }
}

void
Config_manager::add_account(Account* acc)
{
    accounts.push_back(acc);
}

/* Return the number of accounts */
unsigned int
Config_manager::get_accounts_count() const
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

// Account creation/modification
int
Config_manager::save_config_file(Conf& cf)
{
    string filename;

    if (cf.fname().empty()) { // new account
        string nm = get_conf_dir_abs_path() + "/" + "account_XXXXXX";
        char tmp[nm.length()+1];
        memset(tmp, 0, sizeof tmp);
        memcpy(tmp, nm.c_str(), sizeof tmp);
        int t = mkstemp(tmp);
        if (t < 0) {    // error
            perror("mkstemp");
        }
        filename = string(tmp);
        debug("Saving account to file: " + filename);
        cf.set_fname(filename);
    } else {
        filename = get_conf_dir_abs_path() + "/" + cf.fname();
    }

    ofstream ofs(filename);
    if (!ofs) {
        cerr << "Error: cannot create file " << filename << endl;
        return ACCOUNT_SAVE_ERR_OPEN_FILE;
    }

    ofs << "in_server   : " << cf.in_server()   << "\n"
        << "in_port     : " << cf.in_port()     << "\n"
        << "smtp_server : " << cf.smtp_server() << "\n"
        << "smtp_port   : " << cf.smtp_port()   << "\n"
        << "from        : " << cf.from()        << "\n"
        << "user        : " << cf.user()        << "\n"
        << "pass        : " << cf.pass()        << "\n"
        << "protocol    : " << "IMAP"           << "\n";

    if (ofs.bad() || ofs.fail()) {
        return ACCOUNT_SAVE_ERR_WRITE_FILE;
    }

    ofs.close();

    Account *a = new Account(cf);
    add_account(a);

    return ACCOUNT_SAVE_SUCCESS;
}

// Account creation/modification
int
Config_manager::setup_accout(string fname,
                             string in_server, string in_port,
                             string smtp_server, string smtp_port,
                             string from, string user, string pass)
{
    Conf cf {};
    cf.set_fname(fname);
    cf.set_in_server(in_server);
    cf.set_in_port(in_port);
    cf.set_smtp_server(smtp_server);
    cf.set_smtp_port(smtp_port);
    cf.set_from(from);
    cf.set_user(user);
    cf.set_pass(pass);
    cf.set_protocol(PROTOCOL_IMAP);

    if (!cf.is_complete()) {
        return ACCOUNT_SAVE_ERR_EMPTY_FIELD;
    }

    return save_config_file(cf);
}


void
Config_manager::dump_accounts() const
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


    cm->setup_accout(
            "", "imap.server.com", "993",
            "smtp.server.com", "25",
            "boloss", "bl@boloss.com", "passwd");

    return 0;
}

#endif
