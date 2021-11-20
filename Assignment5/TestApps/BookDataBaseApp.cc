//This program is a book data base application used for the storage,
//retrieval and modification of book related data.
//By Lou Rosas

#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include "BookData.h"
#include "BasicHashTableLong.h"
#include "MathTools.h"

void displayOptions();
void setUpBookDataBase();
void printBookDataBase();
int  readBookDataBase(int );
void modifyBookDataBase(int );
void removeBook(int );
void convertToUpperCase(char* );

BookData book;
BasicHashTableLong<BookData> book_data_base;

int main()
{
   displayOptions();
   cout<<"\nHello World\n";
   return 0;
}

void displayOptions()
{
   const int CHECK_TITLE  = 0;
   const int CHECK_ISBN   = 1;
   const int MODIFY_TITLE = 0;
   const int MODIFY_ISBN  = 1;
   const int REMOVE_TITLE = 0;
   const int REMOVE_ISBN  = 1;
   
   //input charater
   char input;
     
   do{
      cout<<"\n\nType the following: \n";
      cout<<"\n1-To input a book: title and ISBN";
      cout<<"\n2-To print out all the books in the collection";
      cout<<"\n3-To see if a book is in the collection by title";
      cout<<"\n4-To see if a book is in the collection by ISBN";
      cout<<"\n5-Modify the title of the book (if in the data base)";
      cout<<"\n6-Modify the ISBN of the book (if in the data base)";
      cout<<"\n7-Remove a book from the database by title";
      cout<<"\n8-Remove a book from the database by ISBN";
      cout<<"\n0-Quit.";
      cout<<"\nSelection: ";
      cin>>input;
      switch(input)
      {
         case '0':
	 case 'q':
	 case 'Q': 
	    break; //The user wants to quit:  do nothing
         case '1':
	    setUpBookDataBase();
	    break;
	 case '2':
	    printBookDataBase();
	    break;
	 case '3':
	    readBookDataBase(CHECK_TITLE);
	    break;
	 case '4':
	    readBookDataBase(CHECK_ISBN);
	    break;
	 case '5':
	    modifyBookDataBase(MODIFY_TITLE);
	    break;
	 case '6':
	    modifyBookDataBase(MODIFY_ISBN);
	    break;
	 case '7':
	    removeBook(REMOVE_TITLE);
	    break;
	 case '8':
	    removeBook(REMOVE_ISBN);
	    break;
         default:
	    cout<<"\n\nWrong selection: please try again\n\n";
      }
   }while(input != '0'&& input != 'q' && input != 'Q');
}

void setUpBookDataBase()
{
   char to_continue = 'y'; //The continuation input
   char title[250];  //Hopefully a title won't be this long!
   unsigned int isbn;
   
   do{
      //ignore the first return character
      cin.ignore();
      //Get the book title
      cout<<"Book Title: ";cin.get(title,250);
      cin.ignore();//ignore the return character
      cout<<"ISBN:  ";cin>>isbn;
      convertToUpperCase(title);
      book.setTitle(title);
      book.setISBN(isbn);
      book_data_base.insert(book.getISBN(),book);
      cout<<"\nto continue: 'y' or 'n'  ";cin>>to_continue;
      cout<<endl;
   }while(to_continue == 'y' || to_continue == 'Y');
}

void printBookDataBase()
{
   int data_base_size = book_data_base.getSetSize();
   BookData books[data_base_size];
   
   char current_title[250];
   
   cout<<"\n\n\nThe complete set of books in the Data Base are as "
     <<"follows: \n";
   cout<<"-----------------------------------------------------------"
     <<"------\n";
   int book_number = book_data_base.getElements(books);
   for(int i = 0; i < book_number; i++)
   {
      books[i].getTitle(current_title);
      cout<<"\nTitle: "<<current_title;
      cout<<"\nISBN:  "<<books[i].getISBN()<<endl;
   }
   cout<<"\nNumber of Books in Library:  "<<book_number
      <<endl<<endl;
}

