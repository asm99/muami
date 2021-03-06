/*
 * MELKONIAN Marc - 13410425
 * debug.hpp - debugging facilities
 */

#ifndef DEBUG_H
#define DEBUG_H

#define debug(arg) debug::print(__FILE__, __LINE__, arg)

#include <iostream>
#include "../util/date.hpp"

using namespace std;

namespace debug {

    void print(const string& file, int line, const string& s);

} /* namespace debug */

#endif /* end of include guard: DEBUG_H */
