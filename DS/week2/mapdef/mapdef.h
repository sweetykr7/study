#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

# include "linkedstack/linkedstack.h"
# include "linkedstack/linkedstack.c"



enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };


void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]); 
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif