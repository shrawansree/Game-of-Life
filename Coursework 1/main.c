//main.c for CW1
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
Date Work Commenced: 8th February 2021
*************************************************************************/
#include "library_management.h"
//#include "book_management.h"
char *output;
//***********************************************************************

char *returnString(const char *prompt) {
    //function to return string
    fflush(stdin);
	printf("%s",prompt);

    size_t size = 32;
    char temp[MAX_STRING];
    char *output = malloc(sizeof(char)*1024);

    fgets(temp,MAX_STRING-1,stdin);

    temp[strcspn(temp,"\n")] = 0;
    strcpy(output,temp);
	return output;
}
