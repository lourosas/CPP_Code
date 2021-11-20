/********************************************************************
* The implementation file of BookData.h
********************************************************************/

#include <iostream.h>
#include <string.h>
#include "Generic.h"
#include "BookData.h"

/*******************************************************************
* Constructor of No Arguments
*******************************************************************/
BookData::BookData()
  : title(0),
    ISBN(0)
 {
 }
 
/*******************************************************************
* Constructor of setting the title and ISBN fields
*******************************************************************/
BookData::BookData(char* the_title, unsigned long isbn_number)
  : title(0),
    ISBN(0)
{
   this->setTitle(the_title);
   this->setISBN(isbn_number);
}

/********************************************************************
* Copy constructor
********************************************************************/
BookData::BookData(BookData& book)
  : title(0),
    ISBN(0)
{
   char* temp_title = new char[256];
   
   book.getTitle(temp_title);
   this->setTitle(temp_title);
   this->setISBN(book.getISBN());
   
   delete [] temp_title;
   temp_title = NULL;
}

/********************************************************************
* Destructor
********************************************************************/
BookData::~BookData()
{
   delete [] this->title;
   this->title =  NULL;
}

/********************************************************************
* Assignment Operator
********************************************************************/
BookData& BookData::operator=(const BookData& book)
{
   char* temp_title = new char[256];
   
   book.getTitle(temp_title);
   this->setTitle(temp_title);
   this->setISBN(book.getISBN());
   
   delete [] temp_title;
   temp_title = NULL;
   
   return *this;
}

/********************************************************************
* Logical Comparison Operator
********************************************************************/
int BookData::operator==(const BookData& book)
{
   int return_value = NO;
   
   char* book_title = new char[256];
   
   book.getTitle(book_title);
   if((!(strcmp(book_title, this->title))) && 
      (book.getISBN() == this->ISBN))
   {
      return_value = YES;
   }
   
   delete [] book_title;
   book_title = NULL;
   
   return return_value;
}

/********************************************************************
* Set the Title field
********************************************************************/
int BookData::setTitle(char* the_title)
{
   int set_value = NO;
   
   delete [] this->title;
   this->title = NULL;
   
   this->title = new char[strlen(the_title) + 1];
   if(this->title)
   {
      strcpy(this->title,the_title);
      set_value = YES;
   }
   
   return set_value;   
}

/********************************************************************
* Set the ISBN field
********************************************************************/
int BookData::setISBN(unsigned long the_isbn)
{
   int set_value = NO;

   if(the_isbn > 0)
   {   
      this->ISBN = the_isbn;
      set_value  = YES;
   }

   return set_value;
}

/********************************************************************
* Get the book's title
********************************************************************/
void BookData::getTitle(char* get_title) const
{
   if(get_title && this->title)
   {
      strcpy(get_title,this->title);
   }
}

/********************************************************************
* Get the books ISBN
********************************************************************/
unsigned long BookData::getISBN() const
{
   return this->ISBN;
}

/********************************************************************
* Print out the data
********************************************************************/
void BookData::print()
{
   cout<<"\nTitle: "<<this->title;
   cout<<"\nISBN:  "<<this->ISBN;
}

/********************************************************************
* Overload the insertion operator
********************************************************************/
ostream& operator<<(ostream& os, BookData& bd)
{
   bd.print();
   return os;
}
