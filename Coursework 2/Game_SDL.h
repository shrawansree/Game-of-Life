#ifndef GAME_SDL_GUARD__H 
#define GAME_SDL_GUARD__H 

#define SDL_MAIN_HANDLED

#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_timer.h"
#include "SDL2/include/SDL2/SDL_image.h"
//global varaiables
#define CELL_SIZE 40

void start_window(int type);
//starts and initialises SDL environment

void draw_grid();
//draws the game grid

void draw_cells();
//draws the cells onto the grid

void end_cleanup();
//destroys SDL enviroment

int check_event();
//checks for user save 

#endif