#ifndef GAME_INTERFACE_GUARD__H 
#define GAME_INTERFACE_GUARD__H 

//function implementation
int load_status(FILE *filename);
    //function to read previous game data from a file
    //returns 0 if successfully read and stored data to program memory
    //returns -1 if error

int save_status(FILE *filename);
    //function to save game data to a file
    //returns 0 if successfully saved data to file
    //returns -1 if error

const char* returnString(const char *prompt);
    //function to return string

int returnInt(const char *prompt);
    //returns int input from user

void reset_grid();
    //resets the grid to all empty cells

void show_grid();
    //displays the grid on the cli

#endif