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
: Object(-1){
   this->generateKey();
}

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
