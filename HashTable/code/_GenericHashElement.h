/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef GENERIC_HASH_ELEMENT_H
#define GENERIC_HASH_ELEMENT_H

#include "Object.h"

template <class Value>
class GenericHashElement{
   public:
      enum{EMPTY, DELETED, SET, UNKNOWN};
      int storeValue;
      Value value;
      GenericHashElement();
      GenericHashElement(Value );
      GenericHashElement(const GenericHashElement& );
      virtual ~GenericHashElement();
      virtual std::ostream& print(std::ostream& ) const;
      virtual GenericHashElement& operator=(const GenericHashElement&);
      virtual GenericHashElement& operator=(const Value&);
      //virtual int operator[](const Object&);
      //virtual const int operator[](const Object&) const;
   protected:
   private:
};
template<class Value>
std::ostream& operator<<(std::ostream& os,
                                    GenericHashElement<Value>& elem);
template<class Value>
std::ostream& operator<<(std::ostream& os,
                              const GenericHashElement<Value>& elem);

/////////////////////Public Member Functions//////////////////////////
/**/
template<class Value>
GenericHashElement<Value>::GenericHashElement(){
   this->storeValue = EMPTY;
}

template<class Value>
GenericHashElement<Value>::GenericHashElement(Value v){
   this->value = v;
}

/*
*/
template<class Value>
GenericHashElement<Value>::GenericHashElement
(
   const GenericHashElement& rhs
){
   this->storeValue = rhs.storeValue;
   this->value      = rhs.value;
}

/*
Virtual
*/
template<class Value>
GenericHashElement<Value>::~GenericHashElement(){}

/*
virtual
*/
template<class Value>
std::ostream& GenericHashElement<Value>::print(std::ostream& os)const{
   os<<"("<<this->storeValue<<", "<<this->value<<")";
   return os;
}

/*
virtual
*/
template<class Value>
GenericHashElement<Value>& GenericHashElement<Value>::operator=
(
   const GenericHashElement& rhs
){
   this->storeValue = rhs.storeValue;
   this->value      = rhs.value;
   return *this;
}

/*
Virtual
*/
template<class Value>
GenericHashElement<Value>& GenericHashElement<Value>::operator=
(
   const Value& v
){
   if(this->storeValue != SET){
      this->value      = v;
      this->storeValue = SET;
   }
   return *this;
}

/*
Virtual

template<class Value>
int GenericHashElement<Value>::operator[](const Object& obj){
   return obj.key();
}
*/

/*
Virtual

template<class Value>
const int GenericHashElement<Value>::operator[](const Object& obj){
   return obj.key();
}
*/
/////////////////////////Function Definitions/////////////////////////
template<class Value>
std::ostream& operator<<(std::ostream& os,
                                     GenericHashElement<Value>& elem)
{
   return (elem.print(os));
}
#endif
//////////////////////////////////////////////////////////////////////
