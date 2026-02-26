#include "stem.h"
#include "zero.h"
#include "cell.h"
#include <iostream>

stem::stem(float x, float y, cell* parent) : cell(x, y, parent) {
    std::cout << "Stem created at (" << x << "," << y << ")\n";
}

stem::~stem() {
    std::cout << "Stem at (" << getX() << "," << getY() << ") destroyed\n";
}

void stem::grow() {
    zero* z = (zero*)getRoot();
    DATA currentData = getData();

    if (z->spend(2.0f, 1.0f)) {
        createChild(currentData.x, currentData.y + 1.0, CELL_STEM);
    }
}

void stem::tick() {
    if (!isAlive()) return;

    grow();
    cell::tick();  // дети
}