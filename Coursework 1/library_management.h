//library_management header file
//updated 2nd February 2021

#ifndef LIBRARY_MANAGEMENT_GUARD__H 
#define LIBRARY_MANAGEMENT_GUARD__H



#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book_management.h"
#include "user_management.h"
#include "loan_management.h"
#include "interface_management.h"

#define MAX_STRING 1024

extern char *output;

//returns a char* to a prompt 
char *returnString(const char *prompt);

#endif
