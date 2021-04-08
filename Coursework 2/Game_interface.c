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
int load_status_new(FILE *filename){
    //function to read previous game data from a file
    //returns 0 if successfully read and stored data to program memory
    //returns -1 if error
    if(filename == NULL) return -1;
    else{
        char holder[61];

        fgets(holder,60,filename);
        sscanf(holder,"%*[^:]:%d%[^\n]",&Game_generation);
            
        fgets(holder,60,filename);
        sscanf(holder,"%*[^:]:%d%[^\n]",&MaxCol);

        fgets(holder,60,filename);
        sscanf(holder,"%*[^:]:%d%[^\n]",&MaxRow);

        if(MaxRow == 0 || MaxCol == 0){
            printf("\n * Error. Invalid read from file * ");
        }
        if(Game_generation == 0){
            printf("\n * Error. Invalid read from file * ");
        }

        grid = (int**)malloc(MaxRow * sizeof(int*));
        for_row{
            grid[row] = (int*)malloc(MaxCol * sizeof(int));
        }

        reset_grid();

        if(MaxRow >25 || MaxCol>25){
            #undef CELL_SIZE
            #define CELL_SIZE 10
        }

        fclose(filename);
        return 0;
    }
}

int load_status(FILE *filename){
    //function to read previous game data from a file
    //returns 0 if successfully read and stored data to program memory
    //returns -1 if error
    if(filename == NULL) return -1;
    else{
        free(grid);
            char holder[61];

            fgets(holder,60,filename);
            sscanf(holder,"%*[^:]:%d%[^\n]",&Game_generation);
            
            fgets(holder,60,filename);
            sscanf(holder,"%*[^:]:%d%[^\n]",&MaxCol);

            fgets(holder,60,filename);
            sscanf(holder,"%*[^:]:%d%[^\n]",&MaxRow);

            if(MaxRow == 0 || MaxCol == 0){
                printf("\n * Error. Invalid read from file * ");
            }
            if(Game_generation == 0){
                printf("\n * Error. Invalid read from file * ");
            }

            grid = (int**)malloc(MaxRow * sizeof(int*));
            for_row{
            grid[row] = (int*)malloc(MaxCol * sizeof(int));
            }

            int c;
            for_row{
                for_col{
                    c = fgetc(filename);
                    while(c != 48 || c != 49){
                        if(c == 48) {grid[row][col] = 0; break;}
                        else if(c == 49){grid[row][col] = 1; break;}
                        else c = fgetc(filename);
                    }
                }
            }

        if(MaxRow >25 || MaxCol>25){
            #undef CELL_SIZE
            #define CELL_SIZE 10
        }

        fclose(filename);
        return 0;
    }
}

int save_status(FILE *filename){
    //function to save game data to a file
    //returns 0 if successfully saved data to file
    //returns -1 if error
    if(filename == NULL) return -1;
    else{
        fprintf(filename,"Itteration:%d\n",Game_generation);
        fprintf(filename,"Rows:%d\n",MaxCol);
        fprintf(filename,"Columns:%d\n",MaxRow);

        for_row{
            for_col{
                fprintf(filename,"%d",grid[row][col]);
            }
            fprintf(filename,"\n",NULL);
        }

        fclose(filename);
        return 0;
    }

}

void reset_grid(){
    //resets the grid to zero
    for_row_col{
        grid[row][col] = 0;
    }
    return;
}
