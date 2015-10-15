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
 *  body-fld-dsp    = "(" string SP body-fld-param ")" / nil
 *
 *  body-fld-lang   = nstring / "(" string *(SP string) ")"
 *
 *  body-fld-loc    = nstring
 */

#ifndef BODY_EXT_MPART_H
#define BODY_EXT_MPART_H

#include "Body_params.hpp"

class Body_ext_mpart
{
    private:
        Body_params* body_fld_param;
        string body_fld_dsp;
        string body_fld_lang;
        string body_fld_loc;
        string body_extension;

    public:
        Body_ext_mpart();
        ~Body_ext_mpart() {};

        // Setters
        void set_dsp(const string& s);
        void set_lang(const string& s);
        void set_loc(const string& s);
        void set_extension(const string& s);

        // Getters
        string dsp();
        string lang();
        string loc();
        string extension();
        Body_params* params();

        // DEBUG
        void dump();
};

stringstream& operator>>(stringstream& ss, Body_ext_mpart* bem);

#endif /* end of include guard: BODY_EXT_MPART_H */

