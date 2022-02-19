#include "Cell.hpp"
#include <string>

int Cell::getValue() { return value; }

bool Cell::setValue(int val) {
    value = val;
    return true;
}

Cell::Cell(int x, int y) {
    this->x = x;
    this->y = y;
}
Cell::Cell() { x = 0; y = 0; }

std::string Cell::toString() {
    // add color functionality here?
    char c = (value == 0) ? '.' : (
        (value <= 9) ? value + '0' : value - 10 + 'A'
    );
    return std::string(1, c);
}
