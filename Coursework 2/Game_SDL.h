#ifndef GAME_SDL_GUARD__H 
#define GAME_SDL_GUARD__H 

#define SDL_MAIN_HANDLED

#include "SDL2/include/SDL2/SDL.h"
#include "SDL2/include/SDL2/SDL_timer.h"
#include "SDL2/include/SDL2/SDL_image.h"
//global varaiables
#define CELL_SIZE 40

extern int window_height;
extern int window_width;

extern SDL_Renderer *gameRender;
extern SDL_Window* gameWindow;

void start_window();
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