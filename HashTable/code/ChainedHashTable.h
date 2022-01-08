/*
 * This file is part of the CPP_Code Dsistribution
 * Copyright (c) 2022 Lou Rosas
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
 */
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#ifndef CHAINED_HASH_TABLE_H
#define CHAINED_HASH_TABLE_H

#include <cmath>
#include "GenericHashTable"
#include "LinkedList.h"

template<class Key, class LinkedList<Value>>
class ChainedHashTable :
public GenericHashTable<Key,LinkedList<Value>>{
   public:
      ChainedHashTable();
      virtual ~ChainedHashTable();

      virtual int    contains(Value);
      virtual int    containsKey(Key);
      virtual int    insert(Key, Value);
      virtual Key*   keys(int&);
      virtual Value  remove(Key);
      virtual Value  retrieve(Key);
      virtual int    searchKeys(Key, int&);
      virtual int    searchValues(Value);
      virtual Value* values(int&);

      virtual std::ostream& print(std::ostream&);
      enum{INSERTION_ERROR = -0xF,
           ALREADY_INSERTED,
           NO_ENTRY_EXCEPTION};
   protected:
      virtual void rehash();
   private:
      int performHash(Key);
};
//Overload the insertion operator
template<class Key, class LinkedList<Value>>
std::ostream& operator<<(std::ostream& os,
                         ChainedHashTable<Key,LinkedList<Value>> cht);

//Class Implemenation
//*********************Constructor/Destructor*************************
/*
Constructor
Constructor of no arguments
*/
template<class Key, class LinkedList<Value>>
ChainedHashTable<Key,LinkedList<Value>>::ChainedHashTable(){}

/*
Destructor
*/
template<class Key,class LinkedList<Value>>
ChainedHashTable<Key,LinkedList<Value>>::~ChainedHashTable(){}

//*********************Public Member Functions************************
/*
Virtual
*/
template<class Key, class LinkedList<Value>>
int ChainedHashTable<Key,LinkedList<Value>>::contains(Value value){
   int EMPTY = GenericHashElement<Key,LinkedList<Value>>::EMPTY;

   return 0;
}

/*
Virtual
*/
template<class Key, class LinkedList<Value>>
int ChainedHashTable<Key,LinkedList<Value>>::containsKey(Key key){
   int SET   = GenericHashElement<Key,Value>::SET;
   int EMPTY = GenericHashElement<Key,Value>::EMPTY;

   return 0;
}

/*
Virtual
*/
template<class Key, class LinkedList<Value>>
int ChainedHashTable<Key,LinkedList<Value>>::insert
(
   Key key,
   Value value
){
   return 0;
}

/*
Virtual
*/
template<class Key, class LinkedList<Value>>
Key* ChainedHashTable<Key,LinkedList<Value>>::keys(int& size){
   return nullptr;
}

/*
Virtual
*/
template<class Key, class LinkedList<Value>>
Value ChainedHashTable<Key,LinkedList<Value>>::remove(Key key){
   Value v;
   return v;
}

/*
Virtual
*/
template<class Key, class LinkedList<Value>>
Value ChainedHashTable<Key,LinkedList<Value>>::retrieve(Key key){
   Value v;
   return v;
}

/*
Virtual
*/
template<class Key, class LinkedList<Value>>
int ChainedHashTable<Key,LinkedList<Value>>::searchKeys
(
   Key  key,
   int& index
){
   return 0;
}

/*
Virtual
*/
template<class Key,class LinkedList<Value>>
int ChainedHashTable<Key,LinkedList<Value>>::searchValues(Value val){
   return 0;
}

/*
Virtual
*/
template<class Key,class LinkedList<Value>>
Value* ChainedHashTable<Key,LinkedList<Value>>::values(int& size){
   return nullptr;
}

/*
Virtual
*/
template<class Key,class LinkedList<Value>>
std::ostream& ChainedHashTable<Key,LinkedList<Value>>::print
(
   std::ostream& os
){
   return os;
}

//*******************Protected Member Functions***********************
/*
*/
template<class Key,class LinkedList<Value>>
void ChainedHashTable<Key,LinkedList<Value>>::rehash(){}

//********************Private Member Functions************************
/*
*/
template<class Key, class LinkedList<Value>>
int ChainedHashTable<Key,LinkedList<Value>>::performHash(Key key){
   return 0;
}

//**********************Function Definition***************************
/*
Insertion Operator
*/
template<class Key,class LinkedList<Value>>
std::ostream& operator<<(std::ostream& os,
                          ChainedHashTable<Key,LinkedList<Value>> cht)
{
   return cht.print(os);
}

#endif
