#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace util {

    vector<int> explode_to_ints(string s, const string& delim);
    string strip_chars(string& src, const string& set);
    string get_new_section(string section, bool is_child);
    int get_body_length(const string& s);
    vector<string> split_string(string src, const string& delim);
    void nullify_string(string& s);

}; // util

#endif /* end of include guard: UTIL_H */
