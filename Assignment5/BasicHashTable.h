//BasicHashTable Class
//A basic data structure calss
//Part of the ongoing work to fulfill my desire
//to create a generic data structure tool set
//for everyday application development and generic programming
//A class by Lou Rosas

#ifndef BASIC_HASH_TABLE
#define BASIC_HASH_TABLE

#include "BasicHashElement.h"
#include "MathTools.h"
#include <iostream.h>
#include <strstream.h>
#include <iomanip.h>
#include <string.h>

template <class Data>
class BasicHashTable
{
   public:
      //Public Methods
      //Constructor with no arguments
      BasicHashTable();

      //Constructor setting the intitial Hash Capacity
      BasicHashTable(const float );

      //Copy constructor
      BasicHashTable(BasicHashTable<Data>& );

      //Destructor
      ~BasicHashTable();

      //Assignment Operator
      BasicHashTable& operator=(BasicHashTable<Data>& );

      //The public method to destroy the BasicHashTable
      void destroyBasicHashTable();

      //Insert method: key being a char*
      bool insert(const char*, const Data& );

      //Insert method:  key being a long
      bool insert(long, const Data& );

      //Insert an entire BasicHashElement object
      bool insert(BasicHashElement<Data>& );

      //Given the key, retrieve the data (if in BasciHashTable): char*
      bool find(const char* , Data& );

      //Given the key, retrieve the data (if in BasicHashTable): long
      bool find(const long , Data& );

      //Check to see if the BasicHashTable contains the given key
      //char* format
      bool containsKey(const char* );

      //Check to see if the BasicHashTable contains the given key
      //long format
      bool containsKey(long );
      
      //Get the number of elements with "legit" data 
      //(BasicHashElement::flag is set to SET)
      int getCurrentSize();

      //Get the BasicHashElements in the BasicHashTable
      void getElements(BasicHashElement<Data>* );

      //Given the data, retrieve the key: char* format
      bool getKey(const Data&, char* );

      //Given the data, retrieve the key: long format
      bool getKey(const Data&, long& );
      
      //Get the max number of slots in the BasicHashTable
      int getMaxSize();

      //Remove the data from the BasicHashTable: char* format
      bool remove(const char*, Data& );

      //Remove the data from the BasicHashTable: long format
      bool remove(long, Data& );

      //Check to see if the BasicHashTable is empty
      bool isEmpty();
      
      //Get the Rehash Capacity
      float getRehashCapacity();

      //Set the Rehash Capacity
      void setRehashCapacity(float );

      //Print the BasicHashTable
      void print();

      //No public attributes

   protected:
      //Get the number of elements in the BasicHashTable
      int getSize();

   private:
      //Private methods
      //Private method to destroy the Basic Hash Table
      void destroyBHT();

      //The hash method: accepts char*
      int hash(const char* );

      //The hash method: accepts long
      int hash(long );

      //The nextHash method:  the method called in the event of a
      //collision
      int nextHash(unsigned int, unsigned int );

      //Given a key, retrieve the position in the BasicHashTable where
      //it is stored (provided the key is in the BasicHashTable)
      //the char* method
      int getPosition(const char* );

      //Given a key, retrieve the position in the BasicHashTable where
      //it is stored (provided the key is in the BasicHashTable)
      //the long method
      int getPosition(long );

      //Re-Hash the BasicHashTable:  remove all deleted data and resize
      //the BasicHashTable
      bool reHash();

      //Set the number of elements currently saved in the BasicHashTable
      void setSize(int );

      //Set the max number of slots in the BasicHashTable
      void setMaxSize(int );

      //The midsquare technique for determining the hash value (the
      //index into the BasicHashTable): used for when the key is of
      //type long
      int midsquare(long );

      //The boundy folding technique for determining the hash value
      //(the index into the BasicHashTable): used for when the key is
      //of type long
      int boundryFolding(long );

      //The folding technique for determining the hash value
      //(the index into the BasicHashTable): used for when the key is
      //of type long
      long folding(unsigned long );

      //The folding technique for determining the hash value
      //(the index into the BasicHashTable):  used for when the
      //key has already been broken up into an array of integers,
      //passing in the number of indices in the array to "fold" into
      //a value
      long folding(int*, int);

      //If the number is so large that it can only be represented by
      //a string, then this method will take that number and break
      //it up into two digit numbers and place into an array
      //i.e:  "4235" will parse into 35 42 into an array (35 at
      //position 0, 42 at position 1 in the array.  This method
      //returns the number of indices of valid numbers in the array.
      //the array that is populated is placed as an input parameter,
      //as well as the string to parse into two digit numbers in the
      //array
      int parse(const char*, int* );


      //Private Attributes
      //The max number of of slots in the BasicHashTable
      int max_size;

      //The number of slots in the BasicHashTable containing data
      //(deleted or not)
      int size;

      //The capcity (size/max_size) ratio the BasicHashTable must
      //attain before the reHash() method is invoked.
      float rehash_capacity;

      //The array of BasicHashElement objects
      BasicHashElement<Data>* basicHashElements;

      //Defaut Rehash Capacity
      static const float DEFAULT_REHASH_CAPACITY;
      
      //The initial max size of the BasicHashTable:  the original number
      //of slots available for storage in the BasicHashTable
      //(THIS NUMBER MUST ALWAY BE PRIME TO AVOID
      // INFINITE LOOP SITUATION INSIDE THE ACTUAL CODE--doing a
      // nextHash and the like)
      static const int INITIAL_MAX_SIZE = 17;
};
//Overload the insertion operator
template <class Data>
ostream& operator<<(ostream& , const BasicHashTable<Data>& );

//For some reason, for a float, the static variables cannot
//be initialized upon declaration.
template <class Data>
const float BasicHashTable<Data>::DEFAULT_REHASH_CAPACITY = 0.6;

//Class Implementation
//Public Methods
/********************************************************************
* Constructor
* Constructor of no attributes
********************************************************************/
template <class Data>
BasicHashTable<Data>::BasicHashTable()
 : size(0),
   max_size(0),
   rehash_capacity(0),
   basicHashElements(NULL)
{
   this->setMaxSize(INITIAL_MAX_SIZE);
   this->setRehashCapacity(DEFAULT_REHASH_CAPACITY);
   this->basicHashElements = 
         new BasicHashElement<Data>[this->getMaxSize()];
}

