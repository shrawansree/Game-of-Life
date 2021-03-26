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
int **grid;

//************************************************************************

int load_status(FILE *filename){
    //function to read previous game data from a file
    //returns 0 if successfully read and stored data to program memory
    //returns -1 if error
    if(filename == NULL) return -1;
    else{
        free(grid);

        fscanf(filename,"\nThe last saved generation :%d",&Game_generation);
        fscanf(filename,"\nThe last saved env. Rows :%d",&MaxRow);
        fscanf(filename,"\nThe last saved env. Cols :%d",&MaxCol);

        grid = (int**)malloc(MaxRow * sizeof(int*));
        for_row{
           grid[row] = (int*)malloc(MaxCol * sizeof(int));
        }

        for_row{
            for_col{
                fscanf(filename,"%d",&grid[row][col]);
            }
            fscanf(filename,"\n",NULL);
        }

        return 0;
    }
}

int save_status(FILE *filename){
    //function to save game data to a file
    //returns 0 if successfully saved data to file
    //returns -1 if error
    if(filename == NULL) return -1;
    else{
        fprintf(filename,"\nThe last saved generation :%d",Game_generation);
        fprintf(filename,"\nThe last saved env. Rows :%d",MaxRow);
        fprintf(filename,"\nThe last saved env. Cols :%d",MaxCol);

        for_row{
            for_col{
                fprintf(filename,"%d",grid[row][col]);
            }
            fprintf(filename,"|\n",NULL);
        }

        return 0;
    }

}

void main(){
    game_start(0);
}
