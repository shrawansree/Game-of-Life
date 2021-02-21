//interface_management function file
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
Date Work Commenced: 19th February 2021
*************************************************************************/
#include "library_management.h"

struct User* currentUser;
struct BookArray* foundBooks;// to return books
char* output;
/************************************************************************/

static void store_all(){
    //stores all books , users and loans upon logging off

        FILE* ptrWLoan = fopen("loans.txt","w+");
    store_loans(ptrWLoan);
    free(ptrWLoan);

        FILE* ptrWBook = fopen("library.txt","w+");
    store_books(ptrWBook);
    free(ptrWBook);

        FILE* ptrWUser = fopen("usersbase.txt","w+");
    store_users(ptrWUser);
    free(ptrWUser);

        return;
}


static void remove_book_byID(){
    //prevents admin from removing books that are on loan
    printf("\n");
    display_all_book(); //displays all books
    printf("\n");

    char* errCh; //error handling possible string input from user
    do{
        errCh = returnString("\n>>>Enter choice : ");
        free(output);
    }   while( isdigit(*errCh) == 0);
    int ID = atoi(errCh);
   

    for( int i =0; i<numLoans; i++){
        if( loans->loanBook.ID == ID){
            printf("\n *Sorry! This book is currently on loan.*");
            return;
        }
    }

    for(int j = 0; j<numBooks; j++){
        if( library[j].ID == ID ){
            remove_book(library[j]);
            return;
        }
    }
    printf("\n *Could not remove book* ");
    return;
}


void main_interface(struct User user){
    //main interface of the program where user can borrow and return, search for books ,(and admins can add/remove books ). 
    // type - 0 : user, type - 1 : admin

    while(1){

        printf("\n* Main Menu *");
        printf("\n 1. Borrow Book ");
        printf("\n 2. Return Book ");
        printf("\n 3. Display All Books ");

        if(user.isAdmin == 1){
            printf("\n 4. Add Book ");
            printf("\n 5. Remove Book ");
        }
        printf("\n 6. Exit");

        char* errCh; //error handling possible string input from user
        do{
            errCh = returnString("\n>>>Enter choice : ");
            free(output);
        }   while( isdigit(*errCh) == 0);
        int choice = atoi(errCh);
   
        switch(choice){
            case 1:{//finds book to borrow
                search_interface(1);
                break;
            }
            case 2:{//allows users to return books 
                return_books(user);
                break;
            }
            case 3:{// finds books on the given year
                display_all_book();
                returnString("\n>>>Press enter to continue ...");
                free(output);
                break;
            }
            case 4:{//displays all books
                if(user.isAdmin == 0){
                    printf("\n *Invalid Choice* ");
                    break;
                    }
                add_book(create_book());
                break;
            }
            case 5:{
                if(user.isAdmin == 0){
                    printf("\n *Invalid Choice* ");
                    break;
                }
                remove_book_byID(); //removes book by ID
                break;
            }
            case 6:{    
                store_all();
                free(currentUser);
                boot_interface();
            }
            default:{ //attempts retry
                printf("\n* Invalid choice *");
                returnString("\n>>>Press enter to continue ...");
                free(output);
                break;
            }
        }

    }


}


void display_found_books(struct BookArray foundBooks){
    //function to display books found from search functions
    if( foundBooks.length < 1){
        printf("\n No books to display!\n");
        return;
    }

    else{
        printf("|%-3s|-|%-25s|-|%-25s|-|%-3s|-|%-3s| \n","ID","Author","Title","Year","Copies");

        for(int i=0; i<foundBooks.length; i++){
            printf("|%-3d| |%-25s| |%-25s| |%-3d| |%-3d| \n",
            foundBooks.array[i].ID, foundBooks.array[i].authors, foundBooks.array[i].title, foundBooks.array[i].year, foundBooks.array[i].copies);
        }
        return;
    }

}


static void search_interface_sub(int choice , int type){

    //sub-function to the search function to prevent repeating code
    //choice routes to the type of search and type routes if search is from the boot menu or from the main menu
    // type - 0 : boot menu , type - 1 : main menu
    foundBooks = (struct BookArray*)malloc(sizeof(struct BookArray*));

    if(choice == 1) *foundBooks = find_book_by_title(returnString("\n Enter title of book : "));
    else if(choice == 2) *foundBooks = find_book_by_author(returnString("\n Enter title of author : "));
    else {
        printf("\n Enter year of publication : ");
        int yearFind = 0;
        scanf("%d",&yearFind);
        *foundBooks = find_book_by_year(yearFind);
    }
    free(output);
    display_found_books(*foundBooks);

    if(type == 0){
        return;
    }

    if(type == 1){
        borrow_books(*currentUser, find_book(foundBooks));
        return;
    }

}


