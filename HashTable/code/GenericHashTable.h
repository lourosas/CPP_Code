/*
 */
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#ifndef GENERIC_HASH_TABLE_H
#define GENERIC_HASH_TABLE_H

#include <iostream>
#include <iomanip>
#include "Object.h"
#include "GenericHashElement.h"
#include "PrimeNumberFinder.h"

template <typename Key, typename Value>
class GenericHashTable{
   public:
      GenericHashTable();
      virtual ~GenericHashTable();

      //Pure Virtual Member Functions
      virtual int    contains(Value)     = 0;
      virtual int    containsKey(Key)    = 0;
      virtual int    insert(Key, Value)  = 0;
      virtual Key*   keys(int&)          = 0;
      virtual Value  remove(Key )        = 0;
      virtual Value  retrieve(Key )      = 0;
      virtual int    searchKeys(Key,int&)= 0;
      virtual int    searchValues(Value) = 0;
      virtual Value* values(int&)        = 0;

      virtual void clear();
      int isEmpty();
      virtual std::ostream& print(std::ostream& );
      int size() const;
   protected:
      virtual void rehash() = 0;
      void size(int);
      static int                      initialCapacity;
      static double                   loadFactor;
      PrimeNumberFinder*              pnf;
      GenericHashElement<Key, Value>* array;
      Value*                          values_;
      Key*                            keys_;
      int                             numberOfElements;
   private:
      int    a_Hash_Value;
      int    b_Hash_Value;
      int    m_Hash_Value;
      int    p_Hash_Value;
      int    _size;
};
//Overload the insertion operator
template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                                    GenericHashTable<Key,Value>& ght);

template<typename Key, typename Value>
int GenericHashTable<Key,Value>::initialCapacity = 101;

template<typename Key, typename Value>
double GenericHashTable<Key, Value>::loadFactor = 0.5;

//Class Implementation
//Public Methods
/*********************************************************************
 * Constructor
 * Constructor of no arguments
*********************************************************************/
template<typename Key, typename Value>
GenericHashTable<Key,Value>::GenericHashTable()
: pnf(nullptr),
  array(nullptr),
  values_(nullptr),
  keys_(nullptr),
  numberOfElements(0),
  a_Hash_Value(1),
  b_Hash_Value(0),
  m_Hash_Value(0),
  p_Hash_Value(103),
  _size(initialCapacity)
{
   this->array = new GenericHashElement<Key,Value>[this->_size];
   if(!this->array){
      std::cout<<"\n\nCould not allocate memory for the Hash Table!"
        <<"\nExiting...";
      exit(0);
   }
   for(int i = 0; i < this->initialCapacity; ++i){
      this->array[i].storeValue=GenericHashElement<Key,Value>::EMPTY;
   }
   this->pnf = new PrimeNumberFinder(10000);
   if(!this->pnf){
      std::cout<<"\n\nCould not allocate memory for the Prime Number "
        <<"Finder!\nExiting...";
      exit(0);
   }
   this->pnf->findPrimes();//Make a 1000 primes
}

/*********************************************************************
Destructor
*********************************************************************/
template<typename Key, typename Value>
GenericHashTable<Key,Value>::~GenericHashTable(){
   if(this->array){
      delete [] this->array;
   }
   if(this->pnf){
      delete this->pnf;
   }
}

///////////////////////Public Member Functions////////////////////////
/*
Virtual
*/
template<typename Key, typename Value>
void GenericHashTable<Key, Value>::clear(){
   if(this->array != nullptr){
      delete [] this->array;
      this->array = nullptr;
      //clear out the number of elements...
      this->numberOfElements = 0;
      //Reset the Size to the Initial Capacity (not that it should
      //matter)
      this->_size = initialCapacity;
      this->array = new GenericHashElement<Key,Value>[this->_size];
   }
}

/*
*/
template<typename Key, typename Value>
int GenericHashTable<Key, Value>::isEmpty(){
   return (this->numberOfElements == 0);
}

/*
Virtual
*/
template<typename Key, typename Value>
std::ostream& GenericHashTable<Key, Value>::print(std::ostream& os){
   os<<std::endl;
   for(int i = 0; i < this->_size; ++i){
      os<<this->array[i]<<", ";
   }
   os<<std::endl;
   return os;
}

/*
*/
template<typename Key, typename Value>
int GenericHashTable<Key, Value>::size() const{
   return this->_size;
}

///////////////////////Protected Member Functions/////////////////////
/*
*/
template<typename Key, typename Value>
void GenericHashTable<Key, Value>::size(int size){
   this->_size = size;
}

//////////////////////Function Declarations///////////////////////////
template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                                     GenericHashTable<Key, Value>& ht)
{
   return (ht.print(os));
}
#endif
