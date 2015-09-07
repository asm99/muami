#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdexcept>
#include "Account.hpp"
#include "error.hpp"

class Config_manager {
    private:
        static const std::string Config_Filename;
        std::vector<Account*> accounts;

        std::string get_config_file_path();
        std::string read_config_file();
        Account* get_account_from_string(std::string token);

    public:
        Config_manager() {};
        ~Config_manager() {};

        std::vector<Account*> get_accounts();
};
