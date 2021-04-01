//main file for Coursework 2
/************************************************************************
University of Leeds
School of Computing
COMP1921 - Programming Project
Coursework 1

I confirm that the following code has been developed and written by me and it is entirely the result of my own work.
I also confirm that I have not copied any parts of this program from another person or any other source or facilitated someone to copy this program from me.
I confirm that I will not publish the program online or share it with anyone without permission of the module leader.

Student Name: Shrawan Sreekumar
Student ID : 201398821
Email: el20ss@leeds.ac.uk
Date Work Commenced: 19th March 2021
*************************************************************************/
//additional headers
#include "Game_main.h"
//************************************************************************
//global varaibles

//************************************************************************

void main(int argc, char** argv){
    /*Initialise SDL*/
    start_window();
    do{
        draw_cells();
        draw_grid();
        evolve_cells();
        SDL_Delay(1000);
    }   while(is_game_over() == 0 && Game_generation--);

    FILE* ptrs = fopen("savestate.txt","w+");
    save_status(ptrs);
    
    end_cleanup();
}
