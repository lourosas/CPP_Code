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

template <typename Key, typename Value>
class GenericHashTable{
   public:
      GenericHashElement();
      virtual ~GenericHashElement();
      //Pure Virtual Member Functions
      Value& remove(Key )    = 0;
      Value& retrieve(Key )  = 0;
      int insert(Key, Value) = 0;

      virtual std::ostream& print(std::ostream& );
      int size();
   protected:
      void rehash();
      static int initialCapacity;
      static double loadFactor;
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
{
   this->_array = new GenericHashElement<Value>[initialCapacity];
   if(!this->_array){
      std::cout<<"\n\nCould not allocate memory for the Hash Table!"
        <<"\nExiting...";
      exit(0);
   }
}
#endif
