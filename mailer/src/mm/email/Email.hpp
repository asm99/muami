#ifndef EMAIL_H
#define EMAIL_H

#include "RFC822_header.hpp"
#include "Bodypart.hpp"
#include "Envelope.hpp"

using namespace std;

/*
 * Messages flags
 * https://tools.ietf.org/html/rfc3501#section-2.3.2
 */
enum Flags {
    FL_ANSWERED  = 0x01,
    FL_FLAGGED   = 0x02,
    FL_DELETED   = 0x04,
    FL_SEEN      = 0x08,
    FL_DRAFT     = 0x10,
    FL_FORWARDED = 0x20,
};

class Email
{
    private:
        int em_uid;
        int em_rfc822_size;
        unsigned char em_flags;
        string em_friendly_time;
        string em_internaldate;
        Envelope em_envelope;
        RFC822_header* em_rfc822_header;
//         Bodypart em_*bodypart;

    public:
        Email(): em_envelope() {};
        ~Email() {};

        // Setters
        void set_uid(int u);
        void set_rfc822_size(int sz);
        void set_flags(unsigned int fl);
        void set_friendly_time(const string& time);
        void set_internaldate(const string& date);
        void set_envelope(const Envelope& env);
        void set_rfc822_header(RFC822_header* const hdr);

        // Getters
        int uid();
        int rfc822_size();
        unsigned int flags();
        string& friendly_time();
        string& internaldate();
        Envelope& envelope();
        RFC822_header* rfc822_header();

        // DEBUG
        void dump();
};

#endif /* end of include guard: EMAIL_H */
