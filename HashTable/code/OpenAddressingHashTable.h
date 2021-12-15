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
      virtual int    searchKeys(Key);
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
   std::cout<<std::endl<<this->searchKeys(key)<<std::endl
     <<this->performHash(key)<<std::endl;
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
int OpenAddressingHashTable<Key, Value>::searchKeys(Key key){
   int EMPTY   = GenericHashElement<Key,Value>::EMPTY;
   int UNKNOWN = GenericHashElement<Key,Value>::UNKNOWN;
   int index   = UNKNOWN;
   int sv      = index;//store value
   int i       = 0;
   //To allot for an index < 0 (which indicates nothing was found
   //or the storeValue in the array is NOT empty (which indicates
   //there may or may NOT have been any collisions), or every value in
   //the Hash table has been accounted for...continue until one of
   //these is false...
   do{
      int idx = this->performHash(key, i);
      if(idx > -1){
         if(this->array[idx].key() == key){
            index = idx;
         }
         sv = this->array[idx].storeValue;
      }
   }while(index < 0 && sv != EMPTY && ++i < this->size());
   std::cout<<std::endl<<sv<<std::endl;
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
