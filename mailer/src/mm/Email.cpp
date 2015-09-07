#include "Email.hpp"

void
Email::dump()
{
    std::cout << "--- DUMP: Email ---" << std::endl;
    this->infos->dump();
}
