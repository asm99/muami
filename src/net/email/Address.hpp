/*
 * MELKONIAN Marc
 * IED 13410425
 * Address.hpp: An envelope address as described in the RFC 3501
 *
 * Doc: https://tools.ietf.org/html/rfc3501#section-9
 *
 * Grammar:
 * --------
 *
 *    address      = "(" addr-name SP addr-adl SP addr-mailbox SP
 *                   addr-host ")"
 *
 *    addr-adl     = nstring
 *                     ; Holds route from [RFC-2822] route-addr if
 *                     ; non-NIL
 *
 *    addr-host    = nstring
 *                     ; NIL indicates [RFC-2822] group syntax.
 *                     ; Otherwise, holds [RFC-2822] domain name
 *
 *    addr-mailbox = nstring
 *                     ; NIL indicates end of [RFC-2822] group; if
 *                     ; non-NIL and addr-host is NIL, holds
 *                     ; [RFC-2822] group name.
 *                     ; Otherwise, holds [RFC-2822] local-part
 *                     ; after removing [RFC-2822] quoting
 *
 *    addr-name    = nstring
 *                     ; If non-NIL, holds phrase from [RFC-2822]
 *                     ; mailbox after removing [RFC-2822] quoting
 */

#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "../util/util.hpp"
#include "../debug/debug.hpp"

using namespace std;

class Address
{
    private:
        string addr_name;
        string addr_adl;
        string addr_mailbox;
        string addr_host;

    public:
        Address() {};
        Address(string s_name, string s_adl, string s_mailbox, string s_host):
            addr_name(s_name),
            addr_adl(s_adl),
            addr_mailbox(s_mailbox),
            addr_host(s_host) {}
        ~Address() {};

        // Setters
        void set_adl(const string& adl);
        void set_host(const string& host);
        void set_mailbox(const string& mailbox);
        void set_name(const string& name);

        // Getters
        string adl() const;
        string host() const;
        string mailbox() const;
        string name() const;
        string email() const;    // e-mail address, ie: me@blah.com
        string usermail() const; // full address, ie: "Me" <me@blah.com>

        // DEBUG
        void dump() const;
};

istream& operator>>(istream& is, Address* a);

#endif /* end of include guard: ADDRESS_H */
