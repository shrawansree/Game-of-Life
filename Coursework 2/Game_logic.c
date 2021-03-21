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
#include "Game_logic.h";
//************************************************************************
//global variables
int MaxRow;
int MaxCol;
int **grid;
//************************************************************************
//function implementation

char *returnString(const char *prompt) {
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
    printf("/n");
    for_row{
        for_col{
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}


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


int game_start(int game_type){
    //called at the start of the program to initialise the grid state
    //if game_type = 0 : starts from a fresh grid
    //if game_type = 1 : starts from pre-deteremined state read from file
    if(game_type>1 || game_type < 0){
        printf("\n * Invalid Type * ");
        return -1;
    }
    else if( game_type == 0 ){
        new_game();
        return 0;
    }
    else{
        continue_game();
        return 0;
    }

}


void new_game(){
    //function initialises a new game from scratch
    prompt_newgame();
    int row,col;
    do{
        row = returnInt("Enter height of game grid : ");
        col = returnInt("Enter width of game grid : ");
    }while(check_row_col(row,col) == -1);

    MaxRow = row;
    MaxCol = col;
    
    **grid = (int**)malloc(MaxRow * sizeof(int*));
    for_row{
        *grid[row] = (int*)malloc(MaxCol * sizeof(int));
    }
    
    return;
}


void continue_game(){
    //continues from previously created session
    prompt_continue_game();
    load_state(/*filename*/);


}