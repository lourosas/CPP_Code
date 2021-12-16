/**/
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#ifndef OPEN_ADDRESSING_HASH_TABLE_H
#define OPEN_ADDRESSING_HASH_TABLE_H

#include "GenericHashTable.h"

template<typename Key, typename Value>
class OpenAddressingHashTable : public GenericHashTable<Key, Value>{
   public:
      OpenAddressingHashTable();
      virtual ~OpenAddressingHashTable();
      virtual int    insert(Key, Value);
      virtual Value  remove(Key );
      virtual Value  retrieve(Key);
      virtual int    searchKeys(Key, int& );
      virtual int    searchValues(Value);
   protected:
      virtual void rehash();
   private:
      int performHash(Key, int  = 0);
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
int OpenAddressingHashTable<Key, Value>::insert(Key key, Value value){
   //int EMPTY   = GenericHashElement<Key,Value>::EMPTY;
   //int UNKNOWN = GenericHashElement<Key,Value>::UNKNOWN;
   int SET = GenericHashElement<Key,Value>::SET;
   //int DELETED = GenericHashElement<Key,Value>::DELETED;

   int storeValue;
   GenericHashElement<Key, Value> ghe(key, value);
   //this->array[key.key()] = value;
   //this->array[key.key()] = value;
   //this->array[key.key()] = ghe;
   //this->array[key.key()].storeValue =
   //                                 GenericHashElement<Key,Value>::SET;
   //std::cout<<this->array[key.key()]<<std::endl;

   //for(int i = 0; i < this->initialCapacity; ++i){
   //   std::cout<<this->array[i]<<", ";
   //}
   //std::cout<<std::endl;
   //The Key is NOT in the Hash Table, so insert it
   int index = this->searchKeys(key, storeValue);
   if(index < 0 || storeValue != SET){
      if(index > -1){}
      else{
         std::cout<<this->performHash(key)<<std::endl;
      }
   }
   return -1;
}

/*
Virtual
*/
template<typename Key, typename Value>
Value OpenAddressingHashTable<Key, Value>::remove(Key key){
   return this->retrieve(key);
}

/*
Virtual
*/
template<typename Key, typename Value>
Value OpenAddressingHashTable<Key, Value>::retrieve(Key key){
   Value value;
   if(this->array){
      value = this->array[0].value();
   }
   return value;
}

/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::searchKeys(Key key, int& sv){
   int EMPTY   = GenericHashElement<Key,Value>::EMPTY;
   //int UNKNOWN = GenericHashElement<Key,Value>::UNKNOWN;
   //int SET     = GenericHashElement<Key,Value>::SET;
   //int DELETED = GenericHashElement<Key,Value>::DELETED;
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
   return index;
}

/*
Virtual
*/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::searchValues(Value object){
   return 0;
}

////////////////////////Protected Member Functions////////////////////
/*
Virtual
*/
template<typename Key, typename Value>
void OpenAddressingHashTable<Key, Value>::rehash(){}

/////////////////////////Private Member Functions/////////////////////
/**/
template<typename Key, typename Value>
int OpenAddressingHashTable<Key, Value>::performHash(Key key, int i){
   int hashPrime = key.key()%this->size();
   int index     = (hashPrime + i + i*i)%this->size();

   return index;
}
#endif
//////////////////////////////////////////////////////////////////////
