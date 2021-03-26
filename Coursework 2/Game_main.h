#ifndef GAME_MAIN_GUARD__H 
#define GAME_MAIN_GUARD__H 

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "Game_logic.h" 
#include "Game_interface.h"

#define for_row for (int row = 0; row < MaxRow; row++)
#define for_col for (int col = 0; col < MaxCol; col++)
#define for_row_col for_row for_col
#define MAX_STRING 1024
#define INT_LIMIT 9999

//Game storage array
int **grid;
int Game_generation;
int MaxRow;
int MaxCol;

#endif