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
      enum{SIZE_ERROR = -0xF,INSERTION_ERROR};
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
            index = this->performHash(key);
         }
         this->array[index] = ghe;
         this->array[index].storeValue = SET;
         ++this->numberOfElements;
      }
   }
   catch(int x){
      if(x == SIZE_ERROR){
         std::cout<<"\nERROR:  "<<ghe<<" could NOT be inserted into "
           <<"the Hash Table--Hash Table Size too small\n";
         int insertionError = INSERTION_ERROR;
         throw insertionError;
      }
   }
   //return the index of where it was stored...I think...leme think
   return index;
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
