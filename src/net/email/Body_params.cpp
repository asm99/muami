#include "Body_params.hpp"

void
Body_params::add_param(const string& key, const string& value)
{
    body_fld_param[key] = value;
}

string
Body_params::get_value(const string& key)
{
    map<string, string>::iterator it = body_fld_param.find(key);
    if (it != body_fld_param.end()) {
        return it->second;
    }
    return "";
}

bool
Body_params::is_nil()
{
    return body_fld_param.size() == 0;
}

void
Body_params::dump()
{
    if (is_nil()) {
        cout << endl;
        return;
    }

    map<string, string>::const_iterator it;
    for (it = body_fld_param.begin(); it != body_fld_param.end(); ++it) {
        cout << it->first << " -> " << it->second << ", ";
    }
    cout << endl;
}

/*
 * TODO: throw exception if an odd number of params is parsed
 */
stringstream&
operator>>(stringstream& ss, Body_params* bp)
{
    string key, val;

    ss >> key;

    if (key == "NIL") {
        return ss;
    }

    ss >> val;

    bp->add_param(
            util::strip_chars(key, "(\""),
            util::strip_chars(val, "\")"));

    if (val.back() == ')') {
        return ss;
    }

    while (ss >> key >> val) {
        bp->add_param(
                util::strip_chars(key, "(\""),
                util::strip_chars(val, "\")"));

        if (val.back() == ')') {
            break;
        }
    }

    return ss;
}
