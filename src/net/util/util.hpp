/*
 * MELKONIAN Marc - 13410425
 * util.hpp - Facilities for processing strings
 */

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

using namespace std;

namespace util {

    void lower(string& s);
    vector<int> explode_to_ints(string s, const string& delim);
    string strip_chars(string& src, const string& set);
    string get_section(string section, bool is_first_subpart, int depth);
    int get_body_length(const string& s);
    vector<string> split_string(string src, const string& delim);
    void nullify_string(string& s);

} /* namespace util */

#endif /* end of include guard: UTIL_H */
