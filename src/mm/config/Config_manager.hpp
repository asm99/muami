/*
 * MELKONIAN Marc
 * IED 13410425
 * Config_manager.hpp: Manages the accounts loaded from the conf directory
 *                     in the user $HOME directory
 * Path to the config dir: $HOME/.config/muami/accounts/
 */

#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <stdexcept>
#include "Account.hpp"
#include "Conf.hpp"
#include "../utils/util.hpp"
#include "../utils/error.hpp"

using namespace std;

enum ACCOUNT_SAVE_CODES {
    ACCOUNT_SAVE_ERR_EMPTY_FIELD = 0,
    ACCOUNT_SAVE_ERR_OPEN_FILE,
    ACCOUNT_SAVE_ERR_WRITE_FILE,
    ACCOUNT_SAVE_SUCCESS,
};

class Config_manager
{
    private:
        vector<Account*> accounts;

        static const string Conf_dir_rel_path;
        string get_conf_dir_abs_path();
        vector<string> list_conf_dir(const string& path);
        string read_conf_file(const string& path, const string& fname);
        Conf get_conf_from_string(const string& s, const string& fname);
        Account* create_account_from_conf(const Conf& conf);
        void load_accounts();
        void add_account(Account* acc);
        int save_config_file(Conf& cf);

        // Account creation/modification

    public:
        class Conf_Invalid {}; /* Exception */

        Config_manager();
        ~Config_manager() {};

        // Account creation/modification
        int setup_accout(string fname, string in_server, string in_port,
                         string smtp_server, string smtp_port,
                         string from, string user, string pass);

        unsigned int get_accounts_count() const;
        Account* get_account_at_index(unsigned int idx);

        // DEBUG
        void dump_accounts() const;
};

#endif /* end of include guard: CONFIG_MANAGER_H */