/********************************************************************
* Constructor that explicitly sets the Hash Capacity (the capacity of
* the BasicHashTable required for the table to be rehashed).
********************************************************************/
template <class Data>
BasicHashTable<Data>::BasicHashTable(const float rh_capacity)
 : size(0),
   max_size(0),
   rehash_capacity(0),
   basicHashElements(NULL)
{
   this->setMaxSize(INITIAL_MAX_SIZE);
   this->setRehashCapacity(rh_capacity);
   this->basicHashElements = 
         new BasicHashElement<Data>[this->getMaxSize()];
}

/********************************************************************
* Copy Constructor
* Creates and copies the data of one BasicHashTable object to the
* newly created BasicHashTable object
********************************************************************/
template <class Data>
BasicHashTable<Data>::BasicHashTable
(
   BasicHashTable<Data>& copy_hash
)
  : size(0),
    max_size(0),
    rehash_capacity(0),
    basicHashElements(NULL)
{
   //The max_size of the copy_hash BasicHashTable
   int max_hash_elements = copy_hash.getMaxSize();

   //The BasicHashElement array to copy from the copy_hash
   //BasicHashTable
   BasicHashElement<Data>* copy_elements
      = new BasicHashElement<Data>[max_hash_elements];

   //Destroy myself
   this->destroyBHT();

   //Set the max size to the initial INITIAL_MAX_SIZE (this will
   //change as needed when data is added)
   this->setMaxSize(INITIAL_MAX_SIZE);

   //Set the rehash_capacity to the Reahsh Capacity of the
   //BasicHashTable that is being copied
   this->setRehashCapacity(copy_hash.getRehashCapacity());

   //Create the BasicHashElement array to the initial size
   //This will change as data is added
   this->basicHashElements =
         new BasicHashElement<Data>[this->getMaxSize()];

   //Get the BasicHashElements from the copy_hash BasicHashTable
   copy_hash.getElements(copy_elements);

   //Insert the BasicHashElements from the copy_hash BasicHashTable
   //into this BasicHashTable
   for(int i = 0; i < max_hash_elements; i++)
   {
      if(copy_elements[i].getFlag() == BasicHashElement<Data>::SET)
      {
         this->insert(copy_elements[i]);
      }
   }

   delete [] copy_elements;
   copy_elements = NULL;
}

/********************************************************************
* Destructor                                                        
********************************************************************/
template <class Data>
BasicHashTable<Data>::~BasicHashTable()
{
   //Call the appropriate method before the object itself is
   //destroyed
   this->destroyBHT();
}

/********************************************************************
* Assignment operator                                               
* Essentially, follow what was done with the Copy Constructor       
********************************************************************/
template <class Data>
BasicHashTable<Data>& BasicHashTable<Data>::operator=
(
   BasicHashTable<Data>& basic_hash_table
)
{
   //The max size of the basic_hash_table BasicHashTable
   int max_hash_elements = basic_hash_table.getMaxSize();

   //The BasicHashElement array to copy from the basic_hash_table
   //BasicHashTable
   BasicHashElement<Data>* copy_elements = 
      new BasicHashElement<Data>[max_hash_elements];

   //Destroy myself
   this->destroyBHT();

   //Set the max_size to the INITIAL_MAX_SIZE (this will change as
   //needed when data is added)
   this->setMaxSize(INITIAL_MAX_SIZE);

   //Set the rehash_capacity to the Rehash Capacity of the
   //BasicHashTable that is being copied
   this->setRehashCapacity(basic_hash_table.getRehashCapacity());

   //Create the BasicHashElement array to the initial size.  This
   //will change as data is added
   this->basicHashElements = 
      new BasicHashElement<Data>[this->getMaxSize()];

   //Get the BasicHashElements from the basic_hash_table BasicHashTable
   basic_hash_table.getElements(copy_elements);

   //Insert the BasicHashElements from the basic_hash_table
   //BasicHashTable in the this BasicHashTable
   for(int i = 0; i < max_hash_elements; i++)
   {
      if(copy_elements[i].getFlag() == BasicHashElement<Data>::SET)
      {
         this->insert(copy_elements[i]);
      }
   }

   delete [] copy_elements;
   copy_elements = NULL;

   return *this;
}

/********************************************************************
* The public method for destroying the BasicHashTable
********************************************************************/
template <class Data>
void BasicHashTable<Data>::destroyBasicHashTable()
{
   //Call the appropriate method to destroy the proper associated
   //objects before the object itself is destroyed
   this->destroyBHT();
}

