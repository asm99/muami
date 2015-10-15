#include "Body.hpp"

// Constructor & destructor
Body::Body()
{
    sibling = nullptr;
    child = nullptr;
    bodypart = new Bodypart();
};

Body::~Body()
{
    delete bodypart;
};

/* Dump a prefix tree of bodys */
void
Body::dump()
{
    if (type == Body_type_mpart) {
        debug("mbody subtype: " + mbody_subtype);
    }

    cout << "section: " << section << endl;
    if (child)
        child->dump();
    if (sibling)
        sibling->dump();
}
