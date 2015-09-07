#include "SDebugger.hpp"

SDebugger::SDebugger()
{
    // Create temp file
    char out_name[] = "/tmp/muami_XXXXXX";
    int fd = mkstemp(out_name);
    if (fd < 0) {
        error("Cannot create file in /tmp directory", 1);
    }

    // Get temp file filename
    char path[256];
    memset(path, 0, sizeof path);
    std::stringstream ss;
    ss << "/proc/self/fd/" << fd;
    readlink((ss.str()).c_str(), path, sizeof path);

    // Open temp file for writing
    this->out.open(path, std::ios_base::in|std::ios_base::out);
    // Print filename
    std::cout << "- debug - writing info to file: " << path << std::endl;
}

/*
 * Print debug message to a tty with FILE and LINE of calling function
 * FIXME: should print to a XTerm window launched by launch_debug_window() but
 *        doesn't work so print to a literal tty name for now
 */
void
SDebugger::tty_debug(char* func, int line, std::string msg)
{
    this->out << "# debug - " << func << " " << line << ": " << msg;
    this->out.flush();
}

#ifdef TTY_DEBUG
int
main()
{
    SDebugger* debugger = SDebugger::get_instance();
    debugger->ttydebug("Test");
    return 0;
}
#endif
