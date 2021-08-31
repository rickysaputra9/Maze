//
// Created by Ricky Saputra on 2/3/2020
//

#include "creature.h"
#include "maze.h"
#include <iostream>

//1st test
void test() {
    Maze m("maze.txt");
//    cout << m << endl;
    Creature c(4, 4);
    cout << "Path: " << c.solve(m) << endl;
    cout << m << endl;
}

//2nd test
void test1() {
    Maze m("maze1.txt");
    // cout << m << endl;
    Creature c(1, 2);
    cout << "Path: " << c.solve(m) << endl;
    cout << m << endl;
}

//3rd test
void test2() {
    Maze m("maze2.txt");
    // cout << m << endl;
    Creature c(4, 12);
    cout << "Path: " << c.solve(m) << endl;
    cout << m << endl;
}

//4th test
void test3() {
    Maze m("maze3.txt");
    // cout << m << endl;
    Creature c(1, 7);
    cout << "Path: " << c.solve(m) << endl;
    cout << m << endl;
}

//This function is to test all the methods above
void testAll() {
    test();
    test1();
    test2();
    test3();
}

int main() {
    testAll();
    cout << "Done!" << std::endl;
    return 0;
}