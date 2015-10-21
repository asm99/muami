#include "error.hpp"

void
error(const std::string msg, int code)
{
    std::cerr << "error: " << msg << std::endl;
    exit(code);
}
