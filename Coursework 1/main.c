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

struct Book *library[stockSize];
struct User *users[userSize];
int numBooks;
int numUsers;

//***********************************************************************
char* invalid_credentials(int type){
    //prints invalid cred output
    //type 1 for invalid registration fields
    if(type == 1) printf("\n Sorry! One or more fields entered are invalid!");
    //type 2 for invalid login
    else if(type == 2) printf("\n Sorry! One or more credentials entered are invalid!");

    char* choice = (char*)malloc(sizeof(char*));
    do{
        printf("\n Would you like to try again.? (y/n) :");
        scanf("%c",*choice);
    }   while(choice != "y" || choice != "n");

    return choice;
}


struct User createUser(int type){
    //upon first initialising the program from scratch : no userbase,library or data : create the first admin user
    //set type 1 for admin and type 0 for normal user.
    char f_name[30];
    char l_name[30];
    char email[30];
    char username[30];
    char password[30];

    printf("\n Enter User First Name : ");
    scanf("%s",f_name);

    printf("\n Enter User Last Name : ");
    scanf("%s",l_name);  

    printf("\n Enter User Email ID : ");
    scanf("%s",email);

    printf("\n Enter User Username : ");
    scanf("%s",username);

    printf("\n Enter User Password");
    printf("\n (at least 8 characters long : including captial letter and special characters) : ");
    scanf("%s",password);

   

    struct User newUser;
     newUser.isAdmin = type;
     newUser.f_name = f_name;
     newUser.l_name = l_name;
     newUser.email = email;
     newUser.username = username;
     newUser.password = password;

    //pass the struct to register_user function
    return newUser;
}


struct BookArray searchBook(){
    //search using functions in book_management.c
    int choice = -1; //user choice
    char* findBy; //string holder
    int findByYear;
    struct BookArray tempStore;

    printf("\n 1. Find book by title ");
    printf("\n 2. Find book by author ");
    printf("\n 3. Find book by year ");

    do{
        printf("\n >>>");
        choice = scanf("%d",choice);
    }   while(choice < 1 && choice > 3);


    switch (choice)
    {
    case 1:{
        printf("\n Enter title of book : ");
        scanf("%s",&findBy);
        tempStore = find_book_by_title (findBy);
        break;
    }
    case 2:{
        printf("\n Enter author of book : ");
        scanf("%s",&findBy);
        tempStore = find_book_by_author (findBy);
        break;
    }
    case 3:{
        printf("\n Enter year of book : ");
        scanf("%d",findByYear);
        tempStore = find_book_by_year (findByYear);
        break;
    }
    default:
        break;
    }

    return tempStore;
}


void add_remove_book(int type){
    //function to let admins add or remove books
    struct Book tempStore;

    printf("\n*Add/Remove Book Menu*");
    //grab details
    printf("\n Enter title of book :");
        scanf("%s",&tempStore.title);
    printf("\n Enter author of book :");
        scanf("%s",&tempStore.authors);
    printf("\n Enter year of book :");
        scanf("%s",&tempStore.year);
    printf("\n Enter copies of book :");
        scanf("%s",&tempStore.copies);

    if(type == 3){
        add_book(tempStore);
    }
    else{
        remove_book(tempStore);
    }
    return;  

}


void borrow_return_book(int type,struct User* user){
    //function to allow user to borrow or return book
    struct BookArray tempStore;

    if(user == NULL){ free(user); return; }

    else{
        printf("\n*Borrow/Return Menu*");
        tempStore = searchBook();
        printf("\n Found %d results ",tempStore.length);

        for(int i = 0; i<tempStore.length ; i++){//ask user to find exact book
            
            printf("\n Title : %c",tempStore.array[i].title);
            printf("\n Author : %c",tempStore.array[i].authors);
            printf("\n Year : %c",tempStore.array[i].year);

            char choice[1];
            do{
                printf("\n Is this the book .? (y/n) : " );
                scanf("%s",&choice);
            }   while(choice != "y" && choice != "n");

            if(choice == "y"){
                if(type == 1) borrow_book(user,tempStore.array[i]);
                else return_book(user, tempStore.array[i]);

                break;
            }
            else continue;

        }
        return;
    }

}


