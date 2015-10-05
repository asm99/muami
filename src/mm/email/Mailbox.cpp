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
Mailbox::set_exists(unsigned int n)
{
    mb_exists = n;
}

void
Mailbox::set_recent(unsigned int n)
{
    mb_recent = n;
}

void
Mailbox::set_unseen(unsigned int n)
{
    mb_unseen = n;
}

void
Mailbox::set_uidvalidity(unsigned int n)
{
    mb_uidvalidity = n;
}

void
Mailbox::set_uidnext(unsigned int n)
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

unsigned int
Mailbox::exists() const
{
    return mb_exists;
}

unsigned int
Mailbox::recent() const
{
    return mb_recent;
}

unsigned int
Mailbox::unseen() const
{
    return mb_unseen;
}

unsigned int
Mailbox::uidvalidity() const
{
    return mb_uidvalidity;
}

unsigned int
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
    cout << "flags      : " << flags() << "\n"
         << "perm_flags : " << perm_flags() << "\n"
         << "exists     : " << exists() << "\n"
         << "recent     : " << recent() << "\n"
         << "unseen     : " << unseen() << "\n"
         << "uidvalidity: " << uidvalidity() << "\n"
         << "uidnext    : " << uidnext() << "\n"
         << "permissions: " << permissions() << endl;
}

