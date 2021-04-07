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
    SDL_SetRenderDrawColor(gameRender, 255, 0,
                               0, SDL_ALPHA_OPAQUE);

    for (int i = 0; i <= (1 + MaxRow * CELL_SIZE) ; i += CELL_SIZE) {
        SDL_RenderDrawLine(gameRender, i, 0, i,window_height);
    }

    for (int j = 0; j <= (1 + MaxCol * CELL_SIZE) ; j += CELL_SIZE) {
        SDL_RenderDrawLine(gameRender, 0, j, window_width, j);
    }

    SDL_RenderPresent(gameRender);
}

void start_window(int type){
    //initialise SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
        printf("Error initializing SDL : %s\n", SDL_GetError());
        exit(1);
    }

    //create window and renderer
    printf("SDL successfully initialised!\n");
 
    //load data from file
    if(type == 0){
        FILE *ptrL = fopen("savestate.txt","r+");
        load_status(ptrL);
    }
    else if(type == 1){
        FILE *ptrL = fopen("loadstate.txt","r+");
        load_status_new(ptrL);
    }

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
}

void draw_cells(){
    //fills grid with cells 
    SDL_SetRenderDrawColor(gameRender, 20, 20, 20, 255);
    SDL_RenderClear(gameRender);

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

int check_event(){
    //checks for save events from user

    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
            //different user input events
            case SDL_KEYDOWN:{
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:{
                        end_cleanup();
                    }

                    case SDLK_s:{
                        FILE* ptrs = fopen("savestate.txt","w+");
                        save_status(ptrs);
                        break;
                    }

                    case SDLK_r:{
                        reset_grid();
                        break;
                    }

                    case SDLK_SPACE:{
                        if(!is_started){
                            is_started = !is_started;
                        }
                        break;
                    }

                    case SDLK_l:{
                        end_cleanup();
                        start_window(1);
                        break;
                    }

                    default:
                        break;
                }
                break;
            }

            case SDL_MOUSEBUTTONDOWN:{
                if(is_started == 0){
                    int sel_col = (event.motion.x / CELL_SIZE);
                    int sel_row = (event.motion.y / CELL_SIZE);
                    if(grid[sel_row][sel_col] == 0){
                        grid[sel_row][sel_col] = 1;
                    }
                    else{
                        grid[sel_row][sel_col] = 0;
                    }
                }
                break;
            }

            default:
                break;
        }
    }

    return 1;
}