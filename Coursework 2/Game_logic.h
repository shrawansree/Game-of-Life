#ifndef GAME_LOGIC_GUARD__H 
#define GAME_LOGIC_GUARD__H 

//functions
int check_row_col(int row, int col);
    //validate rows and cols
    //returns -1 if invalid rows or cols
    //returns 0 if valid

int game_start(int game_type);
    //called at the start of the program to initialise the grid state
    //if game_type = 0 : starts from a fresh grid
    //if game_type = 1 : starts from pre-deteremined state read from file

void new_game();
    //function initialises a new game from scratch

void continue_game();
    //continues from previously created session

int calculate_cell_status(int row, int col , int current_status);
    //calculates the status of the cell based on its position in the grid
    //and the existence of its neighbour cells
    //returns 0 if cell dies, returns 1 if remains alive or comes alive
    //by reproduction

void evolve_cells();
    //calculates the status of each cell in the grid and produces the next generation of cells

int check_horizontal(int row, int col);
    //returns the count of horizontal neighbours of a particular cell

int check_vertical(int row, int col);
    //returns the count of vertical neighbours of a particular cell

int check_diagonal(int row, int col);
    //returns the count of diagonal neighbours of a particular cell

int check_antidiagonal(int row, int col);
    //returns the count of antidiagonal neighbours of a particular cell

int is_game_over();
    //checks if all cells in the environemnt are dead
    //if so, pauses the game and awaits further instructions : returns 1
    //if not, continues game : returns 0

#endif