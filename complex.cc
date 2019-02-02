/********************************************************************
********************************************************************/
#include <iostream>
#include <iomanip>
#include "complex.h"

using namespace std;

/**/
Complex::Complex() :
_real(0),
_imag(0){}

/**/
Complex::Complex(int r, int i) :
_real(r),
_imag(i){}

/*
lvalue
*/
//Complex::Complex(const Complex& c) :
Complex::Complex(Complex& c) :
_real(c.real()),
_imag(c.imag()){
   cout<<"\nIn the copy constructor\n";
}

/*
rvalue
*/
Complex::Complex(Complex&& c){
   cout<<"\nIn the 'move' constructor\n";
   this->_real = c.real();
   this->_imag = c.imag();
}

/* virtual */
Complex::~Complex(){}

//////////////////////Public Member Functions////////////////////////
////////////////////////Operator Overloading/////////////////////////
/*
Assignment Operator lvalue
*/
//Complex& Complex::operator=(const Complex& comp){
Complex& Complex::operator=(Complex& comp){
   if(this != &comp){
      cout<<"\nIn the Assignment Operator\n";
      this->real(comp.real());
      this->imag(comp.imag());
   }
   return *this;
}

/*
Assignment Operator rvalue
*/
Complex& Complex::operator=(Complex&& comp){
   cout<<"\nIn the rvalue assignment Operator\n";
   this->_real = comp.real();
   this->_imag = comp.imag();
   return *this;
}

/*
Addition Operator
*/
Complex Complex::operator+(const Complex& comp){
   int real = this->real() + comp.real();
   int imag = this->imag() + comp.imag();
   Complex temp(real, imag);
   return temp;
}

/*
   Addition Operator, rvalue(???)
*/
Complex Complex::operator+(Complex&& comp){
   int real = this->real() + comp.real();
   int imag = this->imag() + comp.imag();
   Complex temp(real, imag);
   return temp;
}

/*
lvalue (Or, something of that manner)
Subtraction Operator
*/
Complex Complex::operator-(const Complex& comp){
//Complex Complex::operator-(Complex& comp){
   int real = this->real() - comp.real();
   int imag = this->imag() - comp.imag();
   return Complex(real, imag);
}

/*
Subtraction Operator
rvalue (or, something of that manner)
*/
Complex Complex::operator-(Complex&& comp){
   int real = this->real() - comp.real();
   int imag = this->imag() - comp.imag();
   return Complex(real, imag);
}

/*
Multiplication Operator
lvalue (or, something of that manner)
*/
Complex Complex::operator*(const Complex& comp){
   int real = (this->real() * comp.real()) -
              (this->imag() * comp.imag());
   int imag = (this->real() * comp.imag()) +
              (this->imag() * comp.real());
   return Complex(real, imag);
}

/*
Multiplication Operator
rvalue (or, something of that manner)
*/
Complex Complex::operator*(Complex&& comp){
   int real = (this->real() * comp.real()) -
              (this->imag() * comp.imag());
   int imag = (this->real() * comp.imag()) +
              (this->imag() * comp.real());
   return Complex(real, imag);
}

/*
lvalue addition-assingment operator
*/
Complex& Complex::operator+=(const Complex& comp){
   this->real(this->real() + comp.real());
   this->imag(this->imag() + comp.imag());
   return *this;
}

/*
rvalue addition-assignment opeator
*/
Complex& Complex::operator+=(Complex&& comp){
   this->real(this->real() + comp.real());
   this->imag(this->imag() + comp.imag());
   return *this;
}

/*
lvalue subtraction-assignment operator
*/
Complex& Complex::operator-=(const Complex& comp){
   this->real(this->real() - comp.real());
   this->imag(this->imag() - comp.imag());
   return *this;
}

/*
rvalue subtraction-assignment operator
*/
Complex& Complex::operator-=(Complex&& comp){
   this->real(this->real() - comp.real());
   this->imag(this->imag() - comp.imag());
   return *this;
}

