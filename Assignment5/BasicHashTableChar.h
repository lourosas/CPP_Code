/*****************************************************************
* BasicHashTableChar class
* A part of the ongoing work to fulfill my desire
* to create a generic data structure tool set for
* everyday application development.
* This class is designed as a Hash Table that uses a
* character array as the key into the Hash Table.
* A class by Lou Rosas
*****************************************************************/

#ifndef BASIC_HASH_TABLE_CHAR_H
#define BASIC_HASH_TABLE_CHAR_H

#include <typeinfo>
#include <iostream.h>
#include <string.h>
#include <strstream.h>
#include "Generic.h"
#include "GenericHashTable.h"
#include "GenericHashElement.h"
#include "BasicHashElementChar.h"
#include "MathTools.h"

template <class Data>
class BasicHashTableChar  : public GenericHashTable
{
   public:
      //Constructor with no elements
      BasicHashTableChar();
      
      //Constructor setting the initial hash capacity
      BasicHashTableChar(float );
      
      //Copy Constructor
      BasicHashTableChar(BasicHashTableChar<Data>& );
      
      //Destructor
      ~BasicHashTableChar();
      
      //Assignment operator
      BasicHashTableChar<Data>& operator=(BasicHashTableChar<Data>& );
      
      //Public call to destroy the BasicHashTableChar object
      void destroyBasicHashTableChar();
      
      //Insert data with a set key into the BasicHashTableChar
      //Object
      int insert(char*, Data& );
      
      //Insert data as a BasicHashElementChar object
      int insert(BasicHashElementChar<Data>& );
      
      //Given the key, find the data (but don't delete)
      int find(char*, Data& );
      
      //Check to see if the BasicHashTableChar object contains
      //the key in question
      int containsKey(char* );
      
      //Check to see if the BasicHashTableChar object contains
      //the element in question
      int containsElement(Data& );
      
      //Get the elements in the BasicHashTableChar object
      int getElements(Data* );
      
      //Given the Data object, get the key (if it exists)
      int getKey(Data&, char* );
      
      //Get the entire set of keys
      int getKeys(char* [] );
      
      //Get the number of HashElement objects either in the
      //SET or DELETED state
      int getSize();
      
      //Get the number of (HashElement) objects in the SET state
      int getSetSize();
      
      //Get the total number of possible objects the HashTable
      //could hold if it were 100% full (should never happen)
      int getMaxSize();
      
      //Given a set key, remove and return the Data object from
      //the HashElement object and remove the HashElement from the
      //HashTable
      int remove(char*, Data& );
      
      //Check to see if the HashTable is empty (no HashElements
      //in the SET state)
      int isEmpty();
      
      //Get the rehash capacity value (the percentage of how full
      //the HashTable has to be in both SET and DELETED
      //states of the HashElement objects)
      float getRehashCapacity();
      
      //Set a new rehash capacity
      void setRehashCapacity(float );
      
      //Print out the HashTable:  all the HashElements that have
      //not been deleted.
      void print();
      
   private:
      /*************Methods******************************/
      //The private method to destroy the HashTable object
      void destroyBHTC();
      
      //Given a key value, create a hash value
      int hash(char* );
      
      //If the hash value is already used by valid data,
      //call this method and find the next available hash value
      int nextHash(unsigned int, unsigned int );
      
      //Get the actual position in the HashTable
      int getPosition(char* );
      
      //Rehash the HashTable as needed
      int reHash();
      
      //Set the Size of the HashTable
      void setSize(int );
      
      //Set the maximum size of the HashTable (the total number of
      //"slots" in the table that could hold HashElements
      void setMaxSize(int );
      
      //Set the number of HashElement objects with the flag field
      //at SET
      void setSetSize(int );
      
      //The (character version) of the folding technique for
      //finding the hash value
      long folding(int*, int );
      
      //The method used for parsing a string with all the characters
      //between '0' and '9' into an array of integers
      int parse(char*, int* );
      
