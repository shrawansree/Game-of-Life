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


//***********************************************************************
char invalid_credentials(int type){
    //prints invalid cred output
    //type 1 for invalid registration fields
    if(type == 1) printf("\n Sorry! One or more fields entered are invalid!");
    //type 2 for invalid login
    else if(type == 2) printf("\n Sorry! One or more credentials entered are invalid!");

    char choice[1];
    do{
        printf("\n Would you like to try again.? (y/n) :");
        scanf("%c",choice);
    }   while(choice != 'y' && choice != 'n');

    return choice;
}


struct User createUser(int type){
    //upon first initialising the program from scratch : no userbase,library or data : create the first admin user
    //set type 1 for admin and type 0 for normal user.
    struct User newUser;

    printf("\n Enter User First Name : ");
    scanf("%c",newUser.f_name);

    printf("\n Enter User Last Name : ");
    scanf("%c",newUser.l_name);  

    printf("\n Enter User Email ID : ");
    scanf("%c",newUser.email);

    printf("\n Enter User Username : ");
    scanf("%c",newUser.username);

    printf("\n Enter User Password");
    printf("\n (at least 8 characters long : including captial letter and special characters) : ");
    scanf("%c",newUser.password);

    newUser.isAdmin = type;

    //pass the struct to register_user function
    return newUser;
}


void borrow_return_book(int type,struct User* borrower){
    //

}


void library_menu(int type, const char* username, const char* password){
    //logon view into library
    //type 1 is for admin only functionality , type 0 for normal users
    // the actual library menu
    int choice; //menu choice holder
    struct User** currentUser = (struct User**)malloc(sizeof(struct User**));
    for(int i = 0; i< numUsers; i++){
        if(strcmp(users[i]->username,username) == 0 && strcmp(users[i]->password, password) == 0 ){
            currentUser = &users[i]; //get current user details
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

        do{
            printf("\n >>>");
            choice = scanf("%d",choice);
        }   while(choice < 1 && choice > 5);
    }

    //control flow for user choice
    if(choice == 1 || choice == 2){
        borrow_return_book(choice,currentUser);
    }
    else if(choice == 3 || choice == 4){
        add_remove_book(choice,currentUser);
    }

    return;
}


void userRegisterMenu(){
    //register new normal users
    printf("\n*Welcome*");

RESET:    
    struct User newUser = createUser(0);
    if(register_user(newUser) == -1 ){
        char choice[1] = invalid_credentials(1);
        if(choice == 'y'){ goto RESET;}
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
    scanf("%c",username);

    printf("\n Enter Password : ");
    scanf("%c",password);

    if( user_login(username,password) == -1){
        char choice[1] = invalid_credentials(2);
        if(choice == 'y'){ goto RESET;}
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
        scanf("%i",choice);
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

            RESET : 
            struct User newUser = createUser(1); //set type 1 for admin and type 0 for normal user.
            if( register_user(newUser) != 0){
                char choice[1] = invalid_credentials(1);
                if(choice == 'y'){ goto RESET; }
                else exit(0);
            }

            else{
                libLoginMenu();
            }
        }
    }

    return;
}