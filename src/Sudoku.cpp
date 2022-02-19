#include "Sudoku.hpp"
#include "sudokutypes/Regular.hpp"
#include "sudokutypes/X.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <set>

#include <unistd.h>
#include <stdio.h>

using namespace std;

bool set_contains(std::set<int> set, int val) {
    return set.find(val) == set.end();
}

Sudoku::Sudoku(int su_size) {
    this->su_size = su_size;
    su_size_root = 0;
    while (su_size_root * (su_size_root) < su_size)
        su_size_root++;
    for (int i = 0; i < su_size; i++) {
        vector<Cell> v;
        for (int j = 0; j < su_size; j++) {
            Cell c(i, j);
            v.push_back(c);
        }
        cells.push_back(v);
    }
}

Sudoku Sudoku::SudokuLoader(string filename) {
    set<int> valid_sizes {1, 4, 9, 16, 25, 36};
    fstream f;
    f.open(filename, ios_base::in);
    if (!f.is_open()) {
        throw(FileNotOpenException("Could not open file!"));
    }
    int su_size;
    f >> su_size;
    if (set_contains(valid_sizes, su_size)) {
        stringstream ss;
        ss << "Must have size 1, 4, 9, 16, 25 or 36! Have size " << su_size << " instead.";
        throw(InvalidFile(ss.str()));
    }
    string type;
    f >> type;
    Sudoku result(su_size);
    if (type == "Regular")
        result = RegularSudoku(su_size);
    else if (type == "X")
        result = XSudoku(su_size);
    // TODO add more types here
    else {
        stringstream ss;
        ss << "Unknown Sudoku type '" << type << "'! Must be Regular, X, Color or Hyper.";
        throw(InvalidFile(ss.str()));
    }
    char c;
    int pos = 0;
    while (!f.eof() && pos < su_size * su_size)
    {
        int value;
        f >> value;
        result.cells.at(pos / su_size).at(pos % su_size).setValue(value);
        if (value == 0)
            result.available_cells.push_back(result.cells.at(pos / su_size).at(pos % su_size));
        pos++;
    }
    f.close();
    return result;
}


void Sudoku::print()  {
    for (int i = 0; i < su_size; i++) {
        for (int j = 0; j < su_size; j++) {
            cout << cells.at(i).at(j).toString();
            if (j % su_size_root == su_size_root - 1)
                cout << " ";
        }
        cout << endl;
        if(i % su_size_root == su_size_root - 1)
            cout << endl;
    }
}
