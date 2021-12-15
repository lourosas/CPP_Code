/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <iomanip>

template <typename T>
class Object{
   public:
      Object();
      Object(T);
      Object(const Object& );
      virtual ~Object();
      Object& operator=(const Object& );
      int operator==(const Object& )const;
      int key() const;
      T value() const;
      virtual std::ostream& print(std::ostream& ) const;
   protected:
      int _key;
      T _value;
   private:
      virtual void generateKey() = 0;
};
template<typename T>
std::ostream& operator<<(std::ostream& os, Object<T>& obj);
template<typename T>
std::ostream& operator<<(std::ostream& os, const Object<T>& obj);

////////////////////////Public Member Functions///////////////////////
/**/
template<typename T>
Object<T>::Object()
: _key(0)
{}

/**/
template<typename T>
Object<T>::Object(T value)
: _key(0), _value(value)
{}

/**/
template<typename T>
Object<T>::Object(const Object& rhs){
   this->_key   = rhs._key;
   this->_value = rhs._value;
}

/*
virtual
*/
template<typename T>
Object<T>::~Object(){}

/**/
template<typename T>
Object<T>& Object<T>::operator=(const Object& rhs){
   if(this != &rhs){
      this->_key   = rhs._key;
      this->_value = rhs._value;
   }
   return *this;
}

/**/
template<typename T>
int Object<T>::operator==(const Object& obj) const{
   return (this->_value == obj._value);
}

/**/
template<typename T>
int Object<T>::key() const{
   return this->_key;
}

template<typename T>
T Object<T>::value() const{
   return this->_value;
}

/*
virtual
*/
template<typename T>
std::ostream& Object<T>::print(std::ostream& os) const{
   os<<this->_key<<", "<<this->_value;
   return os;
}

////////////////////////Function Declarations/////////////////////////
template<typename T>
std::ostream& operator<<(std::ostream& os, Object<T>& obj)
{
   obj.print(os);
   return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Object<T>& obj)
{
   obj.print(os);
   return os;
}
#endif
//////////////////////////////////////////////////////////////////////
