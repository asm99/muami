/*
 * MELKONIAN Marc
 * IED 13410425
 * Body_ext_1part.hpp: extension part for a single-part BODY
 *
 * Doc: https://tools.ietf.org/html/rfc3501#section-9
 *
 * Grammar:
 * -------
 *
 *  body-fld-dsp    = "(" string SP body-fld-param ")" / nil
 *
 *  body-fld-lang   = nstring / "(" string *(SP string) ")"
 *
 *  body-fld-loc    = nstring
 *
 *  body-fld-md5    = nstring
 *
 *  body-fld-param  = "(" string SP string *(SP string SP string) ")" / nil
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
 */

#ifndef BODY_EXT_1PART_H
#define BODY_EXT_1PART_H

#include "Body_params.hpp"

using namespace std;

class Body_ext_1part
{
    private:
        string body_fld_md5;
        string body_fld_dsp;
        string body_fld_lang;
        string body_fld_loc;
        string body_extension;

    public:
        Body_ext_1part() {};
        ~Body_ext_1part() {};

        // Setters
        void set_md5(const string& s);
        void set_dsp(const string& s);
        void set_lang(const string& s);
        void set_loc(const string& s);
        void set_extension(const string& s);

        // Getters
        string md5();
        string dsp();
        string lang();
        string loc();
        string extension();

        // DEBUG
        void dump();
};

stringstream& operator>>(stringstream& ss, Body_ext_1part* bep);

#endif /* end of include guard: BODY_EXT_1PART_H */
