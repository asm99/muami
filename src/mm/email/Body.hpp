/*
 * MELKONIAN Marc
 * IED 13410425
 * Body.hpp: a BODY part of a message in the RFC3501 grammar
 */

#ifndef BODY_H
#define BODY_H

#include <sstream>
#include "Bodypart.hpp"

using namespace std;

typedef enum Body_type {
    Body_type_1part = 0,
    Body_type_mpart,
} Body_type;

class Body
{
    public:
        Body_type type;
        string mbody_subtype;
        string section;
        Body* sibling;
        Body* child;
        Bodypart* bodypart;

        Body();
        ~Body();

        void dump();
};

#endif /* end of include guard: BODY_H */
