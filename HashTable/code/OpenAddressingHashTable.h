/**/
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
      virtual int    insert(Key, Value);
      virtual Value  remove(Key );
      virtual Value  retrieve(Key);
      virtual int    searchKeys(Key, int& );
      virtual int    searchValues(Value);
   protected:
      virtual void rehash();
   private:
      enum{SIZE_ERROR = -0xFF,INSERTION_ERROR,ALREADY_INSERTED};
      int checkIncreaseSize();
      int  performHash(Key, int  = 0);
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

      //TEST PRINTS FOR THE TIME BEING!!!
      std::cout<<ghe<<std::endl;

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
         //TEST PRINTS FOR THE TIME BEING
         std::cout<<index<<" : "<<ghe<<std::endl;
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
         throw INSERTION_ERROR;
      }
      else if(x == ALREADY_INSERTED){
         std::cout<<std::endl<<ghe<<": PREVIOUSLY INSERTED\n";
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
      //TEST PRINTS FOR THE TIME BEING!!!
      if(sv==GenericHashElement<Key,Value>::SET){
         std::cout<<" Collision: "<<idx<<" ; "<<key.key()<<std::endl;
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
void OpenAddressingHashTable<Key, Value>::rehash(){
   int EMPTY = GenericHashElement<Key,Value>::EMPTY;
   int SET   = GenericHashElement<Key,Value>::SET;

   int newSize = this->checkIncreaseSize();
   if(newSize){
      int tempSize = this->size();
      this->size(newSize);

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
      //find another set of prime numbers
      //create more primes, as needed...
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
#endif
//////////////////////////////////////////////////////////////////////
