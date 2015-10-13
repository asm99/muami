#ifndef BODY_FIELDS_H
#define BODY_FIELDS_H

#include <sstream>
#include "Body_params.hpp"
#include "Nstring.hpp"
#include "../coding/coding.hpp"

using namespace std;

/*
 *  body-fields     = body-fld-param SP body-fld-id SP body-fld-desc SP
 *                    body-fld-enc SP body-fld-octets
 *  body-fld-param  = "(" string SP string *(SP string SP string) ")" / nil
 *  body-fld-id     = nstring
 *  body-fld-desc   = nstring
 *  body-fld-enc    = (DQUOTE ("7BIT" / "8BIT" / "BINARY" / "BASE64"/
 *                    "QUOTED-PRINTABLE") DQUOTE) / string
 *  body-fld-octets = number
 */

class Body_fields
{
    private:
        Nstring body_fld_id;
        Nstring body_fld_desc;
        Body_params* body_fld_param;
        Encoding body_fld_enc;
        unsigned long body_fld_octets;

    public:
        Body_fields();
        ~Body_fields() {};

        // Setters
        void set_id(const Nstring& id);
        void set_desc(const Nstring& desc);
        void set_enc(const Encoding enc);
        void set_octets(const unsigned long octets);

        // Getters
        string id();
        string desc();
        Body_params* params();
        Encoding enc();
        unsigned long octets();

        // DEBUG
        void dump();
};

stringstream& operator>>(stringstream& ss, Body_fields* bf);

#endif /* end of include guard: BODY_FIELDS_H */
