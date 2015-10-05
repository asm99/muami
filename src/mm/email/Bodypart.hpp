#ifndef BODYPART_H
#define BODYPART_H

#include "Bodystructure.hpp"

/* E-mail body part */
class Body
{
    public:
        std::string section;
        Bodystructure* bodystructure;
        Body* sibling;
        Body* child;

        Body() {};
        ~Body() {};
};

#endif /* end of include guard: BODYPART_H */
