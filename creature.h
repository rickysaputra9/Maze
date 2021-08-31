//
// Created by Ricky Saputra on 2/3/2020
//

#pragma once

#include "maze.h"
#include <ostream>

class Creature {
public:
    friend ostream &operator<<(ostream &out, const Creature &creature);

    //public function for Creature,solve and atExit
public:
    Creature(int row, int col);

    string solve(Maze &maze);

    bool atExit(const Maze &maze) const;


    //A private for the row, col and the path
private:
    int row;
    int col;
    string path;
};