/********************************************************************
* The insert method: used for the key of type char*
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::insert
(
   const char* key, 
   const Data& data
)
{
   bool return_value = true;
   int current_position;
   int current_flag;
   int set_key = BasicHashElement<Data>::SET; //assume it to be set

   //Does the BasicHashTable need to be rehashed?
   if(
       !(this->getMaxSize()) ||
       (this->getSize()/(float)this->getMaxSize()) >= 
       this->getRehashCapacity()
   )
   {
      //Rehash the BasicHashTable
      return_value = this->reHash();
   }
   if(return_value)
   {
      //Get the position into the BasicHashTable
      current_position = this->getPosition(key);
      current_flag = basicHashElements[current_position].getFlag();
      //if current_flag == BasicHashElement<Data>::EMPTY (0)
      if(!current_flag)
      {
         //If the BasicHashElement flag field is EMPTY,
         //Set the key field to the key input
         set_key = 
            this->basicHashElements[current_position].setKey(key);
         //Increase the size of the BasicHashTable by one
         if(set_key)
         {
            this->setSize(this->getSize() + 1);
         }
      }
      //Set the data field of the BasicHashElement
      //Set the return value upon storage of the data field
      if(set_key)
      {
         return_value = 
            this->basicHashElements[current_position].
                                                       setData(data);
      }
      else
      {
         return_value = false;
      }
   }
   return return_value;
}

/********************************************************************
* The insert method: used for the key of type long
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::insert
(
   long key,
   const Data& data
)
{
   bool return_value = true;
   int current_position;
   int current_flag;
   int set_key = BasicHashElement<Data>::SET; //assume it to be set

   //Does the BasicHashTable need to be re-hashed?
   if(!(this->getMaxSize()) ||
       (this->getSize()/(float)this->getMaxSize()) >= 
        this->getRehashCapacity()
   )
   {
      //Re-hash the BasicHashTable
      return_value = this->reHash();
   }
   
   if(return_value)
   {
      //Get the position into the BasicHashTable
      current_position = this->getPosition(key);
      current_flag = this->basicHashElements[current_position].getFlag();

      //if current_flag == BasicHashElment<Data>::EMPTY (0)
      if(!current_flag)
      {
         //if the BasicHashElement flag field is EMPTY,
         //set the key field to the key input
         set_key = 
            this->basicHashElements[current_position].setKey(key);
         if(set_key)
         {
            //increase the size of the BasicHashTable by one
            this->setSize(this->getSize() + 1);
         }
      }
      //Set the data field of the BasicHashElement
      //Set the return value upon storage of the data field
      if(set_key)
      {
         return_value =
            this->basicHashElements[current_position].setData(data);
      }
      else
      {
         return_value = false;
      }
   }
   
   return return_value;
}

/********************************************************************
* The insert method: used for inserting an entire BasicHashElement
* object
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::insert
(
   BasicHashElement<Data>& copy_element
)
{
   bool return_value = true;
   bool isChar;
   int  current_position;
   int  current_flag;
   int  set_key = BasicHashElement<Data>::SET; //assume it to be set
   char get_key_char[256];
   int  get_key_long;
   Data the_data;

   //Get the type of key field stored in copy_element
   //of type char*
   copy_element.getKey(get_key_char);
   //of type long
   get_key_long = copy_element.getKey();
   //Get the data in copy_element
   copy_element.getData(the_data);

   //Check to see the type of key field (char* or long)
   if(!strcmp(get_key_char,""))
   {
      //of type long
      isChar = false;
   }
   else
   {
      //of type char*
      isChar = true;
   }

   //Does the BasicHashTable need to be rehashed?
   if(!(this->getMaxSize()) ||
       (this->getSize()/(float)this->getMaxSize()) >=
       this->getRehashCapacity()
   )
   {
      //Rehash the BasicHashTable
      return_value = this->reHash();
   }
   if(return_value)
   {
      //Get the position into the BasicHashTable
      if(isChar)
      {
         current_position = this->getPosition(get_key_char);
      }
      else
      {
         current_position = this->getPosition(get_key_long);
      }
      current_flag = this->basicHashElements[current_position].getFlag();
      //if current_flag == BasicHashElement<Data>::EMPTY (0)
      if(!current_flag)
      {
         //If the BasicHashElement flag field is EMPTY
         //set the key field to the key input
         //determine if the key is of type char* or long
         if(isChar)
         {
            set_key = 
               this->basicHashElements[current_position].
                                                setKey(get_key_char);
         }
         else
         {
            set_key = 
               this->basicHashElements[current_position].
                                                setKey(get_key_long);
         }
         //Increase the size of the BasicHashTable by 1
         if(set_key)
         {
            this->setSize(this->getSize() + 1);
         }
      }
      //Set the data field of the BasicHashElement
      //Set the return value upon storage of the data field
      if(set_key)
      {
         return_value = 
            
            this->basicHashElements[current_position].setData(the_data);
      }
      else
      {
         return_value = false;
      }
   }
   return return_value;
}

/********************************************************************
* Given the key, retrieve the data.  This method is used for the
* key being of type char*.
* If the key is not in the BasicHashTable, this method will return
* false, true otherwise
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::find(const char* key, Data& data)
{
   bool return_flag = false;
   int current_position;
   int current_flag;

   //If the BasicHashTable is not empty
   if(!(this->isEmpty()))
   {
      //Get the current position in the BasicHashTable where the key
      //is located
      current_position = this->getPosition(key);
      current_flag = this->basicHashElements[current_position].getFlag();
      //Is the flag field of the BasicHashElement at SET (2)
      if(current_flag == BasicHashElement<Data>::SET)
      {
         //Get the data from the BasicHashElement
         this->basicHashElements[current_position].getData(data);
         //set the return_flag to true
         return_flag = true;
      }
   }

   return return_flag;
}

/********************************************************************
* Given the key, retrieve the data.  This method is used for the
* key being of type long.
* If the key is not in the BasicHashTable, this method will return
* false, true otherwise
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::find(const long key, Data& data)
{
   bool return_flag = false;
   int current_position;
   int current_flag;

   //If the BasicHashTable is not empty
   if(!(this->isEmpty()))
   {
      //Get the current position in the BasicHashTable where the key
      //is located
      current_position = this->getPosition(key);
      current_flag = this->basicHashElements[current_position].getFlag();
      //Is the flag field of the BasicHashElement at SET (2)?
      if(current_flag == BasicHashElement<Data>::SET)
      {
         //Get the data from the BasicHashElement
         this->basicHashElements[current_position].getData(data);
         //set the return_flag to true
         return_flag = true;
      }
   }

   return return_flag;
}

/********************************************************************
* Check to see if the BasicHashTable contains the given key, used
* for char* format.
* Returns: true if key is in BasicHashTable, false if key is not in
* BasicHashTable.
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::containsKey(const char* key)
{
   bool return_flag = false;
   int current_position;
   int current_flag;

   //Get the current position in the BasicHashTable where the key
   //is located
   current_position = this->getPosition(key);
   current_flag = this->basicHashElements[current_position].getFlag();
   //Is the flag field of the BasicHashElement at SET (2)?
   if(current_flag == BasicHashElement<Data>::SET)
   {
      return_flag = true;
   }

   return return_flag;
}

/********************************************************************
* Check to see if the BasicHashTable contains the given key, used
* for long format.
* Returns: true if key is in BasicHashTable, false if key is not in
* BasicHashTable.
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::containsKey(long key)
{
   bool return_flag = false;
   int current_position;
   int current_flag;

   //Get the current position in the BasicHashTable where the key
   //is located
   current_position = this->getPosition(key);
   current_flag = this->basicHashElements[current_position].getFlag();
   //Is the flag field of the BasicHashElement at SET (2)?
   if(current_flag == BasicHashElement<Data>::SET)
   {
      return_flag = true;
   }

   return return_flag;
}

/********************************************************************
* Get the current number of (viable data only) BasicHashElements in
* the BasicHashTable
********************************************************************/
template <class Data>
int BasicHashTable<Data>::getCurrentSize()
{
   //The current size counter, the value returned
   int current_size = 0;
   //The max size of the HashTable
   int max_size = this->getMaxSize();
   //If the HashTable is filled with Legit OR non-Legit data
   if(!this->isEmpty())
   {
      for(int i = 0; i < max_size; i++)
      {
         if(this->basicHashElements[i].getFlag() == 
               BasicHashElement<Data>::SET)
         {
            ++current_size;
         }
      }
   }
   return current_size;
}

