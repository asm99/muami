#include "Email_infos.hpp"

void
Email_infos::dump()
{
    std::cout
        << "--- DUMP: Email infos ---\n"
        << "uid: " << this->uid << "\n"
        << "size: " << this->size << "\n"
        << "flags: " << static_cast<unsigned>(this->flags) << "\n"
        << "internaldate: " << this->internaldate << "\n"
        << "date: " << this->date << "\n"
        << "subject: " << this->subject << "\n"
        << "from: " << this->from << "\n"
        << std::endl;
}
