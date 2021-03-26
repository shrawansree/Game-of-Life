//game_interface function file
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