/********************************************************************
* Copy the BasicHashElements in the BasicHashTable
********************************************************************/
template <class Data>
void BasicHashTable<Data>::getElements
(
   BasicHashElement<Data>* currentHashElements
)
{
   int max_size_count = 0;
   int size_count     = 0;
   
   int i = 0;
   while((max_size_count < this->getMaxSize()) 
          && (size_count < this->getSize()))
   {
      if(this->basicHashElements[max_size_count].getFlag()
            == BasicHashElement<Data>::SET)
      {
         currentHashElements[i] = this->basicHashElements[max_size_count];
	 size_count++;
	 i++;
      }
      max_size_count++;
   }
}

/********************************************************************
* Given the data, retrieve the key: char* format
* Returns: true if the key was retrieved, false otherwise
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::getKey(const Data& data, char* key)
{
   //With the return value, indicate the key is not found
   bool return_value = false;
   //Set count to 0
   int count = 0;
   //Get the max_count
   int max_count = this->getMaxSize();
   //Store off the most recent data
   Data loc_data;

   //Loop to find the key related to the data
   do{
      int current_flag;
      basicHashElements[count].getData(loc_data);
      
      //Is the current data the same as the incomming data?
      if(loc_data == data)
      {
         //Check the status of the flag: only return the key iff the
         //data in the BasicHashTable is valid (The flag field of the 
         //BasicHashElement is SET (2))
         current_flag = this->basicHashElements[count].getFlag();
         if(current_flag == BasicHashElement<Data>::SET)
         {
            //Must actually retrieve the key
            this->basicHashElements[count].getKey(key);
            if(strcmp(key,""))
            {
               //Indicate the key value is found only if the key is 
               //not "" (Blank), which would indicate no valid data 
               //in the key
               return_value = true;
            }
         }
      }
      count++;
   }while(count < max_count && !return_value);
   return return_value;
}

/********************************************************************
* Given the data, retrieve the key: long format
* Returns: true if the key was retrieved, false otherwise
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::getKey(const Data& data, long& key)
{
   //With the return value, indicate the key is not found
   bool return_value = false;
   //Set count to 0
   int count = 0;
   //Get the max count
   int max_count = this->getMaxSize();
   //Store off the most recent data
   Data  loc_data;

   //Loop to find the key related to the data
   do{
      int current_flag;
      basicHashElements[count].getData(loc_data);

      //is the current data the same as the incomming data?
      if(loc_data == data)
      {
         //Check the status of the flag:  only return the key iff the
         //data in the BasicHashTable is valid (The flag field of the
         //BasicHashElement is SET (2))
         current_flag = this->basicHashElements[count].getFlag();
         if(current_flag == BasicHashElement<Data>::SET)
         {
            //must actually retrieve the data
            key = this->basicHashElements[count].getKey();
            //indicate the key value is found
            return_value = true;
         }
      }
      count++;
   }while(count < max_count && !return_value);
   return return_value;
}

/********************************************************************
* Get the current number of BasicHashElements (either with viable or
* deleted data) in the BasicHashTable
********************************************************************/
template <class Data>
int BasicHashTable<Data>::getSize()
{
   return this->size;
}

/********************************************************************
* Get the max number of slots in the BasicHashTable
********************************************************************/
template <class Data>
int BasicHashTable<Data>::getMaxSize()
{
   return this->max_size;
}

