/*
 * MELKONIAN Marc
 * IED 13410425
 * Envelope.hpp: An e-mail envelope as described in the RFC 3501
 *
 * Doc: https://tools.ietf.org/html/rfc3501#page-84
 *
 * Grammar:
 * --------
 *
 * envelope        = "(" env-date SP env-subject SP env-from SP
 *                   env-sender SP env-reply-to SP env-to SP env-cc SP
 *                   env-bcc SP env-in-reply-to SP env-message-id ")"
 *
 * env-bcc         = "(" 1*address ")" / nil
 *
 * env-cc          = "(" 1*address ")" / nil
 *
 * env-date        = nstring
 *
 * env-from        = "(" 1*address ")" / nil
 *
 * env-in-reply-to = nstring
 *
 * env-message-id  = nstring
 *
 * env-reply-to    = "(" 1*address ")" / nil
 *
 * env-sender      = "(" 1*address ")" / nil
 *
 * env-subject     = nstring
 *
 * env-to          = "(" 1*address ")" / nil
 *
 */

#ifndef ENVELOPE_H
#define ENVELOPE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Address.hpp"
#include "Addresses.hpp"
#include "Nstring.hpp"
#include "../utils/util.hpp"
#include "../coding/coding.hpp"

using namespace std;

class Envelope
{
    private:
        Addresses* env_bcc;
        Addresses* env_cc;
        Nstring    env_date;
        Address*   env_from;
        Nstring    env_in_reply_to;
        Nstring    env_message_id;
        Address*   env_reply_to;
        Address*   env_sender;
        Nstring    env_subject;
        Address*   env_to;

    public:
        Envelope() : env_bcc(), env_cc() {};
        ~Envelope() {};

        // Setters
        void set_bcc(Addresses* const bcc);
        void set_cc(Addresses* const cc);
        void set_date(const Nstring& date);
        void set_from(Address* const from);
        void set_in_reply_to(const Nstring& in_reply_to);
        void set_message_id(const Nstring& message_id);
        void set_reply_to(Address* const reply_to);
        void set_sender(Address* const sender);
        void set_subject(const Nstring& subject);
        void set_to(Address* const to);

        // Getters
        Addresses* bcc() const;
        Addresses* cc() const;
        Nstring   date() const;
        Address*   from() const;
        Nstring   in_reply_to() const;
        Nstring   message_id() const;
        Address*   reply_to() const;
        Address*   sender() const;
        Nstring   subject() const;
        Address*   to() const;

        // DEBUG
        void dump();
};

istream& operator>>(istream& is, Envelope& env);

#endif /* end of include guard: ENVELOPE_H */
