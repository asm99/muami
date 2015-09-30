#include "Body_fields.hpp"

// Default constructor
Body_fields::Body_fields()
{

}

// Default destructor
Body_fields::~Body_fields()
{

}

// Setters
void
Body_fields::set_param(const string& name, const string& value)
{
    body_fld_param[name] = value;
}

void
Body_fields::set_id(const string& id)
{
    body_fld_id = id;
}

void
Body_fields::set_desc(const string& desc)
{
    body_fld_desc = desc;
}

void
Body_fields::set_enc(const Encoding enc)
{
    body_fld_enc = enc;
}

void
Body_fields::set_octets(const int octets)
{
    body_fld_octets = octets;
}

// Getters
string
Body_fields::param(const string& name)
{
    map<string, string>::iterator it = body_fld_param.find(name);
    if (it != body_fld_param.end()) {
        return it->second;
    }
    return "";
}

string
Body_fields::id()
{
    return body_fld_id;
}

string
Body_fields::desc()
{
    return body_fld_desc;
}

Encoding
Body_fields::enc()
{
    return body_fld_enc;
}

int
Body_fields::octets()
{
    return body_fld_octets;
}