int  readBookDataBase(int view_choice)
{
   int return_value = -1;
   BookData current_books[book_data_base.getSetSize()];
   int number_of_books = book_data_base.getElements(current_books);
   
   int is_title_found = NO;
   int is_isbn_found  = NO;
   
   char search_book_title[250];
   char current_book_title[250];
   
   unsigned long current_isbn = 0xFFFFFFFF;
   
   //Ignore the <ENTER> button press
   cin.ignore();
   
   if(number_of_books)
   {
      if(!view_choice)
      {
         cout<<"\n\nBook Title: "; 
         cin.get(search_book_title,250);
         cin.ignore();
	 convertToUpperCase(search_book_title);
      }
      else
      {
         cout<<"\n\nBook ISBN: ";
	 cin>>current_isbn;
	 cin.ignore();
      }
      for(int i = 0; i < number_of_books; i++)
      {
         if(!view_choice)
	 {
	    current_books[i].getTitle(current_book_title);
	    if(!(strcmp(search_book_title, current_book_title)))
	    {
	       is_title_found = YES;
	       return_value = i;
	    }
	 }
	 else if(current_isbn == current_books[i].getISBN())
	 {
	    is_isbn_found = YES;
	    return_value = i;
	 }
	 if(is_title_found || is_isbn_found)
	 {
	    cout<<endl<<current_books[i]<<endl;
	    i = number_of_books;
	 }
      }
      if(!(is_title_found || is_isbn_found))
      {
         cout<<"\n\nBook not found in data base.\n\n";
      }
   }
   else
   {
      cout<<"\n\nTHERE ARE CURRENTLY NO BOOKS IN THE DATA BASE.\n\n";
   }
   return return_value;
}

void modifyBookDataBase(int modification_choice)
{
   const int BY_TITLE = 0;
   const int BY_ISBN  = 1;
   
   char current_title[250];
   char changed_title[250];

   int current_book_index;
   unsigned long current_isbn;
   unsigned long changed_isbn;
   
   BookData current_books[book_data_base.getSetSize()];
   int number_of_books = book_data_base.getElements(current_books);
   
   if((!modification_choice))
   {
      current_book_index = readBookDataBase(BY_ISBN);
   }
   else
   {
      current_book_index = readBookDataBase(BY_TITLE);
   }
   if(current_book_index != -1 && !(modification_choice))
   {
      cout<<"\nEnter the the new title: ";
      cin.get(changed_title,250);
      convertToUpperCase(changed_title);
      cin.ignore();
      current_books[current_book_index].setTitle(changed_title);
      book_data_base.insert(
         current_books[current_book_index].getISBN(),
	 current_books[current_book_index]);
   }
   else if(current_book_index != -1)
   {
      BookData temp_book;
      current_isbn = current_books[current_book_index].getISBN();
      cout<<"\nEnter the new ISBN: ";cin>>changed_isbn;
      book_data_base.remove(current_isbn,temp_book);
      temp_book.setISBN(changed_isbn);
      book_data_base.insert(temp_book.getISBN(),temp_book);
   }
   else
   {
      cout<<"\nThat book can not be currently modified in this "
         <<"Data Base.";
   }
}

void removeBook(int by_isbn)
{
   const int BY_TITLE = 0;
   const int BY_ISBN  = 1;
   
   unsigned long current_isbn = 0xFFFFFFFF;
   int current_book_index;
   char temp_title[250];
   BookData temp_book;
   BookData current_books[book_data_base.getSetSize()];
   book_data_base.getElements(current_books);
   
   if(!by_isbn)
   {
      current_book_index = readBookDataBase(BY_TITLE);
   }
   else
   {
      current_book_index = readBookDataBase(BY_ISBN);
   }
   current_isbn = current_books[current_book_index].getISBN();
   if(current_book_index != -1)
   {
      book_data_base.remove(current_isbn, temp_book);
      temp_book.getTitle(temp_title);
      cout<<"\nRemoved: "<<"\nBook Title: "<<temp_title
        <<"\nISBN: "<<temp_book.getISBN();
   }
   else
   {
      cout<<"\nBook currently not in this data base.";
   }
}

void convertToUpperCase(char* word)
{
   int length = strlen(word);
   for(int i = 0; i < length; i++)
   {
      word[i] = toupper(word[i]);
   }
}
