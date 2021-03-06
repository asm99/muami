#include "Address.hpp"

// Setters
void
Address::set_adl(const string& adl)
{
    addr_adl = adl;
}

void
Address::set_host(const string& host)
{
    addr_host = host;
}

void
Address::set_mailbox(const string& mailbox)
{
    addr_mailbox = mailbox;
}

void
Address::set_name(const string& name)
{
    addr_name = name;
}

// Getters
string
Address::adl() const
{
    return addr_adl;
}

string
Address::host() const
{
    return addr_host;
}

string
Address::mailbox() const
{
    return addr_mailbox;
}

string
Address::name() const
{
    return addr_name;
}

string
Address::email() const
{
    return addr_mailbox + "@" + addr_host;
}

string
Address::usermail() const
{
    string address;
    if (!addr_name.empty()) {
        address += "\"" + addr_name + "\" ";
    }
    address += "<" + email() + ">";
    return address;
}

// Operators overloading
istream&
operator>>(istream& is, Address* a)
{
    enum field {
        ADDR_NAME = 0,
        ADDR_ADL,
        ADDR_MAILBOX,
        ADDR_HOST,
    };

    int step = ADDR_NAME;
    string token, cur_str, stripped;
    size_t pos = 0;

    while (is >> token) {
#ifdef ADDRESS_DEBUG
        debug("Address token: " + token);
#endif

        cur_str += token + " ";

        pos = token.find("NIL");

        if (pos != string::npos
            || count(cur_str.begin(), cur_str.end(), '"') == 2) {

            if (pos != string::npos) {
                cur_str = "";
            }

            stripped = util::strip_chars(cur_str, "()\"");

            switch (step) {
                case ADDR_NAME:
                    a->set_name(stripped);
                    break;
                case ADDR_ADL:
                    a->set_adl(stripped);
                    break;
                case ADDR_MAILBOX:
                    a->set_mailbox(stripped);
                    break;
                case ADDR_HOST:
                    a->set_host(stripped);
                    break;
                default:
                    break;
            }

            if (token.back() == ')')
                break;

            cur_str.clear();
            step++;
        }

    }

    return is;
}

// DEBUG
void
Address::dump() const
{
    debug("");
    cout << "+--------------+--------------"  << endl
         << "|           Address           "  << endl
         << "+--------------+--------------"  << endl
         << "| addr-name    | " + name()      << endl
         << "| addr-adl     | " + adl()       << endl
         << "| addr-mailbox | " + mailbox()   << endl
         << "| addr-host    | " + host()      << endl
         << "+--------------+--------------"  << endl;
}

#ifdef ADDRESS_DEBUG

#include <vector>

int
main()
{
    vector<string> vecs = {
        "((\"Voyages-sncf.com\" NIL \"bonsplans\" \"newsletter.voyages-sncf.com\"))",
        "((\"Angelique\" NIL \"angelique\" \"appel.com\"))",
        "((NIL NIL \"angelique\" \"appel.com\"))",
        "((\"Robert Marechal\" NIL \"marechalc\" \"yahoo.com\"))",
    };

    for (auto s : vecs) {
        istringstream iss(s);
        Address* a = new Address();
        iss >> a;
        if (a) {
            a->dump();
            delete a;
        }
    }

    string s = "((\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\")) ((\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\") (\"Voyages-sncf.com\" NIL \"bonsplans\" \"newsletter.voyages-sncf.com\")) ((\"abc\" NIL \"abc\" \"blah.com\"))";
    istringstream iss(s);
    Address* a = new Address();
    while (iss >> a) {
        cout << "Address a\n";
        if (a) {
            a->dump();
        }
    }
    if (a)
        delete a;

    return 0;
}
#endif