      /*************Data and Attributes******************/
      //The max_size attribute
      int max_size;
      
      //The set_size attribute
      int set_size;
      
      //The size attribute
      int size;
      
      //Rehash capacity attribute
      float rehash_capacity;
      
      //The BasicHashElementChar attribute (pointer ot the object)
      BasicHashElementChar<Data>* bhec;
      
      //Constants used in the code: Borrowed from the 
      //GenericHashElementClass
      static const int EMPTY   = GenericHashElement::EMPTY;
      static const int DELETED = GenericHashElement::DELETED;
      static const int SET     = GenericHashElement::SET;
};
//Overload the insertion operator
template <class Data>
ostream& operator<<(ostream& , BasicHashTableChar<Data>& );


//Class implementations
//Public Methods
/*******************************************************************
* Constructor
* constructor of no arguments
********************************************************************/
template <class Data>
BasicHashTableChar<Data>::BasicHashTableChar()
   : max_size(0),
     size(0),
     set_size(0),
     bhec(NULL)
{
   bhec = new BasicHashElementChar<Data>[INITIAL_MAX_SIZE];
   if(bhec)
   {
      this->setRehashCapacity(DEFAULT_REHASH_CAPACITY);
      this->setMaxSize(INITIAL_MAX_SIZE);
   }
   else
   {
      cout<<"\nUnable to allocate memory for a HashTable: exiting\n";
      exit(0);
   }
}

/********************************************************************
* Constructor that sets the initial hash capacity
********************************************************************/
template <class Data>
BasicHashTableChar<Data>::BasicHashTableChar
(
   float initial_hash_capacity
)
   :  max_size(0),
      size(0),
      set_size(0),
      bhec(NULL)
{
   bhec = new BasicHashElementChar<Data>[INITIAL_MAX_SIZE];
   if(bhec)
   {
      this->setRehashCapacity(initial_hash_capacity);
      this->setMaxSize(INITIAL_MAX_SIZE);
   }
   else
   {
      cout<<"\nUnable to allocate memory for a HashTable: exiting.\n";
      exit(0);
   }
}     

/********************************************************************
* Copy constructor
********************************************************************/
template <class Data>
BasicHashTableChar<Data>::BasicHashTableChar
(
   BasicHashTableChar<Data>& copy_hash
)
   :  max_size(0),
      size(0),
      set_size(0),
      bhec(NULL)
{
   int num_elements;
   int inserted;
   
   //Prepare for the copy
   num_elements = copy_hash.getMaxSize();
   this->setRehashCapacity(copy_hash.getRehashCapacity());
   this->setMaxSize(num_elements);
   bhec = new BasicHashElementChar<Data>[this->getMaxSize()];
   /* If bhec is created, go ahead and copy data from one HastTable
      to another */
   if(bhec)
   {
      if(copy_hash.bhec)
      {
         /* Create a temp pointer to obtain the address of the 
            HashElements in copy_hash */
         BasicHashElementChar<Data>* temp_pointer = copy_hash.bhec;
         for(int i = 0; i < num_elements; i++)
         {
            //Only copy the elements that are legitamate data
            if((*(temp_pointer + i)).getFlag() == SET)
            {
               inserted = this->insert(*(temp_pointer + i));
               if(!inserted)
               {
                  //if the insert did not work, get out of the loop
                  i = num_elements;
               }
            }
         }
         //When done, set the temp_pointer to NULL
         temp_pointer = NULL;
      }
   }
   else
   {
      cout<<"\nUnable to allocate memory for a HashTable: exiting.\n";
      exit(0);
   }
}

/********************************************************************
* Destructor
********************************************************************/
template <class Data>
BasicHashTableChar<Data>::~BasicHashTableChar()
{
   this->destroyBHTC();
}