/********************************************************************
* Remove the requested data from the BasicHashTable:  char* format
* Returns: true if the data was removed, false otherwise
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::remove(const char* key, Data& data)
{
   bool isRemoved = false;
   int current_position;
   int current_flag;
   
   //Check to see if the BasicHashTable is empty
   if(!(this->isEmpty()))
   {
      //Get the current position in the BasicHashTable
      current_position = this->getPosition(key);
      //Get the flag field in the BasicHashTable
      current_flag = this->basicHashElements[current_position].getFlag();
      //Does the flag == BasicHashElement<Data>::SET (2)?
      //No reason to remove something that 1) is already removed
      //or (2) the BasicHashElement contains no data at all
      if(current_flag == BasicHashElement<Data>::SET)
      {
         //Copy the data into the Data input parameter: to be returned
         this->basicHashElements[current_position].getData(data);
         //Remove the data by setting the flag field in the
         //BasicHashElement to BasicHashElement<Data>::DELETED (1)
         //and setting the return boolean
         current_flag = BasicHashElement<Data>::DELETED;
         isRemoved = 
            this->basicHashElements[current_position].
                                               setFlag(current_flag);
      }
   }
   return isRemoved;
}

/********************************************************************
* Remove the requested data from the BasicHashTable:  long format
* Returns: true if the data was removed, false otherwise
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::remove(long key, Data& data)
{
   bool isRemoved = false;
   int current_position;
   int current_flag;

   //Check to see if the BasicHashTable is empty
   if(!(this->isEmpty()))
   {
      //Get the current position in the BasicHashTable
      current_position = this->getPosition(key);
      //Get the flag field in the BasicHashTable
      current_flag = this->basicHashElements[current_position].getFlag();
      //Does the flag==BasicHashElement<Data>::SET (2)?
      //No reason to remove something that 1) is already removed
      //or 2) the BasicHashElement cotains no data at all
      if(current_flag == BasicHashElement<Data>::SET)
      {
         //Copy the data into the Data input parameter: to be returned
         this->basicHashElements[current_position].getData(data);
         //Remove the data by setting the flag field in the
         //BasicHashElement to BasicHashElement<Data>::DELETED (1)
         //And setting the return boolean
         current_flag = BasicHashElement<Data>::DELETED;
         isRemoved =
            this->basicHashElements[current_position].
                                               setFlag(current_flag);
      }
   }
   return isRemoved;
}

/********************************************************************
* Check to see if the BasicHashTable is empty
* Returns: true if empty, false if not
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::isEmpty()
{
   bool return_value = false;

   //If the size of the HashTable is 0, there is no data in the
   //HashTable
   if(!(this->getSize()))
   {
      //The BasicHashTable is truly empty
      return_value = true;
   }
   //If the size of the HashTable is not 0, there could still be data
   //in the HashTable that was DELETED, but still exists in the HashTable
   //This data is not there except for the purpose of acting as a
   //"counting indicator" of when to resize the array of the HashTable.
   //The data is not considered legit, and will be removed on the next
   //reHash() invocation, but the size (in the purest sence) is not 0.
   //Therefore, this needs to be accounted for when determining if the
   //HashTable is empty:  deleted data is NOT legitamite and will not be
   //accesed and therefore a HashTable filled with deleted data is
   //from the users point of view CONCEPTUALLY EMPTY
   else
   {
      int count      = 0;
      int max_size   = this->getMaxSize();
      bool temp_bool = true;
      
      //Need to check if there is any data in SET
      while(count < max_size)
      {
         if(this->basicHashElements[count].getFlag()
	       == BasicHashElement<Data>::SET)
	 {
	    temp_bool = false;
	    count = max_size;
	 }
	 return_value = temp_bool;
	 ++count;
      }
   }
   return return_value;
}

/********************************************************************
* Get the current rehash capacity value
********************************************************************/
template <class Data>
float BasicHashTable<Data>::getRehashCapacity()
{
   return this->rehash_capacity;
}

/********************************************************************
* Set the current rehash capacity value
********************************************************************/
template <class Data>
void BasicHashTable<Data>::setRehashCapacity(float new_capacity)
{
   const float MAX_HASH = 1.00;
   const float MIN_HASH = 0.01; //One percent hash value
   //Cannot have a rehash capacity of over 1.00 (100%)
   if(new_capacity > MAX_HASH)
   {
      this->rehash_capacity = MAX_HASH;
   }
   //Clip the min rehash capacity at 1% and be done with it!!!
   else if(new_capacity < MIN_HASH)
   {
      this->rehash_capacity = MIN_HASH;
   }
   //Rehash capacity is within normal operating range
   else
   {
      this->rehash_capacity = new_capacity;
   }
}

/********************************************************************
* Print the BasicHashTable
********************************************************************/
template <class Data>
void BasicHashTable<Data>::print()
{
   int max_size_count = 0; //counter compared to max_size
   int size_count     = 0; //counter compared to size
   int loop_count     = 0; //counter to check to start a newline

   //If all the data in the BasicHashTable has been printed out,
   //don't bother continuing to loop through the BasicHashTable
   while((max_size_count < this->getMaxSize())
         && (size_count < this->getSize()))
   {
      //Only print out viable (set data)
      if(this->basicHashElements[max_size_count].getFlag() 
            == BasicHashElement<Data>::SET)
      {
         cout<<this->basicHashElements[max_size_count];
         size_count++;
	 //If three elements have been displayed on a line, start
	 //a new line, start loop counter over
	 if(++loop_count == 3)
	 {
	    cout<<endl; 
	    loop_count = 0;
	 }
      }
      max_size_count++;
   }
}

//Private Methods
/********************************************************************
* The private method to destroy the BasicHashTable
********************************************************************/
template <class Data>
void BasicHashTable<Data>::destroyBHT()
{
   if(basicHashElements)
   {
      delete [] basicHashElements;
      basicHashElements = NULL;
   }
   this->setSize(BasicHashElement<Data>::EMPTY);
   this->setMaxSize(INITIAL_MAX_SIZE);
}

/********************************************************************
* Given the key, hash an index into the BasicHashTable:  this serves
* as an index into the array that essentially comprises the 
* BasicHashTable.
* This method is used for a key of type char*
********************************************************************/
template <class Data>
int BasicHashTable<Data>::hash(const char* key)
{
   //Set the return value to some (essentially) illegal value
   int return_value = -1;
   //The max size of the BasicHashTable
   int max_size = this->getMaxSize();
   //The total number of characters in the input string
   int total_string_size = strlen(key);
   //The counter of "non-number characters in the input string
   int non_num_char = 0;
   //The number of "non-number" characters in the string
   for(int i = 0; i < total_string_size; i++)
   {
      if(key[i] > '9' || key[i] < '0')
      {
         ++non_num_char;
      }
   }

   //Is the string completly "numerical" 
   //(all characters are between '0' and '9')
   if(!(non_num_char))
   {
      //The value comming back from the folding method
      long hash_value = 0;
      //The number of array indices with valid data in the
      //two_digit_values[] array
      int indices = 0;
      //The array of two digit values contained in key
      int two_digit_values[150];
      
      //Parse the string into numerical values all < 100
      indices = this->parse(key,two_digit_values);
      //Apply the appropriate Folding technique
      hash_value  = this->folding(two_digit_values, indices);
      //Modulo the return value by the max size and
      //set the modded value to the return_value
      return_value = hash_value % max_size;
   }
   //The string has non-numerical values in it
   else
   {
      //The total ASCII value of the input string
      int total_string_value = 0;
      
      //Add up all the ASCII values of the string characters
      for(int i = 0; i < total_string_size; i++)
      {
         total_string_value += key[i];
      }
      //Modulo the total_string_value by the Max Size
      //Set the Moded value to the return value
      return_value = total_string_value % max_size;
   }

   return return_value;
}

