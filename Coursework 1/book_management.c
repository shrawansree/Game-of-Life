//book_management function file
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
Date Work Commenced: 2nd February 2021
*************************************************************************/

#include "library_management.h"


//declaration
struct Book *library[stockSize];
int numBooks;

//***********************************************************************

struct Book* addRemBook(struct BookArray foundBooks, const char searchString[99]){
    //function to add/remove books from library by title or author
    //returns 0 if successfully added or removed book
    //char type variable used to control : "a" to add ; "r" to remove by author 
    
    if(foundBooks.array == NULL) return -1;
    else{
        struct Book* returnBook; //pointer to found book

        if(searchString == NULL) return -1;

        //look into the array of books supplied to find exact book to add
        else{
            for(int i = 0; i<foundBooks.length; i++){
                //try to find exact book
                if(foundBooks.array[i].authors == searchString){ returnBook = &foundBooks.array[i]; return returnBook; }
                else if(foundBooks.array[i].title == searchString){ returnBook = &foundBooks.array[i]; return returnBook; }
                else {returnBook = NULL ; return returnBook;}

                //dont forget to free the returned pointer
            }
        }

    }
}


int stringSearch(struct Book findBook, char bookSearch[99],char type[1]){

    if(findBook.authors == NULL && findBook.title == NULL) return -1;
    else{
        //attempt to find string within string
        char* testPtr = (char*)malloc(sizeof(char*)); //to test for presence of string within string

        if(type != "t" && type != "a") return -2;
        else if (type == "t"){
            //find book by title
            testPtr = strstr(findBook.title,bookSearch);
            if(testPtr == NULL){
                free(testPtr);
                return -1; 
            } 
            else{
                free(testPtr);
                return 0;
            }
        } 
        else{
            //find book by author
            testPtr = strstr(findBook.authors,bookSearch);
            if(testPtr == NULL){
                free(testPtr);
                return -1; 
            } 
            else{
                free(testPtr);
                return 0;
            }

        }

    }
}


struct BookArray find_book_by_title (const char *title){

    //finds books with a given title.
    //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
    //provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
    //array is the null pointer.

    struct BookArray returnArr; //self explanatory : value to be returned from function
    returnArr.array = NULL;
    returnArr.length = 0;

    struct Book** bookArr[stockSize]; //array of books to be pointed to by returnArr.array - make sure to free after calling function

    if(title == NULL){
        return returnArr;
    }
    else{
        //loop into the library array to find the book (or attempt to find closest match)
        struct Book findTitle; //dereference book from library
        int searchResult; //search result from stringSearch function
        int elementCount = 0; //number of total books retrieved
        int bookArrCount = 0; //to ensure found books are ordered correctly in the array of books


        for(int i = 0; i<numBooks ; i++){
            findTitle = *library[i];
            searchResult = stringSearch(findTitle,title,"t");

            if(searchResult == 0){
                bookArr[bookArrCount] = &library[i];
                elementCount = library[i]->copies + elementCount;
                bookArrCount++;
            }

        }

        returnArr.array = bookArr;
        returnArr.length = bookArrCount; //switch to element count as needed

        return returnArr;
    }

}


struct BookArray find_book_by_author (const char *author){

    //finds books with a given author.
    //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
    //provided author can be found. The length of the array is also recorded in the returned structure, with 0 in case
    //array is the null pointer.

    struct BookArray returnArr; //self explanatory : value to be returned from function
    returnArr.array = NULL;
    returnArr.length = 0;

    struct Book* bookArr[stockSize]; //array of books to be pointed to by returnArr.array - make sure to free after calling function

    if(author == NULL){
        return returnArr;
    }
    else{
        //loop into the library array to find the book (or attempt to find closest match)
        struct Book findAuthor; //dereference book from library
        int searchResult; //search result from stringSearch function
        int elementCount = 0; //number of total books retrieved
        int bookArrCount = 0; //to ensure found books are ordered correctly in the array of books


        for(int i = 0; i<numBooks ; i++){
            findAuthor = *library[i];
            searchResult = stringSearch(findAuthor,author,"a");

            if(searchResult == 0){
                bookArr[bookArrCount] = library[i];
                elementCount = library[i]->copies + elementCount;
                bookArrCount++;
            }

        }

        returnArr.array = bookArr;
        returnArr.length = bookArrCount; //switch to element count as needed

        return returnArr;
    }

}


struct BookArray find_book_by_year (unsigned int year){

    //finds books published in the given year.
    //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
    //provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
    //array is the null pointer.

    struct BookArray returnArr; //self explanatory : value to be returned from function
    returnArr.array = NULL;
    returnArr.length = 0;

