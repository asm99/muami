#include "Body.hpp"

// Constructor & destructor

// Default constructor
Body::Body()
    :subparts()
{
    bodypart = new Bodypart();
}

// Copy constructor
Body::Body(const Body* b)
{
    bodypart = new Bodypart();
    copy(b);
}

// Copy function
void
Body::copy(const Body* b)
{
    type = b->type;
    mbody_subtype = b->mbody_subtype;
    section = b->section;
    *bodypart = *(b->bodypart);
}

// // Copy assignment
// Body*
// Body::operator=(const Body* b)
// {
//     Bodypart* bp = new Bodypart();
//     copy(b);
//     delete bodypart;
//     bodypart = bp;
//     return this;
// }

Body::~Body()
{
    delete bodypart;
}

/* Dump a tree of bodys */
void
Body::dump(int depth)
{
    int padding_left = depth*2;
    char sep = ' ';

    cout << string(padding_left, sep) << "section: " << section;

    if (type == Body_type_mpart) {
        cout << " - mbody subtype: " + mbody_subtype
             << endl;
        depth += 1;
        padding_left *=2;
        cout << string(padding_left, sep)
             << "subparts START n°" << depth
             << endl;

        for (auto b : subparts) {
            b->dump(depth);
        }

        cout << string(padding_left, sep)
             << "subparts END n°" << depth
             << endl;
    }
    else {
        cout << string(padding_left, sep)
             << " - body type, subtype: " + bodypart->type()
                + ", " + bodypart->subtype()
             << endl;
    }

//     bodypart->dump();
}
