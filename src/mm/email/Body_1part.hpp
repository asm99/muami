#ifndef BODY_1PART_H
#define BODY_1PART_H

#include "Envelope.hpp"

using namespace std;

namespace Body_1part {

    enum class Type : char {
        BODY_1PART_TYPE_BASIC = 0,
        BODY_1PART_TYPE_MSG,
        BODY_1PART_TYPE_TEXT,
    };

    struct body_type_basic {
        string type;
        string subtype;
        struct body_fields* fields;
    } body_type_basic;

    struct body_type_msg {
        string type;
        string subtype;         // Can be "RFC822" only if type is "MESSAGE"
        struct body_fields* fields;
        Envelope* envelope;     // only for body-type-msg
        Body* body;             // only for body-type-msg
        int body_fld_lines;     // for body-type-msg and body-type-text
    } body_type_msg;

    struct body_type_text {
        string type;
        string subtype;
        struct body_fields* fields;
        int body_fld_lines;
    } body_type_text;

    enum Body_Type_1part_Elements {
        BODY = 0,
        BODY_EXTENSION,
        BODY_FLD_DESC,
        BODY_FLD_DSP,
        BODY_FLD_ENC,
        BODY_FLD_ID,
        BODY_FLD_LANG,
        BODY_FLD_LINES,
        BODY_FLD_LOC,
        BODY_FLD_MD5,
        BODY_FLD_OCTETS,
        BODY_FLD_PARAM,
        ENVELOPE,
        MEDIA_SUBTYPE,
        MEDIA_TYPE,
    }

    // body-type-1part = (body-type-basic / body-type-msg / body-type-text)
    //                   [SP body-ext-1part]


    private:
    // body-type-basic = media-basic SP body-fields
    //                     ; MESSAGE subtype MUST NOT be "RFC822"
    static vector<int> Body_Type_Basic = {
        // --- body-type-1part ---
        MEDIA_TYPE,                 // string
        MEDIA_SUBTYPE,              // string
        // --- body-fields ---
        BODY_FLD_PARAM,             // list
        BODY_FLD_ID,                // nstring
        BODY_FLD_DESC,              // nstring
        BODY_FLD_ENC,               // string
        BODY_FLD_OCTETS,            // number
        // --- body-ext-1part ---
        BODY_FLD_MD5,               // nstring
        BODY_FLD_DSP,               // "(" string SP body-fld-param ")" / nil
        BODY_FLD_LANG,              // nstring / list
        BODY_FLD_LOC,               // nstring
        BODY_EXTENSION,             // *() nstring / number / list
    }

    // body-type-msg   = media-message SP body-fields SP envelope
    //                   SP body SP body-fld-lines
    static vector<int> Body_Type_Msg = {
        // --- body-type-1part ---
        MEDIA_TYPE,                 // must be "MESSAGE"
        MEDIA_SUBTYPE,              // must be "RFC822"
        // --- body-fields ---
        BODY_FLD_PARAM,
        BODY_FLD_ID,
        BODY_FLD_DESC,
        BODY_FLD_ENC,
        BODY_FLD_OCTETS,
        // --- body-type-msg
        ENVELOPE,
        BODY,
        // --- body-type-text
        BODY_FLD_LINES,             // number
        // --- body-ext-1part ---
        BODY_FLD_MD5,
        BODY_FLD_DSP,
        BODY_FLD_LANG,
        BODY_FLD_LOC,
        BODY_EXTENSION,  // *() nstring / number / list
    }

    // body-type-text  = media-text SP body-fields SP body-fld-lines
    static vector<int> Body_Type_Text = {
        // --- body-type-1part ---
        MEDIA_TYPE,
        MEDIA_SUBTYPE,
        // --- body-fields ---
        BODY_FLD_PARAM,
        BODY_FLD_ID,
        BODY_FLD_DESC,
        BODY_FLD_ENC,
        BODY_FLD_OCTETS,
        // --- body-type-text
        BODY_FLD_LINES,             // number
        // --- body-ext-1part ---
        BODY_FLD_MD5,
        BODY_FLD_DSP,
        BODY_FLD_LANG,
        BODY_FLD_LOC,
        BODY_EXTENSION,  // *() nstring / number / list
    }

    public:
        BODY = 0,
        BODY_EXTENSION,
        BODY_FLD_DESC,
        BODY_FLD_DSP,
        BODY_FLD_ENC,
        BODY_FLD_ID,
        BODY_FLD_LANG,
        BODY_FLD_LINES,
        BODY_FLD_LOC,
        BODY_FLD_MD5,
        BODY_FLD_OCTETS,
        BODY_FLD_PARAM,
        ENVELOPE,
        MEDIA_SUBTYPE,
        MEDIA_TYPE,

} // namespace Body_1part

#endif /* end of include guard: BODY_1PART_H */
