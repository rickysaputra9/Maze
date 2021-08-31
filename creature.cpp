//
// Created by Ricky Saputra on 2/3/2020
//

#include "creature.h"

//Current location of creature
ostream &operator<<(ostream &out, const Creature &creature) {
    return out << "C(" << creature.row << ", " << creature.col << ")";
}

//Initialize
Creature::Creature(int row, int col) : row(row), col(col) {}

//This function for the maze at exit
bool Creature::atExit(const Maze &maze) const {
    return col == maze.getExitColumn() && row == maze.getExitRow();
}

string Creature::solve(Maze &maze) {
    //if maze already at exit, return the path
    if (atExit(maze)) {
        return path;
    }

    //if statement if only path is clear
    //if maze goes to W, mark as path
    if (maze.isClear(row, col - 1)) {
        path.append("W");
        maze.markAsPath(row, col);
        col--;
        maze.markAsPath(row, col);
        return solve(maze);
        //if maze goes to E, mark as path
    } else if (maze.isClear(row, col + 1)) {
        path.append("E");
        maze.markAsPath(row, col);
        col++;
        maze.markAsPath(row, col);
        return solve(maze);
        //if maze goes to S, mark as path
    } else if (maze.isClear(row + 1, col)) {
        path.append("S");
        maze.markAsPath(row, col);
        row++;
        maze.markAsPath(row, col);
        return solve(maze);
        //if maze goes to N, mark as path
    } else if (maze.isClear(row - 1, col)) {
        path.append("N");
        maze.markAsPath(row, col);
        row--;
        maze.markAsPath(row, col);
        return solve(maze);
    }

    //Mark visit for West, East, South, North
    if (maze.visit(row, col - 1)) {
        path.pop_back();
        maze.markAsVisited(row, col);
        col--;
        maze.markAsVisited(row, col);
        return solve(maze);
    } else if (maze.visit(row, col + 1)) {
        path.pop_back();
        maze.markAsVisited(row, col);
        col++;
        maze.markAsVisited(row, col);
        return solve(maze);
    } else if (maze.visit(row + 1, col)) {
        path.pop_back();
        maze.markAsVisited(row, col);
        row++;
        maze.markAsVisited(row, col);
        return solve(maze);
    } else if (maze.visit(row - 1, col)) {
        path.pop_back();
        maze.markAsVisited(row, col);
        row--;
        maze.markAsVisited(row, col);
        return solve(maze);
    }
    return path;
}

