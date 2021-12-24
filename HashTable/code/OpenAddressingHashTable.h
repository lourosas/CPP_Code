/* 
 * This file is part of the CPP_Code Dsistribution
 * Copyright (c) 2021 Lou Rosas
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#ifndef OPEN_ADDRESSING_HASH_TABLE_H
#define OPEN_ADDRESSING_HASH_TABLE_H

#include <cmath>
#include "GenericHashTable.h"

template<typename Key, typename Value>
class OpenAddressingHashTable : public GenericHashTable<Key, Value>{
   public:
      OpenAddressingHashTable();
      virtual ~OpenAddressingHashTable();
      virtual int    contains(Value);
      virtual int    containsKey(Key);
      virtual int    insert(Key, Value);
      virtual Key*   keys(int&);
      virtual Value  remove(Key );
      virtual Value  retrieve(Key);
      virtual int    searchKeys(Key, int& );
      virtual int    searchValues(Value);
      virtual Value* values(int&);
      enum{SIZE_ERROR = -0xFF,
           INSERTION_ERROR,
           ALREADY_INSERTED,
           NO_ENTRY_EXCEPTION};
   protected:
      virtual void rehash();
   private:
      int checkIncreaseSize();
      int performHash(Key, int  = 0);
      int searchForEmpty(Key);
      //Value _value;
};

//Class Implemenation
//Pubic Method
/*********************************************************************
Constructor
Constructor of no arguments
*********************************************************************/
template<typename Key, typename Value>
OpenAddressingHashTable<Key,Value>::OpenAddressingHashTable(){}

/*********************************************************************
Destructor
*********************************************************************/
template<typename Key, typename Value>
OpenAddressingHashTable<Key, Value>::~OpenAddressingHashTable(){}


/////////////////Public Member Functions//////////////////////////////
/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::contains(Value value){
   int EMPTY = GenericHashElement<Key,Value>::EMPTY;
   return(this->searchValues(value) > EMPTY);
}

/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::containsKey(Key key){
   int SET   = GenericHashElement<Key,Value>::SET;
   int EMPTY = GenericHashElement<Key,Value>::EMPTY;

   int containsKey = 0;
   int storeValue   = EMPTY;
   try{
      int index   = this->searchKeys(key, storeValue);
      containsKey = ((index > EMPTY) && (storeValue == SET));
   }
   catch(int x){}

   return containsKey;
}

/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::insert(Key key, Value value){
   int SET    = GenericHashElement<Key,Value>::SET;
   int index  = GenericHashElement<Key,Value>::EMPTY;
   int storeValue = index;

   GenericHashElement<Key, Value> ghe(key, value);
   try{
      index = this->searchKeys(key, storeValue);
      if(index < 0 || storeValue != SET){
         if(index < 0){
            //If the Key is not there, find out where the Key belongs
            //in the Hash Table
            index = this->searchForEmpty(key);
         }
         this->array[index] = ghe;
         this->array[index].storeValue = SET;
         ++this->numberOfElements;
         this->rehash();
      }
      //The Key-Value pair is already in the Hash Table
      else{
         int x = ALREADY_INSERTED;
         throw x;
      }
   }
   catch(int x){
      if(x == SIZE_ERROR){
         std::cout<<"\nERROR:  "<<ghe<<" could NOT be inserted: "
           <<"Size too small\n";
         int x = INSERTION_ERROR;
         throw x;
      }
      else if(x == ALREADY_INSERTED){
         std::cout<<std::endl<<(ghe.value()).value()
           <<": PREVIOUSLY INSERTED\n\n";
         //throw ALREADY_INSERTED;
      }
   }
   //return the index of where it was stored...I think...leme think
   return index;
}

/*
Virtual
*/
template<typename Key, typename Value>
Key* OpenAddressingHashTable<Key,Value>::keys(int& size){
   int SET = GenericHashElement<Key,Value>::SET;
   if(this->keys_ != nullptr){
      delete [] this->keys_;
      this->keys_ = nullptr;
   }
   size = this->numberOfElements;
   if(size){
      int idx = 0;
      this->keys_ = new Key[this->numberOfElements];
      if(this->keys_ != nullptr){
         for(int i = 0; i < this->size(); ++i){
            if(this->array[i].storeValue == SET){
               this->keys_[idx] = this->array[i].key();
               ++idx;
            }
         }
         size = this->numberOfElements;
      }
   }
   return this->keys_;
}

/*
Virtual
*/
template<typename Key, typename Value>
Value OpenAddressingHashTable<Key, Value>::remove(Key key){
   int DELETED = GenericHashElement<Key, Value>::DELETED;
   Value value;

   if(this->containsKey(key)){
      int sv;
      int index = this->searchKeys(key,sv);
      value     = this->array[index].value();
      //Now, go ahead and delete it by setting Store Value to DELETED
      this->array[index].storeValue = DELETED;
      --this->numberOfElements;
   }
   else{
      int exception = NO_ENTRY_EXCEPTION;
      throw exception;
   }
   return value;
}

