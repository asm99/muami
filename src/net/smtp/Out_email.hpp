/*
 * MELKONIAN Marc - 13410425
 * Out_email.hpp - class for an "outgoing" e-mail (= an e-mail to send)
 */

#ifndef OUT_EMAIL_H
#define OUT_EMAIL_H

#include "../email/Address.hpp"
#include "../email/Addresses.hpp"

using namespace std;

class Out_email
{
    private:
        Address em_to;
        Addresses* em_cc;
        Addresses* em_bcc;
        string em_subject;
        string em_content;

    public:
        Out_email();
        ~Out_email();

        // Setters
        void set_to(const Address& a);
        void set_subject(string s);
        void set_content(string s);
        void add_cc(Address* a);
        void add_bcc(Address* a);

        // Getters
        const Address& to() const;
        Addresses* cc();
        Addresses* bcc();
        string subject() const;
        string content() const;

        // DEBUG
        void dump() const;
};

#endif /* end of include guard: OUT_EMAIL_H */
