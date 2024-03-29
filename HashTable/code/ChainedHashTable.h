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
#include "GenericHashTable.h"
#include "Integer.h"
#include "List.h"
#include "LinkedList.h"

template<class Key, class Value>
class ChainedHashTable : public GenericHashTable<Key,Value>{
   public:
      ChainedHashTable();
      virtual ~ChainedHashTable();

      virtual int    contains(Value);
      virtual int    containsKey(Key);
      virtual int    insert(Key, Value);
      virtual Key*   keys(int&);
      virtual int    keySize();
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
      int checkIncreaseSize();
      int insertNoCheck(Key,Value);
      int performHash(Key);
      LinkedList<Value>* _linkedlist;
      LinkedList<GenericHashElement<Key,Value>>* _list;
      LinkedList<Key>    _keys;
      int _insertionCount;
};
//Overload the insertion operator
template<class Key,class Value>
std::ostream& operator<<(std::ostream& os,
                                    ChainedHashTable<Key,Value>& cht);

//Class Implemenation
//*********************Constructor/Destructor*************************
/*
Constructor
Constructor of no arguments
*/
template<class Key, class Value>
ChainedHashTable<Key,Value>::ChainedHashTable()
: _linkedlist(nullptr), _list(nullptr), _insertionCount(0)
{
   int capacity = GenericHashTable<Key,Value>::initialCapacity;
   this->_linkedlist = new LinkedList<Value>[capacity];
   int c = capacity;
   this->_list = new LinkedList<GenericHashElement<Key,Value>>[c];

   if(!(this->_linkedlist)){
      std::cout<<"\n\nCould not allocate memory for the Hash Table!"
        <<"\nExiting...";
      exit(0);
   }
   if(!(this->_list)){
      std::cout<<"\n\nCould not allocate memory for the Hash Table!"
        <<"\nExiting...";
      exit(0);
   }
}


/*
Destructor
*/
template<class Key, class Value>
ChainedHashTable<Key,Value>::~ChainedHashTable(){
   if(this->_linkedlist){
      delete[] this->_linkedlist;
   }
   if(this->_list){
      delete[] this->_list;
   }
}

//*********************Public Member Functions************************
/*
Virtual
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::contains(Value value){
   int EMPTY    = 0;
   int contains = EMPTY;
   if(this->_linkedlist != nullptr){
      int i = 0;
      while(i < this->size() && !contains){
         if(!(this->_linkedlist[i].isEmpty())){
            contains = this->_linkedlist[i].contains(value);
         }
         ++i;
      }
   }
   return contains;
}

/*
Virtual
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::containsKey(Key key){
   return(this->_keys.contains(key));
}

/*
Virtual
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::insert(Key key,Value value){
   Value value_ = value.value();
   int index    = INSERTION_ERROR;
   int insertionLimit = 5000;
   if(this->_linkedlist != nullptr){
      int idx = this->performHash(key);
      if(!(this->contains(value))){
         index = this->_linkedlist[idx].add(value);
         GenericHashElement<Key,Value> ghe(key,value);
         ghe.storeValue = GenericHashElement<Key,Value>::SET;
         index = this->_list[idx].add(ghe);
         this->_keys.add(key);
         if(++(this->_insertionCount) >= insertionLimit){
            //Check to see if a rehash is need ever 5000 insertions
            this->rehash();
            this->_insertionCount = 0;
         }
      }
      else{
         index = ALREADY_INSERTED;
      }
   }
   return index;
}

/*
Virtual
*/
template<class Key, class Value>
Key* ChainedHashTable<Key,Value>::keys(int& keys){
   keys = this->keySize();
   if(keys && this->keys_){
      delete[] this->keys_;
   }
   this->keys_ = new Key[keys];
   if(this->keys_){
      for(int i = 0; i < keys; ++i){
         this->keys_[i] = this->_keys.get(i);
      }
   }
   return this->keys_;
}

/*
Virtual
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::keySize(){
   int keySize = 0;
   if(this->_linkedlist){
      keySize = this->_keys.size();
   }
   return keySize;
}

/*
Virtual
*/
template<class Key, class Value>
Value ChainedHashTable<Key,Value>::remove(Key key){
   int index;
   Value v;
   if(!(this->searchKeys(key,index))){
      int error = NO_ENTRY_EXCEPTION;
      throw error;
   }
   if(!(this->_list[index].isEmpty())){
      for(int i = 0; i < this->_list[index].size(); ++i){
         if(key == this->_list[index].get(i).key()){
            v = this->_list[index].remove(i).value();
         }
      }
   }
   return v;
}

/*
Virtual
*/
template<class Key, class Value>
Value ChainedHashTable<Key,Value>::retrieve(Key key){
   int index;
   Value v;
   if(!(this->searchKeys(key,index))){
      int error = NO_ENTRY_EXCEPTION;
      throw error;
   }
   if(!(this->_list[index].isEmpty())){
      for(int i = 0; i < this->_list[index].size(); ++i){
         if(key == this->_list[index].get(i).key()){
            v = this->_list[index].peek(i).value();
         }
      }
   }
   return v;
}

