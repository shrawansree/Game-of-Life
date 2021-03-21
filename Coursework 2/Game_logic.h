#ifndef GAME_LOGIC_GUARD__H 
#define GAME_LOGIC_GUARD__H 

#include <stdio.h> 
#include <stdlib.h> 

#define for_row for (int row = 0; row < MaxRow; row++)
#define for_col for (int col = 0; col < MaxCol; col++)
#define for_row_col for_row for_col
#define MAX_STRING 1024

//Game storage array
int **grid;
int MaxRow;
int MaxCol;



#endif