/********************************************************************
* Assignment Operator
* Essentially follow the copy constructor
********************************************************************/
template <class Data>
BasicHashTableChar<Data>& BasicHashTableChar<Data>::operator=
(
   BasicHashTableChar<Data>& assign_hash
)
{
   int num_elements;
   int inserted;
   
   this->destroyBHTC();
   
   //Prepare for the copy
   num_elements = assign_hash.getMaxSize();
   this->setRehashCapacity(assign_hash.getRehashCapacity());
   bhec = new BasicHashElementChar<Data>[num_elements];
   this->setMaxSize(num_elements);
   
   //If bhec is created, go ahead and copy data from one HashTable to
   //anoter.
   if(bhec)
   {
      if(assign_hash.bhec)
      {
         //Create a temp pointer to obtain the address of the
         //HashElements in assign_hash
         BasicHashElementChar<Data>* temp_pointer = assign_hash.bhec;
         for(int i = 0; i < num_elements; i++)
         {
            //Only copy the legitimate data objects
            if((*(temp_pointer + i)).getFlag() == SET)
            {
               inserted = this->insert(*(temp_pointer + i));
               if(!inserted)
               {
                  //If the insert did not work, get out of the loop
                  i = num_elements;
               }
            }
         }
         //When done, set the temp_pointer to NULL
         temp_pointer = NULL;
      }
   }
   else
   {
      cout<<"\nUnable to allocate memory for a HashTable: exiting.\n";
      exit(0);
   }
   
   return *this;
}

/********************************************************************
* Public call method to destroy the BasicHashTableChar object
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::destroyBasicHashTableChar()
{
   this->destroyBHTC();
}

/********************************************************************
* Insert data into the HashTable
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::insert
(
   char* the_key, 
   Data& the_data
)
{
   const int NO_INSERT_LIMIT = -1;
   const int ADD             =  1;
   
   int inserted         = NO;
   int check_flag       = EMPTY;
   int current_position = NO_INSERT_LIMIT;
   
   //Rehash the table if needed
   if(!(this->getMaxSize()) || !(this->bhec) || 
        ((float)this->getSize())/this->getMaxSize() >=
         this->getRehashCapacity())
   {
      this->reHash();
   }
   current_position = this->getPosition(the_key);
   if(current_position > NO_INSERT_LIMIT)
   {
      //Check the value of the current flag
      check_flag = (*(bhec + current_position)).getFlag();
      
      /* If the data belongs at the current position, insert
         everything regardless of the check_flag value (miniscule
         in the performanc hit) */
      inserted  = (*(bhec + current_position)).setKey(the_key);
      inserted *= (*(bhec + current_position)).setData(the_data);
      inserted *= (*(bhec + current_position)).setFlag(SET);
      
      if(inserted && !check_flag)
      {
         this->setSize(this->getSize() + ADD);
         this->setSetSize(this->getSetSize() + ADD);
      }      
   }
   return inserted;
}

