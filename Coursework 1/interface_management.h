//interface_management.h
//updated 19th February 2021

#ifndef INTERFACE_MANAGEMENT_GUARD__H 
#define INTERFACE_MANAGEMENT_GUARD__H


#include <stdio.h>

//function to display books found from search functions
void display_found_books(struct BookArray foundBooks);

//Initial interface that user meets. Prompts user to login, register or search for books
void boot_interface();

//Handles user login screen
int login_interface();

//handles user registration screen. 'type' determines what kind of user is created (normal - 0 / admin - 1)
void register_interface(int type);

//handles searching for books
//type - 0 : boot menu , type - 1 : main interface
void search_interface(int type);

//main interface of the program where user can borrow and return, search for books ,(and admins can add/remove books ). 
// type - 0 : user, type - 1 : admin
void main_interface(struct User user);

#endif
