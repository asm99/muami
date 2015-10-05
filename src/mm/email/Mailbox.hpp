/*
 * MELKONIAN Marc
 * IED 13410425
 * Address.hpp: An envelope address as described in the RFC 3501
 *
 * Doc: https://tools.ietf.org/html/rfc3501#section-6.3.1
 */

#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
#include "Email.hpp"
#include "flags.hpp"

using namespace std;

class Mailbox
{
    private:
        unsigned int mb_flags;
        unsigned int mb_perm_flags;
        unsigned int mb_exists;
        unsigned int mb_recent;
        unsigned int mb_unseen;
        unsigned int mb_uidvalidity;
        unsigned int mb_uidnext;
        int mb_permissions;

        string mb_attributes;
        string mb_separator;

        vector<Email*> mb_emails;

    public:
        Mailbox(): mb_emails() {};
        ~Mailbox() {};

        // Setters
        void set_flags(unsigned int n);
        void set_perm_flags(unsigned int n);
        void set_exists(unsigned int n);
        void set_recent(unsigned int n);
        void set_unseen(unsigned int n);
        void set_uidvalidity(unsigned int n);
        void set_uidnext(unsigned int n);
        void set_permissions(int n);

        void set_attributes(const string& s);
        void set_separator(const string& s);

        // Getters
        unsigned int flags() const;
        unsigned int perm_flags() const;
        unsigned int exists() const;
        unsigned int recent() const;
        unsigned int unseen() const;
        unsigned int uidvalidity() const;
        unsigned int uidnext() const;
        int permissions() const;

        string attributes();
        string separator();

        vector<Email*>& emails();

        // DEBUG
        void dump();
};

#endif /* end of include guard: MAILBOX_H */
