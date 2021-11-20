/********************************************************************
* BasicHashTableLong Class
* A part of the ongoing work to fullfil my desire
* to create a generic data structure tool set for
* everyday application development.
* This Class is designed as a Hash Table that uses a
* long integer type as the key into the Hash Table.
* A Class by Lou Rosas
********************************************************************/

#ifndef BASIC_HASH_TABLE_LONG_H
#define BASIC_HASH_TABLE_LONG_H

#include <typeinfo>
#include <iostream.h>
#include "Generic.h"
#include "GenericHashTable.h"
#include "GenericHashElement.h"
#include "BasicHashElementLong.h"
#include "MathTools.h"

template <class Data>
class BasicHashTableLong : public GenericHashTable
{
   public:
      //Constructor with no arguments
      BasicHashTableLong();
      
      //Constructor setting the initial hash capacity
      BasicHashTableLong(float );
      
      //Copy Constructor
      BasicHashTableLong(BasicHashTableLong<Data>& );
      
      //Destructor
      ~BasicHashTableLong();
      
      //Assignment Operator
      BasicHashTableLong& operator=(BasicHashTableLong<Data>& );
      
      //public call to destroy the BasicHashTableLong object
      void destroyBasicHashTableLong();
      
      //insert data with a set key into the BasicHashTableLong
      //object
      int insert(long, const Data& );
      
      //Insert data as a BasicHashElementLong object
      int insert(BasicHashElementLong<Data>& );
      
      //Given the key, find the data (but don't delete)
      int find(long, Data& );
      
      //Check to see if the BasicHashTableLong object contains
      //the key in question
      int containsKey(long );
      
      //Check to see if the BasicHashTableLong object contains
      //the element in question
      int containsElement(Data& );
      
      //Get all the Set elements in the BasicHashTableLong object
      int getElements(Data* );
      
      //Given the Data object, get the key (if it exists in the
      //BasicHashTableLong object)
      int getKey(const Data&, long& );
      
      //Get the entire set of keys
      int getKeys(long* );
      
      //Get the number of GenericHashElementLong objects either
      //in the set or deleted state
      int getSize();
      
      //Get the number of set GenericHashElementLong objects
      //in the GenericHashTableLong object
      int getSetSize();
      
      //Get the total number of "spaces" contained in the
      //GenericHashTableLong object
      int getMaxSize();
      
      //Given a set key, remove and return the Data object from
      //the BasicHashElementLong object and remove the object
      //from the BasicHashTableLong object
      int remove(long, Data& );
      
      //Check to see if the BasicHashTableLong object is empty
      //(no objects set)
      int isEmpty();
      
      //Get the rehash capacity value (the percentage of how full
      //the BasicHashTableLong object has to be (in both set and
      //deleted BasicHashElementLong objects) before it will
      //rehash to a larger size
      float getRehashCapacity();
      
      //Set a new rehash capacity
      void setRehashCapacity(float );
      
      //Print out the BasicHashTableLong object:  all the
      //BasicHashElementLong objects that have not been deleted
      void print();
      
            
   private:
      /*******Methods**********/
      //The private method to destroy the BasicHashTableLong object
      void destroyBHTL();
      
      //Given the key value, create a hash number to index into
      //the BasicHashTableLong object
      int hash(unsigned long );
      
      //If the hash position is already taken, call this method
      //to try to find the next available position in the
      //BasicHashTableLong object
      int nextHash(unsigned int, unsigned int );
      
      //Get the actual position in the BasicHashTableLong object
      //to index into
      int getPosition(unsigned long );
      
      //Reset the max size of the BasicHashTableLong object and
      //re-insert the BasicHashElementLong objects back into the
      //BasicHashTableLong object.
      int reHash();
      
      //Set the size of the BasicHashTableLong object--the number
      //of BasicHashElementLong objects that are set (valid) or
      //deleted (for re-hashing puposes)
      void setSize(int );
      
      //Set the number of BasicHashElementLong object with the
      //flag field as SET.  This number will "yo-yo" as data
      //is set and deleted in the BasicHashTableLong object
      void setSetSize(int );
      
      //Set the maximum size of the BasicHashTableLong object (the
      //total number of "Slots" in the table that could hold
      //BasicHashElementLong objects
      void setMaxSize(int );
      
