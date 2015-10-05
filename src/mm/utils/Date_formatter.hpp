/*
 * MELKONIAN Marc - 13410425
 * Date_formatter.hpp - date strings formatting related things
 * Date: 04 August 2015
 */

#ifndef DATE_FORMATTER_H
#define DATE_FORMATTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

class Date_formatter
{
    private:
        struct tm date_localtime();

    public:
        Date_formatter() {};
        ~Date_formatter() {};

        string format_date(string s);
        string current_date();
};

#endif /* end of include guard: DATE_FORMATTER_H */
