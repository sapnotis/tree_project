#include "stem.hpp"
#include "cell.hpp"

stem::stem(Coords coords, cell* parent) : cell(coords, parent) { }

stem::~stem() { }

void stem::tick() {
    for (unsigned int i=0; i < this->children.size(); i++)
        children[i]->tick();
    
    if ( this->alive )
        spread();
}

void stem::spread() {
    
}