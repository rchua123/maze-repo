# Maze

Goals: Understanding recursion, solving mazes, working with multiple ADTs

For this assignment, you will write a program that can solve a maze. The problem description is 
taken from Carrano Chapter 5 Problem 9 (Carrano Chapter 5, Problem 4 in 6th edition) which is 
linked to this assignment.

The maze is provided by a text file in the following format:

`20  7
0  18`

`xxxxxxxxxxxxxxxxxx  x 
x     x      xxxx x 
x xxxxx xxxxx  xx x 
x xxxxx xxxxxxx xx x 
x x          xx xx  x
x  xxxxxxxxxx  xx  x 
xxxxxxxxxxxxxxxxxxxx`

The first 2 numbers are: `width-of-maze` `height-of-maze`
The next 2 numbers are: `row-exit` `column-exit` 
`x`     represents wall
`space` represents movable space

Unlike the textbook version, the entrance to the Maze is not specified as part of the maze.txt file 
but will be provided by Creature's location

When maze is printed, you should also add
`*` part of the path to exit
`+` visited square not part of the path to  exit



## Compile and Run

```
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp -o assignment3
./assignment3
```

