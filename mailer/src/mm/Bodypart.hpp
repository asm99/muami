#ifndef BODYPART_H
#define BODYPART_H

#include "Bodystructure.hpp"

/* E-mail body part */
class Bodypart {
    public:
        std::string section;
        Bodystructure* bodystructure;
        Bodypart* sibling;
        Bodypart* child;

        Bodypart() {};
        ~Bodypart() {};
};

#endif /* end of include guard: BODYPART_H */
