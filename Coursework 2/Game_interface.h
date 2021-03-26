#ifndef GAME_INTERFACE_GUARD__H 
#define GAME_INTERFACE_GUARD__H 


const char* returnString(const char *prompt);
    //function to return string

int returnInt(const char *prompt);
    //returns int input from user

void reset_grid();
    //resets the grid to all empty cells

void show_grid();
    //displays the grid on the cli

#endif