/*
*/
#include "Object.h"
//////////////////////////////////////////////////////////////////////
////////////////////////Public Member Functions///////////////////////
/**/
Object::Object()
: _key(0)
{}

/**/
Object::Object(int key)
: _key(key){}

/**/
Object::Object(const Object& rhs){
   this->_key = rhs.key();
}

/*
Virtual
*/
Object::~Object(){}

/*
*/
int Object::key() const{
   return this->_key;
}

/*
*/
Object& Object::operator=(const Object& rhs){
   if(this != &rhs){
      this->_key = rhs.key();
   }
   return *this;
}

/*
virtual
*/
std::ostream& Object::print(std::ostream& os){
   os<<this->_key;
   return os;
}
////////////////////////Function Declarations/////////////////////////
std::ostream& operator<<(std::ostream& os, Object& obj)
{
   obj.print(os);
   return os;
}
//////////////////////////////////////////////////////////////////////
