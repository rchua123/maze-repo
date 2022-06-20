/*
 * Name: Ryan Chua
 * Class: Maze.cpp
 * This Maze class reads mazes from a .txt file and fills in the maze using a 2d array. In the 
 * .txt file, the first two lines give the maze's width, height, row-exit, and column-exit
 * which will be read and stored in a private int variable. The methods that this class includes
 * will check if a certain block in the maze is clear, is a wall, is a path, or is visited.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include "Maze.h"

using namespace std;

/**
* Maze constructor
* Pre-Conditions: Maze has to have row and column less than MAX_SIZE which is 100.
* Simply calls the readFile method using the file name to the maze and initiates int variables
* to 0.
* @param MazeFile is a file name string for the maze.
*/
Maze::Maze(string MazeFile){
    width = 0;
    height = 0;
    rowExit = 0;
    columnExit = 0;
    readFile(MazeFile);
}

/**
* readFile Method
* This method reads the file using fstream and fills in the maze from the file into the 
* field multidimensional array. This method also calls the FillIntData to instantiate values for
* int width, height, rowExit and columnExit.
* @param fileName is the name of the maze that is read.
* @return 0 execute success.
*/
int Maze::readFile(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);

    if(myFile.is_open()){
        string line;
        //These four lines reads the first two lines in the file and fills in values for height,width,rowExit,columnExit.
        getline(myFile, line);
        FillIntData(line);
        getline(myFile, line);
        FillIntData(line);
        if(NotValidSizes()){
            cout << "One or more maze parameters is either negative or greater than Max Size." << endl;
        }
        else{
            //fills in multidimensional array 'field' with the maze in the file.
            for(int i = 0; i < height; i++){
                getline(myFile,line);
            
                for(int j = 0; j < width;j++){
                    field[i][j] = line[j];
                }           
            }
        }
        myFile.close();
    }
    else
        cout << "Unable to open file" <<endl;
    return 0;
}
/**
* FillIntData Method
* This method takes the first four numbers in the maze file and stores them in the MazeNumbers
* vector. Then instantiate width, height, rowExit, and columnExit with the values in MazeNumbers.
* @param toFill the line from the file that gets read.
*/
void Maze::FillIntData(string toFill){
    //takes in the string line from the file.
    istringstream is(toFill);
    int numbers;
    //convert string into ints and store the ints into a vector
    while(is >> numbers){
        MazeNumbers.push_back(numbers);
    }
    //Will get called once the first two lines of the file is read.
    if(MazeNumbers.size() == 4){
        width = MazeNumbers.at(0);
        height = MazeNumbers.at(1);
        rowExit = MazeNumbers.at(2);
        columnExit = MazeNumbers.at(3);
    }
}

/**
* private NotValidSizes() Method
* This method checks to see if the first four numbers in the text file is not within
* bounds, i.e. if height is a negative number or more than MAX_SIZES.
* @return true if one of the variables is not within bounds and false if all are within bounds.
*/
bool Maze::NotValidSizes() const{
    return (width < 0 || width > MAX_SIZE) || (height < 0 || height > MAX_SIZE)
           || (rowExit < 0 || rowExit > MAX_SIZE) || (columnExit < 0 || columnExit > MAX_SIZE);
}

/**
* IsClear Method
* This method checks to see if the block in the maze is clear.
* @param row y axis location of block.
* @param column x axis location of block.
* @return true if the block is a space and false if otherwise.
*/
bool Maze::IsClear(int row, int column) const{
    return field[row][column] == ' ';
}

/**
* IsWall Method
* This method checks to see if the block in the maze is a wall.
* @param row y axis location of block.
* @param column x axis location of block.
* @return true if the block is a 'x' and false if otherwise.
*/
bool Maze::IsWall(int row, int column) const{
    return field[row][column] == 'x';
}

/**
* IsPath Method
* This method checks to see if the block in the maze is a path to the exit.
* @param row y axis location of block.
* @param column x axis location of block.
* @return true if the block is a '*' and false if otherwise.
*/
bool Maze::IsPath(int row, int column) const{
    return field[row][column] == '*';
}

/**
* IsVisited Method
* This method checks to see if the block in the maze has been visited.
* @param row y axis location of block.
* @param column x axis location of block.
* @return true if the block is a '+' and false if otherwise.
*/
bool Maze::IsVisited(int row, int column) const{
    return field[row][column] == '+';
}

/**
* MarkAsPath Method
* This method turns the block into '*' when called upon. If the creature steps on the 
* block and it is part of the path, then mark.
* @param row y axis location of block.
* @param column x axis location of block.
*/     
void Maze::MarkAsPath(int row, int column){
    field[row][column] = '*';
}

/**
* MarkAsVisited Method
* This method turns the block into '+' when called upon. If the creature steps on the 
* block and it is clear, then mark as visited.
* @param row y axis location of block.
* @param column x axis location of block.
*/  
void Maze::MarkAsVisited(int row, int column){
    field[row][column] = '+';
}

/**
* Overloaded '<<' operator method
* The maze will output the current state of the maze when it is called. It will loop through
* two for-loops to get all the values in the multidimensional array.
* Pre-Condition: none.
* @param out overloads cout.
* @param maze Maze object that allows the variables/methods in the class to be called.
* @return the current condition of the maze.
*/
ostream &operator<<(ostream& out, const Maze& maze){
    for(int i = 0; i < maze.height; i++){
        for(int j = 0; j < maze.width; j++){
            out << maze.field[i][j];
        }
        out << endl;
    }
    return out;
}

//Getters
int Maze::getWidth() const{
    return width;
}
int Maze::getHeight() const{
    return height;
}
int Maze::getRowExit() const{
    return rowExit;
}
int Maze::getColumnExit() const{
    return columnExit;
}