      //The midsquare technique for finding the hash value (index)
      int midsquare(unsigned long );
      
      //The boundry folding technique for finding the hash value
      int boundryFolding(unsigned long );
      
      //The folding technique for finding the hash value
      long folding(unsigned long );
      
      /*********Data and attributes****************/
      //The max_size attribute
      int max_size;
      
      //The size attribute:  both for SET and DELETED elements
      int size;
      
      //The set_size attribute:  for SET elements only
      int set_size;
      
      //The Rehash Capacity attribute
      float rehash_capacity;
      
      //The BasicHashElementLong attribute (pointer to the object)
      BasicHashElementLong<Data>* bhel;

      //Constants to be used in the code:  borrowed from the
      //GenericHashElmentClass      
      static const int EMPTY   = GenericHashElement::EMPTY;
      static const int DELETED = GenericHashElement::DELETED;
      static const int SET     = GenericHashElement::SET;
};
//Overload the insertion operator
template <class Data>
ostream& operator<<(ostream& , BasicHashTableLong<Data>& );


//Class Implementation
//Public Methods
/********************************************************************
* Constructor
* constructor of no arguments
********************************************************************/
template <class Data>
BasicHashTableLong<Data>::BasicHashTableLong()
  :  max_size(0),
     size(0),
     set_size(0),
     bhel(NULL)
{
   bhel = new BasicHashElementLong<Data>[INITIAL_MAX_SIZE];
   if(bhel)
   {
      this->setRehashCapacity(DEFAULT_REHASH_CAPACITY);
      this->setMaxSize(INITIAL_MAX_SIZE);
   }
   else
   {
      cout<<"\nUnable to allocate memory for a HashTable: exiting.\n";
      exit(0);
   }
}

