//user_management function file
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
Date Work Commenced: 5th February 2021
*************************************************************************/

#include "library_management.h"


//declaration
// struct Book *library[stockSize]; //uncomment only for tests
// int numBooks;

//***********************************************************************

int user_login(const char username,const char password){
    //check validity
    if(username == NULL || password == NULL){
        return -1;
    } 
    else{
        for(int i = 0; i<numUsers; i++){
            if(strcmp(username,users[i]->username) == 0 && strcmp(password,users[i]->password) == 0){
                return users[i]->isAdmin;
            }
        }
        return -1;
    }
}


int store_users(FILE *file){

    //saves the array of users in the specified file
    //returns 0 if users were stored correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{
        
        fwrite(&numUsers,sizeof(int),1,file);
        fwrite(&users,sizeof(struct Book),numBooks,file);

        return 0;
    }
}


int load_users(FILE *file){

    //loads the array of users from the specified file
    //the file must have been generated by a previous call to store_books()
    //returns 0 if users were loaded correctly, or an error code otherwise

    if(file == NULL) return -1;
    else{
        
        fread(&numUsers,sizeof(int),1,file);
        for(int i=0; i < numBooks; i++ ){
            free(users[i]->f_name);
            free(users[i]->l_name);
            free(users[i]->email);
            free(users[i]->username);
            free(users[i]->password);
            // free(users[i]->isAdmin);
        }
        free(users);

        *users = (struct User*)malloc(sizeof(struct User*)*userSize);
        fread(&users,sizeof(struct User),numUsers,file); //dont forget to free the *library array

        return 0;
    }
}


int register_user(struct User newUser){

    //code to add new user
    //first name checks
    if(newUser.f_name == NULL) return -1;
    
    //last name checks
    if(newUser.l_name == NULL) return -1;

    //email check
    if(newUser.email == NULL) return -1;
    else if( strstr(newUser.email,"@") == NULL ) return -1;
    //else if( strstr(newUser.email,".co.uk") == NULL ) return -1; //popular email domains
    //else if( strstr(newUser.email,".org") == NULL ) return -1; 
    //else if( strstr(newUser.email,".com") == NULL ) return -1;

    //user username check
    if(newUser.username == NULL) return -1;
    else{
        for(int i =0 ; i<numUsers ; i++){
            if(strcmp(newUser.username, users[i]->username ) == 0){
                return -1;
            }
        }
    }

    //user password check
    if(newUser.password == NULL)return -1;
    else if(strlen(newUser.password) < 8) return -1;

    for(int i=0; i < strlen(newUser.password) ; i++){ //check for captial letter in password
        if(isupper(newUser.password[i]) != 0) break ;
        else return -1;
    }

    //if all checks are good then add user 
    users[numUsers] = &newUser;
    numUsers++;

    return 0;
}


// int remove_users(struct User* oldUser){

//     //check if empty input
    
//     if(oldUser->username==NULL){
//         free(oldUser);
//         return -1;
//     } 
//     else{
//         for(int i = 0; i < numUsers; i++){
//             if(strcmp(users[i]->username , oldUser->username)==0){ 
//                 oldUser = users[i];
//                 break;
//             }
//             else return -1;
//         }

//         free(oldUser->f_name);
//         free(oldUser->l_name);
//         free(oldUser->email);
//         free(oldUser->username);
//         free(oldUser->password);
//         free(oldUser);
        
//         return 0;
//     }
// }


int borrow_book(struct User borrower, struct Book* borrowedBook){

    //code for when user borrows book
    struct Book* foundBook = (struct Book*)malloc(sizeof(struct Book*));

    if(borrowedBook == NULL ) 
    {   
        free(foundBook);
        return -1;
    }
    else{ //find book in library and subtract a copy from it
        for(int i = 0; i < numBooks; i++){
            if(strcmp(borrowedBook->title,library[i]->title) == 0){
                foundBook = library[i];
                break;
            }
        }

        foundBook->copies = foundBook->copies-1;
        borrower.booksOnHand[borrower.numBooksOnHand] = foundBook;
        borrower.numBooksOnHand ++;

        free(foundBook);
        return 0;
    }

}


int return_book(struct User returner,struct Book* returnBook){

    //code for when user returns book
    struct Book* foundBook = (struct Book*)malloc(sizeof(struct Book*));

    if(returnBook == NULL ) 
    {   
        free(foundBook);
        return -1;
    }
    else{
        for(int i =0; i < numBooks; i++){
            if(strcmp(returnBook->title, library[i]->title) == 0){
                foundBook = library[i];
                break;
            }
        }

        foundBook->copies = foundBook->copies+1;
        free(returnBook->authors);
        free(returnBook->title);
        free(returnBook->year);
        free(returnBook->copies);
        free(foundBook);

        return 0;
    }
}



// int main(){
//     //skeleton framework
// }