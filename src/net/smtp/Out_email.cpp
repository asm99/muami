#include "Out_email.hpp"

// Setters
void
Out_email::set_to(const Address& a)
{
    em_to = a;
}

void
Out_email::set_subject(string s)
{
    em_subject = s;
}

void
Out_email::set_content(string s)
{
    em_content = s;
}

void
Out_email::add_cc(Address* a)
{
    em_cc.add_address(a);
}

void
Out_email::add_bcc(Address* a)
{
    em_bcc.add_address(a);
}

// Getters
const Address&
Out_email::to() const
{
    return em_to;
}

string
Out_email::subject() const
{
    return em_subject;
}

string
Out_email::content() const
{
    return em_content;
}

Addresses&
Out_email::cc()
{
    return em_cc;
}

Addresses&
Out_email::bcc()
{
    return em_bcc;
}

// DEBUG
void
Out_email::dump() const
{
    debug("");
    cout << "--- Out e-mail ---" << endl;
    cout << "to: " ; to().dump();
    cout << "subject: " << subject() << endl;
    cout << "content: " << content() << endl;
}
