/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */


#define VERSION 0.01

#include <iostream>
#include "Sudoku.hpp"

using namespace std;

    void usage(char* scriptname) {
        cout << "Sudoku parser v" << VERSION << endl
            << "Usage: " << scriptname << " FILENAME" << endl
            << "Seb. Schauer 2022" << endl;
    }

    int main(int argc, char **argv)
    {
        if (argc != 2) {
            usage(argv[0]);
            cout << "Need exactly one parameter (the filename)!" << endl << "Exiting Sudoku solver." << endl;
            return 1;
        }
        try {
            Sudoku sudoku = Sudoku::SudokuLoader(argv[1]);
            sudoku.print();
        } catch (std::exception& e) {
            cout << e.what() << endl << "Exiting Sudoku solver." << endl;
            return 1;
        }

        return 0;
    }

