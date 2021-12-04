/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef GENERIC_HASH_ELEMENT_H
#define GENERIC_HASH_ELEMENT_H

#include "Object.h"

template <class Value>
class GenericHashElement{
   public:
      enum{EMPTY, DELETED, SET};
      int storeValue;
      Value value;
   protected:
   private:
};
#endif
//////////////////////////////////////////////////////////////////////
