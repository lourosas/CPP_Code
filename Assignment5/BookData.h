/********************************************************************
* A Class used for storing a book's title and ISBN.
* A class by Lou Rosas
********************************************************************/

#ifndef BOOK_DATA_H
#define BOOK_DATA_H

#include <string.h>
#include <iostream.h>
#include "Generic.h"

class BookData
{
   public:
      //Constructor of no arguments
      BookData();
      
      //Constructor setting the title and ISBN
      BookData(char*, unsigned long);
      
      //Copy Constructor
      BookData(BookData& );
      
      //Destructor
      ~BookData();
      
      //Assignment Operator
      BookData& operator=(const BookData& );

      //Comparison Operator
      int operator==(const BookData& );
      
      //Set the title field
      int setTitle(char* );
      
      //Set the ISBN
      int setISBN(unsigned long );
      
      //Get the title field
      void getTitle(char* ) const;
      
      //Get the ISBN
      unsigned long getISBN()const;
      
      //print method
      void print();
      
   private:
      char* title;
      unsigned long ISBN;
};
ostream& operator<<(ostream&, BookData& );

#endif
