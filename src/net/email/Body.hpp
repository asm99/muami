/*
 * MELKONIAN Marc
 * IED 13410425
 * Body.hpp: a class for representing a BODY part of a message in the
 *           RFC3501 grammar
 */

#ifndef BODY_H
#define BODY_H

#include <sstream>
#include <vector>
#include "Bodypart.hpp"

using namespace std;

typedef enum Body_type {
    Body_type_1part = 0,
    Body_type_mpart,
} Body_type;

class Body
{
    private:
        void copy(const Body* b);       // Copy function

    public:
        Body_type type;
        string mbody_subtype;
        string section;
        Bodypart* bodypart;
        vector<Body*> subparts;

        // Constructors & destructor
        Body();                         // default constructor
        Body(const Body* b);            // copy constructor
//         Body* operator=(const Body* b); // assignment operator
        ~Body();                        // default destructor

        // DEBUG
        void dump(int depth=0);
};

#endif /* end of include guard: BODY_H */
