//BasicHashElement Class
//A basic data structures class
//Part of the ongoing work to fulfill my desire
//to create a generic data structure tool set
//for everyday application development
//This class is designed exclusively for the BasicHastTable class
//A class by Lou Rosas

#ifndef BASIC_HASH_ELEMENT_H
#define BASIC_HASH_ELEMENT_H

#include <iostream.h>
#include <iomanip.h>
#include <string.h>
#include <typeinfo>

template <class Data>
class BasicHashElement
{
   public:
      //Constructor with no arguments
      BasicHashElement();

      //Constructor setting the Key and Data, with the Key being a
      //char*
      BasicHashElement(const char* ,const Data& );

      //Constructor setting the Key and Data, with the Key being a
      //long
      BasicHashElement(long, const Data& );

      //Copy Constructor
      BasicHashElement(BasicHashElement& );

      //Destructor
      ~BasicHashElement();

      //Assignment Operator
      BasicHashElement& operator=(BasicHashElement& );

      //Set the key, with the key being a char*
      int setKey(const char* );

      //Set the key, with the key being a long
      int setKey(long );

      //Set the data
      int setData(const Data& );

      //Set the Flag value (Default to EMPTY (0))
      int setFlag(int );

      //Return the key for key being a char*
      void getKey(char* );

      //Return the key for key being a long
      long getKey();

      //Return the Data
      void getData(Data& );

      //Return the flag value
      int getFlag();

      //Print the attributes
      void print();

      //public attributes
      //Simple flag values
     //No data stored in the BasicHashElement object
     static const int EMPTY   = 0;

     //Invalid data in the BasicHashElement object--ussually
     //associated with deleted data
     static const int DELETED = 1;

     //Valid data in the BasicHashElement object
     static const int SET     = 2;

   private:
     //No private methods

     //The key stored as a long type
     long key;

     //The key stored as a char*
     char* key_string;

     //The data
     Data data;

     //the flag field
     int flag;
};
//Overload the insertion operator
template <class Data>
ostream& operator<<(ostream&, const BasicHashElement<Data>& );

//Class Implementation
//Pulbic Methods
/********************************************************************
* Constructor                                                       *
* Constructor of no attributes                                      *
********************************************************************/
template <class Data>
BasicHashElement<Data>::BasicHashElement()
  : key(0),
    key_string(NULL),
    data(0),
    flag(0)
{
}

/********************************************************************
* Constructor that explicitly sets the key and data fields          *
* objects:  used for when the key is a char* type                   *
********************************************************************/
template <class Data>
BasicHashElement<Data>::BasicHashElement
(
   const char* the_key,
   const Data& the_data
)
  : key(0),
    key_string(NULL),
    data(0),
    flag(0)
{
   this->setKey(the_key);
   this->setData(the_data);
}

/********************************************************************
* Constructor that explicitly sets the key and data fields          *
* objects:  used for when the key is a long type                    *
********************************************************************/
template <class Data>
BasicHashElement<Data>::BasicHashElement
(
   long the_key,
   const Data& the_data
)
  : key(0),
    key_string(NULL),
    data(0),
    flag(0)
{
   this->setKey(the_key);
   this->setData(the_data);
}

/********************************************************************
* Copy constructor                                                  *
* Copies One BasicHashElement Object fields to another              *
* BasicHashElement Object fields, completely separate in memory.    *
********************************************************************/
template <class Data>
BasicHashElement<Data>::BasicHashElement
(
   BasicHashElement<Data>& copy_element
)
  : key(0),
    key_string(NULL),
    data(0),
    flag(0)
{
   char temp[256];
   Data  the_data;

   //Copy the data field
   copy_element.getData(the_data);
   this->setData(the_data);
   //Copy the flag field
   this->setFlag(copy_element.getFlag());
   //Check to see if the key field to be copied is of type char*
   copy_element.getKey(temp);
   //temp must be 'valid' (neither NULL nor "")
   if(temp && strcmp(temp,""))
   {
      //If temp is a char*, set the key_string field
      this->setKey(temp);
   }
   else
   {
      //If temp is not a char*, set the key field
      this->setKey(copy_element.getKey());
   }
}

