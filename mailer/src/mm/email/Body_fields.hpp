#ifndef BODY_FIELDS_H
#define BODY_FIELDS_H

#include <map>
#include "../codings/codings.hpp"

using namespace std;

// body-fields     = body-fld-param SP body-fld-id SP body-fld-desc SP
//                   body-fld-enc SP body-fld-octets
// body-fld-param  = "(" string SP string *(SP string SP string) ")" / nil
// body-fld-id     = nstring
// body-fld-desc   = nstring
// body-fld-enc    = (DQUOTE ("7BIT" / "8BIT" / "BINARY" / "BASE64"/
//                   "QUOTED-PRINTABLE") DQUOTE) / string
// body-fld-octets = number

class Body_fields
{
    private:
        map<string, string> body_fld_param;
        string body_fld_id;
        string body_fld_desc;
        Encoding body_fld_enc;
        int body_fld_octets;

    public:
        Body_fields();
        ~Body_fields();

        // Setters
        void set_param(const string& name, const string& value);
        void set_id(const string& id);
        void set_desc(const string& desc);
        void set_enc(const Encoding enc);
        void set_octets(const int octets);

        // Getters
        string param(const string& name);
        string id();
        string desc();
        Encoding enc();
        int octets();
};

#endif /* end of include guard: BODY_FIELDS_H */
