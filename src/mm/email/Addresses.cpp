#include "Addresses.hpp"

void
Addresses::add_addresses(string s)
{
    Address* a = new Address();
    istringstream iss(s);
    while (iss >> a) {
        Address* cpy = new Address();
        *cpy = *a;
        addrs.push_back(cpy);
    }
}

unsigned int
Addresses::size()
{
    return addrs.size();
}

// Operators overloading

Address*
Addresses::operator[](unsigned int i)
{
    if (i >= addrs.size()) {
        cerr << "Out of bounds addrs" << endl;
        return nullptr;
    }
    return addrs[i];
}

istream&
operator>>(istream& is, Addresses* addresses)
{
    string s, token;
    size_t cl_op_paren_pos;
    int count = 0;  // if NIL is the only string, there are no addresses
                    // and count will be 0
    while (is >> token) {
#ifdef ADDRESSES_DEBUG
        cout << "Addresses token: " << token << endl;
#endif
        // Nstring is NIL
        if (count == 0 && token.find("NIL") != string::npos)
            return is;

        cl_op_paren_pos = token.find(")(");
        if (cl_op_paren_pos != string::npos) {
            token.insert(cl_op_paren_pos + 1, 1, ' ');
        }
        s += token + " ";

        if (token.compare(token.length()-2, 2, "))") == 0)
            break;

        count++;
    }

    cout << "s: " << s << endl;
    addresses->add_addresses(s);

    return is;
}

// DEBUG

void
Addresses::dump()
{
    unsigned int sz = addrs.size();
	debug("Addresses size: " + to_string(sz));
    for (unsigned int i = 0; i < sz; i++) {
        addrs[i]->dump();
    }
}

#ifdef ADDRESSES_DEBUG
int
main()
{
    string s = "((\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\") (\"Robert Marechal\" NIL \"marechalr\" \"yahoo.com\") (\"Voyages-sncf.com\" NIL \"bonsplans\" \"newsletter.voyages-sncf.com\"))";
//     string s = "NIL";

    istringstream iss(s);
    Addresses* ads = new Addresses();
    iss >> ads;
    cout << "size: " << ads->size() << endl;
//     ads->dump();

    return 0;
}
#endif
