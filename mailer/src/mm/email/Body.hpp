#ifndef BODY_H
#define BODY_H

#include "../coding/coding.h"

class Body
{
enum Body_Types {
    BODY_TYPE_1PART,
    BODY_TYPE_MPART,
};

struct body_ext {
    string body_fld_md5;                    // for body-ext-1part
    map<string, string> body_fld_param;     // for body-ext-mpart
    string body_fld_dsp;                    // disposition
    string body_fld_lang;                   // language
    string body_fld_loc;                    // location
//     body-extension  // optional, must be accepted
} body_ext ;


    public:
        Body_1part_Type type;
        string section;
        Body* sibling;
        Body* child;

        Body();
        ~Body();
        void dump() {};
};

#endif /* end of include guard: BODY_H */