/*******************************************************************
* Insert data into the HashTable as a HashElement object
*******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::insert
(
   BasicHashElementChar<Data>& element
)
{
   int inserted = NO;
   
   char copy_key[256];
   Data copy_data;
   
   element.getKey(copy_key);
   element.getData(copy_data);
   inserted = this->insert(copy_key, copy_data);
   
   return inserted;
}

/********************************************************************
* Given the key, find the data - without deleting it
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::find(char* the_key, Data& the_data)
{
   int num_elements = this->getMaxSize();
   int found        = NO;
   
   int current_flag;
   
   char current_key[256];
   
   if(this->containsKey(the_key))
   {
      for(int i = 0; i < num_elements; i++)
      {
         (*(bhec + i)).getKey(current_key);
         //Was the key found?
         if(!(strcmp(the_key, current_key)))
         {
            //Retrieve the current flag
            current_flag = (*(bhec + i)).getFlag();
            if(current_flag == SET)
            {
               (*(bhec + i)).getData(the_data);
               i = num_elements;
               found = YES;
            }
         }
      }
   }
   return found;
}

/********************************************************************
* Check to see if the HashTable contains the key in question
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::containsKey(char* the_key)
{
   int contains       = NO;
   int retrieved_flag = EMPTY;
   int num_elements   = this->getMaxSize();
   
   int  current_flag;
   char retrieved_key[256];
   
   //Itterate through all HashElements to find key value
   for(int i = 0; i < num_elements; i++)
   {
      (*(bhec + i)).getKey(retrieved_key);
      if(!(strcmp(retrieved_key, the_key)))
      {
         //Retrieve the current flag
         current_flag = (*(bhec + i)).getFlag();
         if(current_flag == SET)
         {
            contains = YES;
            i = num_elements;
         }
      }
   }
   return contains;
}

/*******************************************************************
* Check to see if the HashTable contains the element in question
*******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::containsElement(Data& the_data)
{
   int contains     = NO;
   int num_elements = this->getMaxSize();
   
   Data retrieved_data;
   char retrieved_key[256];
   
   //Itterate trough all the elements and get the current key
   for(int i = 0; i < num_elements; i++)
   {
      (*(bhec + i)).getKey(retrieved_key);
      if(this->find(retrieved_key, retrieved_data))
      {
         //Was the Data found?
         if(retrieved_data == the_data)
         {
            contains = YES;
            i = num_elements;
         }
      }
   }   
   return contains;
}

/*******************************************************************
* Get the elements in the HashTable
*******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getElements(Data* copy_elements)
{
   int num_elements  = this->getMaxSize();
   int loop_counter  = 0;
   int data_elements = 0;
   
   int  current_flag;
   Data the_data;
   
   //Itterate through all the elements and get the current flag
   do{
      current_flag = (*(bhec + loop_counter)).getFlag();
      if(current_flag == SET)
      {
         (*(bhec + loop_counter)).getData(the_data);
         copy_elements[data_elements] = the_data;
         ++data_elements;
      }
      ++loop_counter;
   }while(loop_counter < num_elements);
   return data_elements;
}

/******************************************************************
* Given the Data object, get the key (if it exists)
******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getKey
(
   Data& the_data,
   char* the_key
)
{
   int key_found    = NO;
   int num_elements = this->getMaxSize();
   
   char retrieved_key[256];
   int  retrieved_flag;
   
   Data retrieved_data;
   
   //Itterate through all the elements and get the current key
   for(int i = 0; i < num_elements; i++)
   {
      (*(bhec + i)).getKey(retrieved_key);
      //Itterate through all the elements and get the current flag
      retrieved_flag = (*(bhec + i)).getFlag();
      if(retrieved_flag == SET)
      {
         if(this->find(retrieved_key, retrieved_data))
         {
            //If the data is the same, copy the key value to the
            //outgoing key value
            if(retrieved_data == the_data)
            {
               strcpy(the_key, retrieved_key);
               key_found = YES;
               i = num_elements;
            }
         }
      }
   }
   return key_found;
}

/*******************************************************************
* Get the entire set of Keys.  NOTE:  the HashElement MUST have
* the flag set to SET (2)
*******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getKeys(char* keys[])
{
   int num_elements = this->getMaxSize();
   int flag_counter = 0;
   int loop_counter = 0;
   
   char retrieved_key[256];
   int  retrieved_flag;
   
   //Itterate through all the elements and get the current flag
   for(; loop_counter < num_elements; loop_counter++)
   {
      retrieved_flag = (*(bhec + loop_counter)).getFlag();
      if(retrieved_flag == SET)
      {
         (*(bhec + loop_counter)).getKey(retrieved_key);
         strcpy(keys[flag_counter],retrieved_key);
         ++flag_counter;
      }
   }
   return flag_counter;
}

/********************************************************************
* Get the number of HashElements either in the SET or DELETED state
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getSize()
{
   return (this->size);
}

/********************************************************************
* Get the number of HashElements in the SET state
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getSetSize()
{
   return (this->set_size);
}

/********************************************************************
* Get the total number of possible objects the HashTable could
* hold if it were 100% full (should never happen)
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getMaxSize()
{
   return (this->max_size);
}

/********************************************************************
* Given a set key, remove and return the Data from the HashElement
* and remove the HashElement from the HashTable
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::remove(char* key_in, Data& data_out)
{
   const int REMOVED     =  1;
   const int NO_POSITION = -1;
   
   int is_removed = NO;
   int position   = NO_POSITION;
   
   int retrieved_flag;
   
   //Is the HashTable empty?
   if(!(this->isEmpty()))
   {
      position = this->getPosition(key_in);
      retrieved_flag = (*(bhec + position)).getFlag();
      if(retrieved_flag == SET)
      {
         (*(bhec + position)).getData(data_out);
         is_removed = (*(bhec + position)).setFlag(DELETED);
         this->setSetSize((this->getSetSize()) - REMOVED);
      }
   }
   return is_removed;
}

/*******************************************************************
* Check to see if the HashTable is empty (no HashElements in the
* SET state)
*******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::isEmpty()
{
   return (!(this->getSetSize()));
}

/********************************************************************
* Get the rehash capacity value (the percentage of how full the
* HashTable has to be in both SET and DELETED states of the
* HashElement)
********************************************************************/
template <class Data>
float BasicHashTableChar<Data>::getRehashCapacity()
{
   return (this->rehash_capacity);
}

