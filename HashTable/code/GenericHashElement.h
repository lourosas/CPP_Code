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
#ifndef GENERIC_HASH_ELEMENT_H
#define GENERIC_HASH_ELEMENT_H

#include "Object.h"

template <class Key, class Value>
class GenericHashElement{
   public:
      enum{UNKNOWN=-4,SET,DELETED,EMPTY};
      GenericHashElement();
      GenericHashElement(Key, Value );
      GenericHashElement(const GenericHashElement& );
      virtual ~GenericHashElement();
      virtual GenericHashElement& operator=(const GenericHashElement&);
      virtual int operator==(const GenericHashElement& );
      virtual int operator>(const GenericHashElement& );
      virtual int operator>=(const GenericHashElement& );
      virtual int operator<(const GenericHashElement& );
      virtual int operator<=(const GenericHashElement& );
      virtual std::ostream& print(std::ostream& ) const;
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
   this->storeValue = EMPTY;
}

template<class Key, class Value>
GenericHashElement<Key, Value>::GenericHashElement(Key k, Value v){
   this->_key        = k;
   this->_value      = v;
   this->storeValue  = EMPTY;
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
virtual
*/
template<class Key, class Value>
int GenericHashElement<Key,Value>::operator==
(
   const GenericHashElement& rhs
){
   return ((this->key()==rhs.key()) && (this->value()==rhs.value()));
}

/*
virutal
*/
template<class Key, class Value>
int GenericHashElement<Key,Value>::operator>
(
   const GenericHashElement& rhs
){
   return (this->value() > rhs.value());
}

/*
virtual
*/
template<class Key, class Value>
int GenericHashElement<Key,Value>::operator>=
(
   const GenericHashElement& rhs
){
   return (this->value() >= rhs.value());
}

/*
virtual
*/
template<class Key,class Value>
int GenericHashElement<Key,Value>::operator<
(
   const GenericHashElement& rhs
){
   return (this->value() < rhs.value());
}

/*
virtual
*/
template<class Key,class Value>
int GenericHashElement<Key,Value>::operator<=
(
   const GenericHashElement& rhs
){
   return(this->value() <= rhs.value());
}

/*
virtual
*/
template<class Key, class Value>
std::ostream& GenericHashElement<Key, Value>::print
(
   std::ostream& os
)const{
   /*
   os<<"("<<this->storeValue<<", "<<this->_key<<", "
      <<this->_value<<")";
   */
   os<<"(";
   if(this->storeValue == UNKNOWN){os<<" UNKNOWN, ";}
   else if(this->storeValue == SET){os<<" SET, ";}
   else if(this->storeValue == DELETED){os<<" DELETED, ";}
   else if(this->storeValue == EMPTY){os<<" EMPTY, ";}
   os<<this->_key.key()<<", "<<this->_value.value()<<")";
   return os;
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