/*
Virtual
*/
template<typename Key, typename Value>
Value OpenAddressingHashTable<Key, Value>::retrieve(Key key){
   Value value;
   if(this->containsKey(key)){
      int sv;
      int index = this->searchKeys(key,sv);
      value     = this->array[index].value();
   }
   else{
      int exception = NO_ENTRY_EXCEPTION;
      throw exception;
   }
   return value;
}

/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::searchKeys(Key key, int& sv){
   int EMPTY   = GenericHashElement<Key,Value>::EMPTY;

   int index   = EMPTY;
   int i       = 0;

   sv          = index;
   //To allot for an index < 0 (which indicates nothing was found
   //or the storeValue in the array is NOT empty (which indicates
   //there may or may NOT have been any collisions), or every value in
   //the Hash table has been accounted for...continue until one of
   //these is false...
   do{
      int idx = this->performHash(key, i);
      if(idx > -1){
         sv = this->array[idx].storeValue;
         if(this->array[idx].key() == key){
            index = idx;
         }
      }
   }while(index < 0 && sv != EMPTY && ++i < this->size());
   if(i >= this->size()){
      int sizeError = SIZE_ERROR;
      throw sizeError;
   }
   return index;
}

/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::searchValues(Value object){
   int index = GenericHashElement<Key,Value>::EMPTY;
   int kys   = 0;
   int vals  = 0;
   this->keys(kys);
   this->values(vals);
   if(kys && vals &&
      (kys==this->numberOfElements && vals==this->numberOfElements)){
      int found = 0; int idx   = 0;
      for(int i = 0; i < vals && !found; ++i){
         if(this->values_[i] == object){
            found = 1;
            idx = i;
         }
      }
      int sv = GenericHashElement<Key,Value>::EMPTY;
      if(found){
         try{
            index = this->searchKeys(this->keys_[idx], sv);
            if(sv != GenericHashElement<Key,Value>::SET){
               //This should never happen!!
               throw int(-1);
            }
         }
         catch(int x){
            index = GenericHashElement<Key,Value>::EMPTY;
         }
      }
   }
   return index;
}

/*
Virtual
*/
template<typename Key, typename Value>
Value* OpenAddressingHashTable<Key,Value>::values(int& size){
   if(this->values_ != nullptr){
      delete [] this->values_;
      this->values_ = nullptr;
   }
   size = this->numberOfElements;
   if(size){
      int size_;
      this->keys(size_);
      if(size_ == this->numberOfElements){
         this->values_ = new Value[this->numberOfElements];
         for(int i = 0; i < size_; ++i){
            this->values_[i] = this->retrieve(this->keys_[i]);
         }
      }
   }
   return this->values_;
}

////////////////////////Protected Member Functions////////////////////
/*
Virtual
*/
template<typename Key, typename Value>
void OpenAddressingHashTable<Key, Value>::rehash(){
   int EMPTY = GenericHashElement<Key,Value>::EMPTY;
   int SET   = GenericHashElement<Key,Value>::SET;

   int newSize = this->checkIncreaseSize();
   if(newSize){
      int tempSize = this->size();
      this->size(newSize);
      //Reset the number of elements in the Hash Table
      this->numberOfElements = 0;

      GenericHashElement<Key,Value>* temp = this->array;

      this->array = new GenericHashElement<Key, Value>[this->size()];
      for(int i = 0; i < this->size(); ++i){
         this->array[i].storeValue = EMPTY;
      }
      //Now, replace...
      for(int i = 0; i < tempSize; ++i){
         if(temp[i].storeValue == SET){
            this->insert(temp[i].key(), temp[i].value());
         }
      }
      delete [] temp;
   }
}

/////////////////////////Private Member Functions/////////////////////
/*
Rehashing a Hash Table is very expensive time wise...
It is best not to have to continue to rehash...
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::checkIncreaseSize(){
   double currentPercentage =
                          (double)this->numberOfElements/this->size();
   int newSize = 0;
   if(currentPercentage > GenericHashTable<Key,Value>::loadFactor){
      int e = 1;
      double m = pow(10,e);
      int compareValue = 10*this->size();
      while(this->pnf->lastPrime() < compareValue){
         delete this->pnf;
         this->pnf = new PrimeNumberFinder(m*this->pnf->size());
         this->pnf->findPrimes();
         ++e;
         m = pow(10,e);
      }
      //resize as needed
      int count     = (this->pnf->numberOfPrimes())/2 - 1;
      int testPrime = -1;
      do{
         testPrime = this->pnf->primeAt(count);
         ++count;
      }while(testPrime < compareValue);
      //this->size(testPrime);
      //set the next size to the most appropriate prime...
      newSize = testPrime;
   }
   return newSize;
}

/**/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::performHash(Key key, int i){
   int hashPrime = key.key()%this->size();
   int index     = (hashPrime + i + i*i)%this->size();

   return index;
}

/**/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key,Value>::searchForEmpty(Key key){
   int SET   = GenericHashElement<Key,Value>::SET;
   int index = -1;
   int i     = 0;
   do{
      index = this->performHash(key,i);
      ++i;
   }while(this->array[index].storeValue == SET);
   return index;
}
#endif
//////////////////////////////////////////////////////////////////////
