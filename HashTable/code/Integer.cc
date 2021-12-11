/*
 * The Key is going to be the SAME as the value!!!
 * THAT IS WHY THEY ARE INTERCHANGEABLE!!!
*/
#include "Object.h"
#include "Integer.h"
//////////////////////////////////////////////////////////////////////
////////////////////////Public Member Functions///////////////////////
/**/
Integer::Integer()
: Object(0){}

/**/
Integer::Integer(int value)
: Object(value){
   this->generateKey();
}

/**/
//Integer::Integer(const Integer& rhs){
//   this->_key = rhs.key();
//}

/*Virtual*/
Integer::~Integer(){}

/**/
//Integer& Integer::operator=(const Integer& rhs){
//   if(this != &rhs){
//      this->_key = rhs.key();
//   }
//   return *this;
//}

/* Virtual */
std::ostream& Integer::print(std::ostream& os) const{
   os<<"(";
   Object::print(os); //Use the 'Inheritance protocol...'
   os<<")";
   //os<<"("<<this->_key<<", "<<this->_value<<")";
   return os;
}
///////////////////////Private Member Functions///////////////////////
/*
The Key and the Value are the same for this type
*/
void Integer::generateKey(){
   this->_key = this->_value;
}

////////////////////////Function Declarations/////////////////////////
std::ostream& operator<<(std::ostream& os, Integer& int_){
   return int_.print(os);
}

std::ostream& operator<<(std::ostream& os, const Integer& int_){
   return int_.print(os);
}
//////////////////////////////////////////////////////////////////////
