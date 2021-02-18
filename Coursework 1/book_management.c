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

struct Book library[library_size]; //array of  books in library
static int numBooks = 0;
static char *output;
//******************| additional created functions for book_management.c |******************

char *returnString(const char *prompt) {
    //function to return string
    fflush(stdin);
	printf("%s",prompt);

    size_t size = 32;
    char temp[1024];
    char *output = malloc(sizeof(char)*1024);

    fgets(temp,1023,stdin);

    temp[strcspn(temp,"\n")] = 0;
    strcpy(output,temp);
	return output;
}




//***********************************************************************

struct BookArray find_book_by_title (const char *title){

    //finds books with a given title.
    //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
    //provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
    //array is the null pointer.
    struct BookArray returnArray; 
    returnArray.array[loan_size];
    returnArray.array = (struct Book*)malloc(sizeof(struct Book*)*loan_size);
    returnArray.length = 0; //set to 0

    if(title == NULL) return returnArray; //check if input empty
    else{
        //find book using title
        for(int i=0; i<numBooks; i++){
            if(strstr(library[i].title,title) != NULL){
                returnArray.array[returnArray.length] = library[i];
                returnArray.length++;
            }
        }

        return returnArray;
    }
}


struct BookArray find_book_by_author (const char *author){

    //finds books with a given author.
    //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
    //provided author can be found. The length of the array is also recorded in the returned structure, with 0 in case
    //array is the null pointer.

    struct BookArray returnArray; 
    returnArray.array[loan_size];
    returnArray.array = (struct Book*)malloc(sizeof(struct Book*)*loan_size);
    returnArray.length = 0; //set to 0

    if(author == NULL) return returnArray;
    else{
        //find book using author
        for(int i=0; i<numBooks; i++){
            if(strstr(library[i].authors,author) != NULL){
                returnArray.array[returnArray.length] = library[i];
                returnArray.length++;
            }
        }

        return returnArray;
    }
}


struct BookArray find_book_by_year (unsigned int year){

    //finds books published in the given year.
    //returns a BookArray structure, where the field "array" is a newly allocated array of books, or null if no book with the 
    //provided title can be found. The length of the array is also recorded in the returned structure, with 0 in case
    //array is the null pointer.

    struct BookArray returnArray; 
    returnArray.array[loan_size];
    returnArray.array = (struct Book*)malloc(sizeof(struct Book*)*loan_size);
    returnArray.length = 0; //set to 0
    
    if(year < 0) return returnArray; //check if input empty

    else{
        //find book using year
        for(int i=0; i<numBooks; i++){
            if(library[i].year == year){
                returnArray.array[returnArray.length] = library[i];
                returnArray.length++;
            }
        }

        return returnArray;
    }

}
 

int store_books(FILE *file){

    //saves the database of books in the specified file
    //returns 0 if books were stored correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{
        char tmpauthor[50];
        char tmptitle[50];

        fprintf(file,"%d\n",numBooks);
        for(int i=0; i<numBooks; i++){
            strcpy(tmpauthor,library[i].authors);
            strcpy(tmptitle,library[i].title);

               fprintf(file,"%d \t %s \n %s \n %d \t %d \n",
                            library[i].ID, tmpauthor, tmptitle , library[i].year, library[i].copies);

        }
        fclose(file);
        return 0;
    }
}


int load_books(FILE *file){ 

    //loads the database of books from the specified file
    //the file must have been generated by a previous call to store_books()
    //returns 0 if books were loaded correctly, or an error code otherwise
    if(file == NULL) return -1;
    else{

        fscanf(file,"%d\n",&numBooks); 
        char tmpAut[1024];
        char tmpTitle[1024];

        for(int i=0; i<numBooks; i++){

            fscanf(file,"%d \t",&library[i].ID);
            fgets(tmpAut,1024,file);
            fgets(tmpTitle,1024,file);
            fscanf(file,"%d \t",&library[i].year);
            fscanf(file,"%d \n",&library[i].copies);

            tmpAut[strcspn(tmpAut,"\n")] = 0;
            tmpTitle[strcspn(tmpTitle,"\n")] = 0;

            library[i].authors = strdup(tmpAut);
            library[i].title = strdup(tmpTitle);
             //dont forget to free the *library array
        }
        fclose(file);
        return 0;
    }
}


int add_book(struct Book book){

    //adds a book to the ones available to the library
    //returns 0 if the book could be added, or an error code otherwise
    if(book.authors == NULL) return -1;
    else if(book.title == NULL) return -1;
    else{
        
        library[numBooks].ID = numBooks+1;
        library[numBooks].authors = book.authors;
        library[numBooks].title = book.title;
        library[numBooks].year = book.year;
        library[numBooks].copies = book.copies;

        numBooks++; 
        printf("\nSuccessfully added book \n");
        return 0;
    }

}


int remove_book(struct Book book){

    //removes a book from the library
    //returns 0 if the book could be successfully removed, or an error code otherwise.
    if(book.authors == NULL)return -1;
    else if(book.title == NULL) return -1;
    else{
        for(int i =0; i<numBooks; i++){
            if( strcmp(library[i].authors, book.authors) == 0 ){
                if( strcmp(library[i].title, book.title ) == 0 ){
                    for(int j = i; j<numBooks; j++){
                        library[j] = library[j + 1];
                    }
                    numBooks--;
                    printf("Successfully removed book\n");
                    return 0;
                }
            }
        }

        printf("Sorry! Could not remove book.\n");
        return -1;
    }

}

const struct Book create_book(){
    //creates a new Book to be added to the library
    
    struct Book newBook;

    newBook.authors = returnString("Enter Author : ");
    free(output);
    newBook.title = returnString("Enter Title : ");
    free(output);
    printf("\nEnter Year : ");
    scanf("%d",&newBook.year);

    printf("Enter Copies : ");
    scanf("%d",&newBook.copies);

    return newBook;
}


int display_all_book(){
    //function to display all books
    printf("|%-3s|-|%-25s|-|%-25s|-|%-3s|-|%-3s| \n","ID","Author","Title","Year","Copies");
    for(int i=0; i<numBooks; i++){
        printf("|%-3d| |%-25s| |%-25s| |%-3d| |%-3d| \n",
            library[i].ID, library[i].authors, library[i].title, library[i].year, library[i].copies);
    }
}

//test main function
int main(){

    //if(library){//attempt to load library if already present
    FILE *ptr = fopen("library.txt","r+");
    load_books(ptr);
    free(ptr);  
    //}

    // add_book(create_book());
    // add_book(create_book());
 
    // display_book();
    // FILE *ftprw = fopen("library.txt","w+");
    // store_books(ftprw);
    // free(ftprw);

    // struct Book remover;
    // remover.authors = "asd";
    // remover.title = "qwe";
    // remover.year = 1990;

    // remove_book(remover);
    // display_book();
    // FILE *ftprr = fopen("library.txt","r+");
    // load_books(ftprr);
    // free(ftprr);
    display_all_book();

    struct BookArray testArray;
    testArray = find_book_by_title("fggr");

    printf("|%-3s|-|%-25s|-|%-25s|-|%-3s|-|%-3s| \n","ID","Author","Title","Year","Copies");
    for(int i=0; i< testArray.length; i++){
        printf("|%-3d| |%-25s| |%-25s| |%-3d| |%-3d| \n",
            testArray.array[i].ID,  testArray.array[i].authors,  testArray.array[i].title,  testArray.array[i].year,  testArray.array[i].copies);
    }
}
    //testing code goes here}
