#include "base36.hpp"

namespace  {

/*
 * Reverse a string
 * reverse("ABCD") => "DCBA"
 */
string
reverse(const string& s)
{
    int slen = s.length();
    string rev;
    rev.resize(slen);
    for (int i = slen-1, j = 0; i > -1 ; i--, j++) {
        rev[j] = s[i];
    }
    return rev;
}

} /* namespace  */

/*
 * Convert a number to its base36 representation
 * FIXME: char* res allocation size
 */
string
base36::encode(unsigned long num)
{
    const char base36symbols[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    int base = 36;
    int mod;
    char symbol;
    string res;

    do {
        mod = num % base;
        symbol = base36symbols[mod];
        res.push_back(symbol);
        num /= base;
    } while (num > 0);

    return reverse(res);
}

#ifdef BASE36_DEBUG

#include <map>

/*
 * Testing functions
 * Only errors are printed out
 */
int
main()
{
    map<string, string> revs = {
        { "ABCDEF", "FEDCBA" },
    };

    map<unsigned long, string> base36s = {
        { 1804289383, "tu86lj" },
    };

    map<string, string>::const_iterator it;
    for (it = revs.begin(); it != revs.end(); ++it) {
        string reversed = reverse(it->first);
        if (reversed != it->second) {
            cerr << "Error reversing: "
                 << it->first << " => " << it->second
                 << endl;
        }
    }

    map<unsigned long, string>::const_iterator itt;
    for (itt = base36s.begin(); itt != base36s.end(); ++itt) {
        string encoded = base36::encode(itt->first);
        if (encoded != itt->second) {
            cerr << "Error encoding in base36: "
                 << itt->first << " => " << itt->second
                 << endl;
        }
    }

    return 0;
}
#endif