/********************************************************************
* Constructor that sets the initial hash capacity
********************************************************************/
template <class Data>
BasicHashTableLong<Data>::BasicHashTableLong
(
   float initial_hash_capacity
)
   :  max_size(0),
      size(0),
      set_size(0),
      bhel(NULL)
{
   bhel = new BasicHashElementLong<Data>[INITIAL_MAX_SIZE];
   if(bhel)
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
* Copy Constructor
* Copies one BasicHashTableLong object to another
********************************************************************/
template <class Data>
BasicHashTableLong<Data>::BasicHashTableLong
(
   BasicHashTableLong<Data>& copy_hash
)
   :  max_size(0),
      size(0),
      set_size(0),
      bhel(NULL)
{
   int num_elements;
   int inserted;

   //Prepare for the copy
   num_elements = copy_hash.getMaxSize();
   this->setRehashCapacity(copy_hash.getRehashCapacity());
   this->setMaxSize(num_elements);
   bhel = new BasicHashElementLong<Data>[this->getMaxSize()];
   /* If bhel is created, go ahead and copy data from one Hash Table to
   another */
   if(bhel)
   {
      if(copy_hash.bhel)  
      {
         /*Create a temp pointer to obtain the address of the
         Hash Elements in copy_hash*/
         BasicHashElementLong<Data>* temp_pointer = copy_hash.bhel;
         for(int i=0; i<num_elements; i++)
         {
            /*Only copy the elements that are legitimate data*/
            if((*(temp_pointer + i)).getFlag()==SET)
            {
               inserted = this->insert(*(temp_pointer + i));
               if(!inserted)
               { 
                  /*If the insert did not work, get out of the loop*/
                  i = num_elements;
               }
            }
         }
         /*When done, set the temp_pointer to NULL*/
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
BasicHashTableLong<Data>::~BasicHashTableLong()
{
   this->destroyBHTL();
}

/********************************************************************
* Assignment Operator
* Essentially follow the copy constructor
********************************************************************/
template <class Data>
BasicHashTableLong<Data>& BasicHashTableLong<Data>::operator=
(
   BasicHashTableLong<Data>& assign_hash
)
{
   int num_elements;
   int inserted;
   
   this->destroyBHTL();
   
   //Prepare for the copy
   num_elements = assign_hash.getMaxSize();
   this->setRehashCapacity(assign_hash.getRehashCapacity());
   this->setMaxSize(num_elements);
   bhel = new BasicHashElementLong<Data>[this->getMaxSize()];
   
   /*If bhel is created, go ahead and copy data from one Hash Table to 
     another */
   if(bhel)
   {
      if(assign_hash.bhel)
      {
         /*Create a temp pointer to obtain the address of the
         Hash Elements in copy_hash*/
         BasicHashElementLong<Data>* temp_pointer = assign_hash.bhel;
         for(int i = 0; i < num_elements; i++)
         {
            /*Only copy the legitimate data objects*/
            if((*(temp_pointer + i)).getFlag() == SET)
            {
               inserted = this->insert(*(temp_pointer + i));
               if(!inserted)
               {
                  /*If the insert did not work, get out of the loop*/
                  i = num_elements;
               }
            }
         )
         /*When done, set the temp_pointer to NULL*/
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
* Public call method to destroy the BasicHashTableLong object
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::destroyBasicHashTableLong()
{
   this->destroyBHTL();
}

/********************************************************************
* Insert data into the BasicHashTableLong object
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::insert
(
   long the_key,
   const Data& the_data
)
{
   const int NO_INSERT_LIMIT = -1;
   const int ADD             = 1;
   
   int inserted         = NO;
   int check_flag       = EMPTY;
   int current_position = NO_INSERT_LIMIT;
   
   /*Rehash the Hash Table if needed*/
   if(!(this->getMaxSize()) || !(this->bhel) ||
       ((float)this->getSize())/this->getMaxSize() >=
        this->getRehashCapacity())
   {
      this->reHash();
   }
   current_position = this->getPosition(the_key);
   if(current_position > NO_INSERT_LIMIT)
   {
      /*Get the value of the current flag*/
      check_flag = (*(bhel + current_position)).getFlag();
      
      /*If the data belongs at the current position, insert everything
       regardless of check_flag value (miniscule in the performance hit)*/
      inserted     = (*(bhel + current_position)).setKey(the_key);
      inserted    *= (*(bhel + current_position)).setData(the_data);
      inserted    *= (*(bhel + current_position)).setFlag(SET);
      
      /*Only increase the size and the set_size if the current_flag was
      EMPTY (0)*/
      if(inserted && !check_flag)
      {
         this->setSize(this->getSize() + ADD);
         this->setSetSize(this->getSetSize() + ADD);
      }
   }
   return inserted;
}

/********************************************************************
* Insert an entire BasicHashElementLong object into the 
* BasicHashElementLong object
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::insert
(
   BasicHashElementLong<Data>& element
)
{
   int inserted  = NO;
   int copy_key  = NO;
   Data copy_data;
   
   element.getData(copy_data);
   copy_key = element.getKey();
   inserted  = this->insert(copy_key, copy_data);
   
   return inserted;
}

/********************************************************************
* Given the key, return the data--without deleting it
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::find(long the_key, Data& the_data)
{
   int  found           = NO;
   int  num_elements    = this->getMaxSize();
   long retrieved_key;
   int  retrieved_flag;
   
   for(int i = 0; i<num_elements; i++)
   {
      retrieved_key  = (*(bhel + i)).getKey();
      if(retrieved_key == the_key)
      {
         retrieved_flag = (*(bhel + i)).getFlag();
         if(retrieved_flag == SET)
         {
            (*(bhel + i)).getData(the_data);
            i = num_elements;
            found = YES;
         }
      }      
   }
   return found;
}

/********************************************************************
* Check to see if the BasicHashTableLong object contains the key
* in question
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::containsKey(long the_key)
{
   int  contains       = NO;
   long retrieved_key  = -1;
   int  retrieved_flag = EMPTY;
   int  num_elements   = this->getMaxSize();

   /*Itterate through all Hash Elements to find the key value*/
   for(int i = 0; i < num_elements; i++)
   {
      retrieved_key = (*(bhel + i)).getKey();
      /*Was the key found?*/
      if(retrieved_key == the_key)
      {
         /*Retrieve the current flag*/
         retrieved_flag = (*(bhel + i)).getFlag();
         i = num_elements;
         /*If the flag is set, a legitimate key was found with valid data*/
         if(retrieved_flag == SET)
         {
            contains = YES;
         }
      }
   }   
   return contains;
}


/********************************************************************
* Check to see if the BasicHashTableLong object contains the element
* in question
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::containsElement(Data& the_data)
{
   long retrieved_key;
   Data retrieved_data;
   int  contains = NO;
   int  num_elements = this->getMaxSize();
   
   /*Itterate through all the elements, get the current key of that element*/
   for(int i = 0; i<num_elements; i++)
   {
      /*Get the associated object of the key*/
      retrieved_key = (*(bhel + i)).getKey();
      if(this->find(retrieved_key, retrieved_data))
      {
         /*Was the object found?*/
         if(retrieved_data == the_data)
         {
            contains = YES;
            i = num_elements;
         }
      }
   }
   return contains;
}

/********************************************************************
* Get all the Set elements int the BasicHashTableLong object
* The elements with a flag set to SET (2)
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getElements
(
   Data* copy_elements
)
{
   /*Get the total possible number of elements*/
   int num_elements  = this->getMaxSize();
   
   /*Get the current number of elements set in the Hash Table*/
   int set_elements  = this->getSetSize();
   
   int retrieved_flag;
   Data the_data;
   
   int data_elements = 0;
   int loop_counter  = 0;

   /*Itterrate through all the elements and get the current flags*/   
   do{
      retrieved_flag = (*(bhel + loop_counter)).getFlag();
      /*Is the current flag set?*/
      if(retrieved_flag == SET)
      {
          /*Get the data and copy it to the outgoing elements array*/
         (*(bhel + loop_counter)).getData(the_data);
         *(copy_elements + data_elements) = the_data;
         data_elements++;
      }
      loop_counter++;
   }while(loop_counter < num_elements);
   
   return set_elements;
}

/********************************************************************
* Given the Data object, get the key (if it exists in the
* BasicHashTableLong object)
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getKey
(
   const Data& the_data,
   long& out_key
)
{
   int key_found    = NO;
   int num_elements = this->getMaxSize();
   
   int retrieved_key;
   int retrieved_flag;
   
   Data retrieved_data;

   /*Itterate thorough all the elements and get the current key and
     current flag */   
   for(int i = 0; i < num_elements; i++)
   {
      retrieved_key  = (*(bhel + i)).getKey();
      retrieved_flag = (*(bhel + i)).getFlag();
      
      if(retrieved_flag == SET)
      {
         /*Get the associted data with the current key*/
         if(this->find(retrieved_key, retrieved_data))
         {
            if(the_data == retrieved_data)
            {
               /*If the data is the same, assign the out_key to the
               current key, indicate the key found and exit the loop*/
               out_key   = retrieved_key;
               key_found = YES;
               i = num_elements;
            }
         }
      }
   }
   return key_found;
}

/********************************************************************
* Get all the Set keys in the BasicHashTableLong object
* The Hash Element MUST have the flag set to SET (2)
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getKeys(long* keys)
{
   int num_elements = this->getMaxSize();
   
   /*Get the current number of elements in the Hash Table*/
   int set_elements = this->getSetSize();
   
   int flag_counter = 0;
   int loop_counter = 0;
   
   int retrieved_key;
   int retrieved_flag;
   
   /*Itterate through all the elements and get the current flags*/
   do{
      retrieved_flag = (*(bhel + loop_counter)).getFlag();
      /*Is the current flag set?*/
      if(retrieved_flag == SET)
      {
         /*Get the flag and copy it to the outgoing flag array*/
         retrieved_key = (*(bhel + loop_counter)).getKey();
         *(keys + flag_counter) = retrieved_key;
         flag_counter++;
      }
      loop_counter++;
   }while(loop_counter < num_elements);   
   return set_elements;
}

/********************************************************************
* Get the number of GenericHashElementLong objects either
* in the set or deleted state
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getSize()
{
   return (this->size);
}

/*******************************************************************
* Get the number of set GenericHashElementLong objects 
* (in the SET state) in the GenericHashTableLong object
*******************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getSetSize()
{
   return (this->set_size);
}

/********************************************************************
* Get the total number of "spaces" (slots) that can hold or are
* holding data in the BasicHashTableLong object
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getMaxSize()
{
   return (this->max_size);
}


/********************************************************************
* Given a set key, remove and return the Data object from
* the BasicHashElementLong object and remove the object
* from the BasicHashTableLong object
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::remove(long key_in, Data& data_out)
{
   const int REMOVED     = 1;
   const int NO_POSITION = -1;
   
   int is_removed = NO;
   int position   = NO_POSITION;
   
   int retrieved_flag;
   
   /*Is the Hash Table empty?*/
   if(!(this->isEmpty()))
   {
      /*If the Hash Table is not empty, get the key position*/
      position = this->getPosition(key_in);
      if(position > NO_POSITION)
      {
         /*If the position is legitimate, get the flag value*/
         retrieved_flag = (*(bhel + position)).getFlag();
         if(retrieved_flag == SET)
         {
            /*If the flag value is set, 1)Get the data, 2)Set the flag
            for the Hash Element to DELETED (1) 3)Reduce the #of set
            Hash Elements by one*/
            (*(bhel + position)).getData(data_out);
            is_removed = (*(bhel + position)).setFlag(DELETED);
            this->setSetSize(this->getSetSize() - REMOVED);
         }
      }
   }
   return is_removed;
}