/*
lvalue multiplication-assignment operator
*/
Complex& Complex::operator*=(const Complex& comp){
   int real_ = (this->real() * comp.real()) -
               (this->imag() * comp.imag());
   int imag_ = (this->real() * comp.imag()) +
               (this->imag() * comp.real());
   this->real(real_);
   this->imag(imag_);
   return *this;
}

/*
rvalue multiplication-assignment operator
*/
Complex& Complex::operator*=(Complex&& comp){
   int real_ = (this->real() * comp.real()) -
               (this->imag() * comp.imag());
   int imag_ = (this->real() * comp.imag()) +
               (this->imag() * comp.real());
   this->real(real_);
   this->imag(imag_);
   return *this;
}

/*
Comparison Operator
lvalue comparison (or, something of that manner)
*/
int Complex::operator==(const Complex& comp){
   int isEqual = 0;
   if((this->real() == comp.real()) &&
      (this->imag() == comp.imag())){
      isEqual = 1;
   }
   return isEqual;
}

/*
Comparison Operator
rvalue (or, something of that manner)
*/
int Complex::operator==(Complex&& comp){
   return((this->real()==comp.real()) && (this->imag()==comp.imag()));
}

/*
lvalue greater than operator
*/
int Complex::operator>(const Complex& comp){
//int Complex::operator>(Complex& comp){
   return(this->lengthSquared() >  comp.lengthSquared());
}

/*
rvalue greater than operator
*/
int Complex::operator>(Complex&& comp){
   return(this->lengthSquared() > comp.lengthSquared());
}

/*
lvalue greater than or equal operator
*/
int Complex::operator>=(const Complex& comp){
   return(this->lengthSquared() >= comp.lengthSquared());
}

/*
rvalue greater than or equal operator
*/
int Complex::operator>=(Complex&& comp){
   return(this->lengthSquared() >= comp.lengthSquared());
}

/*
lvalue less than operator
*/
int Complex::operator<(const Complex& comp){
   return(this->lengthSquared() <  comp.lengthSquared());
}

/*
rvalue less than operator
*/
int Complex::operator<(Complex&& comp){
   return(this->lengthSquared() <  comp.lengthSquared());
}


/*
lvalue less than or equal to operator
*/
int Complex::operator<=(const Complex& comp){
   return(this->lengthSquared() <= comp.lengthSquared());
}

/*
rvalue less than or equal to operator
*/
int Complex::operator<=(Complex&& comp){
   return(this->lengthSquared() <= comp.lengthSquared());
}

/*
*/
Complex Complex::complexConjugate(){
   return Complex((this->real()),(-1*(this->imag())));
}

int Complex::lengthSquared() const{
//int Complex::lengthSquared(){
   int a = this->real();
   int b = this->imag();

   return (a*a) + (b*b);
}

/**/
/*
ostream& Complex::print(ostream& os) const{
   if(this->imag() >= 0){
      os<<this->real()<<"+"<<this->imag();
   }
   else{
      os<<this->real()<<this->imag();
   }
   os<<"i";
   return os;
}
*/

/**/
/*
int Complex::real(){
   return this->_real;
}
*/
/**/
/*
int Complex::imag(){
   return this->_imag;
}
*/

/**/
int Complex::real() const{
   return this->_real;
}

/**/
int Complex::imag() const{
   return this->_imag;
}

//////////////////////Private Member Functions///////////////////////
/**/
/*
void Complex::real(const int realPart){
   this->_real = realPart;
}
*/
/**/
/*
void Complex::imag(const int imagPart){
   this->_imag = imagPart;
}
*/

/**/
void Complex::real(int realPart){
   this->_real = realPart;
}

/**/
void Complex::imag(int imagPart){
   this->_imag = imagPart;
}

/////////////////////////Function Definitions////////////////////////
/**/
ostream& operator<<(ostream& os, const Complex& c){
   //c.print(os);
   os<<c.real();
   if(c.imag() >= 0){
      os<<"+";
   }
   os<<c.imag()<<"i";
   return os;
}

/*
rvalue
*/
ostream& operator<<(ostream& os, Complex&& c){
   os<<"\n\nIn the rvalue insertion operator\n";
   os<<c.real();
   if(c.imag() >= 0){
      os<<"+";
   }
   os<<c.imag()<<"i";
   return os;
}
