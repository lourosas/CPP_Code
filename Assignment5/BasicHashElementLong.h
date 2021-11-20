/******************************************************************
**BasicHashElementLong Class
**A part of the ongoing work to fulfill my desire
**to create a generic data structure tool set for
**everyday application development.
**This class is designed exclusively for the BasicHashTableLong
**class.
**A class by Lou Rosas
******************************************************************/

#ifndef BASIC_HASH_ELEMENT_LONG_H
#define BASIC_HASH_ELEMENT_LONG_H

#include <typeinfo>
#include <iostream.h>
#include "Generic.h"
#include "GenericHashElement.h"

template <class Data>
class BasicHashElementLong : public GenericHashElement
{
   public:
      //Constructor with no arguments
      BasicHashElementLong();
      
      //Constructor setting the key and data attributes
      BasicHashElementLong(const long, const Data& );
      
      //Copy Constructor
      BasicHashElementLong(BasicHashElementLong<Data>& );
      
      //Destructor
      ~BasicHashElementLong();
      
      //Assignment Operator
      BasicHashElementLong<Data>& operator=(BasicHashElementLong<Data>& );
      
      //Set the key field
      int setKey(const long );
      
      //Set the data field
      int setData(const Data& );
      
      //Set the flag field
      int setFlag(const int = EMPTY );
      
      //Get the key field
      long getKey();
      
      //Get the data field
      void getData(Data& );
      
      //Get the flag field
      int getFlag();
      
      //Print out the attributes in the class
      void print();
      
   private:
      //The key attribute
      long key;
      
      //The flag attribute
      int flag;
      
      //the Data attribute
      Data data;
};
//Overload the insertion operator
template <class Data>
ostream& operator<<(ostream&, BasicHashElementLong<Data>& );

//Class Implementation
//Public Methods
/********************************************************************
* Constructor
* Constructor of no arguments
********************************************************************/
template <class Data>
BasicHashElementLong<Data>::BasicHashElementLong()
   : key(0),
     flag(0)
{
}

/********************************************************************
* Constructor that explicitly sets the key and data fields
********************************************************************/
template <class Data>
BasicHashElementLong<Data>::BasicHashElementLong
(
   const long the_key,
   const Data& the_data
)
   :  key(0),
      flag(0)
{
   this->setKey(the_key);
   this->setData(the_data);
}

/********************************************************************
* Copy constructor
* Copies One BHEL Object to another
********************************************************************/
template <class Data>
BasicHashElementLong<Data>::BasicHashElementLong
(
   BasicHashElementLong<Data>& copy_element
)
   :  key(0),
      flag(0)
{
   Data copy_data;
   
   //Copy the key, flag and data fields from one object into the
   //current object
   this->setKey(copy_element.getKey());
   this->setFlag(copy_element.getFlag());
   copy_element.getData(copy_data);
   this->setData(copy_data);
}

/********************************************************************
* Destructor
********************************************************************/
template <class Data>
BasicHashElementLong<Data>::~BasicHashElementLong()
{
   //Nothing to destroy
}

/*******************************************************************
* Assignement Operator
* Essentially follow the copy constructor
*******************************************************************/
template <class Data>
BasicHashElementLong<Data>& BasicHashElementLong<Data>::operator=
(
   BasicHashElementLong<Data>& basic_hash_element
)
{
   Data assignment_data;
   
   //Copy the key, flag and data fields of one object into the
   //current object
   this->setKey(basic_hash_element.getKey());
   this->setFlag(basic_hash_element.getFlag());
   basic_hash_element.getData(assignment_data);
   this->setData(assignment_data);
   
   return *this;
}

/********************************************************************
* Set the key field
********************************************************************/
template <class Data>
int BasicHashElementLong<Data>::setKey(const long key_data)
{
   this->key = key_data;
   return YES;
}

/********************************************************************
* Set the data field
********************************************************************/
template <class Data>
int BasicHashElementLong<Data>::setData(const Data& the_data)
{
   this->data = the_data;
   return YES;
}

/********************************************************************
* Set the flag field
********************************************************************/
template <class Data>
int BasicHashElementLong<Data>::setFlag(const int flag_data)
{
   int return_value = NO;
   if(flag_data >= EMPTY && flag_data <= SET)
   {
      this->flag = flag_data;
      return_value = YES;
   }
   return return_value;
}

/********************************************************************
* Get the key field
********************************************************************/
template <class Data>
long BasicHashElementLong<Data>::getKey()
{
   return this->key;
}

/********************************************************************
* Get the data field
********************************************************************/
template <class Data>
void BasicHashElementLong<Data>::getData(Data& the_data)
{
   the_data = this->data;
}

/********************************************************************
* Get the flag field
********************************************************************/
template <class Data>
int BasicHashElementLong<Data>::getFlag()
{
   return this->flag;
}

/********************************************************************
* A simple print method
********************************************************************/
template <class Data>
void BasicHashElementLong<Data>::print()
{
   cout<<"("<<this->key<<", "<<this->data<<")";
}

/*******************************************************************
* Overload the insertion operator
*******************************************************************/
template <class Data>
ostream& operator<<(ostream& os, BasicHashElementLong<Data>& bhel)
{
   bhel.print();
   return os;
}

#endif
