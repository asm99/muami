#ifndef EMAIL_INFOS_H
#define EMAIL_INFOS_H

#include <iostream>

class Email_infos {
    public:
        int uid;
        int size;
        unsigned char flags;
        std::string internaldate;  // Received date
        std::string date;          // Sent date
        std::string subject;
        std::string from;

        Email_infos() {};
        ~Email_infos() {};

        void dump();
};

#endif /* end of include guard: EMAIL_INFOS_H */
