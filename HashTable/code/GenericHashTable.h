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
      virtual Value& remove(Key )    = 0;
      virtual Value& retrieve(Key )  = 0;
      virtual int insert(Key, Value) = 0;

      virtual std::ostream& print(std::ostream& );
      int size() const;
   protected:
      virtual void rehash() = 0;
      static int initialCapacity;
      static double loadFactor;
      PrimeNumberFinder* pnf;
   private:
      int a_Hash_Value;
      int b_Hash_Value;
      int m_Hash_Value;
      int p_Hash_Value;
      int _size;
      GenericHashElement<Value>* _array;
};
//Overload the insertion operator
template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                                    GenericHashTable<Key,Value>& ght);

//Class Implementation
//Public Methods
/*********************************************************************
 * Constructor
 * Constructor of no arguments
*********************************************************************/
template<typename Key, typename Value>
GenericHashTable<Key,Value>::GenericHashTable()
: initialCapacity(101),
  a_Hash_Value(1),
  b_Hash_Value(0),
  m_Hash_Value(0),
  p_Hash_Value(103),
  _size(initialCapacity),
  _array(nullptr)
  pnf(nullptr)
{
   this->_array = new GenericHashElement<Value>[initialCapacity];
   if(!this->_array){
      std::cout<<"\n\nCould not allocate memory for the Hash Table!"
        <<"\nExiting...";
      exit(0);
   }
   this->pnf = new PrimeNumberFinder(1000);
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
   if(this->_array){
      delete [] this->_array;
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
std::ostream& GenericHashTable<Key, Value>::print(std::ostream& os)}{
   return os;
}

/*
*/
template<typename Key, typename Value>
int GenericHashTable<Key, Value>::size() const{
   return this->_size;
}

//////////////////////Function Declarations///////////////////////////
template<typename Key, typename Value>
std::ostream& operator<<(std::ostream& os,
                                     GenericHashTable<Key, Value>& ht)
{
   return (ht.print(os));
}
#endif
