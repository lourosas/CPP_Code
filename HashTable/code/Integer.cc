/*
 * The Key is going to be the SAME as the value!!!
 * THAT IS WHY THE ARE INTERCHANGEABLE!!!
*/
#include "Object.h"
#include "Integer.h"
//////////////////////////////////////////////////////////////////////
////////////////////////Public Member Functions///////////////////////
/**/
Integer::Integer()
: Object(0){}

/**/
Integer::Integer(int key)
: Object(key){}

/**/
Integer::Integer(const Integer& rhs){
   this->_key = rhs.key();
}

/*Virtual*/
Integer::~Integer(){}

/**/
Integer& Integer::operator=(const Integer& rhs){
   if(this != &rhs){
      this->_key = rhs.key();
   }
   return *this;
}

/* Virtual */
std::ostream& Integer::print(std::ostream& os){
   return Object::print(os);
}
////////////////////////Function Declarations/////////////////////////
std::ostream& operator<<(std::ostream& os, Integer& int_){
   return int_.print(os);
}
//////////////////////////////////////////////////////////////////////
