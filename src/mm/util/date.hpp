/*
 * MELKONIAN Marc - 13410425
 * Date_formatter.hpp - date strings formatting related things
 * Date: 04 August 2015
 */

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <sys/time.h>

using namespace std;

namespace Date {

    string format_date(string s);
    string current_date();
    string debug_date();

} /* namespace Date */

#endif /* end of include guard: DATE_H */
