/*
 * MELKONIAN Marc - 13410425
 * flags.hpp - Email flags definitions
 * Date: 04 May 2015
 */

#ifndef FLAGS_H
#define FLAGS_H

/*
 * Messages flags
 * Doc: https://tools.ietf.org/html/rfc3501#section-2.3.2
 */
enum Flags {
    FL_ANSWERED  = 0x01,
    FL_FLAGGED   = 0x02,
    FL_DELETED   = 0x04,
    FL_SEEN      = 0x08,
    FL_DRAFT     = 0x10,
    FL_FORWARDED = 0x20,
    FL_MDNSENT   = 0x40,
};

/*
 * Flag wether the client is authorized to modify a mailbox or not.
 */
enum Permissions {
    PERMISSION_READ_WRITE = 0,
    PERMISSION_READ_ONLY,
};

#endif /* end of include guard: FLAGS_H */