/********************************************************************
* Check to see if the BasicHashTableLong object is empty
* (no objects set)
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::isEmpty()
{
   return (!(this->getSetSize()));
}

/********************************************************************
* Get the rehash capacity value (the percentage of how full
* the BasicHashTableLong object has to be (in both set and
* deleted BasicHashElementLong objects) before it will
* rehash to a larger size.
********************************************************************/
template <class Data>
float BasicHashTableLong<Data>::getRehashCapacity()
{
   return (this->rehash_capacity);
}

/********************************************************************
* Set a new rehash capacity
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::setRehashCapacity(float new_capacity)
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
* Print out the BasicHashTableLong object:  all the
* BasicHashElementLong objects that have not been deleted
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::print()
{
   int num_elements = this->getMaxSize();
   
   int retrieved_flag;
   if(bhel)
   {
      for(int i = 0; i < num_elements; i++)
      {
         retrieved_flag = (*(bhel + i)).getFlag();
         if(retrieved_flag == SET)
         {
            cout<<endl<<(*(bhel + i));
         }
      }
      cout<<endl;
   }
}

//Private Methods
/********************************************************************
* The private method to destroy the BasicHashTableLong object
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::destroyBHTL()
{
   delete [] this->bhel;
   this->bhel = NULL;
   //NO = 0
   this->setMaxSize(INITIAL_MAX_SIZE);
   this->setSize(NO);
   this->setSetSize(NO);
}

/********************************************************************
* Given the key value, create a hash number to index into
* the BasicHashTableLong object
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::hash(unsigned long hash_key)
{
   //Minimum and Maximum values
   const long MINIMUM = 10000;
   const unsigned long MAXIMUM = 1000000000;
   
   int   num_elements = this->getMaxSize();
   
   //The illegal value if returned, don't add anything
   long hash_value = -1;

   if(hash_key < MINIMUM)
   {
      //Apply midsquare technique for small key values
      hash_value = (int)(this->midsquare(hash_key));
   }
   else if(hash_key >= MINIMUM && hash_key < MAXIMUM)
   {
      //Apply boundry folding technique for medium key values
      hash_value = (int)(this->boundryFolding(hash_key));
   }
   else
   {
      //Apply folding technique for large key values
      hash_value = this->folding(hash_key);
   }
   //Return the hash value moduloed with the max elements
   return (int)(hash_value % num_elements);
}

/********************************************************************
* If the hash position is already taken, call this method
* to try to find the next available position in the
* BasicHashTableLong object.
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::nextHash
(
   unsigned int previous_position,
   unsigned int fib_position
)
{
   unsigned long fib_value;
   int num_elements = this->getMaxSize();
   
   //Illegal value if returned, don't add anything
   unsigned long next_hash_value;
   
   fib_value = MathTools::fibSeriesNumber((int)fib_position);
   
   next_hash_value = fib_value + previous_position;
   
   return(next_hash_value % (unsigned long)num_elements);
}

/********************************************************************
* Get the actual position in the BasicHashTableLong object
* to index into the BasicHashTableLong object
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::getPosition(unsigned long key_value)
{
   //Indicate first time through the loop
   int once_pass = YES;
   int fib_index = 0;
   
   int current_position;
   int the_flag;
   int the_key;

   do{   
      if(once_pass)
      {
         //If the first time through the loop, get the hash value
         //and set indicate not first time through the loop
         current_position = this->hash(key_value);
         once_pass = NO;
      }
      else
      {
         //Increase the Fibinacci index and get the next hash position
         ++fib_index;
         current_position = this->nextHash(current_position, fib_index);
      }
      //Get the flag value
      the_flag = (*(bhel + current_position)).getFlag();
      //Get the key value
      the_key  = (*(bhel + current_position)).getKey();
      
     /* Keep looping as long as the flag value is set AND the current
      * key is not the same as the requested key OR if the flag value
      * indicates the data was deleted (key = 1)
      */
   }while((the_flag && (the_key != key_value)) || the_flag == DELETED);
   
   return current_position;
}

