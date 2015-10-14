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

//     if (bp->bodystructure) {
//         debug("type/subtype [section]: "
//             + bp->bodystructure->type
//             + "/" + bp->bodystructure->subtype
//             + " [" << bp->section << "]");
//     }

    if (type == Body_type_mpart) {
        debug("mbody subtype: " + mbody_subtype);
    }

    cout << "section: " << section << endl;
    if (child)
        child->dump();
    if (sibling)
        sibling->dump();
}
