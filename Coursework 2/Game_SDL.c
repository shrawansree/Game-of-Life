//SDL functions for Game of Life
//game_interface function file
/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 2

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name: Shrawan Sreekumar
Student ID : 201398821
Email: el20ss@leeds.ac.uk
Date Work Commenced: 25th March 2021
*************************************************************************/
//additional headers
#include "Game_main.h"
//************************************************************************
int window_width = 0;
int window_height = 0;

SDL_Rect cell = {
        .x = 0,
        .y = 0,
        .w = CELL_SIZE,
        .h = CELL_SIZE,
};

SDL_Renderer *gameRender;
SDL_Window* gameWindow;

//function implementation
void draw_grid(){
    //sets up and draws grid based on the number of cells present 
    SDL_SetRenderDrawColor(gameRender, 20, 20, 20, 255);
    SDL_RenderClear(gameRender);
    SDL_SetRenderDrawColor(gameRender, 45, 45,
                               45, 255);

    for (int i = 0; i < MaxRow * CELL_SIZE; i += CELL_SIZE) {
        SDL_RenderDrawLine(gameRender, i, 0, i, window_width);
    }

    for (int j = 0; j < MaxCol * CELL_SIZE; j += CELL_SIZE) {
        SDL_RenderDrawLine(gameRender, 0, j, window_height, j);
    }

}

void start_window(){
    //initialise SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
        printf("Error initializing SDL : %s\n", SDL_GetError());
        exit(1);
    }

    //create window and renderer
    printf("SDL successfully initialised!\n");
 
    //load data from file
    FILE *ptrL = fopen("saved_state.txt","r+");
    load_status(ptrL);

    //size of window
    window_width = (MaxRow * CELL_SIZE);
    window_height = (MaxCol* CELL_SIZE);

    SDL_CreateWindowAndRenderer(window_width, window_height,
                    0, &gameWindow, &gameRender);
    if(gameWindow == NULL){
         printf("Error initializing SDL Window\n");
         exit(1);
    }

    SDL_SetWindowTitle(gameWindow, " Game Of Life ");
    return;
}

void end_cleanup(){
    SDL_DestroyRenderer(gameRender);
    SDL_DestroyWindow(gameWindow);
    SDL_Quit();
}

void draw_cells(){
    //fills grid with cells 
    for_row_col{
        SDL_SetRenderDrawColor(gameRender, 20, 20, 20, 255);
        cell.x = col * CELL_SIZE;
        cell.y = row * CELL_SIZE;
        if( grid[row][col] == 1){
            SDL_SetRenderDrawColor(gameRender, 255, 255, 255, 255);
        }
        SDL_RenderFillRect(gameRender, &cell);
    }

    SDL_RenderPresent(gameRender);
    return;
}