/********************************************************************
* Reset the max size of the BasicHashTableLong object and
* re-insert the BasicHashElementLong objects back into the
* BasicHashTableLong object.
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::reHash()
{
   const int NO_SIZE           = 0;
   const int PRIME_LOOP_LIMIT = 20;
   
   int return_value = NO;
   
   int new_size;
   int temp_size;
   BasicHashElementLong<Data>* temp_pointer;
   
   temp_pointer = NULL;
   
   if(!(this->getMaxSize()))
   {
      //Set new size to the initial size
      new_size = INITIAL_MAX_SIZE;
      temp_size = NO_SIZE;
   }
   else
   {
      new_size = this->getMaxSize();
      temp_size = new_size;
      //Set new size to the 20th itteration prime number
      for(int i = 0; i < PRIME_LOOP_LIMIT; i++)
      {
         new_size = MathTools::getNextPrime(new_size);
      }
   }
   //Set max size to new size
   this->setMaxSize(new_size);
   //Set a temp pointer to the bhel pointer
   temp_pointer = bhel;
   bhel = NULL;
   //Reset the size ans set_size attributes
   this->setSize(NO_SIZE);
   this->setSetSize(NO_SIZE);
   //Create the new BasicHashElements array to the size of new size
   bhel = new BasicHashElementLong<Data>[new_size];
   //Is bhel valid (was memory allocated)?
   if(bhel)
   {
      int current_size = temp_size;
      //Insert all legitimate data from temp into bhel
      for(int i = 0; i < current_size; i++)
      {
         Data temp_data;
         int  temp_key;
         if((*(temp_pointer + i)).getFlag() == SET)
         {
            (*(temp_pointer + i)).getData(temp_data);
            temp_key = (*(temp_pointer + i)).getKey();
            this->insert(temp_key, temp_data);
         }
      }
      return_value = YES;
   }
   //Delete temp_pointer and set to NULL
   delete [] temp_pointer;
   temp_pointer = NULL;
   return return_value;
}

/********************************************************************
* Set the size of the BasicHashTableLong object--the number
* of BasicHashElementLong objects that are set (valid) or
* deleted (for re-hashing puposes).
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::setSize(int the_size)
{
   this->size = the_size;
}

/********************************************************************
* Set the number of BasicHashElementLong object with the
* flag field as SET.  This number will "yo-yo" as data
* is set and deleted in the BasicHashTableLong object
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::setSetSize(int new_set_size)
{
   this->set_size = new_set_size;
}

/********************************************************************
* Set the maximum size of the BasicHashTableLong object (the
* total number of "Slots" in the table that could hold
* BasicHashElementLong objects.
********************************************************************/
template <class Data>
void BasicHashTableLong<Data>::setMaxSize(int new_max_size)
{
   const int ZERO = 0;
 
   if((new_max_size == ZERO) ||
      ((new_max_size > 0) && 
       (new_max_size >= this->max_size) &&
       (MathTools::isPrime(new_max_size))))
   {
      this->max_size = new_max_size;
   }
   else if(new_max_size > 0)
   {
      this->max_size = MathTools::getNextPrime(new_max_size);
   }
   else
   {
      this->max_size = INITIAL_MAX_SIZE;
   }
}

