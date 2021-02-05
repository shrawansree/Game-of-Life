//library_management header file
//updated 2nd February 2021

#include <stdlib.h>
#include "book_management.h"

#define stockSize 9999          //Maximum number of different books that can be held in the library

extern struct Book *library[stockSize];

extern int numBooks;

//additional created functions
struct Book* addRemBook(struct BookArray foundBooks, const char searchString[99]);
int stringSearch(struct Book findBook, char bookSearch[99],char type[1]);