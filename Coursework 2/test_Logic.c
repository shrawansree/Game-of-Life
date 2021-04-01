//Unit test for Game_logic.c
/***********************************************************************
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
#include "Game_main.h"
#include "unity.h"
//vairables to pass into functions to test
int row;
int col;
//functions implementation
void test_horizontal(){
    //checks if the check_direction functions work as required
    TEST_ASSERT_EQUAL_INT(1, check_horizontal(row,col) );
}

void test_vertical(){
    //checks if the check_direction functions work as required
    TEST_ASSERT_EQUAL_INT(1, check_vertical(row,col) );
}

void test_diagonal(){
    //checks if the check_direction functions work as required
    TEST_ASSERT_EQUAL_INT(1, check_diagonal(row,col) );
}

void test_antidiagonal(){
    //checks if the check_direction functions work as required
    TEST_ASSERT_EQUAL_INT(0, check_antidiagonal(row,col) );
}

void test_cell_status(){
    //checks if cell's next status is properly set
    TEST_ASSERT_EQUAL_INT(1 , calculate_cell_status(0 , 0 , grid[0][0]));
}

void test_evolve(){
    //checks if new generations are successfully created
    while(is_game_over() == 0){
        evolve_cells();
    }
}


void setUp(){
    //empty
}

void tearDown(){
    //empty
}

void main(){
    UNITY_BEGIN();

    FILE *ptrL = fopen("saved_state.txt","r+");
    load_status(ptrL);

    row = 0;
    col = 0;

    RUN_TEST(test_horizontal);
    RUN_TEST(test_vertical);
    RUN_TEST(test_diagonal);
    RUN_TEST(test_antidiagonal);
    RUN_TEST(test_cell_status);
    RUN_TEST(test_evolve);

    UNITY_END();
}