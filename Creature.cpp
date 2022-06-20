/*
 * Name: Ryan Chua
 * Class: Creature.cpp
 * This Creature class creates a creature object that allows the creature to move through the maze.
 * The creature is given a starting location that is starting at a clear block and the creature's 
 * objective is to find the exit using recursive movement calls. Along the creature's journey, the
 * path to the exit will be documented on a string solvePath. If the creature does not find the exit,
 * then solvePath will return "X" indicating its failure.
 */

#include <iostream>
#include <string>
#include "Creature.h"
#include "Maze.h"

using namespace std;

/**
* Creature constructor
* Pre-Conditions: Creature must start on a block in the maze that is clear.
* This constructor instantiates row and column and solvePath.
* @param row y-axis location of block.
* @param column x-axis location of block.
*/
Creature::Creature(int row, int column){
    this->row = row;
    this->column = column;
    solvePath = "";
}

/**
* NotValidStart method
* Pre-Conditions: none.
* This method checks to see if the creature start location is on a wall block or out of bounds. 
* The creature location should only start on a clear block.
* @param maze Creature must determine location based on the maze.
* @return true if the creature starting location is on a wall block, false if creature is on 
*         a clear block.
*/
bool Creature::NotValidStart(Maze& maze) const{
    return maze.IsWall(this->row,this->column) || ((this->row < 0) || (this->row >= maze.getHeight())
    || (this->column < 0) || (this->column >= maze.getWidth()));
}

/**
* GoNorth method
* Pre-Conditions: none.
* This method is a recursive method that moves the creature north (up one row). Calls for other
* directional methods (GoSouth, GoWest, GoEast) when the creature can't go north anymore.
* @param maze uses the current state of the maze to determine the creatures path.
* @return True if the creature made it to the exit. False if otherwise.
*/
bool Creature::GoNorth(Maze& maze){
    bool success = false;
    //First check to see if the creature is at a valid starting location.
    if(NotValidStart(maze)){
        cout << "Creature is not at a valid starting point. Try new location." << endl;
        success = false;
    }
    //Base case to check if creature is at exit.
    else if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
        success = true;
    }
    //If not at exit, then move north if it is a clear block.
    else if(maze.IsClear(this->row - 1, this->column)){
        this->row--; //Move North if it is a clear block.
        maze.MarkAsPath(this->row,this->column);
        solvePath += "N"; //Mark destination 'N' as path to exit.
        if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
            success = true;
        }
        else{
            //Keep going North until it can't anymore. Check if other directions are clear.
            success = GoNorth(maze);
            if(!success){
                success = GoWest(maze);
                if(!success){
                    success = GoEast(maze);
                    if(!success){
                        maze.MarkAsVisited(this->row,this->column); //change path to visited.
                        this->row++; //backtrack.
                        solvePath.pop_back(); //Since it is not part of the path anymore, take it out.
                    }
                }
            }
        }
    }
    /*
     * This else if condition is for when the creature initially tries to move into a wall.
     * Try other directions to see if the other blocks are clear, else the creature is trapped
     * and return false.
     */
    else if(maze.IsWall(this->row - 1, this->column)){
        if(!(maze.IsWall(this->row + 1, this->column)))
            GoSouth(maze);
        else if(!(maze.IsWall(this->row, this->column+1)))
             GoEast(maze);
        else if(!(maze.IsWall(this->row, this->column-1)))
            GoWest(maze);
        else
            success = false;
    }
    else
        success = false;

    return success;
}

/**
* GoSouth method
* Pre-Conditions: none.
* This method is a recursive method that moves the creature south (down one row). Calls for other
* directional methods (GoNorth, GoWest, GoEast) when the creature can't go south anymore. This method
* essentially works the same as GoNorth.
* @param maze uses the current state of the maze to determine the creatures path.
* @return True if the creature made it to the exit. False if otherwise.
*/
bool Creature::GoSouth(Maze& maze){
    bool success = false;
    //First check to see if the creature is at a valid starting location.
    if(NotValidStart(maze)){
        cout << "Creature is not at a valid starting point. Try new location." << endl;
        success = false;
    }
    //Base case to check if creature is at exit.
    else if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
        success = true;
    }
    //If not at exit, then move south if it is a clear block.
    else if(maze.IsClear(this->row + 1, this->column)){
        this->row++; //Move south
        maze.MarkAsPath(this->row,this->column);
        solvePath += "S"; //Mark destination 'S' as path to exit.
        if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
            success = true;
        }
        //Keep going South until it can't anymore. Check if other directions are clear.
        else{
            success = GoSouth(maze);
            if(!success){
                success = GoWest(maze);
                if(!success){
                    success = GoEast(maze);
                    if(!success){
                        maze.MarkAsVisited(this->row,this->column); //change path to visited.
                        this->row--; //backtrack.
                        solvePath.pop_back(); //Since it is not part of the path anymore, take it out.
                    }
                }
            }
        }
    }
    //Else if condition works the same as the one in GoNorth, GoWest, GoEast.
    else if(maze.IsWall(this->row + 1, this->column)){
        if(!(maze.IsWall(this->row - 1, this->column)))
            GoNorth(maze);
        else if(!(maze.IsWall(this->row, this->column+1)))
             GoEast(maze);
        else if(!(maze.IsWall(this->row, this->column-1)))
            GoWest(maze);
        else
            success = false;
    }
    else
        success = false;

    return success;
}

