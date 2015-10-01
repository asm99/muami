#include "Nstring.hpp"

void
Nstring::set_str(const string& s)
{
    nstr = s;
}

string
Nstring::str()
{
    return nstr;
}

void
Nstring::dump()
{
    cout << str() << endl;
}

/*
 * FIXME: date should not strip '('
 */
istream&
operator>>(istream& is, Nstring& ns)
{
    string acc, s;
    int count = 0;
    bool is_raw = false;
    while(is >> s) {
        if (count == 0) {
            if (s.find("NIL") != string::npos) { // Nstring is NIL
                break;
            } else if (s[0] == '{') {
                is_raw = true;
            }
        }

        if (is_raw) {
            if (s.compare(0, 2, "((") == 0) {
                for (unsigned int i = 0; i < s.length(); i++) {
                    is.unget();
                }
                return is;
                break;
            }
        }

        acc += s + " ";

        if (s.back() == '"' && s[s.length()-2] != '\\')
            break;

        count++;
    }
    util::nullify_string(acc);
//     ns.set_str(util::strip_chars(acc, "(\""));
    ns.set_str(acc);
    return is;
}
