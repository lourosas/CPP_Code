//HashTable Class
//A basic data structure class
//Posrt of the ongoing work to fulfill my desire
//to create a generic data structure tool set for
//everyday application development.
//A class by Lou Rosas

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "BasicHashTable.h"
#include "BasicHashElement.h"
#include "MathTools.h"
#include "HashElement.h"
#include <iostream.h>
#include <typeinfo>

template <class Key, class Data>
class HashTable : public BasicHashTable<Data>
{
   public:
      //Public Methods
      //Constructor of no arguments
      HashTable();
      
      //Constructor setting the initial re-hash capacity
      HashTable(const float );
      
      //Copy constructor
      HashTable(HashTable<Key, Data>& );
      
      //Destructor
      ~HashTable();
      
      //Assignment Operator
      HashTable<Key, Data>& operator=(HashTable<Key, Data>& );
      
      //Check to see if the given HashTable contains the given
      //Key& format
      bool containsKey(const Key& );
      
      //public method to destroy the HashTable
      void destroyHashTable();
      
      //Insert method
      bool insert(const Key& , const Data& );
      
      //Insert an entire HashElement object
      bool insert(HashElement<Key, Data>& );
      
      //Given the Key, find the data related to that Key, but don't
      //remove it
      bool find(const Key& , Data& );
      
      //Get the entire group of HashTable Elements
      //(all the elements in the array)
      void getElements(HashElement<Key, Data>* );
      
      //Given the Data, get the Key (if it exists)
      bool getKey(const Data&, Key& );
      
      //Get the current size (the total number of elements in the
      //HashTable that have the flag field to SET (2))
      int getCurrentSize();
      
      //Get the max number of slots in the HashTable
      int getMaxSize();
      
      //Given the Key, remove the data and return the data return true
      //if the data was removed, false if the data was not removed
      bool remove(const Key&, Data& );
      
      //Check to see if the HashTable is empty
      bool isEmpty();
      
      //Print out the HashTable
      void print();
      
   protected:
      //Get the number of elements in the HashTable
      //(with the flag field of BOTH DELETED (1) and SET (2)
      int getSize();
      
   private:
      //Private Methods
      //Private Method to call the desturctor of the attributes 
      //in the HashTable in need of proper destruction
      void destroyHT();
      
      //The actuall hashing method: used to get the appropriate index
      //into the hash table
      int hash(Key& );
      
      //If there is a collision upon insert (meaning data is already in
      //spot that is desired), call this method to find the next index
      //to try into the HashTable
      int nextHash(const unsigned int, const unsigned int);
      
      //Given a Key, retrieve the position in the HashTable where the
      //Key is stored (provided the key is in the HashTable)
      int getPosition(const Key& );
      
      //ReHash the HashTable, remove all the deleted data and resize the
      //array
      bool reHash();
      
      //Set the number of HashElements with "valid" data
      void setCurrentSize(const int );
      
      //Set the number of elements currently saved in the
      //HashTable
      void setSize(const int );
      
      //Set the max number of slots in the HashTable
      void setMaxSize(const int );
      
      //Indicate if the Key is of type long:  if it is, call the
      //Appropriate methods in the super class (BasicHashTable<Data>)
      void setKeyLong(bool );
      
      //Indicate if the Key is of type char*, if it is, call the
      //appropriate methodes in the super class (BasicHashTable<Data>)
      void setKeyChar(bool );
      
      //Return true if the Key is of type long
      bool isKeyLong();
      
      //Return true if the Key is of type char*
      bool isKeyChar();
      
      //Private Attributes
      //The number of entries in the HashTable with valid data (flag = SET)
      int current_size;
      
      //The array of HashElement Objects
      HashElement<Key, Data>* hashElements;
      
      //The Boolean indicator for Key of type char*
      bool is_key_char;
      
      //The Boolean indicator for Key of type long
      bool is_key_long;
      
      //Default Rehash Capacity
      static const float DEFAULT_REHASH_CAPACITY = 0.6;
      
      //The initial max size of the HashTable:  must be prime, as
      //well as ALL other resizes (to prevent a possible infinite loop)
      static const int INITIAL_MAX_SIZE = 17; //Start with a prime
};
//Overload the insertion operator
template <class Key, class Data>
ostream& operator<<(ostream&, HashTable<Key, Data>& );

