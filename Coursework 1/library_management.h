//library_management header file
//updated 2nd February 2021

#include <stdlib.h>
#include "book_management.h"

#define stockSize 9999          //Maximum number of different books that can be held in the library

extern struct Book *library[stockSize];

extern int numBooks;