/********************************************************************
* Given the key, hash an index into the BasicHashTable:  this serves
* as an index into the array that essentially comprises the 
* BasicHashTable.
* This method is used for a key of type long
********************************************************************/
template <class Data>
int BasicHashTable<Data>::hash(long key)
{
   //Set the return value to some (essentially) illeagal value
   int return_value = -1;
   //the hash_value:  set the return value to some (essentially)
   //illeagal value
   int hash_value = -1;
   //The max size of the BasicHashTable
   int max_size = this->getMaxSize();

   //the midsquare technique value limit
   const long MIDSQUARE_LIMIT = 10000;
   //the boundry folding technique value limit
   const long BOUNDRY_FOLDING_LIMIT = 1000000000;
   

   //Is key < 10,000?
   if(key < MIDSQUARE_LIMIT)
   {
      //Apply the midsquare technique
      hash_value = this->midsquare(key);
   }
   //Is key >= 10,000 and < 1,000,000,000?
   else if(key >= MIDSQUARE_LIMIT && key < BOUNDRY_FOLDING_LIMIT)
   {
      //Apply the boundry folding technique
      hash_value = this->boundryFolding(key);
   }
   //If the key is > 1,000,000,000, apply the last method possible
   //to acquire the hash value
   else
   {
      //Apply the folding technique
      hash_value = this->folding(key);
   }
   //Modulo divide the hash_value by the max size of the
   //BasicHashTable and set that value to the return_value
   return_value = hash_value % max_size;

   return return_value;
}

/********************************************************************
* Upon the event of a collision in the BasicHashTable, the reHash()
* method is invoked.  This method calculates the next posible index
* into the BasicHashTable given the previous index and the
* Fibonacci series index
********************************************************************/
template <class Data>
int BasicHashTable<Data>::nextHash
(
   unsigned int previous_index, 
   unsigned int fibonacci_index
)
{
   //The Fibinacci number in the sequence
   unsigned int fib_number;

   //Set the return value to some (essentially) illeagal value
   int return_value = -1;
   //the set value
   unsigned int set_value = 0xFFFFFFFF;
   //The max size of the BasicHashTable
   int max_size = this->getMaxSize();

   //Get Fibinacci sequence number
   fib_number = MathTools::fibSeriesNumber(fibonacci_index);
   //Add the fib_number to previous_index, storing in return_value
   set_value = fib_number + previous_index;
   //Modulo divide the set_value by the max_size of the 
   //BasicHashTable
   return_value = set_value % max_size;

   return return_value;
}

/********************************************************************
* This method performs multiple tasks direclty related to one 
* another:  Given a key value, this method will retrieve the
* position in the BasicHashTable where the data is located if the
* data is in the BasicHashTable, OR the next position AVAILABLE WHERE
* the data could be stored if not in the BasicHashTable already.
* This method is used for the key of type char*
********************************************************************/
template <class Data>
int BasicHashTable<Data>::getPosition(const char* key)
{
   int  current_position;
   int  return_position;
   int  flag_value;
   char current_key[256];

   //Indicates only been through the do-while loop once
   bool once_pass = true;
   int fib_index = 0;

   do{
      if(once_pass)
      {
         //Get the hash value of the key
         current_position = this->hash(key);
         //indicate been through the loop once already
         once_pass = false;
      }
      //Been through the loop once already
      else
      {
         //Increase the Fibinacci index by 1
         ++fib_index;
         //Get the next hash position
         current_position = this->nextHash(current_position, fib_index);
      }
      //Get the flag value
      flag_value = this->basicHashElements[current_position].getFlag();
      //Get the key value
      this->basicHashElements[current_position].getKey(current_key);
   //Keep looping while the flag_value is set (!0) AND the
   //key,current_key combination is different OR the flag_value is
   //set to DELETED (1)
   }while((flag_value) && (strcmp(current_key, key) 
                    || flag_value == BasicHashElement<Data>::DELETED));

   //Assign return_postion to current_position
   return_position = current_position;

   return return_position;
}

/********************************************************************
* This method performs multiple tasks direclty related to one 
* another:  Given a key value, this method will retrieve the
* position in the BasicHashTable where the data is located if the
* data is in the BasicHashTable, OR the next position AVAILABLE WHERE
* the data could be stored if not in the BasicHashTable already.
* This method is used for the key of type long
********************************************************************/
template <class Data>
int BasicHashTable<Data>::getPosition(long key)
{
   int current_position;
   int return_position;
   int flag_value;
   int current_key;

   //Indicates only been through the do-while loop once
   bool once_pass = true;
   int  fib_index = 0;

   do{
      if(once_pass)
      {
         //get the hash value of the key
         current_position = this->hash(key);
         //indicate the loop has been executed once already
         once_pass = false;
      }
      else
      {
         //Increase the Fibinacci index by 1
         ++fib_index;
         //get the next hash position
         current_position = this->nextHash(current_position, fib_index);
      }
      //Get the flag value
      flag_value = this->basicHashElements[current_position].getFlag();
      //Get the key value
      current_key = this->basicHashElements[current_position].getKey();
   //Keep looping while the flag_value is set (!0) AND the
   //key,current_key combination is different OR the flag_value is
   //set to DELETED (1)
   }while((flag_value) && ((current_key != key)
                     || flag_value == BasicHashElement<Data>::DELETED));

   //Assign return_position to current_position
   return_position = current_position;
   
   return return_position;
}