    struct Book* bookArr[stockSize]; //array of books to be pointed to by returnArr.array - make sure to free after calling function

    if(year < 1){
        return returnArr;
    }
    else{
        //loop into the library array to find the book (or attempt to find closest match)
        struct Book findYear; //dereference book from library
        int searchResult; //search result from stringSearch function
        int elementCount = 0; //number of total books retrieved
        int bookArrCount = 0; //to ensure found books are ordered correctly in the array of books


        for(int i = 0; i<numBooks ; i++){
            findYear = *library[i];

            if(findYear.year == year){
                bookArr[bookArrCount] = library[i];
                elementCount = library[i]->copies + elementCount;
                bookArrCount++;
            }

        }

        returnArr.array = bookArr;
        returnArr.length = bookArrCount; //switch to element count as needed

        return returnArr;
    }    

}


int store_books(FILE *file){

    //saves the database of books in the specified file
    //returns 0 if books were stored correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{
        
        fwrite(&numBooks,sizeof(int),1,file);
        fwrite(&library,sizeof(struct Book),numBooks,file);

        return 0;
    }
}


int load_books(FILE *file){

    //loads the database of books from the specified file
    //the file must have been generated by a previous call to store_books()
    //returns 0 if books were loaded correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{
        *library = (struct Book*)malloc(sizeof(struct Book*)*stockSize);

        fread(&numBooks,sizeof(int),1,file);
        fread(&library,sizeof(struct Book),numBooks,file); //dont forget to free the *library array

        return 0;
    }
}


int add_book(struct Book book){

    //adds a book to the ones available to the library
    //returns 0 if the book could be added, or an error code otherwise
    char findBook[100];  //attempt to find the book within the library
    
    if(book.title == NULL || book.authors == NULL) return -1;
    else{
        //attempting to find book in library
        struct Book* foundBook = (struct Book*)malloc(sizeof(struct Book*)); //catch found book 

        if(find_book_by_author(book.authors).length == 0){

            if(find_book_by_title(book.title).length == 0){ return -1; }
            else{
                //add book by title
                foundBook = addRemBook(find_book_by_title(book.title), book.title);

                if(foundBook == NULL){ //if exact book is not found : add book to library
                    library[numBooks+1]->authors =  book.authors;
                    library[numBooks+1]->title = book.title;
                    library[numBooks+1]->copies = book.copies;
                    library[numBooks+1]->year = book.year;
                    numBooks++;
                    free(foundBook);
                    return 0;
                }
                else{ //if exact book found : add copy to library
                    foundBook->copies = foundBook->copies + 1;
                    free(foundBook);
                    return 0;
                }
            }
        }
        
        else{
            //add book by author
            foundBook = addRemBook(find_book_by_author(book.authors), book.authors);

            if(foundBook == NULL){ //if exact book is not found : add book to library
                library[numBooks+1]->authors =  book.authors;
                library[numBooks+1]->title = book.title;
                library[numBooks+1]->copies = book.copies;
                library[numBooks+1]->year = book.year;
                free(foundBook);
                return 0;
            }
            else{ //if exact book found : add copy to library
                foundBook->copies = foundBook->copies + 1;
                free(foundBook);
                return 0;
            }
        }

    }


}


int remove_book(struct Book book){

    //removes a book from the library
    //returns 0 if the book could be successfully removed, or an error code otherwise.

    char findBook[100];  //attempt to find the book within the library
    
    if(book.title == NULL || book.authors == NULL) return -1;
    else{
        struct Book* foundBook = (struct Book*)malloc(sizeof(struct Book*)); //catch found book 

        //attempting to find book in library
        if(find_book_by_author(book.authors).length == 0){

            if(find_book_by_title(book.title).length == 0){return -1;}
            else{
                //find book by title
                foundBook = addRemBook(find_book_by_title(book.title),book.title);
                if(foundBook==NULL){ free(foundBook); return -1; }
                else{
                    foundBook->authors = NULL;
                    foundBook->copies = NULL;
                    foundBook->title = NULL;
                    foundBook->year = NULL;

                    free(foundBook);
                    return 0;
                }
            }
        }
        else{
            //find book by author
            foundBook = addRemBook(find_book_by_title(book.title),book.title);
            if(foundBook==NULL){ free(foundBook); return -1; }
            else{
                foundBook->authors = NULL;
                foundBook->copies = NULL;
                foundBook->title = NULL;
                foundBook->year = NULL;

                free(foundBook);
                    return 0;        
            }    
        }
    }
}


//test main function
int main(){

    //testing code goes here

}
