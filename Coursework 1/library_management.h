//library_management header file
//updated 2nd February 2021

#ifndef LIBRARY_MANAGEMENT_GUARD__H 
#define LIBRARY_MANAGEMENT_GUARD__H



#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book_management.h"


struct User{
		char* name; //user first name
		char* email; // user email : ensure @ symbol is present when taking input
		char* username; //user login username
        char* password; //user login password
        int isAdmin;
        struct Book* booksOnHand; //books with the user is set in this array
        int numBooksOnHand; //number of books with the user
    };

extern struct User* users; //array of users
extern int numUsers;
 

//******************| additional created functions for user_management.c |******************

char *returnString(const char *prompt); //returns string to user prompt


#endif
