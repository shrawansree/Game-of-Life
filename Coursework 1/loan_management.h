//loan management.h
//updated 18th February 2021

#ifndef LOAN_MANAGEMENT_GUARD__H 
#define LOAN_MANAGEMENT_GUARD__H 

#include <stdio.h>

#define MAX_LOANS 99

struct userLoan{

    struct Book loanBook;
    int userID;
    char* username;

};

extern struct userLoan loans[MAX_LOANS]; //array to hold loan books
extern int numLoans;

//allows current user to borrow books from the library. Should decrease the value of copies in the library by 1 and add it to the loaned books
//adds loaned book and its borrower to a new array of loaned books
int borrow_books(struct User user, struct Book* loan);

//allows current user to return book to the library. Should decrease the value of the copies in the loan array and increment in the library.
int return_books(struct User user);


//uses the find book_by functions and the display function to locate the exact book needed to have taken action on within the library returns a pointer to it
//returns NULL if no book is found
struct Book* find_book(struct BookArray* books);

//stores the loaned books and their current borrowers in a file
//returns 0 if books were stored correctly, or an error code otherwise
int store_loans(FILE *file);

//loads the loaned books and their current borrowers from a file
//returns 0 if books were stored correctly, or an error code otherwise
int load_loans(FILE *file);



#endif