/********************************************************************
* Destructor                                                        *
********************************************************************/
template <class Data>
BasicHashElement<Data>::~BasicHashElement()
{
   if(this->key_string)
   {
      delete [] this->key_string;
      this->key_string = NULL;
   }
}

/********************************************************************
* Assignment operator                                               *
* Essentially, follow what was done with the Copy Constructor       *
********************************************************************/
template <class Data>
BasicHashElement<Data>& BasicHashElement<Data>::operator=
(
   BasicHashElement<Data>& basic_hash_element
)
{
   char temp[256];
   Data the_data;

   //Copy the data field
   basic_hash_element.getData(the_data);
   this->setData(the_data);
   //Copyt the flag field
   this->setFlag(basic_hash_element.getFlag());
   //Check to see if the key field to be copied is of type char*
   basic_hash_element.getKey(temp);
   //temp must be a 'valid' string (neither NULL nor "")
   if(temp && strcmp(temp,""))
   {
      //If temp is a char*, set the key_string field
      this->setKey(temp);
   }
   else
   {
      //If temp is not a char*, set the key field
      this->setKey(basic_hash_element.getKey());
   }
   return *this;
}

/********************************************************************
* Get the data field                                                *
* NOTE:  the assigment operator MUST be defined for the Data type   *
*        in order to message this method.  If the assigment operator*
*        is NOT defined, unknown consequences could result.         *
********************************************************************/
template <class Data>
void BasicHashElement<Data>::getData(Data& copy_data)
{
   copy_data = this->data;
}

/********************************************************************
* Get the key field: for the of the data type of char*              *
********************************************************************/
template <class Data>
void BasicHashElement<Data>::getKey(char* return_key)
{
   if(this->key_string && strcmp(key_string,""))
   {
      strcpy(return_key, this->key_string);
   }
   else
   {
      memset(return_key, 0, strlen(return_key + 1));
   }
}

/********************************************************************
* Get the key field: for the of the data type of long               *
********************************************************************/
template <class Data>
long BasicHashElement<Data>::getKey()
{
   return this->key;
}

/********************************************************************
* Return the flag field                                             *
********************************************************************/
template <class Data>
int BasicHashElement<Data>::getFlag()
{
   return this->flag;
}

/********************************************************************
* Set the key field: for the key field being of type long           *
********************************************************************/
template <class Data>
int BasicHashElement<Data>::setKey(long the_key)
{
   this->key = the_key;
   return 1;
}

/********************************************************************
* Set the key field: for the key field being of type char*          *
********************************************************************/
template <class Data>
int BasicHashElement<Data>::setKey(const char* the_key)
{
   int return_value = 0;
   if(this->key_string)
   {
      delete [] this->key_string;
      this->key_string = NULL;
   }
   this->key_string = new char[strlen(the_key) + 1];
   if(this->key_string)
   {
      strcpy(this->key_string, the_key);
      return_value = 1;
   }
   return return_value;
}

/********************************************************************
* Set the data field                                                *
* NOTE:  the assigment operator MUST be defined for the Data type   *
*        in order to message this method.  If the assigment operator*
*        is NOT defined, unknown consequences could result.         *
********************************************************************/
template <class Data>
int BasicHashElement<Data>::setData(const Data& the_data)
{
   this->data = the_data;
   this->setFlag(SET);
   return 1;
}

/********************************************************************
* Set the flag field                                                *
********************************************************************/
template <class Data>
int BasicHashElement<Data>::setFlag(int flag_value = EMPTY)
{
   this->flag = flag_value;
   return 1;
}

/********************************************************************
* The print method                                                  *
********************************************************************/
template <class Data>
void BasicHashElement<Data>::print()
{
   //Print out the appropriate data iff the flag field indicates
   //the data is valid (good data set in the object)
   if(this->flag == SET)
   {
      //key_string must be 'valid' (neither NULL nor "")
      if(this->key_string && strcmp(this->key_string,""))
      {
         cout<<"("<<this->key_string<<", "<<this->data<<") ";
      }
      else
      {
         cout<<"("<<this->key<<", "<<this->data<<") ";
      }
   }
}

/********************************************************************
* Insertion Operator                                                *
********************************************************************/
template <class Data>
ostream& operator<<(ostream& os, BasicHashElement<Data>& bhe)
{
   bhe.print();
   return os;
}

#endif
