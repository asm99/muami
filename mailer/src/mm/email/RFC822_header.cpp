#include "RFC822_header.hpp"

const vector<string> RFC822_header::tags = {
    // tags after the ":"
    "from",     // sending host
    "by",       // receiving host
    "via",      // physical path
    "with",     // link/mail protocol
    "id",       // receiver msg id
    "for",      // initial form
    // date after the ";"
    "date",     // date
};

// Default constructor
RFC822_header::RFC822_header()
{
    for (auto s : tags) {
        received[s] = "";
    }
}

// Default destructor
RFC822_header::~RFC822_header()
{
}

// Dump the content of a RFC822 header
void
RFC822_header::dump()
{
    cout << "RFC822 header:" << endl;
    for (auto s : tags) {
        cout << s << " : " << received[s] << endl;
    }
}

#ifdef RFC822_HEADER_DEBUG
int main()
{
    RFC822_header* hdr = new RFC822_header();
    hdr->dump();
    return 0;
}
#endif
