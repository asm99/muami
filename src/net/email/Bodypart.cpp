#include "Bodypart.hpp"

// Constructor
Bodypart::Bodypart()
//     :bp_envelope()
{
    body_fields = new Body_fields();
    body_ext_1part = new Body_ext_1part();
    body_ext_mpart = new Body_ext_mpart();
//     bp_body = new Body();
}

// Setters
void
Bodypart::set_body_1part_type(const string& s)
{
    if (s == "text") {
        body_1part_type = BODY_1PART_TYPE_TEXT;
    }
    else if (s == "message") {
        body_1part_type = BODY_1PART_TYPE_MSG;
    }
    else if (s == "application"
             || s == "audio"
             || s == "image"
             || s == "message"
             || s == "video") {
        body_1part_type = BODY_1PART_TYPE_BASIC;
    }
    else {
        body_1part_type = BODY_1PART_TYPE_UNKNOWN;
        throw Bodypart::Bodypart_Type_Unknown();
    }
}

void
Bodypart::set_type(const string& s)
{
    media_type = s;
}

void
Bodypart::set_subtype(const string& s)
{
    media_subtype = s;
}

void
Bodypart::set_lines(unsigned long ul)
{
    body_fld_lines = ul;
}

// Getters
Body_1part_type
Bodypart::body_type()
{
    return body_1part_type;
}

string
Bodypart::type()
{
    return media_type;
}

string
Bodypart::subtype()
{
    return media_subtype;
}

unsigned long
Bodypart::lines()
{
    return body_fld_lines;
}

Body_fields*
Bodypart::fields()
{
    return body_fields;
}

Body_ext_1part*
Bodypart::ext_1part()
{
    return body_ext_1part;
}

Body_ext_mpart*
Bodypart::ext_mpart()
{
    return body_ext_mpart;
}

// Envelope&
// Bodypart::envelope()
// {
//     return bp_envelope;
// }

// Operator overload
stringstream&
operator>>(stringstream& ss, Bodypart* bp)
{
    string token;
    string type, subtype;

    ss >> type >> subtype;

    util::lower(type);
    util::lower(subtype);

    bp->set_type(util::strip_chars(type, "\""));
    bp->set_body_1part_type(util::strip_chars(type, "\""));
    bp->set_subtype(util::strip_chars(subtype, "\""));

    if (type == "message" && subtype != "rfc822") {
        throw Bodypart::Bodypart_Subtype_Mismatch();
    }

    switch (bp->body_type()) {
        case BODY_1PART_TYPE_TEXT:
        {
            unsigned long ul;
            ss >> bp->fields() >> ul;
            bp->set_lines(ul);
            ss >> bp->ext_1part();
        }
        break;
        case BODY_1PART_TYPE_BASIC:
        {
            ss >> bp->fields();
            ss >> bp->ext_1part();
        }
        break;
        case BODY_1PART_TYPE_MSG:
        {
//  *  body-type-msg   = media-message SP body-fields SP envelope
//  *                    SP body SP body-fld-lines
            ss >> bp->fields();
//             ss >> bp->envelope();

//             vector<Body*> vec {};
//             IMAP_parser::imap_parse_bodystructure(
//                     ss, bp->body(), vec, "1", false);

            unsigned long ul;
            ss >> bp->fields() >> ul;
            bp->set_lines(ul);
        }
        break;
        default:
        break;
    }

    return ss;
}

void
Bodypart::dump()
{
    debug("");
    cout << "+----------------+----------------" << endl
         << "|            Bodypart             " << endl
         << "+----------------+----------------" << endl
         << "| media-type     |" + type()        << endl
         << "| media-subtype  |" + subtype()     << endl;
    fields()->dump();

    switch (body_type()) {
        case BODY_1PART_TYPE_TEXT:
        {
            cout << "+----------------+----------------"      << endl
                 << "| body-fld-lines |" + to_string(lines()) << endl;
        }
        break;
        case BODY_1PART_TYPE_BASIC:
        break;
        case BODY_1PART_TYPE_MSG:
        break;
        default:
        break;
    }


    ext_1part()->dump();
    ext_mpart()->dump();

    cout << "+----------------+----------------\n" << endl;
}
