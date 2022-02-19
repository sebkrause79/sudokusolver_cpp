#ifndef SUDOKU_H
#define SUDOKU_H


#include <iostream>
#include <vector>
#include "Error.hpp"
#include "Cell.hpp"

using namespace std;

class Sudoku {
protected:
    int su_size;
    int su_size_root;
    vector<vector<Cell>> cells;
    vector<Cell> available_cells;

    Sudoku(int size);
public:
    static Sudoku SudokuLoader(std::string filename);
    virtual void print();
};


enum SudokuType { REGULAR, X, HYPER, COLOR };

#endif
