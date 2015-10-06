#include "debug.hpp"

void
debug::print(const string& file, int line, const string& s)
{
    cerr << "--- DEBUG:" << file << ":" << line << ":" << s << endl;
}