/********************************************************************
* Set a new rehash capacity
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::setRehashCapacity(float new_capacity)
{
   float MIN_VALUE = 0.01;
   float MAX_VALUE = 0.99;
   
   if(new_capacity > MAX_VALUE)
   {
      this->rehash_capacity = MAX_VALUE;
   }
   else if(new_capacity < MIN_VALUE)
   {
      this->rehash_capacity = MIN_VALUE;
   }
   else
   {
      this->rehash_capacity = new_capacity;
   }
}

/********************************************************************
* Print out the HashTable:  all the HashElements that are not deleted
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::print()
{
   int num_elements = this->getMaxSize();
   
   int retrieved_flag;
   
   if(bhec)
   {
      for(int i = 0; i < num_elements; i++)
      {
         retrieved_flag = (*(bhec + i)).getFlag();
         if(retrieved_flag == SET)
         {
            cout<<endl<<(*(bhec + i));
         }
      }
      cout<<endl;
   }
}

//Private Methods
/********************************************************************
* The private method to destroy the HashTable object
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::destroyBHTC()
{
   delete this->bhec;
   this->bhec = NULL;
   
   //NOTE: NO = 0
   this->setMaxSize(INITIAL_MAX_SIZE);
   this->setSize(NO);
   this->setSetSize(NO);
}

/********************************************************************
* Given a key value, create a hash table
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::hash(char* key)
{
   int num_elements = this->getMaxSize();
   
   //The illegal value:  if returned, don't add anything
   int hash_value    = -1;
   
   //The counter of 'Non-numerical" characters in the input string
   int non_num_count =  0;
   
   //Set the return value to some (essentially) illegal value
   int return_value  = -1;
   
   //The total number of input characters in the input string
   int string_length = strlen(key);
   
   //Check to see if the string has completely "numerical" characters
   //('0' - '9')
   for(int i = 0; i < string_length; i++)
   {
      if(key[i] > '9' || key[i] < '0')
      {
         ++non_num_count;
      }
   }
   
   //Is the string completely "numerical"?
   if(!non_num_count)
   {
      //The value comming back from the folding method
      long hash_value = 0;
      
      //The number of array indices in the two digit numerical array
      int  indices    = 0;
      
      //The array of two digit values contained in the key
      int  two_digit_values[256];
      
      //Parse the string into numerical values all < 100
      indices = this->parse(key, two_digit_values);
      
      //Apply the Folding technique
      hash_value = this->folding(two_digit_values, indices);
      
      //Set the modded value to the return value
      return_value = hash_value % max_size;
   }
   else
   {
      //The total ASCII value of the input string
      int total_string_value = 0;
      
      //Add up all the ASCII values of the string characters
      for(int i = 0; i < string_length; i++)
      {
         total_string_value += key[i];
      }
      //Modulo the total_string_value by the max_size and
      //set to the return value
      return_value = total_string_value % max_size;
   }
   return return_value;
}

/********************************************************************
* If the hash value is already used by valid data, call this method
* and find the next available hash value
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::nextHash
(
   unsigned int previous_position,
   unsigned int fib_index
)
{
   //The Fibinacci number in the sequence
   unsigned int fib_number;
   
   //Set the return value to some illegal value
   int return_value = -1;
   
   //The set value
   unsigned int set_value = 0xFFFFFFFF;
   int max_size = this->getMaxSize();
   
   //Get the Fibinacci sequence number
   fib_number = MathTools::fibSeriesNumber(fib_index);
   //Add the fib_number to previous_position, storing in return_value
   set_value = fib_number + previous_position;
   
   //Modulo divide the set_value by the max_size and return
   return_value = set_value % max_size;
   
   return return_value;
}

/********************************************************************
* Get the actual position in the HashTable
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::getPosition(char* key_value)
{
   //Indicate first time through the loop
   int once_pass = YES;
   int fib_index = 0;
   
   char the_key[256];
   int   current_position;
   int   the_flag;
   int   key_compare_value;
   
   do{
      if(once_pass)
      {
         //If the first time through the loop, get the hash value
         //and then indicate no-longer first time through the loop
         current_position = this->hash(key_value);
         once_pass = NO;
      }
      else
      {
         //Increase the Fibinacci index by one and get the next hash
         //position
         ++fib_index;
         current_position = 
            this->nextHash(current_position, fib_index);
      }
      //Get the current flag value
      the_flag = (*(bhec + current_position)).getFlag();
      
      //Get the current key
      (*(bhec + current_position)).getKey(the_key);
      
      //compare the two different strings
      key_compare_value = strcmp(the_key, key_value);      
   }while((the_flag && key_compare_value) || the_flag == DELETED);
   
   return current_position;
}

/*******************************************************************
* Rehash the HashTable if needed
*******************************************************************/
template <class Data>
int BasicHashTableChar<Data>::reHash()
{
   const int NO_SIZE          = 0;
   const int PRIME_LOOP_LIMIT = 20;
   
   int return_value = NO;
   
   int new_size;
   int previous_size;
   BasicHashElementChar<Data>* temp_pointer;
   
   temp_pointer = NULL;
   
   if(!(this->getMaxSize()))
   {
      //Set new_size to INITIAL_MAX_SIZE
      new_size      = INITIAL_MAX_SIZE;
      previous_size = NO_SIZE;
   }
   else
   {
      previous_size = this->getMaxSize();
      new_size = previous_size;
      //Set new_size to the 20th itteration prime number
      for(int i = 0; i < PRIME_LOOP_LIMIT; i++)
      {
         new_size = MathTools::getNextPrime(new_size);
      }
   }
   //Set max_size to new_size
   this->setMaxSize(new_size);
   //Set temp_pointer to bhec pointer
   temp_pointer = this->bhec;
   bhec = NULL;
   //Set size and set_size fields to 0
   this->setSize(NO_SIZE);
   this->setSetSize(NO_SIZE);
   
   //Create the new HashElement array to the size of new_size
   bhec = new BasicHashElementChar<Data>[new_size];
   //bhec valid?
   if(bhec)
   {
      int current_size = previous_size;
      //insert all legitimate data from temp into bhec
      for(int i = 0; i < current_size; i++)
      {
         char temp_key[256];
         Data temp_data;
         
         if((*(temp_pointer + i)).getFlag() == SET)
         {
            (*(temp_pointer + i)).getKey(temp_key);
            (*(temp_pointer + i)).getData(temp_data);
            this->insert(temp_key, temp_data);
         }
      }
      return_value = YES;
   }
   
   //Delete temp_pointer and set to NULL
   delete [] temp_pointer;
   temp_pointer = NULL;
   return return_value;
   
   return NO;
}

