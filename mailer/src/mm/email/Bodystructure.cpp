#include "Bodystructure.hpp"

void
Bodystructure::dump_bodystructure(Bodystructure* bs)
{
    std::cout << "--- Bodystructure ---\n"
        << "size: " << bs->size << "\n"
        << "type: " << bs->type << "\n"
        << "subtype: " << bs->subtype << "\n"
        << "id: " << bs->id << "\n"
        << "description: " << bs->description << "\n"
        << "encoding: " << bs->encoding
        << std::endl;
//     char** parameters;
//     extension_parameters* extension_parameters;
}