void search_interface(int type){
    //handles searching for books

    while(1){
        printf("\n* Browse Books *");
        printf("\n 1. Find books by title.");
        printf("\n 2. Find books by author.");
        printf("\n 3. Find books by year.");
        printf("\n 4. Display all books in library.");
        printf("\n 5. Quit to previous menu.");

        char* errCh; //error handling possible string input from user
        do{
            errCh = returnString("\n>>>Enter choice : ");
            free(output);
        }   while( isdigit(*errCh) == 0);
        int choice = atoi(errCh);
   
        switch(choice){

            case 1:{// finds books with required title
                search_interface_sub(choice, type);
                free(foundBooks->array);
                free(foundBooks);
                break;
            }
            case 2:{//finds books with required author
                search_interface_sub(choice , type);
                free(foundBooks->array);
                free(foundBooks);
                break;
            }
            case 3:{// finds books on the given year
                search_interface_sub(choice , type);
                free(foundBooks->array);
                free(foundBooks);
                break;
            }
            case 4:{//displays all books
                display_all_book();
                returnString("\n Press enter to continue ...");
                free(output);
                break;
            }
            case 5:{
                return;
            }
            default:{ //attempts retry
                printf("\n* Invalid choice *");
                break;
            }
        }
    }
}


void register_interface(int type){
    //handles user registration screen
    printf("\n* Register *");

    int status = 0; //determines if registration is successful

    if(type == 1){
        printf("\n* Initial Boot *");
        printf("\n You are the first user. Therefore you will be the admin of the system. ");

        do{
            status = register_users( create_new_user(), 1); //creates a new user with admin type
        }   while( status == -1);

        FILE* ptrWUser = fopen("usersbase.txt","w+");
        store_users(ptrWUser);
        free(ptrWUser);
        return;
    }
    
    else{

        do{
            status = register_users( create_new_user(), type); //creates a new user with admin type
        }   while( status == -1);

        FILE* ptrWUser = fopen("usersbase.txt","w+");
        store_users(ptrWUser);
        free(ptrWUser);

        return;
    }

}


int login_interface(){
    //Handles user login screen
    printf("\n* Login *");
    char username[MAX_STRING];
    char password[MAX_STRING];
    currentUser = (struct User*)malloc(sizeof(struct User*));

    while(1){
        strcpy(username, returnString("\n Enter username : "));
        free(output);

        strcpy(password, returnString("\n Enter password : "));
        free(output);

        *currentUser = login_users(username, password);

        if(currentUser->username == NULL){
            printf("\n Login Failed.");
            char choice;
            do{
                choice = *returnString("\n Try again.?(y/n) : ");
                free(output);
            }   while(choice != 'y' && choice != 'n');

            if(choice == 'y') continue; //attempt to relogin
            else return -1; //returns to the boot menu
        }
       else{
            main_interface(*currentUser); //login as normal user
            free(currentUser);
            return 0; 
        } 
    }
}


void boot_interface(){
    //Initial interface that user meets. Prompts user to login, register or search for books

    while(1){
        printf("\n* Welcome to the Library *");

        printf("\n Would you like to : ");
        printf("\n 1. Login ");
        printf("\n 2. Register ");
        printf("\n 3. Browse books ");
        printf("\n 4. Quit ");

        char* errCh; //error handling possible string input from user
        do{
            errCh = returnString("\n>>>Enter choice : ");
            free(output);
        }   while( isdigit(*errCh) == 0);
        int choice = atoi(errCh);
   
        switch(choice){
            case 1:{// routes to login interface
                login_interface();
                break;
            }

            case 2:{//routes to registration interface
                register_interface(0);
                break;
            }
            case 3:{// routes to search interface
                search_interface(0);
                break;
            }
            case 4:{
                exit(0);
            }
            default:{ //attempts retry
                printf("\n* Invalid choice *");
                break;
            }
        }
    }
}