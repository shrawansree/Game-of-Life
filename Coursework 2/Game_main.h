#ifndef GAME_MAIN_GUARD__H 
#define GAME_MAIN_GUARD__H 

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "Game_SDL.h"
#include "Game_logic.h" 
#include "Game_interface.h"

#define for_row for (int row = 0; row < MaxCol; row++)
#define for_col for (int col = 0; col < MaxRow; col++)
#define for_row_col for_col for_row 
#define MAX_STRING 1024
#define INT_LIMIT 9999

extern int **grid;
extern int Game_generation;
extern int MaxRow;
extern int MaxCol;

extern SDL_bool is_started;

#endif