/*
 * MELKONIAN Marc - 13410425
 * Date_formatter.hpp - date strings formatting related things
 * Date: 04 August 2015
 */

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

class Date_formatter {
    private:
        struct tm date_localtime();

    public:
        Date_formatter() {};
        ~Date_formatter() {};
        std::string format_date(std::string);
        std::string current_date();
};
