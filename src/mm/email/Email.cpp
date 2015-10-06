#include "Email.hpp"

// Setters

void
Email::set_uid(int u)
{
    em_uid = u;
}

void
Email::set_rfc822_size(int sz)
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


// Getters

int
Email::uid()
{
    return em_uid;
}

int
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

// DEBUG
void
Email::dump()
{
    debug("uid           : " + uid()          );
    debug("rfc822_size   : " + rfc822_size()  );
    debug("friendly_time : " + friendly_time());
    debug("internaldate  : " + internaldate() );
    debug("flags         : " + flags()        );
    envelope().dump();
}
