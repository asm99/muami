#include "Mailbox.hpp"

// Setters

void
Mailbox::set_flags(unsigned int n)
{
    mb_flags = n;
}

void
Mailbox::set_perm_flags(unsigned int n)
{
    mb_perm_flags = n;
}

void
Mailbox::set_exists(unsigned long n)
{
    mb_exists = n;
}

void
Mailbox::set_recent(unsigned long n)
{
    mb_recent = n;
}

void
Mailbox::set_unseen(unsigned long n)
{
    mb_unseen = n;
}

void
Mailbox::set_uidvalidity(unsigned long n)
{
    mb_uidvalidity = n;
}

void
Mailbox::set_uidnext(unsigned long n)
{
    mb_uidnext = n;
}

void
Mailbox::set_permissions(int n)
{
    mb_permissions = n;
}

void
Mailbox::set_attributes(const string& s)
{
    mb_attributes = s;
}

void
Mailbox::set_separator(const string& s)
{
    mb_separator = s;
}

// Getters

unsigned int
Mailbox::flags() const
{
    return mb_flags;
}

unsigned int
Mailbox::perm_flags() const
{
    return mb_perm_flags;
}

unsigned long
Mailbox::exists() const
{
    return mb_exists;
}

unsigned long
Mailbox::recent() const
{
    return mb_recent;
}

unsigned long
Mailbox::unseen() const
{
    return mb_unseen;
}

unsigned long
Mailbox::uidvalidity() const
{
    return mb_uidvalidity;
}

unsigned long
Mailbox::uidnext() const
{
    return mb_uidnext;
}

int
Mailbox::permissions() const
{
    return mb_permissions;
}

string
Mailbox::attributes()
{
    return mb_attributes;
}

string
Mailbox::separator()
{
    return mb_separator;
}

vector<Email*>&
Mailbox::emails()
{
    return mb_emails;
}

// DEBUG

void
Mailbox::dump()
{
    debug("flags      : " + flags()       );
    debug("perm_flags : " + perm_flags()  );
    debug("exists     : " + exists()      );
    debug("recent     : " + recent()      );
    debug("unseen     : " + unseen()      );
    debug("uidvalidity: " + uidvalidity() );
    debug("uidnext    : " + uidnext()     );
    debug("permissions: " + permissions() );
}

