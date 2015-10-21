/*
 * MELKONIAN Marc
 * IED 13410425
 * Body.hpp: a BODY part of a message in the RFC3501 grammar
 *
 * Doc: https://tools.ietf.org/html/rfc3501#section-9
 *
 * Grammar:
 * -------
 *
 *  body-ext-mpart  = body-fld-param [SP body-fld-dsp [SP body-fld-lang
 *                    [SP body-fld-loc *(SP body-extension)]]]
 *                      ; MUST NOT be returned on non-extensible
 *                      ; "BODY" fetch
 *
 *  body-fields     = body-fld-param SP body-fld-id SP body-fld-desc SP
 *                    body-fld-enc SP body-fld-octets
 *
 *  body-fld-desc   = nstring
 *
 *  body-fld-dsp    = "(" string SP body-fld-param ")" / nil
 *
 *  body-fld-enc    = (DQUOTE ("7BIT" / "8BIT" / "BINARY" / "BASE64"/
 *                    "QUOTED-PRINTABLE") DQUOTE) / string
 *
 *  body-fld-id     = nstring
 *
 *  body-fld-lang   = nstring / "(" string *(SP string) ")"
 *
 *  body-fld-loc    = nstring
 *
 *  body-fld-lines  = number
 *
 *  body-fld-md5    = nstring
 *
 *  body-fld-octets = number
 *
 *  body-fld-param  = "(" string SP string *(SP string SP string) ")" / nil
 *
 *  body-type-1part = (body-type-basic / body-type-msg / body-type-text)
 *                    [SP body-ext-1part]
 *
 *  body-type-basic = media-basic SP body-fields
 *                      ; MESSAGE subtype MUST NOT be "RFC822"
 *
 *  body-type-mpart = 1*body SP media-subtype
 *                    [SP body-ext-mpart]
 *
 *  body-type-msg   = media-message SP body-fields SP envelope
 *                    SP body SP body-fld-lines
 *
 *  body-type-text  = media-text SP body-fields SP body-fld-lines
 *
 *  body            = "(" (body-type-1part / body-type-mpart) ")"
 *
 *  body-extension  = nstring / number /
 *                     "(" body-extension *(SP body-extension) ")"
 *                      ; Future expansion.  Client implementations
 *                      ; MUST accept body-extension fields.  Server
 *                      ; implementations MUST NOT generate
 *                      ; body-extension fields except as defined by
 *                      ; future standard or standards-track
 *                      ; revisions of this specification.
 *
 *  body-ext-1part  = body-fld-md5 [SP body-fld-dsp [SP body-fld-lang
 *                    [SP body-fld-loc *(SP body-extension)]]]
 *                      ; MUST NOT be returned on non-extensible
 *                      ; "BODY" fetch
 *
 *
 *  media-basic     = ((DQUOTE ("APPLICATION" / "AUDIO" / "IMAGE" /
 *                    "MESSAGE" / "VIDEO") DQUOTE) / string) SP
 *                    media-subtype
 *                      ; Defined in [MIME-IMT]
 *
 *  media-message   = DQUOTE "MESSAGE" DQUOTE SP DQUOTE "RFC822" DQUOTE
 *                      ; Defined in [MIME-IMT]
 *
 *  media-subtype   = string
 *                      ; Defined in [MIME-IMT]
 *
 *  media-text      = DQUOTE "TEXT" DQUOTE SP media-subtype
 *                      ; Defined in [MIME-IMT]
 *
 */

// typedef enum Body_type {
//     Body_type_1part = 0,
//     Body_type_mpart,
// } Body_type;

// struct body_type_basic {
//     string type;
//     string subtype;
//     struct body_fields* fields;
// } body_type_basic;
//
// struct body_type_msg {
//     string type;
//     string subtype;         // Can be "RFC822" only if type is "MESSAGE"
//     struct body_fields* fields;
//     Envelope* envelope;     // only for body-type-msg
//     Body* body;             // only for body-type-msg
//     int body_fld_lines;     // for body-type-msg and body-type-text
// } body_type_msg;
//
// struct body_type_text {
//     string type;
//     string subtype;
//     struct body_fields* fields;
//     int body_fld_lines;
// } body_type_text;
//
// enum Body_Type_1part_Elements {
//     BODY = 0,
//     BODY_EXTENSION,
//     BODY_FLD_DESC,
//     BODY_FLD_DSP,
//     BODY_FLD_ENC,
//     BODY_FLD_ID,
//     BODY_FLD_LANG,
//     BODY_FLD_LINES,
//     BODY_FLD_LOC,
//     BODY_FLD_MD5,
//     BODY_FLD_OCTETS,
//     BODY_FLD_PARAM,
//     ENVELOPE,
//     MEDIA_SUBTYPE,
//     MEDIA_TYPE,
// }

#ifndef BODYPART_H
#define BODYPART_H

#include <vector>
#include "Body_fields.hpp"
#include "Body_ext_1part.hpp"
#include "Body_ext_mpart.hpp"
#include "Envelope.hpp"
#include "../util/util.hpp"
// #include "Body.hpp"

using namespace std;

typedef enum Body_1part_type {
    BODY_1PART_TYPE_BASIC = 0,
    BODY_1PART_TYPE_MSG,
    BODY_1PART_TYPE_TEXT,
    BODY_1PART_TYPE_UNKNOWN,
} Body_1part_type;

class Bodypart
{
    private:
        Body_1part_type body_1part_type;
        string media_type;
        string media_subtype;           // "RFC822" only if type is "MESSAGE"
        Body_fields* body_fields;
        Body_ext_1part* body_ext_1part;
        Body_ext_mpart* body_ext_mpart;
//         Envelope bp_envelope;           // only for body-type-msg
//         Body* bp_body;                  // only for body-type-msg
        unsigned long body_fld_lines;   // for body-type-msg and body-type-text

    public:
        // Exceptions
        class Bodypart_Type_Unknown {};
        class Bodypart_Subtype_Mismatch {};

        // Constructors & Destructors
        Bodypart();
        ~Bodypart() {};

        // Setters
        void set_type(const string& s);
        void set_subtype(const string& s); // "RFC822" only if type is "MESSAGE"
        void set_lines(unsigned long ul);
        void set_body_1part_type(const string& s);

        // Getters
        Body_1part_type body_type();
        string type();
        string subtype();
        unsigned long lines();
        Body_fields* fields();
        Body_ext_1part* ext_1part();
        Body_ext_mpart* ext_mpart();
//         Envelope& envelope();
//         Body* body();

        // DEBUG
        void dump();
};

stringstream& operator>>(stringstream& ss, Bodypart* bp);

#endif /* end of include guard: BODYPART_H */
