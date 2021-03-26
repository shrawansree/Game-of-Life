//game_logic function file
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
//global variables
int MaxRow;
int MaxCol;
int** grid;
int Game_generation;
//************************************************************************
//function implementation

int check_row_col(int row, int col){
    //validate rows and cols
    //returns -1 if invalid rows or cols
    //returns 0 if valid

    if(row < 0 || col < 0){
        printf("\n*Co-ordinates cannot contain negative numbers*");
        return -1;
    }
    if(row > MaxRow || col > MaxCol){
        printf("\n*Co-ordinates cannot exceed environment boundaries*");
        return -1;
    }
    else{
        return 0;
    }
}

const char* is_edge_cell(int row, int col){
    //function that checks if the cell is an edge cell
    //returns "ey" : "edge yes" if edge cell, "en" : "edge no" if not edge cell
    //returns "tr/tl" : "top right/top left" or 
    //"br/bl" : "bottom right/ bottom left" if special case edge cell (corner cells)

    if(row == 0 || col == 0){
        if(row == 0 && col == 0) return "tl";
        else if(row == 0 && col == MaxCol-1) return "tr";
        else return "ey";
    }
    else if( row == MaxRow-1 || col == MaxCol-1){
        if(row == MaxRow-1 && col == MaxCol-1) return "br";
        else if(row == MaxRow-1 && col ==0) return "bl";
        else return "ey";
    }
    else return "en";

}

int check_horizontal(int row, int col, const char* is_edge){
    //returns the count of horizontal neighbours of a particular cell
    int count = 0;

    //if(is_edge == "en"){
        if( grid[row + 1][col] == 1) count+= 1;
        if( grid[row - 1][col] == 1) count+= 1;
        return count;
    //}

}

int check_verticals(int row, int col, const char* is_edge){
    //returns the count of vertical neighbours of a particular cell
    int count = 0;

    //if(is_edge == "en"){
        if( grid[row][col + 1] == 1) count+= 1;
        if( grid[row][col - 1] == 1) count+= 1;
        return count;
    //}

}

int check_diagonal(int row, int col, const char* is_edge){
    //returns the count of diagonal neighbours of a particular cell
    int count = 0;

    //if(is_edge == "en"){
        if( grid[row + 1][col + 1] == 1) count+= 1;
        if( grid[row - 1][col - 1] == 1) count+= 1;
        return count;
    //}

}

int check_antidiagonal(int row, int col, const char* is_edge){
    //returns the count of anti digonal neighbours of a particular cell
    int count = 0;
    //if(is_edge == "en"){
        if( grid[row + 1][col - 1] == 1) count+= 1;
        if( grid[row - 1][col + 1] == 1) count+= 1;
        return count;
    //}
}

int calculate_cell_status(int row, int col , int current_status){
    //calculates the status of the cell based on its position in the grid
    //and the existence of its neighbour cells
    //returns 0 if cell dies, returns 1 if remains alive or comes alive
    //by reproduction

    const char* is_edge = is_edge_cell(row,col);

    int status_count = check_horizontal(row,col,is_edge)
                    + check_verticals(row,col,is_edge)
                +check_diagonal(row,col,is_edge)
            +check_antidiagonal(row,col,is_edge);

    if(status_count <= 1) return 0;
    else if(status_count <= 3){
        if(status_count == 3 && current_status == 0) return 1;
        else return current_status;
    }
    else return 0;

}

void evolve_cells(){
    //calculates the status of each cell in the grid and produces the next generation of cells
    for_row_col{
        grid[row][col] = calculate_cell_status(row, col , grid[row][col]);
    }

    Game_generation++;

    show_grid();
}

int is_game_over(){
    //checks if all cells in the environemnt are dead
    //if so, pauses the game and awaits further instructions : returns 1
    //if not, continues game : returns 0
    for_row_col{
        if(grid[row][col] == 1){
            return 0;
        }
        else{
            return 1;
        }
    }
}

void new_game(){
    //function initialises a new game from scratch
    //prompt_newgame();
    int row,col;
    do{
        MaxRow = INT_LIMIT;
        MaxCol = INT_LIMIT;
        row = returnInt("Enter height of game grid : ");
        col = returnInt("Enter width of game grid : ");
    }while(check_row_col(row,col) == -1);

    MaxRow = row;
    MaxCol = col;
    
    grid = (int**)malloc(MaxRow * sizeof(int*));
    for_row{
        grid[row] = (int*)malloc(MaxCol * sizeof(int));
    }

    Game_generation = 0;
    reset_grid();
    show_grid();

    return;
}

void continue_game(){
    //continues from previously created session
    //prompt_continue_game();

    FILE *ptr = fopen("saved_state.txt","r+");
    load_status(ptr);
    free(ptr);

    show_grid();

    return;
}

int game_start(int game_type){
    //called at the start of the program to initialise the grid state
    //if game_type = 0 : starts from a fresh grid
    //if game_type = 1 : starts from pre-deteremined state read from file
    if(game_type>1 || game_type < 0){
        printf("\n * Invalid Type * ");
        return -1;
    }
    else if( game_type == 0 ) new_game();
    else continue_game();

    while(is_game_over() == 0){
        evolve_cells();
        returnString(">>>Press Enter to continue ");
    }

}