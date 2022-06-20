/*
 * Name: Ryan Chua
 * Class: assignment3.cpp
 * Tester class.
 */

#include <iostream>
#include <string>
#include "Maze.h"
#include "Creature.h"

using namespace std;

void Test1(){
    
    Maze m("mazeSimple.txt");
    cout << "Width: " << m.getWidth() << endl;
    cout << "Height: " << m.getHeight() << endl;
    cout << "RowExit: " << m.getRowExit() << endl;
    cout << "ColumnExit: " << m.getColumnExit() << endl;
    cout << m;
    cout << "Clear?: " << m.IsClear(1,2) << endl;
    cout << "Wall?: " << m.IsWall(0,0) << endl;
    
    Creature c(0,0);
    cout << "Creature location: " << c << endl;
    c.GoSouth(m);
    cout << m;
    cout << "Creature end Location: " << c << endl;
    cout << "Path to exit: " << c.Solve(m) << endl;
    cout << "Visited?: " << m.IsVisited(3,4) << endl;
    cout << "Path?: " << m.IsPath(3,4) << endl; 
    cout << endl;
}

void Test2(){
    Maze m("maze.txt");
    cout << "Width: " << m.getWidth() << endl;
    cout << "Height: " << m.getHeight() << endl;
    cout << "RowExit: " << m.getRowExit() << endl;
    cout << "ColumnExit: " << m.getColumnExit() << endl;
    cout << m;
    
    Creature c(4,4);
    cout << "Creature location: " << c << endl;
    c.GoSouth(m);
    cout << m;
    cout << "Creature end Location: " << c << endl;
    cout << "Path to exit: " << c.Solve(m) << endl;
    cout << endl;
}

void Test3(){
    Maze m("mazeNoExit1.txt");
    cout << "Width: " << m.getWidth() << endl;
    cout << "Height: " << m.getHeight() << endl;
    cout << "RowExit: " << m.getRowExit() << endl;
    cout << "ColumnExit: " << m.getColumnExit() << endl;
    cout << m;
    
    Creature c(1,1);
    cout << "Creature location: " << c << endl;
    c.GoSouth(m);
    cout << m;
    cout << "Creature end Location: " << c << endl;
    cout << "Path to exit: " << c.Solve(m) << endl;
    cout << endl;
}
void Test4(){
    Maze m("maze0.txt");
    cout << "Width: " << m.getWidth() << endl;
    cout << "Height: " << m.getHeight() << endl;
    cout << "RowExit: " << m.getRowExit() << endl;
    cout << "ColumnExit: " << m.getColumnExit() << endl;
    cout << m;
    
    Creature c(3,1);
    cout << "Creature location: " << c << endl;
    c.GoSouth(m);
    cout << m;
    cout << "Creature end Location: " << c << endl;
    cout << "Path to exit: " << c.Solve(m) << endl;
    cout << endl;
}

void Test5(){
    Maze m("Prac.txt");
    cout << "Width: " << m.getWidth() << endl;
    cout << "Height: " << m.getHeight() << endl;
    cout << "RowExit: " << m.getRowExit() << endl;
    cout << "ColumnExit: " << m.getColumnExit() << endl;
    cout << m;
    
    Creature c(2,1);
    cout << "Creature location: " << c << endl;
    c.GoSouth(m);
    cout << m;
    cout << "Creature end Location: " << c << endl;
    cout << "Path to exit: " << c.Solve(m) << endl;
    cout << endl;
}
void TestAll(){
    Test1();
    Test2();
    Test3();
    Test4();
    //Test5();
}

int main(){
    TestAll();
    return 0;
}