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
      virtual std::ostream& print(std::ostream& ) const;
   protected:
   private:
};
template<class Value>
std::ostream& operator<<(std::ostream& os,
                                    GenericHashElement<Value>& elem);
template<class Value>
std::ostream& operator<<(std::ostream& os,
                              const GenericHashElement<Value>& elem);

/*
virtual
*/
template<class Value>
std::ostream& GenericHashElement<Value>::print(std::ostream& os)const{
   os<<"("<<this->storeValue<<", "<<this->value<<")";
   return os;
}

/////////////////////////Function Definitions/////////////////////////
template<class Value>
std::ostream& operator<<(std::ostream& os,
                                     GenericHashElement<Value>& elem)
{
   return (elem.print(os));
}
#endif
//////////////////////////////////////////////////////////////////////
