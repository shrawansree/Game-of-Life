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

//function implementation
int load_status(FILE *filename);
    //function to read previous game data from a file
    //returns 0 if successfully read and stored data to program memory
    //returns -1 if error

int save_status(FILE *filename);
    //function to save game data to a file
    //returns 0 if successfully saved data to file
    //returns -1 if error

#endif