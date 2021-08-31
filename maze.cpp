//
// Created by Ricky Saputra on 2/3/2020
//

#include "maze.h"
#include <fstream>
#include <iostream>
#include <sstream>

//To print out
ostream &operator<<(ostream &out, const Maze &maze) {
    for (int row = 0; row < maze.height; row++) {
        for (int col = 0; col < maze.width; col++) {
            out << maze.field[row][col];
        }

        out << endl;
    }

    out << endl;

    return out;
}

// For CLion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
Maze::Maze(const string &fileName) : field{{0}}, width{0}, height{0}, exitRow{0}, exitColumn{0} {
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    inFile >> width >> height;
    inFile >> exitRow >> exitColumn;

    string str;
    getline(inFile, str);
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
            inFile.get(field[row][col]);
            // cout << row << ", " << col << ": " << field[row][col] << endl;
        }

        getline(inFile, str);
    }
}

//to exit in row
int Maze::getExitRow() const {
    return exitRow;
}

//to exit in column
int Maze::getExitColumn() const {
    return exitColumn;
}

//to mark ' ' if the path will be clear
bool Maze::isClear(int row, int col) const {
    return field[row][col] == ' ';
}

//Mark * if the path is visits
bool Maze::visit(int row, int col) const {
    return field[row][col] == '*';
}

//To mark the path *
void Maze::markAsPath(int row, int col) {
    field[row][col] = '*';
}

//Mark + if the path has been visited
void Maze::markAsVisited(int row, int col) {
    field[row][col] = '+';
}

