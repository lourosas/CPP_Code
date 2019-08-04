/*
*/
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stdexcept>
#include "fraction.h"

using namespace std;

/**/
Fraction::Fraction(int num, int den){
   if(den == 0){
      throw runtime_error("Denominator ZERO!\n");
   }
   this->_numerator   = num;
   this->_denominator = den;
   this->reduce();
   if(this->_denominator < 0){
      this->_numerator   *= -1;
      this->_denominator *= -1;
   }
}

/**/
Fraction::Fraction(const Fraction& rhs){
   if(rhs._denominator == 0){
      throw runtime_error("Denominator ZERO!\n");
   }
   this->_numerator   = rhs._numerator;
   this->_denominator = rhs._denominator;
   this->reduce();
   if(this->_denominator < 0){
      this->_numerator   *= -1;
      this->_denominator *= -1;
   }
}

/**/
Fraction::~Fraction(){}

////////////////////////Operator Overloading//////////////////////////
/**/
Fraction& Fraction::operator=(const Fraction& rhs){
   if(this != & rhs){
      this->_numerator = rhs._numerator;
      this->_denominator = rhs._denominator;
      this->reduce();
      if(this->_denominator < 0){
         this->_numerator   *= -1;
         this->_denominator *= -1;
      }
   }
   return *this;
}

/**/
Fraction Fraction::operator+(const Fraction& rhs){
   int num = this->_numerator*rhs._denominator +
             this->_denominator*rhs._numerator;
   int den = this->_denominator*rhs._denominator;
   try{
      return Fraction(num, den);
   }
   catch(runtime_error& e){
      cout<<e.what();
      throw e;
   }
}

/**/
Fraction Fraction::operator-(const Fraction& rhs){
   Fraction test = rhs;
   test = test * -1;
    try{
       return (*this) + test;
    }
    catch(runtime_error& e){
       throw e;
    }
}

/**/
Fraction Fraction::operator*(const Fraction& rhs){
   int num = this->_numerator*rhs._numerator;
   int den = this->_denominator*rhs._denominator;
   try{
      return Fraction(num, den);
   }
   catch(runtime_error& e){
      cout<<e.what();
      throw e;
   }
}

/**/
Fraction Fraction::operator*(int value){
   try{
      return Fraction((value*this->_numerator),this->_denominator);
   }
   catch(runtime_error& e){
      cout<<e.what();
      throw e;
   }
}

/**/
Fraction Fraction::operator/(const Fraction& rhs){
   try{
      Fraction test(rhs._denominator, rhs._numerator);
      return (*this)*(test);
   }
   catch(runtime_error& e){
      cout<<e.what();
      throw e;
   }
}

/**/
Fraction Fraction::operator/(int value){
   try{
      Fraction div(1, value);
      return div*(*this);
   }
   catch(runtime_error& e){
      cout<<e.what();
      throw e;
   }
}

/**/
Fraction Fraction::divide(const Fraction& rhs){
   try{
      return (*this)/rhs;
   }
   catch(runtime_error& e){ throw e; }
}

/**/
Fraction Fraction::divide(int value){
   try{
      return (*this)/value;
   }
   catch(runtime_error& e){ throw e; }
}

/**/
ostream& Fraction::print(ostream& os) const{
   os<<this->_numerator;
   if(this->_numerator != 0 && this->_numerator != 1){
      os<<"/"<<this->_denominator;
   }
   return os;
}

/**/
int Fraction::findGCD(){
   int GCD   = 1;
   int found = 0;
   int a = this->_numerator;
   int b = this->_denominator;
   if(a == 0){
      found = 1;
   }
   while(!found){
      if((a % b) == 0){
         GCD = b;
         found = 1;
      }
      else if((b % a) == 0){
         GCD = a;
         found = 1;
      }
      else{
         int temp = a;
         a = a % b;
         b = b % temp;
      }
   }
   return GCD;
}

/**/
void Fraction::reduce(){
   int gcd = this->findGCD();
   this->_numerator   /= gcd;
   this->_denominator /= gcd;
}

ostream& operator<<(ostream& os, const Fraction& rhs)
{
   return rhs.print(os);
}

//////////////////////////////////////////////////////////////////////