/********************************************************************
* When the BasicHashTable gets too large:  either with current
* or deleted data, it needs to be rehashed.  Rehashing removes
* all deleted data, resizes the BasicHashTable to the next
* available prime number, stores the valid data back into the newly
* sized BasicHashTable and stores any new data pending.
********************************************************************/
template <class Data>
bool BasicHashTable<Data>::reHash()
{
   cout<<"\n\n\nIn the reHash() method\nBefore: ";
   cout<<"\nmax_elements: "<<this->getMaxSize();
   cout<<"\ngetSize() (num total elements hashed):  "<<this->getSize();
   cout<<"\ngetCurrentSize() (num valid data hashed): "
      <<this->getCurrentSize();
   
   //The return Boolean
   bool return_value = false;
   
   //The value used to resize the BasicHashTable
   int temp_size;
   
   //The current max size to the BasicHashTable
   int previous_max_size;
   
   //The pointer used to preserve the data pointed to by
   //basicHashElements as basicHashElements gets resized
   BasicHashElement<Data>* tempHashElements;

   //Get the current max size of the BasicHashTable
   previous_max_size = this->getMaxSize();

   //Is the Max Size of the BasicHashTable 0?  If so, there is
   //no place to store the data;
   if(!previous_max_size)
   {  
      //Set temp_size to INITIAL_MAX_SIZE
      temp_size = INITIAL_MAX_SIZE;
   }
   else
   {
      //Set temp_size to the next prime number
      temp_size = MathTools::getNextPrime(previous_max_size);
   }
   //Set max_size to temp_size
   this->setMaxSize(temp_size);
      
   //Set the temp pointer to basicHashElements
   tempHashElements = basicHashElements;
   
   //Set basicHashElements to NULL
   basicHashElements = NULL;
   
   //Create new BasicHashElement array
   basicHashElements = new BasicHashElement<Data>[this->getMaxSize()];
   
   //basicHashElements NOT NULL?
   if(basicHashElements)
   {
      //Reset the current size of the HashTable (no data in the newly
      //created array), therfor set the size to 0
      this->setSize(BasicHashElement<Data>::EMPTY);
      
      //Insert all legitimate data from tempHashElements into
      //basicHashElements
      for(int i = 0; i < previous_max_size; i++)
      {	 
         //A temp flag value to deterimine which the appropriate
	 //data copied from one array to the next
         int temp_flag = tempHashElements[i].getFlag();
         
         if(temp_flag == BasicHashElement<Data>::SET)
         {
            this->insert(tempHashElements[i]);
	 }
      }
      //Set return value to true
      return_value = true;
   }
   //Delete tempHashElements and set to NULL
   delete [] tempHashElements;
   tempHashElements = NULL;
   
   cout<<"\nAfter: \nmax_elements: "<<this->getMaxSize();
   cout<<"\ngetSize() (num total elements hashed):  "<<this->getSize();
   cout<<"\ngetCurrentSize() (num valid data hashed): "
      <<this->getCurrentSize();
   cout<<endl<<endl;

   return return_value;
}

/********************************************************************
* Sets the number of positions in the BasicHashTable containing
* viable or deleted data:  based on the flag field of the
* BasicHashElement
********************************************************************/
template <class Data>
void BasicHashTable<Data>::setSize(int current_size)
{
   this->size = current_size;
}

/********************************************************************
* Sets the Max number of slots in the BasicHashTable.  Because of
* the way the BasicHashTable is set up, only a certain percentage
* of those slots in the BasicHashTable will be filled with data.
* In other words:  not all the slots in the BasicHashTable will
* contain data, some will be empty.  This is not the number of how
* much data is IN the table, rather the total number of slots in the
* BasicHashTable itself
********************************************************************/
template <class Data>
void BasicHashTable<Data>::setMaxSize(int maxSize)
{
   //Is maxSize Prime?
   if(MathTools::isPrime(maxSize))
   {
      //Set max_size to maxSize
      this->max_size = maxSize;
   }
   else
   {
      if(maxSize > 0)
      {
         //Set max_size to the next prime number
         this->max_size = MathTools::getNextPrime(maxSize);
      }
      else
      {
         //Set max_size to INITIAL_MAX_SIZE
         this->max_size = INITIAL_MAX_SIZE;
      }
   }
}

/********************************************************************
* The midsquare technique for determining the hash value into the
* BasicHashTable.  This is used for a key of type long, and when
* that key value is < 10000.
********************************************************************/
template <class Data>
int BasicHashTable<Data>::midsquare(long key)
{
   //The small value for comparision sake
   const int SMALL_VALUE = 1000;
   //The large value for comparision sake
   const int LARGE_VALUE = 100000;

   int  return_value;  //The value to return
   long temp_value;    //The value assigned to key

   //Set temp_value to key^2;
   temp_value = key*key;
   if(temp_value > LARGE_VALUE)
   {
      //Take temp_value and modulo divide by 100000 and reassign
      temp_value %= LARGE_VALUE;
   }
   if(temp_value > SMALL_VALUE)
   {
      //Take temp_value divided by 100 and reassign
      temp_value /= SMALL_VALUE;
   }
   return_value = temp_value;

   return return_value;
}

/********************************************************************
* The boundryFolding technique for determining the hash value into
* the BasicHashTable.  This is used for a key of type long, and when
* that key value is >= 10000 and < 1000000000.
********************************************************************/
template <class Data>
int BasicHashTable<Data>::boundryFolding(long key)
{
   //The maximum comparision value
   const int MAX_VALUE = 10000;
   //The minimum comparision value
   const int MIN_VALUE = 100;
   //The value to aid in the reversal of digits
   const int REV_VALUE = 10;
   //The size of the array
   const int ARRAY_SIZE = 5;

   //Set counter to 0
   //The loop counter/array position
   int counter = 0;
   //Temp storage value of the key
   //Assign temp to key
   long temp = key;
   int return_value = 0;

   //The number storage array:  The size of this array does not need
   //to be any larger
   int storage_array[ARRAY_SIZE];

   while(temp >= MAX_VALUE)
   {
      //Is counter even?
      if(!(counter % 2))
      {
         //Assign storage_array at counter to temp mod 10000
         storage_array[counter] = temp % MAX_VALUE;
         //Set temp to temp/10000
         temp /= MAX_VALUE;
      }
      else
      {
         //First temporary storage value
         int temp1;
         //Second temporary storage value
         int temp2;

         //Assign storage_array at counter to temp mod 100
         storage_array[counter] = temp % MIN_VALUE;

         //Procede with the digit reversal by getting the lower of
         //the two digits and multiplying it by 10 and store
         temp1 = (storage_array[counter] % REV_VALUE) * REV_VALUE;
         //store the upper of the two digits
         temp2 = storage_array[counter] / REV_VALUE;
         //Reverse the digits and restore into the array
         storage_array[counter] =  temp1 + temp2;
         //Set temp to temp div 100
         temp /= MIN_VALUE;
      }
      ++counter;
   }
   //Assign storage at position counter to temp
   storage_array[counter] = temp;
   ++counter;
   //Sum up all the digits in the array
   for(int i = 0; i < counter; i++)
   {
      return_value += storage_array[i];
   }
   return return_value;
}

