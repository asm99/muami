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
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdexcept>
#include <errno.h>
#include "Account.hpp"
#include "../utils/error.hpp"

using namespace std;

class Config_manager
{
    private:
        static const string Conf_dir_rel_path;
        vector<Account*> accounts;

        string get_conf_dir_abs_path();
        vector<string> list_conf_dir(const string& path);
        string read_conf_file(const string& path, const string& fname);
        Account* get_account_from_string(string s, const string& fname);
        void load_accounts(vector<Account*>& accs);

    public:
        Config_manager();
        ~Config_manager() {};

        unsigned int get_accounts_count();
        Account* get_account_at_index(unsigned int idx);

        // DEBUG
        void dump_accounts();
};

#endif /* end of include guard: CONFIG_MANAGER_H */