/*
Virtual
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::searchKeys(Key key,int& index){
   int containsKey = this->containsKey(key);
   if(containsKey){
      index = this->performHash(key);
   }
   else{
      index = -1;
   }
   return containsKey;
}

/*
Virtual
*/
template<class Key,class Value>
int ChainedHashTable<Key,Value>::searchValues(Value value){
   return this->contains(value);
}

/*
Virtual
*/
template<class Key,class Value>
Value* ChainedHashTable<Key,Value>::values(int& size){
   int temp = 0;
   if(this->_linkedlist != nullptr){
      for(int i = 0; i < this->size(); ++i){
         temp += this->_linkedlist[i].size();
      }
      size = temp;
      if(temp && this->values_){
         delete[] this->values_;
      }
      this->values_ = new Value[size];
      if(this->values_ != nullptr){
         int index = 0;
         for(int i = 0; i < this->size(); ++i){
            if(!(this->_linkedlist[i].isEmpty())){
               for(int j = 0; j < this->_linkedlist[i].size(); ++j){
                  this->values_[index]=this->_linkedlist[i].get(j);
                  ++index;
               }
            }
         }
      }
   }
   return this->values_;
}

/*
Virtual
*/
template<class Key, class Value>
std::ostream& ChainedHashTable<Key,Value>::print
(
   std::ostream& os
){
   /*
   int size = 0;
   this->values_ = this->values(size);
   for(int i = 0; i < size; ++i){
      os<<this->values_[i].value();
      if(i < size - 1){
         os<<", ";
      }
   }
   */
   for(int i = 0; i < this->size(); ++i){
      if(!(this->_list[i].isEmpty())){
         os<<this->_list[i];
      }
      /*if(i < this->size()){
         os<<", ";
      }*/
   }
   return os;
}

//*******************Protected Member Functions***********************
/*
*/
template<class Key, class Value>
void ChainedHashTable<Key,Value>::rehash(){
   int newSize = this->checkIncreaseSize();
   if(newSize){
      int tempSize = this->size();
      this->size(newSize);
      LinkedList<Value>* tempLL = this->_linkedlist;
      LinkedList<GenericHashElement<Key,Value>>* tempL = this->_list;
      int c = newSize;
      this->_linkedlist = new LinkedList<Value>[c];
      this->_list = new LinkedList<GenericHashElement<Key,Value>>[c];
      this->_keys.clear();
      for(int i = 0; i < tempSize; ++i){
         for(int j = 0; j < tempL[i].size(); ++j){
            Key key     = tempL[i].peek(j).key();
            Value value = tempL[i].peek(j).value();
         }
      }
      delete[] tempLL;
      delete[] tempL;
   }
}

//********************Private Member Functions************************
/*
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::checkIncreaseSize(){
   int increaseSize = 0;
   //Rehash when any in the LinkedList get to this size
   int limit        = 5000;
   int i            = 0;
   int found        = 0;
   while(i < this->size() && !increaseSize){
      increaseSize = (this->_linkedlist[i].size() >= limit);
      ++i;
   }
   if(increaseSize){
      if(this->size() > this->pnf->lastPrime()){
         //Time to resize
         int pnfsize = this->pnf->size();
         delete this->pnf;
         this->pnf = new PrimeNumberFinder(10*pnfsize);
         this->pnf->findPrimes();
      }
      i = 0;
      while(i < this->pnf->numberOfPrimes() && !found){
         if(this->pnf->primeAt(i) < this->size()){
            ++i;
         }
         else{
            found = 1;
         }
      }
      int currentPrime = this->pnf->primeAt(i);
      while(this->pnf->primeAt(i) < 5*currentPrime){ ++i; }
      increaseSize = this->pnf->primeAt(i);
   }
   return increaseSize;
}

/*
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::insertNoCheck(Key key, Value value){
   Value value_ = value.value();
   int   index = INSERTION_ERROR;
   if(this->_linkedlist != nullptr){
      int idx = this->performHash(key);
      this->_linkedlist[idx].add(value);
      GenericHashElement<Key,Value> ghe(key,value);
      ghe.storeValue = GenericHashElement<Key,Value>::SET;
      index = this->_list[idx].add(ghe);
      this->_keys.add(key);
   }
   else{
      index = ALREADY_INSERTED;
   }
   return index;
}

/*
*/
template<class Key, class Value>
int ChainedHashTable<Key,Value>::performHash(Key key){
   int key_ = key.key();
   return (key_ % this->size());
}

//**********************Function Definition***************************
/*
Insertion Operator
*/
template<class Key, class Value>
std::ostream& operator<<(std::ostream& os,
                                   ChainedHashTable<Key,Value>& cht)
{
   return cht.print(os);
}

#endif
