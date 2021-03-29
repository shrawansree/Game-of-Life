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


const char* returnString(const char *prompt) {
    //function to return string
    fflush(stdin);
	printf("\n%s",prompt);

    size_t size = 32;
    char temp[MAX_STRING];
    char *output = malloc(sizeof(char)*MAX_STRING);

    fgets(temp,MAX_STRING-1,stdin);

    if(temp == NULL) return NULL;

    temp[strcspn(temp,"\n")] = 0;
    strcpy(output, temp);
	return output;
}

int returnInt(const char *prompt){
    //returns int input from user
    fflush(stdin);
	printf("\n%s",prompt);

    int output = -1;
    fscanf(stdin,"%d",&output);
    return output;
}

void reset_grid(){
    //resets the grid to all empty cells
    for_row_col{
        grid[row][col] = 0;
    }
}

void show_grid(){
    //displays the grid on the cli
    printf("\n");
    for_row{
        for_col{
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int load_status(FILE *filename){
    //function to read previous game data from a file
    //returns 0 if successfully read and stored data to program memory
    //returns -1 if error
    if(filename == NULL) return -1;
    else{
        free(grid);

        fscanf(filename,"\nThe last saved generation :%d",&Game_generation);
        fscanf(filename,"\nThe last saved env. Rows :%d",&MaxCol);
        fscanf(filename,"\nThe last saved env. Cols :%d\n",&MaxRow);

        grid = (int**)malloc(MaxRow * sizeof(int*));
        for_row{
           grid[row] = (int*)malloc(MaxCol * sizeof(int));
        }

        for_row{
            for_col{
                fscanf(filename,"|%d|",&grid[row][col]);
            }
            fscanf(filename,"\n",NULL);
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
        fprintf(filename,"\nThe last saved generation :%d",Game_generation);
        fprintf(filename,"\nThe last saved env. Rows :%d",MaxRow);
        fprintf(filename,"\nThe last saved env. Cols :%d\n",MaxCol);

        for_row{
            for_col{
                fprintf(filename,"|%d|",grid[row][col]);
            }
            fprintf(filename,"\n",NULL);
        }

        fclose(filename);
        return 0;
    }

}