/********************************************************************
* The midsquare technique for finding the hash value (index).
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::midsquare(unsigned long input_key)
{
   const int MAX = 100000;
   const int MIN = 1000;
   
   int midsquare_value;
   
   unsigned long temp;
   
   //Square the key   
   temp = input_key * input_key;
   
   //temp > 100000?
   if(temp > MAX)
   {
      //Take temp, modulo divide by 100000 and reassign to temp
      temp %= MAX;
   }
   //temp > 1000?
   if(temp > MIN)
   {
      temp /= MIN;
   }
   
   midsquare_value = temp;
   
   return midsquare_value;
}

/********************************************************************
* The boundry folding technique for finding the hash value (index).
********************************************************************/
template <class Data>
int BasicHashTableLong<Data>::boundryFolding(unsigned long input_key)
{
   const int MAX         = 10000;
   const int MIN         = 100;
   const int REVERSE_MOD = 10;
   const int ARRAY_SIZE  = 4;
   const int EVEN        = 2;
   
   int  array_counter   = 0;
   int  boundry_folding = 0;
   long temp            = input_key;
   
   int storage_array[ARRAY_SIZE];
   
   
   //temp >= 10000?
   while(temp >= MAX)
   {
      //Is the counter even?
      if(!(array_counter % EVEN))
      {
         //Assign storage to temp mod 10000
         //Divide temp by 10000 and reassign
         storage_array[array_counter] = temp % MAX;
         temp /= MAX;
      }
      else
      {
         //Take temp modulo 100
         //Reverse the digits and store into the array
         //Set temp to temp divided by 100
         int pre_reverse_1;
         int pre_reverse_2;

         pre_reverse_1 = temp % MIN;
         pre_reverse_2 = pre_reverse_1 % REVERSE_MOD;
         pre_reverse_2 *= REVERSE_MOD;
         pre_reverse_1 /= REVERSE_MOD;
         pre_reverse_2 += pre_reverse_1;
         storage_array[array_counter] = pre_reverse_2;
         temp /= MIN;
      }
      ++array_counter;
   }
   storage_array[array_counter] = temp;
   ++array_counter;
   
   //Sum up all the digits in the array and return
   for(int i = 0; i < array_counter; i++)
   {
      boundry_folding += storage_array[i];
   }

   return boundry_folding;
}

