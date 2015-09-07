#ifndef EMAIL_H
#define EMAIL_H

#include "Email_infos.hpp"
#include "RFC822_header.hpp"
#include "Bodypart.hpp"

// typedef struct subject {
//         int uid;
//         int size;
//         unsigned char flags;
//         char* date;
//         char* subject;
//         char* from;
// } subject;

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

class Email {
    public:
		Email_infos* infos;
        RFC822_header* rfc822_hdr;
        Bodypart *bodypart;

        Email() {};
        ~Email() {};

        void dump();
};

#endif /* end of include guard: EMAIL_H */