/*******************************************************************
* Set the size of the HashTable
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::setSize(int the_size)
{
   this->size = the_size;
}

/*******************************************************************
* Set the maximum size of the HashTable (the total nubmer of "slots"
* in the table that could hold HashElements
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::setMaxSize(int new_max_size)
{
   const int ZERO = 0;
   
   if((new_max_size == ZERO) ||
      ((new_max_size > ZERO) &&
       (new_max_size >= this->max_size) &&
       (MathTools::isPrime(new_max_size))))
   {
      this->max_size = new_max_size;
   }
   else if(new_max_size > ZERO)
   {
      this->max_size = MathTools::getNextPrime(new_max_size);
   }
   else
   {
      this->max_size = INITIAL_MAX_SIZE;
   }
}

/********************************************************************
* Set the number of HashElements with the flag field as SET
********************************************************************/
template <class Data>
void BasicHashTableChar<Data>::setSetSize(int new_set_size)
{
   this->set_size = new_set_size;
}

/********************************************************************
* The (character version) of the folding technique for finding the
* hash value
********************************************************************/
template <class Data>
long BasicHashTableChar<Data>::folding(int* numbers, int indices)
{
   const int ADD_LIMIT = 2;
   
   //The return value
   long return_value;
   //The number that stores temp1 + temp2
   long temp1;
   
   //The loop counter
   int counter = 0;
   
   //The number that stores the values added up (the first two)
   long temp2 = 0;
   //The number that stores the values multiplied
   long temp3 = 1;
   
   while(counter < indices)
   {
      if(counter < ADD_LIMIT)
      {
         temp2 += numbers[counter];
      }
      else
      {
         temp3 *= numbers[counter];
      }
      ++counter;
   }
   
   //Assign temp1 to temp2 regardless
   temp1 = temp2;   
   if(counter > ADD_LIMIT)
   {
      temp1 += temp3;
   }
   return_value = temp1;
   
   return return_value;
}

