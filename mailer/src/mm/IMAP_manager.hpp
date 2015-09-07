#ifndef IMAP_MANAGER_H
#define IMAP_MANAGER_H

/*
 * MELKONIAN Marc - 13410425
 * IMAP_manager.hpp - communication with IMAP server related things
 * Date: 04 May 2015
 */

#include "Protocol_manager.hpp"
// #include "debug.hpp"
#include "Email.hpp"

class IMAP_manager : public Protocol_manager {
    private:
        std::string get_next_tag();
        std::string prepare_cmd(const std::string cmd);

    public:
        IMAP_manager(const std::string machine_port);
        ~IMAP_manager();

};

#endif /* end of include guard: IMAP_MANAGER_H */
