/********************************************************************
* BasicHashElementChar class
* A part of the ongoing work to fullfill my desire
* to create a generic data structure tool set for
* everyday application development.
* This class is designed exclusively for the BasicHashTableChar
* class.
* A class by Lou Rosas
********************************************************************/

#ifndef BASIC_HASH_ELEMENT_CHAR_H
#define BASIC_HASH_ELEMENT_CHAR_H

#include <typeinfo>
#include <iostream.h>
#include <string.h>
#include "Generic.h"
#include "GenericHashElement.h"

template <class Data>
class BasicHashElementChar : public GenericHashElement
{
   public:
      //Constructor with no arguments
      BasicHashElementChar();
      
      //Constructor setting the key and data attributes
      BasicHashElementChar(char*, const Data& );
      
      //Copy Constructor
      BasicHashElementChar(BasicHashElementChar<Data>& );
      
      //Destructor
      ~BasicHashElementChar();
      
      //Assignment Operator
      BasicHashElementChar<Data>& operator=(BasicHashElementChar<Data>& );
      
      //Set the key field
      int setKey(char* );
      
      //Set the data field
      int setData(const Data& );
      
      //Set the flag field
      int setFlag(const int = EMPTY);
      
      //Get the key field
      void getKey(char* );
      
      //Get the data field
      void getData(Data& );
      
      //Get the flag field
      int getFlag();
      
      //Print out the attributes in the class
      void print();
      
   private:
      //The key attribute
      char* key;
      
      //the flag attribute
      int flag;
      
      //the data attribute
      Data data;
};
//Overload the insertion operator
template <class Data>
ostream& operator<<(ostream& os, const BasicHashElementChar<Data>& );

//Class Implementations
//Public Methods
/**********************************************************************
* Constructor
* Constructor of no arguments
**********************************************************************/
template <class Data>
BasicHashElementChar<Data>::BasicHashElementChar()
   : key(NULL),
     flag(0),
     data(0)
{
   this->setKey("");
}

/**********************************************************************
* Constructor that explicitly sets the key and data fields
**********************************************************************/
template <class Data>
BasicHashElementChar<Data>::BasicHashElementChar
(
   char* the_key,
   const Data& the_data
)
   : key(NULL),
     flag(0),
     data(0)
{
   this->setKey(the_key);
   this->setData(the_data);
}

/**********************************************************************
* Copy Constructor
* Copies one BasicHashElementChar object to another
**********************************************************************/
template <class Data>
BasicHashElementChar<Data>::BasicHashElementChar
(
   BasicHashElementChar<Data>& copy_element
)
   : key(NULL),
     flag(0),
     data(0)
{
   char copy_key[500];
   Data copy_data;
   
   //Copy the key, flag and data fields from one object into the
   //current object
   copy_element.getKey(copy_key);
   this->setKey(copy_key);
   
   this->setFlag(copy_element.getFlag());
   
   copy_element.getData(copy_data);
   this->setData(copy_data);
}

/**********************************************************************
* Destructor
**********************************************************************/
template <class Data>
BasicHashElementChar<Data>::~BasicHashElementChar()
{
   delete [] this->key;
   this->key = NULL;
}

/**********************************************************************
* Assignement Operator
* Essentially follow the copy constructor
**********************************************************************/
template <class Data>
BasicHashElementChar<Data>& BasicHashElementChar<Data>::operator=
(
   BasicHashElementChar<Data>& basic_hash_element_char
)
{
   char copy_key[500];
   Data copy_data;
   
   //Copy the key, flag and data fields from one object into the
   //current object
   basic_hash_element_char.getKey(copy_key);
   this->setKey(copy_key);
   
   this->setFlag(basic_hash_element_char.getFlag());
   
   basic_hash_element_char.getData(copy_data);
   this->setData(copy_data);
}

/**********************************************************************
* Set the key field
**********************************************************************/
template <class Data>
int BasicHashElementChar<Data>::setKey(char* key_data)
{
   int return_value = NO;
   
   delete [] this->key;
   this->key = NULL;
   
   this->key = new char[strlen(key_data) + 1];
   if(this->key)
   {
      strcpy(this->key,key_data);
      return_value = YES;
   }
   return return_value;
}

/**********************************************************************
* Set the data field
**********************************************************************/
template <class Data>
int BasicHashElementChar<Data>::setData(const Data& the_data)
{
   this->data = the_data;
   return YES;
}

/**********************************************************************
* Set the flag field
**********************************************************************/
template <class Data>
int BasicHashElementChar<Data>::setFlag(const int the_flag)
{
   this->flag = the_flag;
   return YES;
}

/**********************************************************************
* Get the key field
**********************************************************************/
template <class Data>
void BasicHashElementChar<Data>::getKey(char* the_key)
{
   if(this->key)
   {
      strcpy(the_key, this->key);
   }
   else
   {
      strcpy(the_key, "\0");
   }
}

/**********************************************************************
* Get the data field
**********************************************************************/
template <class Data>
void BasicHashElementChar<Data>::getData(Data& the_data)
{
   the_data = this->data;
}

/*********************************************************************
* Get the flag field
*********************************************************************/
template <class Data>
int BasicHashElementChar<Data>::getFlag()
{
   return this->flag;
}

/*********************************************************************
* A simple print method
*********************************************************************/
template <class Data>
void BasicHashElementChar<Data>::print()
{
   if(this->key)
      cout<<"("<<this->key<<", "<<this->data<<")";
   else
      cout<<"("<<'\0'<<", "<<this->data<<")";
}

/*********************************************************************
* Overload the insertion operator
*********************************************************************/
template <class Data>
ostream& operator<<(ostream& os, BasicHashElementChar<Data>& bhec)
{
   bhec.print();
   return os;
}

#endif
