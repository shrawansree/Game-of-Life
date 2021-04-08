//game_logic function file
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
Date Work Commenced: 19th March 2021
*************************************************************************/
//additional headers
#include "Game_main.h"
//************************************************************************
//global variables
int** grid_hold;
//************************************************************************
//function implementation

int check_horizontal(int row, int col){
    //returns the count of horizontal neighbours of a particular cell
    int count = 0;


    if( row + 1 < MaxRow){
        if( grid[row + 1][col] == 1) count+= 1;
    }
    if( row - 1 >= 0){
        if( grid[row - 1][col] == 1) count+= 1;
    }
        return count;
}

int check_vertical(int row, int col){
    //returns the count of vertical neighbours of a particular cell
    int count = 0;

    if( col + 1 < MaxCol){
        if( grid[row][col + 1] == 1) count+= 1;
    }
    if( col - 1 >= 0){
        if( grid[row][col - 1] == 1) count+= 1;
    }
        return count;


}

int check_diagonal(int row, int col){
    //returns the count of diagonal neighbours of a particular cell
    int count = 0;

    if( row + 1 < MaxRow && col + 1 < MaxCol){
        if( grid[row + 1][col + 1] == 1) count+= 1;
    }
    if( row - 1 >= 0 && col - 1 >= 0){
        if( grid[row - 1][col - 1] == 1) count+= 1;
    }
        return count;

}

int check_antidiagonal(int row, int col){
    //returns the count of anti digonal neighbours of a particular cell
    int count = 0;

    if( row + 1 < MaxRow && col - 1 >= 0){
        if( grid[row + 1][col - 1] == 1) count+= 1;
    }
    if( row - 1 >= 0 && col + 1 < MaxCol){
        if( grid[row - 1][col + 1] == 1) count+= 1;
    }
        return count;
    //}
}

int calculate_cell_status(int row, int col , int current_status){
    //calculates the status of the cell based on its position in the grid
    //and the existence of its neighbour cells
    //returns 0 if cell dies, returns 1 if remains alive or comes alive
    //by reproduction

    int status_count = check_horizontal(row,col)
                    +check_vertical(row,col)
                +check_diagonal(row,col)
            +check_antidiagonal(row,col);

    if(status_count <=1 && current_status == 1) return 0;
        else if(status_count <= 3 && current_status == 1) return 1;
        else if(status_count > 3 && current_status == 1 ) return 0;
        else{
            if(status_count == 3 && current_status == 0) return 1;
            else return 0;
        } 
}

void evolve_cells(){
    //calculates the status of each cell in the grid and produces the next generation of cells
    grid_hold = (int**)malloc(MaxRow * sizeof(int*));
        for_row{ //temp holder for new grid values
           grid_hold[row] = (int*)malloc(MaxCol * sizeof(int));
        }

    for_row_col{
        grid_hold[row][col] = calculate_cell_status(row, col , grid[row][col]);
    }

    for_row_col{
        grid[row][col] = grid_hold[row][col];
    }
}

int is_game_over(){
    //checks if all cells in the environemnt are dead
    //if so, pauses the game and awaits further instructions : returns 1
    //if not, continues game : returns 0
    for_row_col{
        if(grid[row][col] == 1){
            return 0;
        }
    }
    return 1;
    
}
