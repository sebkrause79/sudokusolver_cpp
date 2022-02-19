#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
private:
    int value;
    int x, y;
public:
    bool setValue(int val);
    int getValue();
    Cell(int x, int y);
    Cell();
    std::string toString();
};

#endif
