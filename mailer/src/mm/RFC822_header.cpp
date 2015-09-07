#include "RFC822_header.hpp"

// Dump the content of a RFC822 header
void
RFC822_header::Dump_header(RFC822_header* hdr)
{
    std::cout << "RFC822 header: \n"
        << hdr->return_path << "\n"
        << hdr->envelope_to << "\n"
        << hdr->delivery_date << "\n"
        << hdr->message_id << "\n"
        << hdr->date << "\n"
        << hdr->subject << "\n"
        << hdr->from << "\n"
        << hdr->to << "\n"
        << hdr->user_agent << "\n"
        << hdr->mime_version << "\n"
        << hdr->content_type
        << std::endl;
}

#ifdef RFC822_HEADER_DEBUG
int main()
{
    Dump_header(nullptr);
    return 0;
}
#endif
