#include "Body_fields.hpp"

// Constructor
Body_fields::Body_fields()
{
    body_fld_param = new Body_params();
}

// Setters
void
Body_fields::set_id(const Nstring& id)
{
    body_fld_id = id;
}

void
Body_fields::set_desc(const Nstring& desc)
{
    body_fld_desc = desc;
}

void
Body_fields::set_enc(const Encoding enc)
{
    body_fld_enc = enc;
}

void
Body_fields::set_octets(const unsigned long octets)
{
    body_fld_octets = octets;
}

// Getters
Body_params*
Body_fields::params()
{
    return body_fld_param;
}

string
Body_fields::id()
{
    return body_fld_id.str();
}

string
Body_fields::desc()
{
    return body_fld_desc.str();
}

Encoding
Body_fields::enc()
{
    return body_fld_enc;
}

unsigned long
Body_fields::octets()
{
    return body_fld_octets;
}

// DEBUG
void
Body_fields::dump()
{
    debug("--- body_fields ---");
    debug("body_fld_id    : " + id());
    debug("body_fld_desc  : " + desc());
    debug("body_fld_enc   : " + to_string(enc()));
    debug("body_fld_octets: " + to_string(octets()));
    params()->dump();
}

stringstream&
operator>>(stringstream& ss, Body_fields* bf)
{
    Nstring tok_id, tok_desc;
    string tok_enc;
    unsigned long ul_octets;

    ss >> bf->params() >> tok_id >> tok_desc >> tok_enc >> ul_octets;

    bf->set_id(tok_id);
    bf->set_desc(tok_desc);
    bf->set_octets(ul_octets);

    util::lower(tok_enc);
    string enc = util::strip_chars(tok_enc, "\"");

    Encoding encoding;

    if      (enc == "7bit")             { encoding = ENC_7BIT; }
    else if (enc == "8bit")             { encoding = ENC_8BIT; }
    else if (enc == "binary")           { encoding = ENC_BINARY; }
    else if (enc == "base64")           { encoding = ENC_BASE64; }
    else if (enc == "quoted-printable") { encoding = ENC_QUOTED_PRINTABLE; }
    else                                { encoding = ENC_UNKNOWN; }

    bf->set_enc(encoding);

    return ss;
}
