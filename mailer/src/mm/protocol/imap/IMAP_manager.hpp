/*
 * MELKONIAN Marc - 13410425
 * IMAP_manager.hpp - communication with IMAP server related things
 * Date: 04 May 2015
 */

#ifndef IMAP_MANAGER_H
#define IMAP_MANAGER_H

#include "../Protocol_manager.hpp"
#include "../../email/Email.hpp"

using namespace std;

class IMAP_manager : public Protocol_manager
{
    private:
        string get_next_tag();
        string prepare_cmd(const string cmd);

    public:
        IMAP_manager(const string machine_port);
        ~IMAP_manager();
};

#endif /* end of include guard: IMAP_MANAGER_H */