/********************************************************************
* The folding technique for determining the hash value into
* the BasicHashTable.  This is used for a key of type long, and when
* that key value is > 1000000000.
* NOTE:  This method is limited in size to ULONG_MAX (4294967295)
*        Anything larger than this will be modded with ULONG_MAX,
*        and the modded value will be used instead:  which is not a
*        "complete" representation of the input data!  Caution is
*        advised.
********************************************************************/
template <class Data>
long BasicHashTable<Data>::folding(unsigned long key)
{
   //The compare value
   const int COMP_VALUE         = 100;
   //The maximum number of numbers that can be stored in the array
   const int ARRAY_SIZE         = 175;
   //The first two values in the array are to be added together
   const int MULTIPLY_THRESHOLD = 2;

   //The first counter
   int counter1 = 0;
   //The second counter
   int counter2 = 0;

   //The stored off value
   unsigned long temp;
   //The first temp value stored off
   int temp1 = 0;
   //The second temp value stored off
   int temp2 = 0;
   //The last temp value stored off
   int temp3 = 1;
   //All three temp values will be used to compute the return value


   //The number storage array
   unsigned int storage_array[ARRAY_SIZE];
   int return_value;

   //Assign temp to key
   temp = key;

   //temp > 100?
   while(temp > COMP_VALUE)
   {
      //Assign storage to temp mod 100
      storage_array[counter1] = temp % COMP_VALUE;
      //Set temp to temp div 100
      temp /= COMP_VALUE;
      ++counter1;
   }
   //Assign storage to temp
   storage_array[counter1] = temp;
   ++counter1;

   //counter2 < counter1?
   while(counter2 < counter1)
   {
      if(counter2 < MULTIPLY_THRESHOLD)
      {
         //Add storage at counter2 to temp2
         temp2 += storage_array[counter2];
      }
      else
      {
         //Multiply storage at counter2 to temp3
         temp3 *= storage_array[counter2];
      }
      ++counter2;
   }
   if(counter2 > MULTIPLY_THRESHOLD)
   {
      //Assign temp1 to temp2 added to temp3
      temp1 = temp2 + temp3;
   }
   else
   {
      temp1 = temp2;
   }
   //Save off temp1 to return value
   return_value = temp1;

   return return_value;
}

/********************************************************************
* The folding technique for determining the hash value
* (the index into the BasicHashTable):  used for when the
* key has already been broken up into an array of integers,
* passing in the number of indices in the array to "fold" into
* a value
********************************************************************/
template <class Data>
long BasicHashTable<Data>::folding(int* numbers, int indices)
{
   //Define some constants (to avoid "Majic Number Syndrome")
   //The limit to the number of indices in the array that
   //will be added to the return result.  The rest of the values
   //will be multiplied together
   const int ADDITION_LIMIT = 2;

   //The return value
   long return_value;
   //The number that stores temp1 + temp2 together
   long temp;

   //Set counter to 0
   int counter = 0;
   //The number that stores the values added up (only the first two)
   long temp2 = 0;
   //The number that stores the values multiplied 
   //(past the first two)
   long temp3 = 1;
   
   //counter < indices?
   while(counter < indices)
   {
      if(counter < ADDITION_LIMIT)
      {
         //Add the first two numbers in the array together
         //and store in temp1
         temp2 += numbers[counter];
      }
      else
      {
         //Multiply the remainder of the numbers together and
         //store in temp2
         temp3 *= numbers[counter];
      }
      ++counter;
   }
   //Assign temp2 to temp (regardless of how many indices there were)
   temp = temp2;
   if(counter > ADDITION_LIMIT)
   {
      //Add temp3 to temp (since temp2 already been added in)
      temp += temp3;
   }
   return_value = temp;

   return return_value;
}

/********************************************************************
* If the number is so large that it can only be represented by
* a string, then this method will take that number and break
* it up into two digit numbers and place into an array
* i.e:  "4235" will parse into 35 42 into an array (35 at
* position 0, 42 at position 1 in the array.  This method
* returns the number of indices of valid numbers in the array.
* the array that is populated is placed as an input parameter,
* as well as the string to parse into two digit numbers in the
* array
********************************************************************/
template <class Data>
int BasicHashTable<Data>::parse(const char* key, int* result)
{
   //The temp value integer used to convert two characters from
   //the temp string to integers
   int temp_value;

   //The single character value
   const int SINGLE_CHAR   = 1;
   //The pointer subtraction value for current_string
   const int CONVERT_VALUE = 2;

   //Copy the key input into temp
   char* temp = new char[strlen(key) + 1];
   strcpy(temp, key);

   //The Boolean to determine IF temp has an odd number of characters
   bool is_odd_size = (bool)(strlen(temp) % CONVERT_VALUE);
   //Set current_string to the position of the next to last
   //character in temp
   char* current_string = temp + (strlen(key) - CONVERT_VALUE);
   //The looping counter to convert string into an array of
   //digits < 100
   int counter = 0;

   //current_string >= temp?
   while(current_string >= temp)
   {
      //Get two characters from current_string, place in temp_value
      //converted to an integer
      istrstream is(current_string, CONVERT_VALUE);
      is>>temp_value;
      //Copy temp_value to result[counter]
      result[counter] = temp_value;

      //Decrement current_string by 2, increment counter by 1
      current_string -= CONVERT_VALUE;
      ++counter;
   }
   //Are there an odd number of characters in temp?
   if(is_odd_size)
   {
      //Set current_string to temp
      current_string = temp;
      //Get one character for current_string,
      //place in temp_value converted to an integer
      istrstream is(current_string, SINGLE_CHAR);
      is>>temp_value;
      //Copy temp_value to result[counter]
      result[counter] = temp_value;
      ++counter;
   }
   delete [] temp;
   temp           = NULL;
   current_string = NULL;

   return counter;
}

/********************************************************************
* Insertion Operator                                                
********************************************************************/
template <class Data>
ostream& operator<<(ostream& os, BasicHashTable<Data>& bht)
{
   bht.print();
   return os;
}
#endif
