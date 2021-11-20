//HashElement Class
//A generic data structures class
//Part of the ongoing work to fulfill my desire
//to create a generic data structure tool set
//for everyday application development
//This class is designed exclusively for the HastTable class
//A class by Lou Rosas

#ifndef HASH_ELEMENT_H
#define HASH_ELEMENT_H

//#include "Generic.h"
#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <typeinfo>

template <class Key, class Data>
class HashElement
{
   public:
      //Constructor with no arguments
      HashElement();

      //Constructor setting the key and data fields
      HashElement(const Key&, const Data& );

      //Copy constructor
      HashElement(const HashElement<Key, Data>& );

      //Destructor
      ~HashElement();

      //Assignment Operator
      HashElement<Key, Data>& operator=(const HashElement<Key, Data>& );

      //Get the data field: method #1
      void getData(Data& );

      //Get the data field: method #2
      Data& getData();

      //Get the key field: method #1
      void getKey(Key& );

      //Get the key field: method #2
      Key& getKey();

      //Get the flag field
      int getFlag();

      //Set the data field
      virtual BOOLEAN setData(const Data& );

      //Set the Key field
      virtual BOOLEAN setKey(const Key& );

      //Set the Key Field for a char*
      virtual BOOLEAN setKeyString(const char* );

      //Set the flag field
      BOOLEAN setFlag(int );

      //The print method
      void print();

      //Simple flag values
      //No data in the HashElement object
      static const int EMPTY   = 0;
      //Indicates in-valid data in the HashElement--ussually
      //associated with a delete message in the HashTable
      static const int DELETED = 1;
      //Indicates valid data in the HashElement
      static const int SET     = 2;

   private:
      Key   key;
      char* key_string;
      Data  data;
      int   flag;
};
//Overload the insertion operator
template <class Key, class Data>
ostream& operator<<(ostream&, HashElement<Key, Data>& );

//Class Implementation
//Public Methods
/********************************************************************
* Constructor                                                       *
* Constructor of no attributes                                      *
********************************************************************/
template <class Key, class Data>
HashElement<Key, Data>::HashElement()
 :key(0),
  key_string(0),
  data(0),
  flag(0)
{
}

/********************************************************************
* Constructor that explicitly sets the key and data fields          *
* object                                                            *
********************************************************************/
template <class Key, class Data>
HashElement<Key, Data>::HashElement(const Key& key, const Data& the_data)
  :key(0),
   key_string(0),
   data(0),
   flag(0)
{
   cout<<endl<<endl<<typeid(Key).name()<<endl;
   if(typeid(Key) == typeid(char* ))
   {
      char* temp;
      cout<<"\nC++ sucks\n";
      temp = (char* )key;
      cout<<endl<<temp<<endl;
      this->setKeyString(temp);
   }
   else if(typeid(Key) == typeid(int))
   {
      int temp;
      cout<<"\nC++ really fucking sucks!!\n";
      temp = (int)key;
      cout<<endl<<temp<<endl;
      this->setKey(temp);
   }
   if(typeid(Key) == typeid(char* ))
   {
      cout<<endl<<this->key_string<<endl;
   }
}

/********************************************************************
* Copy constructor                                                  *
* Copies One HashElement Object fields to another HashElement Object*
* fields, completely separate in memory.                            *
********************************************************************/
template <class Key, class Data>
HashElement<Key, Data>::HashElement
(
   const HashElement<Key, Data>& copy_element
)
{
   
}

/********************************************************************
* Destructor                                                        *
********************************************************************/
template <class Key, class Data>
HashElement<Key, Data>::~HashElement()
{
   
}

/********************************************************************
* Assignment operator                                               *
* Essentially, follow what was done with the Copy Constructor       *
********************************************************************/
template <class Key, class Data>
HashElement<Key, Data>& HashElement<Key, Data>::operator=
(
   const HashElement<Key, Data>& hash_element
)
{
   return *this;
}

/********************************************************************
* Get the data field:  method #1                                    *
********************************************************************/
template <class Key, class Data>
void HashElement<Key, Data>::getData(Data& copy_data)
{
}

/********************************************************************
* Get the data field: method #2                                     *
********************************************************************/
template <class Key, class Data>
Data& HashElement<Key, Data>::getData()
{
   return this->data;
}

/********************************************************************
* Get the key field: method #1                                      *
********************************************************************/
template <class Key, class Data>
void HashElement<Key, Data>::getKey(Key& copy_key)
{
   
}

/********************************************************************
* Get the key field: method #2                                      *
********************************************************************/
template <class Key, class Data>
Key& HashElement<Key, Data>::getKey()
{
   return this->key;
}

/********************************************************************
* Return the flag field                                             *
********************************************************************/
template <class Key, class Data>
int HashElement<Key, Data>::getFlag()
{
   return this->flag;
}

/********************************************************************
* Set the data field based on the input                             *
********************************************************************/
template <class Key, class Data>
BOOLEAN HashElement<Key, Data>::setData(const Data& the_data)
{
   BOOLEAN return_bool = FALSE;
   return return_bool;
}

/********************************************************************
* Set the key field                                                 *
********************************************************************/
template <class Key, class Data>
BOOLEAN HashElement<Key, Data>::setKey(const Key& the_key)
{
   BOOLEAN return_bool = FALSE;
   this->key = the_key;
   return_bool = TRUE;
   return return_bool;
}

/********************************************************************
* Set the key field for a string                                    *
********************************************************************/
template <class Key, class Data>
BOOLEAN HashElement<Key, Data>::setKeyString(const char* the_key)
{
   BOOLEAN return_bool = FALSE;
   delete[] this->key_string;
   this->key_string = new char[strlen(the_key) + 1];
   if(key_string)
   {
      strcpy(this->key_string, the_key);
      return_bool = TRUE;
   }
   return  return_bool;
}
/********************************************************************
* The print method                                                  *
********************************************************************/
template <class Key, class Data>
void HashElement<Key, Data>::print()
{
   cout<<"( "<<this->key<<", "<<this->data<<") ";
}

/********************************************************************
* Insertion Operator                                                *
********************************************************************/
template <class Key, class Data>
ostream& operator<<(ostream& os, HashElement<Key, Data>& he)
{
   he.print();
   return os;
}
#endif