//For some reason, for a float, the staic variable cannot be initialized
//upon declaration
/*template <class Key, class Data>
static const float HashTable<Key, Data>::DEFAULT_REHASH_CAPACITY = 0.6;
*/
//Class Implementations
//*************************PUBLIC METHODS****************************
/********************************************************************
* Constructor
* Constructor of no attributes
********************************************************************/
template<class Key, class Data>
HashTable<Key, Data>::HashTable()
 : current_size(0),
   hashElements(NULL),
   is_key_char(false),
   is_key_long(false)
{
   //Initialize the Attributes
   //Set Max Size
   this->setMaxSize(INITIAL_MAX_SIZE);
   
   //Set Rehash Capacity
   this->setRehashCapacity(DEFAULT_REHASH_CAPACITY);

   //Create the hashElement objects array
   this->hashElements = new HashElement<Key,Data>(this->getMaxSize());
   
   //Set up to determine if the Key is of the main primative types
   //As defined in the super class BasicHashTable
   if(typeid(Key) == typeid(char*))
      this->setKeyChar(true);
   if(typeid(Key) == typeid(long))
      this->setKeyLong(true);
}

/********************************************************************
* The constructor that explicitly sets the hash capacity (the
* capacity of the HashTable requuired for the table to be rehashed)
********************************************************************/
template <class Key, class Data>
HashTable<Key, Data>::HashTable(const float rehash_capacity)
 : current_size(0),
   hashElements(NULL),
   is_key_char(false),
   is_key_long(false)
{
   //Initialize the Attributes
   //Set Max Size
   this->setMaxSize(INITIAL_MAX_SIZE);
   
   //Set the Rehash Capacity
   this->setRehashCapacity(DEFAULT_REHASH_CAPACITY);
   
   //Create the hashElement objects array
   this->hashElements = new HashElement<Key,Data>(this->getMaxSize());
   
   //Set up to determine if the Key is of type of the two main
   //primative types as defined by the super class:  BasicHashTable
   if(typeid(Key) == typeid(char*))
      this->setKeyChar(true);
   if(typeid(Key) == typeid(long))
      this->setKeyLong(true);
}

/********************************************************************
* Copy Constructor
* Creates and copies the data of one HashTable object to this newly
* created HashTable object
********************************************************************/
template <class Key, class Data>
HashTable<Key, Data>::HashTable(HashTable<Key, Data>& copy_hash)
 : current_size(0),
   hashElements(NULL),
   is_key_char(false),
   is_key_long(false)
{
}

/********************************************************************
* Destructor
********************************************************************/
template <class Key, class Data>
HashTable<Key, Data>::~HashTable()
{
   //Call the appropriate method to message the destructors of the
   //class attributes that need to be destroyed properly, so as to
   //prevent a memory leak (such as for pointers). In other words,
   //handle the cleanup of any memory that was allocated.
   this->destroyHT();
}

/********************************************************************
* The Assignment operator
********************************************************************/
template <class Key, class Data>
HashTable<Key, Data>& HashTable<Key, Data>::operator=
(
   HashTable<Key, Data>& copy_hash
)
{
   return *this;
}

/********************************************************************
* Check to see if the HashTable contains the given key.
* Returns: true if the key is in the HashTable, flase if the key
* is not in the HashTable.  If the is_key_char or is_key_long is set,
* The appropriate containsKey() method from the supper class is
* messaged.
********************************************************************/
template <class Key, class Data>
bool HashTable<Key,Data>::containsKey(const Key& the_key)
{
   return false;
}

/********************************************************************
* The public method call to destroy the appropriate data in the
* HashTable
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::destroyHashTable()
{
   this->destroyHT();
}


/********************************************************************
* The insert method used for inserting data with a set Key and Data
* combination.  If the Key is of type char* or of type long, call
* the appropriate method in the super class.
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::insert
(
   const Key&  the_key, 
   const Data& the_data
)
{
   return false;
}

/********************************************************************
* The insert method used for inserting an entire HashElement object
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::insert
(
   HashElement<Key,Data>& copy_element
)
{
   return false;
}

/********************************************************************
* Given the key, retrieve the data, but don't remove it.
* If the key is not in the HashTable, this method will return false,
* true otherwise. If the Key is of type char* or of type long, call
* the appropriate method in the super class
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::find(const Key& key, Data& data)
{
   return false;
}

/********************************************************************
* Get all the HashElement(s) in the HashTable
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::getElements
(
   HashElement<Key, Data>* currentHashElements
)
{
}

/********************************************************************
* Given the data, retrieve the key
* Returns: true if the key was retrieved, false otherwise.  If the
* Key is of type char* or of type long, call the appropriate method
* in the super class.
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::getKey(const Data& data, Key& key)
{
   return false;
}

/********************************************************************
* Return the current size (the total number of elements in the
* HashTable that have the flag field SET (2))
********************************************************************/
template <class Key, class Data>
int HashTable<Key, Data>::getCurrentSize()
{
   return this->current_size;
}

