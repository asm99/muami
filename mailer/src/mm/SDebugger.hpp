/* MELKONIAN Marc - 13410425
 * debug.h - debugging facilities
 * Date: 04 May 2015
 */

#define _XOPEN_SOURCE 700

// #include <stdbool.h>
// #include <termios.h>
// #include <errno.h>
// #include <libgen.h>
// #include <sys/wait.h>

// #include <stdio.h>
// #include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <fstream>
#include <random>
#include "error.hpp"

#define ttydebug(...) tty_debug(__FILE__, __LINE__, __VA_ARGS__);

class SDebugger {
    private:
        std::fstream out;

        SDebugger();
        SDebugger(SDebugger const&)       = delete;
        void operator=(SDebugger const&)  = delete;

    public:
        static SDebugger* get_instance()
        {
            static SDebugger* instance;  // Guaranteed to be destroyed.
            if (!instance) {
                instance = new SDebugger();
            }
            return instance;
        }

        void tty_debug(char* func, int line, std::string msg);
};