void library_menu(int type,char* username,char* password){
    //logon view into library
    //type 1 is for admin only functionality , type 0 for normal users
    // the actual library menu
    int choice; //menu choice holder
    struct User* currentUser = (struct User*)malloc(sizeof(struct User*));
    for(int i = 0; i< numUsers; i++){
        if(strcmp(users[i]->username,username) == 0){
            if(strcmp(users[i]->password, password) == 0 ){
                currentUser = users[i]; //get current user details
            }
        }
    }

    printf("\n*Library Main Menu*");
    printf("\n 1. Borrow Book ");
    printf("\n 2. Return Book ");

    if(type != 1){//if normal user
        do{
            printf("\n >>>");
            choice = scanf("%d",choice);
        }   while(choice < 1 && choice > 2);
    }
    else{
        //if admin
        printf("\n*Admin Mode*");
        printf("\n 3. Add Book");
        printf("\n 4. Remove Book");
        printf("\n 5. Exit");
        do{
            printf("\n >>>");
            choice = scanf("%d",choice);
        }   while(choice < 1 && choice > 6);
    }

    //control flow for user choice
    if(choice == 1 || choice == 2){
        borrow_return_book(choice,currentUser);
        free(currentUser);
        library_menu(type,username,password);

    }
    else if(choice == 3 || choice == 4){
        add_remove_book(choice);
        free(currentUser);
        library_menu(type,username,password);
    }
    else{
        free(currentUser);
        exit(0);
    }
    return;
}


void userRegisterMenu(){
    //register new normal users
    printf("\n*Welcome*");
    struct User* newUser = (struct User*)malloc(sizeof(struct User*));
    *newUser = createUser(0);

RESET:   
    if(register_user(newUser) == -1 ){
        char* choice;
        choice = invalid_credentials(1);
        if(choice == "y"){ free(choice); goto RESET;}
        else exit(0);
    }

    else{
        printf("\n*Successfully registered*");
        libLoginMenu();
    }

    return;
}


void userLoginMenu(){
    //login menu
    char* username;
    char* password;

    printf("\n*Login Menu*");

RESET: 
    printf("\n Enter Username : ");
    scanf("%s",&username);

    printf("\n Enter Password : ");
    scanf("%s",&password);

    if( user_login(username,password) == -1){
        char* choice;
        choice = invalid_credentials(2);
        if(choice == "y"){ free(choice); goto RESET;}
        else exit(0);
    }

    else{
        printf("\n*Successful Login*");
        library_menu(user_login(username,password),username,password);
    }

    return;
}


void libLoginMenu(){
    //Login Menu for the program
    //This program is going to be menu driven.

    printf("\n*Main Menu*");
    printf("\n 1. Login ");
    printf("\n 2. Register ");
    printf("\n 3. Exit App ");
    int choice = -1;

    do{ //loop prompt till valid choice provided - saves time having to implement a check for user input
        printf("\n >>>");
        scanf("%d",choice);
    }   while( choice < 1 && choice > 3);

    switch (choice){
        case 1:{
            userLoginMenu();
            break;
        }
        case 2:{
            userRegisterMenu();
            break;
        }
        case 3:{
            exit(0);
        }
        default:    
            printf("ERROR");
    } 
}


void main(){

    //begin program by checking if a prexisting userbase and library exist
    FILE *ptr = fopen("userbase.txt","r");

    if(ptr != NULL){
        free(ptr);
        libLoginMenu();
    }

    else{
        free(ptr);
        while(1){
            //program critical step : loop to ensure that admin user is properly initialised
            printf("\n Hello! This is the first instance of the library system boot!");
            printf("\n As the first user, you shall be the admin! Please enter details below. ");
            struct User* newUser = (struct User*)malloc(sizeof(struct User*)); 
            *newUser = createUser(1);
            printf("here");
            RESET : 
                //set type 1 for admin and type 0 for normal user.
            if( register_user(newUser) != 0){
                
                char* choice;
                choice = invalid_credentials(1);
                if(choice == "y"){ free(choice); goto RESET; }
                else if(choice == "n") exit(0);
            }

            else{
                free(newUser);
                libLoginMenu();
            }
        }
    }

    return;
}