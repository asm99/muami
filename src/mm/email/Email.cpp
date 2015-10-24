#include "Email.hpp"

// Constructor
Email::Email()
    : em_envelope(), em_parts()
{
//     body = new Body();
}

// Setters

void
Email::set_uid(unsigned long u)
{
    em_uid = u;
}

void
Email::set_rfc822_size(unsigned long sz)
{
    em_rfc822_size = sz;
}

void
Email::set_flags(unsigned int fl)
{
    em_flags = fl;
}

void
Email::set_friendly_time(const string& time)
{
    em_friendly_time = time;
}

void
Email::set_internaldate(const string& date)
{
    em_internaldate = date;
}

void
Email::set_envelope(const Envelope& env)
{
    em_envelope = env;
}

void
Email::set_rfc822_header(RFC822_header* const hdr)
{
    em_rfc822_header = hdr;
}

void
Email::add_part(string section, Bodypart* bp)
{
    em_parts[section] = bp;
}

// Getters

unsigned long
Email::uid()
{
    return em_uid;
}

unsigned long
Email::rfc822_size()
{
    return em_rfc822_size;
}

unsigned int
Email::flags()
{
    return em_flags;
}

string&
Email::friendly_time()
{
    return em_friendly_time;
}

string&
Email::internaldate()
{
    return em_internaldate;
}

Envelope&
Email::envelope()
{
    return em_envelope;
}

RFC822_header*
Email::rfc822_header()
{
    return em_rfc822_header;
}

map<string, Bodypart*>&
Email::parts()
{
    return em_parts;
}

// DEBUG
void
Email::dump()
{
    debug(" --- Email ---");
    debug("uid           : " + to_string(uid())          );
    debug("rfc822_size   : " + to_string(rfc822_size())  );
    debug("friendly_time : " + friendly_time());
    debug("internaldate  : " + internaldate() );
    debug("flags         : " + flags()        );
    envelope().dump();
}

void
Email::dump_parts()
{
    cout << "--- Email parts ---" << endl;

    map<string, Bodypart*>::const_iterator it;
    for (it = em_parts.begin(); it != em_parts.end(); ++it) {
        cout << "  " << it->first
             << " -> " << it->second->type()
             << ", " << it->second->subtype() << endl;
    }

    cout << "-------------------" << endl;
}
