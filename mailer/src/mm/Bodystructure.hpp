#ifndef BODYSTRUCTURE_H
#define BODYSTRUCTURE_H

#include <iostream>

/*
 * doc: http://tools.ietf.org/html/rfc3501#page-73
 */
class Bodystructure {
    public:
        int size;
        std::string type;
        std::string subtype;
        std::string id;
        std::string description;
        std::string encoding;
//         char** parameters;
//         extension_parameters* extension_parameters;

        Bodystructure() {};
        ~Bodystructure() {};

        void dump_bodystructure(Bodystructure* bs);
};

#endif /* end of include guard: BODYSTRUCTURE_H */
