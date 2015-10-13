#include "Body.hpp"

// Constructor
Body::Body()
{
    sibling = nullptr;
    child = nullptr;
    bodypart = new Bodypart();
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

    cout << "section: " << section << endl;
    if (child)
        child->dump();
    if (sibling)
        sibling->dump();
}
