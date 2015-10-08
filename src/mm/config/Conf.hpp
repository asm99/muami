#ifndef CONF_H
#define CONF_H

#include <iostream>
#include "../protocol/protocols.hpp"
#include "../debug/debug.hpp"

using namespace std;

class Conf
{
    private:
        string conf_fname;             // config filename
        string conf_in_server;         // IMAP server address
        string conf_in_port;           // IMAPS port
        string conf_smtp_server;       // SMTP server address
        string conf_smtp_port;         // SMTPS port
        string conf_from;              // username + email "Marc" <marc@ok.com>
        string conf_user;              // username to connect to server
        string conf_pass;              // password
        Email_Protocol conf_protocol;  // IMAP, POP3, etc.

    public:
        Conf() {};
        ~Conf() {};

        bool is_complete() const;

        // Setters
        void set_fname(const string& s);
        void set_in_server(const string& s);
        void set_in_port(const string& s);
        void set_smtp_server(const string& s);
        void set_smtp_port(const string& s);
        void set_from(const string& s);
        void set_user(const string& s);
        void set_pass(const string& s);
        void set_protocol(Email_Protocol ep);

        // Getters
        string fname() const;
        string in_server() const;
        string in_port() const;
        string smtp_server() const;
        string smtp_port() const;
        string from() const;
        string user() const;
        string pass() const;
        Email_Protocol protocol() const;

        // DEBUG
        void dump() const;
};

#endif /* end of include guard: CONF_H */
