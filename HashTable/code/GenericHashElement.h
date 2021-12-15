/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef GENERIC_HASH_ELEMENT_H
#define GENERIC_HASH_ELEMENT_H

#include "Object.h"

template <class Key, class Value>
class GenericHashElement{
   public:
      enum{EMPTY, DELETED, SET, UNKNOWN};
      GenericHashElement();
      GenericHashElement(Key, Value );
      GenericHashElement(const GenericHashElement& );
      virtual ~GenericHashElement();
      virtual std::ostream& print(std::ostream& ) const;
      virtual GenericHashElement& operator=(const GenericHashElement&);
      Key   key()   const;
      Value value() const;
      int   storeValue;
      //virtual int operator[](const Object&);
      //virtual const int operator[](const Object&) const;
   protected:
   private:
      Key   _key;
      Value _value;
};
template<class Key, class Value>
std::ostream& operator<<(std::ostream& os,
                                GenericHashElement<Key, Value>& elem);
template<class Key, class Value>
std::ostream& operator<<(std::ostream& os,
                          const GenericHashElement<Key, Value>& elem);

/////////////////////Public Member Functions//////////////////////////
/**/
template<class Key, class Value>
GenericHashElement<Key, Value>::GenericHashElement(){
   this->storeValue = UNKNOWN;
}

template<class Key, class Value>
GenericHashElement<Key, Value>::GenericHashElement(Key k, Value v){
   this->_key        = k;
   this->_value      = v;
   this->storeValue  = UNKNOWN;
}

/*
*/
template<class Key, class Value>
GenericHashElement<Key, Value>::GenericHashElement
(
   const GenericHashElement& rhs
){
   this->_key        = rhs._key;
   this->_value      = rhs._value;
   this->storeValue  = rhs.storeValue;
}

/*
Virtual
*/
template<class Key, class Value>
GenericHashElement<Key, Value>::~GenericHashElement(){}

/*
virtual
*/
template<class Key, class Value>
std::ostream& GenericHashElement<Key, Value>::print
(
   std::ostream& os
)const{
   os<<"("<<this->storeValue<<", "<<this->_key.key()<<", "
      <<this->_value<<")";
   return os;
}

/*
virtual
*/
template<class Key, class Value>
GenericHashElement<Key,Value>&
GenericHashElement<Key, Value>::operator=
(
   const GenericHashElement& rhs
){
   this->_key        = rhs._key;
   this->storeValue  = rhs.storeValue;
   this->_value      = rhs._value;
   return *this;
}

/*
*/
template<class Key, class Value>
Key GenericHashElement<Key, Value>::key() const{
   return this->_key;
}

/*
*/
template<class Key, class Value>
Value GenericHashElement<Key, Value>::value() const{
   return this->_value;
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
template<class Key, class Value>
std::ostream& operator<<(std::ostream& os,
                                 GenericHashElement<Key, Value>& elem)
{
   return (elem.print(os));
}

template<class Key, class Value>
std::ostream& operator<<(std::ostream& os,
                           const GenericHashElement<Key, Value>& elem)
{
   return (elem.print(os));
}
#endif
//////////////////////////////////////////////////////////////////////
