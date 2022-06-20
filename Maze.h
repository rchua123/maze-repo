/*
 * Name: Ryan Chua
 * Class: Maze.h
 * This Maze header file includes all of the methods and private variables used in the cpp 
 * file.
 */
#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

using namespace std;

class Maze{
    public:
        //Maze constructor requring a valid file name
        explicit Maze(string MazeFile);

        //reads file and fills variables with values
        int readFile(string fileName);

        bool IsClear(int row, int column) const;
        bool IsWall(int row, int column) const;
        bool IsPath(int row, int column) const;
        bool IsVisited(int row, int column) const;
        
        //mark the maze with *
        void MarkAsPath(int row, int column);
        //mark the maze with +
        void MarkAsVisited(int row, int column);
        
        friend ostream &operator<<(ostream& out, const Maze& maze);

        //Getters
        int getWidth() const;
        int getHeight() const;
        int getRowExit() const;
        int getColumnExit() const;

    private:

        //Variables
        int width;
        int height;
        int rowExit;
        int columnExit;
        static const int MAX_SIZE = 100;
        char field[MAX_SIZE][MAX_SIZE];
        vector<int> MazeNumbers; //Store the first four numbers from the maze file.

        //Methods
        void FillIntData(string toFill); 
        bool NotValidSizes() const;

};
#endif