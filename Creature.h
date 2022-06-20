/*
 * Name: Ryan Chua
 * Class: Creature.h
 * This Creature header file includes all of the methods and private variables used in the cpp 
 * file.
 */
#ifndef CREATURE_H
#define CREATURE_H

#include "Maze.h"

using namespace std;

class Creature{
    public:
        //Creature constructor takes starting position
        Creature(int row, int column);

        //Creature Movement methods
        bool GoNorth(Maze& maze);
        bool GoSouth(Maze& maze);
        bool GoEast(Maze& maze);
        bool GoWest(Maze& maze);

        //Solve method
        string Solve(Maze& maze);
        
        friend ostream &operator<<(ostream& out, const Creature& creature);

        //Getters
        int getRow() const;
        int getColumn() const;

        
    private:
        //Varaibles
        int row;
        int column;

        string solvePath; //Used to concatenate path to exit.

        //Methods
        bool NotValidStart(Maze& maze) const;
        
};
#endif