/**
* GoEast method
* Pre-Conditions: none.
* This method is a recursive method that moves the creature east (right one column). Calls for other
* directional methods (GoSouth, GoWest, GoNorth) when the creature can't go east anymore.
* @param maze uses the current state of the maze to determine the creatures path.
* @return True if the creature made it to the exit. False if otherwise.
*/
bool Creature::GoEast(Maze& maze){
    bool success = false;
    //First check to see if the creature is at a valid starting location.
    if(NotValidStart(maze)){
        cout << "Creature is not at a valid starting point. Try new location." << endl;
        success = false;
    }
    //Base case to check if creature is at exit.
    else if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
        success = true;
    }
    //If not at exit, then move east if it is a clear block.
    else if(maze.IsClear(this->row, this->column + 1)){
        this->column++; //Move east
        maze.MarkAsPath(this->row,this->column);
        solvePath += "E"; //Mark destination 'E' as path to exit.
        if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
            success = true;
        }
        //Keep going East until it can't anymore. Check if other directions are clear.
        else{
            success = GoEast(maze);
            if(!success){
                success = GoNorth(maze);
                if(!success){
                    success = GoSouth(maze);
                    if(!success){
                        maze.MarkAsVisited(this->row,this->column); //change path to visited.
                        this->column--; //backtrack
                        solvePath.pop_back(); //Since it is not part of the path anymore, take it out.
                    }
                }
            }
        }
    }
    //Else if condition works the same as the one in GoNorth, GoSouth, GoWest.
    else if(maze.IsWall(this->row, this->column + 1)){
        if(!(maze.IsWall(this->row, this->column - 1)))
            GoWest(maze);
        else if(!(maze.IsWall(this->row - 1, this->column)))
             GoNorth(maze);
        else if(!(maze.IsWall(this->row + 1, this->column)))
            GoSouth(maze);
        else
            success = false;
    }
    else
        success = false;

    return success;
}
bool Creature::GoWest(Maze& maze){
    bool success = false;
    //First check to see if the creature is at a valid starting location.
    if(NotValidStart(maze)){
        cout << "Creature is not at a valid starting point. Try new location." << endl;
        success = false;
    }
    //Base case to check if creature is at exit.
    else if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
        success = true;
    }
    //If not at exit, then move west if it is a clear block.
    else if(maze.IsClear(this->row, this->column - 1)){
        this->column--; //Move west
        maze.MarkAsPath(this->row,this->column);
        solvePath += "W"; //Mark destination 'W' as path to exit.
        if(this->row == maze.getRowExit() && this->column == maze.getColumnExit()){
            success = true;
        }
        //Keep going West until it can't anymore. Check if other directions are clear.
        else{
            success = GoWest(maze);
            if(!success){
                success = GoNorth(maze);
                if(!success){
                    success = GoSouth(maze);
                    if(!success){
                        maze.MarkAsVisited(this->row,this->column); //change path to visited.
                        this->column++; //backtrack
                        solvePath.pop_back(); //Since it is not part of the path anymore, take it out.
                    }
                }
            }
        }
    }
    //Else if condition works the same as the one in GoNorth, GoSouth, GoEast.
    else if(maze.IsWall(this->row, this->column - 1)){
        if(!(maze.IsWall(this->row, this->column + 1)))
            GoEast(maze);
        else if(!(maze.IsWall(this->row - 1, this->column)))
             GoNorth(maze);
        else if(!(maze.IsWall(this->row + 1, this->column)))
            GoSouth(maze);
        else
            success = false;
    }
    else
        success = false;

    return success;
}

/**
* Solve method
* Pre-Conditions: none.
* This method returns a string in the form NSWENW. Where N = North, S = South, W = West,
* and E = East that will let the creature get to the exit.
* @param maze uses the current state of the maze to determine the creatures path.
* @return a string of the path starting at the creatures location.
*/
string Creature::Solve(Maze& maze){
    //If creature cannot get to the exit, return "X".
    if((this->row != maze.getRowExit()) && this->column != maze.getColumnExit())
        solvePath = "X";
    return solvePath;
}

/**
* Overloaded '<<' operator method
* This method prints out the location of the creature in a form of a point: (x,y).
* Pre-Condition: none.
* @param out overloads cout.
* @param creature Creature object that allows the variables/methods in the class to be called.
* @return The location of the creature.
*/
ostream &operator<<(ostream& out, const Creature& creature){
    out << "(" << creature.row << "," << creature.column << ")";
    return out;
}

//Getters
int Creature::getRow() const{
    return row;
}

int Creature::getColumn() const{
    return column;
}