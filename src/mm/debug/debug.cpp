#include "debug.hpp"

void
debug::print(const string& file, int line, const string& s)
{
    string date = Date::debug_date();

    cerr << "[" << date << "][DEBUG] "
         << file << ":" << line << ":" << s
         << endl;
}