/********************************************************************
* The method used for parsing a string with all the characters
* between '0' and '9' into an array of integers
********************************************************************/
template <class Data>
int BasicHashTableChar<Data>::parse(char* key, int* numbers)
{
   const int SINGLE_CHAR   = 1;
   const int CONVERT_VALUE = 2;
   
   int temp_value;
   int is_odd_size;
   
   int num_counter = NO;
   char* current_string = NULL;
   
   temp = new char[strlen(key) + 1];
   strcpy(temp, key);
   is_odd_size = (strlen(temp) % CONVERT_VALUE);
   current_string = (temp + (strlen(temp - CONVERT_VALUE)));
   
   while(current_string >= temp)
   {
      istrstream is(current_string, CONVERT_VALUE);
      is>>temp_value;
      numbers[num_counter] = temp_value;
      
      current_string -= CONVERT_VALUE;
      ++num_counter;
   }
   if(is_odd_size)
   {
      current_string = temp;
      istrsream is(current_string, SINGER_CHAR);
      is>>temp_value;
      numbers[counter] = temp_value;
      ++num_counter;
   }
   
   delete [] temp;
   temp = NULL;
   current_string = NULL;
   
   return num_counter;
}



/*********************************************************************
* Overload the insertion operator
*********************************************************************/
template <class Data>
ostream& operator<<(ostream& os, BasicHashTableChar<Data>& bhtc)
{
   bhtc.print();
   return os;
}


#endif
