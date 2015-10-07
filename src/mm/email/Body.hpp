#ifndef BODY_H
#define BODY_H

#include "Bodystructure.hpp"

/* E-mail body part */
class Body
{
    public:
        std::string section;
        Bodystructure* bodystructure;
        Body* sibling;
        Body* child;

        Body() { sibling = nullptr; child = nullptr; };
        ~Body() {};
};

#endif /* end of include guard: BODY_H */
