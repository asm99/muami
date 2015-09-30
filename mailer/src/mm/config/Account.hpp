/*
 * MELKONIAN Marc
 * IED 13410425
 * Account.hpp: each account is loaded from a config file in the config
 *              directory of in the user $HOME directory
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

typedef enum Email_Protocol {
    PROTOCOL_IMAP = 0,
    PROTOCOL_POP3,
} Email_Protocol;

class Account
{
    private:
        string acc_id;      // identifier (used in UI status bar)
        string acc_imap;    // IMAP server address
        string acc_iport;   // IMAPS port
        string acc_smtp;    // SMTP server address
        string acc_sport;   // SMTPS port
        string acc_from;    // username + email "Marc" <marc@ok.com>
        string acc_user;    // username to connect to server
        string acc_pass;    // password

    public:
        Account() {};
        ~Account() {};

        // Setters
        void set_id(const string& s);
        void set_imap(const string& s);
        void set_iport(const string& s);
        void set_smtp(const string& s);
        void set_sport(const string& s);
        void set_from(const string& s);
        void set_user(const string& s);
        void set_pass(const string& s);

        // Getters
        string id();
        string imap();
        string iport();
        string smtp();
        string sport();
        string from();
        string user();
        string pass();

        // DEBUG
        void dump();
};

#endif /* end of include guard: ACCOUNT_H */