/********************************************************************
* The folding technique for finding the hash value (index).
********************************************************************/
template <class Data>
long BasicHashTableLong<Data>::folding(unsigned long input_key)
{
   const int COMPARE_NUMBER = 100;
   const int ARRAY_SIZE     = 5;
   const int ADD_LIMIT      = 2;
   
   long folding       = 0;
   int  array_counter = 0;
   int  counter       = 0;
   unsigned long temp = input_key;
   int  add_temp      = 0;
   int  multiply_temp = 1;
   
   int storage_array[ARRAY_SIZE];
   

   //temp >= 100?   
   while(temp >= COMPARE_NUMBER)
   {
      //Break the original numbers into an array of 2-digit numbers
      storage_array[array_counter] = temp % COMPARE_NUMBER;
      temp /= COMPARE_NUMBER;
      ++array_counter;
   }
   storage_array[array_counter] = temp;
   ++array_counter;
   while(counter < array_counter)
   {
      if(counter < ADD_LIMIT)
      {
         //The first two digits in the array add together
         add_temp += storage_array[counter];
      }
      else
      {
         //Ther remainint digits in the array multiply together
         multiply_temp *= storage_array[counter];
      }
      ++counter;
   }
   
   //Set up the return value based on the number of values in the array.
   //If the array contains 2 or less, nothing was multiplied together
   //and just assign to the return value.  If the array contains more
   //than 2 elements, add BOTH the multiply and add sections together
   //and assign to the return value.
   if(counter <= ADD_LIMIT)
   {
      folding = add_temp;
   }
   else
   {
      folding = add_temp + multiply_temp;
   }
   return folding;
}


/********************************************************************
* Overload the insertion operator
********************************************************************/
template <class Data>
ostream& operator<<(ostream& os, BasicHashTableLong<Data>& bhtl)
{
   bhtl.print();
   return os;
}

#endif