/********************************************************************
* Remove the requested data from the HashTable
* Returns: true if the data was removed, false otherwise.  If the
* Key is of type char* or of type long, call the appropriate method
* in the super class
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::remove(const Key& key, Data& data)
{
   return false;
}

/********************************************************************
* Check to see if the BasicHashTable is empty
* Returns: true if empty, false if not
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::isEmpty()
{
   bool return_value = false;
   if(!(this->getCurrentSize()))
   {
      //The HashTable is truly empty
      return_value = true;
   }
   return return_value;
}

/********************************************************************
* Print the HashTable
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::print()
{
}


//************************PRIVATE METHODS****************************
/********************************************************************
* The private method used to call the destructors for the class
* attributes needing to be destroyed properly.  (Garbage collection)
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::destroyHT()
{
}

/********************************************************************
* Given the key, determine the hash index into the HashTable.  This
* serves as an index into the array that comprises the HashTable.
* Since the Key can be of ANY object, it is the objects
* responsibility to provide the hash value (via the
* generateHashCode() method).  This will get the appropriate
* hash value from which to start.  If the Key value is of type
* char* or of type long, the appropriate method in the super class
* will be called. Returns -1 if no hash value was obtained
* (an error indication)
********************************************************************/
template <class Key, class Data>
int HashTable<Key, Data>::hash(Key& key_input)
{
   return -1;
}

/********************************************************************
* Upon the event of a collision in the HashTable, the reHash()
* method is invoked.  This method calculates the next possible index
* into the HashTable given the previous index and the correct
* Fibinacci series index.
* Returns -1 if no next hash value was obtained (an error indication)
********************************************************************/
template <class Key, class Data>
int HashTable<Key, Data>::nextHash
(
   const unsigned int previous_index,
   const unsigned int fibonacci_index
)
{
   return -1;
}

/********************************************************************
* This method performs multiple tasks direclty related to one 
* another:  Given a key value, this method will retrieve the
* position in the HashTable where the data is located if the
* data is in the HashTable, OR the next position AVAILABLE WHERE
* the data could be stored if not in the HashTable already.
* If the Key value is of type char* or long, the appropriate method
* in the super class is called.
********************************************************************/
template <class Key, class Data>
int HashTable<Key, Data>::getPosition(const Key& the_key)
{
   return 0;
}

/********************************************************************
* When the HashTable gets too large:  either with current
* or deleted data, it needs to be rehashed.  Rehashing removes
* all deleted data, resizes the HashTable to the next
* available prime number, stores the valid data back into the newly
* sized HashTable.  If the Key value is of type char* or long, the
* appropriate method in the super class is called.
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::reHash()
{
   return false;
}

/********************************************************************
* Set the number of HashElements with "valid" data (HashElements
* with the flag field set to SET (2))
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::setCurrentSize(const int currentSize)
{
   this->current_size = currentSize;
}

/********************************************************************
* Indicate if the Key is of type long.  This allows the class
* to message the appropriate super class methods for selected
* functionality as defined by the class.
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::setKeyLong(bool key_long)
{
   this->is_key_long = key_long;
}

/********************************************************************
* Indicate if the Key is of type char*.  This allows the class
* to message the appropriate super class methods for selected
* functionality as defined by the class.
********************************************************************/
template <class Key, class Data>
void HashTable<Key, Data>::setKeyChar(bool key_char)
{
   this->is_key_char = key_char;
}

/********************************************************************
* Return true if the Key is of type long
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::isKeyLong()
{
   return is_key_long;
}

/********************************************************************
* Return true if the Key is of type char*
********************************************************************/
template <class Key, class Data>
bool HashTable<Key, Data>::isKeyChar()
{
   return is_key_char;
}

/********************************************************************
* Insertion Operator                                                
********************************************************************/
template <class Key, class Data>
ostream& operator<<(ostream& os, HashTable<Key, Data>& ht)
{
   ht.print();
   return os;
}
#endif
