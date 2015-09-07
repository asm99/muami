#ifndef RFC822_HEADER_H
#define RFC822_HEADER_H

#include <iostream>
#include <string>

// E-mail rfc822 header
class RFC822_header {
    public:
        std::string return_path;
        std::string envelope_to;
        std::string delivery_date;
        std::string message_id;
        std::string date;
        std::string subject;
        std::string from;
        std::string to;
        std::string user_agent;
        std::string mime_version;
        std::string content_type;

        RFC822_header() {};
        ~RFC822_header() {};

        void Dump_header(RFC822_header* hdr);
};


#endif /* end of include guard: RFC822_HEADER_H */
