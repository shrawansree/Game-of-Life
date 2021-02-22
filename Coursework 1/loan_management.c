//loan_management function file
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
Date Work Commenced: 18th February 2021
*************************************************************************/
#include "library_management.h"

struct userLoan loans[MAX_LOANS];
struct Book* found_book;
int numLoans = 0;
char *output;
/************************************************************************/

int store_loans(FILE *file){

    //stores the loaned books and their current borrowers in a file
    //returns 0 if books were stored correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{
        static char tmpauthor[MAX_STRING];
        static char tmptitle[MAX_STRING];
        static char tmpUsername[MAX_STRING];

        fprintf(file,"%d\n",numLoans);
        for(int i=0; i<numLoans; i++){
            strcpy(tmpauthor,loans[i].loanBook.authors);
            strcpy(tmptitle,loans[i].loanBook.title);
            strcpy(tmpUsername,loans[i].username);

               fprintf(file,"%d\t%s\n%s\n%d\t%d\t%d\t%s\n",
        loans[i].loanBook.ID, tmpauthor, tmptitle , loans[i].loanBook.year, loans[i].loanBook.copies, loans[i].userID, tmpUsername );

        }
        fclose(file);
        return 0;
    }
}


int load_loans(FILE *file){ 

    //loads the database of books from the specified file
    //the file must have been generated by a previous call to store_books()
    //returns 0 if books were loaded correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{

        fscanf(file,"%d\n",&numLoans); 
        static char tmpAut[MAX_STRING];
        static char tmpTitle[MAX_STRING];
        static char tmpUsername[MAX_STRING];

        for(int i=0; i<numLoans; i++){

            fscanf(file,"%d \t",&loans[i].loanBook.ID);

            fgets(tmpAut,MAX_STRING,file);
            fgets(tmpTitle,MAX_STRING,file);

            fscanf(file,"%d\t",&loans[i].loanBook.year);
            fscanf(file,"%d\t",&loans[i].loanBook.copies);
            fscanf(file,"%d\t",&loans[i].userID);
            fgets(tmpUsername,MAX_STRING,file);

            tmpAut[strcspn(tmpAut,"\n")] = 0;
            tmpTitle[strcspn(tmpTitle,"\n")] = 0;
            tmpUsername[strcspn(tmpUsername,"\n")] = 0;

            strcpy(loans[i].loanBook.authors,tmpAut);
            strcpy(loans[i].loanBook.title,tmpTitle);
            strcpy(loans[i].username,tmpUsername);
            
        }
        fclose(file);
        return 0;
    }
}


struct Book* find_book(struct BookArray* books){
    //uses the find book_by functions and the display function to locate the exact book needed to have taken action on within the library returns a pointer to it
    //returns NULL if no book is found

    found_book = (struct Book*)malloc(sizeof(struct Book*));
    int ID = 0;

    if(books->length<1){
        printf("\n *Could not retrieve book*");
        return NULL;
            
    }

    printf("\n>>>Enter ID : ");
    scanf("%d",&ID);

    for(int i=0; i<books->length; i++){

        if( books->array[i].ID == ID ){
            found_book = &books->array[i];            
            return found_book;
        }
    }

    printf("\n *Could not retrieve book*");
    return NULL;
    

}


int borrow_books(struct User user, struct Book* loan){

    //allows current user to borrow books from the library. Should decrease the value of copies in the library by 1 and add it to the loaned books
    //adds loaned book and its borrower to a new array of loaned books
    if( user.username == NULL ){
        printf("\n*Invalid borrower*");
        return -1;
    }
    else if(loan == NULL){
        printf("\n*Book not detected*");
        return -1;
    }
    
    else{

        for(int i = 0; i<numLoans; i++){
            if( loans[i].userID == user.ID ){ //user ID match
                if( strcmp(loans[i].username,user.username) == 0 ){ //username match
                    if( loans[i].loanBook.ID == loan->ID){ //book ID match
                        if( strcmp(loans[i].loanBook.title, loan->title ) == 0 ){ //book title match
                            printf("\nYou already hold a copy of this book !");
                            return -1;
                        }
                    }
                }
            }
        }

        //get book from library
        for(int i = 0; i<numBooks; i++){
            if( strcmp(library[i].authors, loan->authors) == 0){
                if( strcmp(library[i].title, loan->title) == 0){
                    if( library[i].year = loan->year){
                        *loan = library[i];
                        library[i].copies = library[i].copies - 1;
                    }
                }
            }
        }

        loans[numLoans].loanBook = *loan;
        loans[numLoans].loanBook.copies = 1;
        loan->copies = loan->copies - 1;

        loans[numLoans].userID = user.ID;
//        loans[numLoans].username = (char*)malloc(sizeof(char*)*MAX_STRING);
        loans[numLoans].username = user.username;

        printf("\n *Successfully borrowed book* ");
        free(found_book);
        numLoans++;
        return 0;
    }

}


int return_books(struct User user){
    //allows current user to return book to the library. Should decrease the value of the copies in the loan array and increment in the library.
    if(user.username == NULL){
        printf("\n*Invalid User Detected*");
        return -1;
    }

    else{

        //if no books to return
        int userReturnCount = 0;

        printf("|%-3s|-|%-25s|-|%-25s|-|%-3s|-|%-3s| \n","ID","Author","Title","Year","Copies");
        for(int i=0; i<numLoans; i++){
            if( strcmp(loans[i].username, user.username) == 0 && loans[i].userID == user.ID ){
                printf("|%-3d| |%-25s| |%-25s| |%-3d| |%-3d| \n",
                loans[i].loanBook.ID,loans[i].loanBook.authors, loans[i].loanBook.title, loans[i].loanBook.year, loans[i].loanBook.copies);
                userReturnCount++;
            }        
        }

        if(userReturnCount<1){
            printf("\n *No book to return.*");
            return 0;
        }

        int choice;
        printf("\nEnter ID of book you wish to return : ");
        scanf("%d",&choice);

        for(int i = 0; i<numLoans; i++){
            if( loans[i].loanBook.ID == choice ){//found book

                for(int a =0; a<numBooks; a++){ //find book in library and add one to copies
                    if( strcmp( library[a].authors, loans[i].loanBook.authors) == 0){
                        if(strcmp( library[a].title, loans[i].loanBook.title) == 0){
                            if(library[a].year == loans[i].loanBook.year){
                                library[a].copies = library[a].copies + 1;
                            }
                        }
                    }
                }

                for(int j = i; j<numLoans; j++){//remove book from loans
                    loans[j] = loans[j + 1];
                }

                printf("\n*Successfully returned book*");
                numLoans--;
                return 0;
            }
        }
        printf("\n *Failed to return book* ");
        return 0;
    }
}