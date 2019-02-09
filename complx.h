/*********************************************************************
*********************************************************************/
#ifndef COMPLX_H
#define COMPLX_H
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

template <typename T = double>
class Complx{
   public:
      Complx();
      Complx(const T&, const T&);
      Complx(const Complx<T>& );                //lvalue
      Complx(Complx<T>&& );               //rvalue

      virtual ~Complx();

      Complx<T>& operator=(const Complx<T>& ) ; //lvalue
      Complx<T>& operator=(Complx<T>&& ); //rvalue

      Complx<T> operator+(const Complx<T>& ); //lvalue
      Complx<T> operator+(Complx<T>&& );      //rvalue
      Complx<T> operator-(const Complx<T>& ); //lvalue
      Complx<T> operator-(Complx<T>&& );      //rvalue
      Complx<T> operator*(const Complx<T>& ); //lvalue
      Complx<T> operator*(Complx<T>&& );      //rvalue
      Complx<>  operator/(const Complx<T>& ); //lvalue
      Complx<>  operator/(Complx<T>& );       //lvalue
      Complx<>  operator/(Complx<T>&& );      //rvalue

      int operator==(const Complx<T>& );      //lvalue
      int operator==(Complx<T>&& );           //rvalue
      int operator>(const Complx<T>& );       //lvalue
      int operator>(Complx<T>&& );            //rvalue
      int operator>=(const Complx<T>& );      //lvalue
      int operator>=(Complx<T>&& );           //rvalue
      int operator<(const Complx<T>& );       //lvalue
      int operator<(Complx<T>&& );            //rvalue
      int operator<=(const Complx<T>& );      //lvalue
      int operator<=(Complx<T>&& );           //rvalue

      Complx<T> complexConjugate();
      Complx<T> complexConjugate() const;
      T lengthSquared() const;

      T real() const;
      T imag() const;
   private:
      T real_;
      T imag_;
      void real(const T& );
      void imag(const T& );
};

//lvalue
template <typename T = double>
ostream& operator<<(ostream& os, const Complx<T>& c);
//rvalue
template <typename T = double>
ostream& operator<<(ostream& os, Complx<T>&& c);

/*
*/
template <typename T>
Complx<T>::Complx(){
   this->real_ = T();
   this->imag_ = T();
}

/*
*/
template <typename T>
Complx<T>::Complx(const T& r, const T& i) : 
real_(r),
imag_(i){}

/*
lvalue copy constructor
*/
template <typename T>
Complx<T>::Complx(const Complx<T>& c) :
real_(c.real()),
imag_(c.imag()){}

/*
rvalue copy constructor
(Actually, the actual term in move constructor)
*/
template <typename T>
Complx<T>::Complx(Complx<T>&& c){
   this->real_ = c.real();
   this->imag_ = c.imag();
}

/*
virtual destructor
*/
template <typename T>
Complx<T>::~Complx(){}

/////////////////////////////Operator Overloading/////////////////////
/*
lvalue assignment operator overloading
*/
template <typename T>
Complx<T>& Complx<T>::operator=(const Complx<T>& comp){
   if(this != &comp){
      this->real(comp.real());
      this->imag(comp.imag());
   }
   return *this;
}

/*
rvalue assignment operator overloading
*/
template <typename T>
Complx<T>& Complx<T>::operator=(Complx<T>&& comp){
   if(this != &comp){
      this->real(comp.real());
      this->imag(comp.imag());
   }
   return *this;
}

/*
lvalue addition operator
*/
template <typename T>
Complx<T> Complx<T>::operator+(const Complx<T>& c){
   T real = this->real() + c.real();
   T imag = this->imag() + c.imag();
   return Complx<T>(real, imag);
}

/*
rvalue addition operator
*/
template <typename T>
Complx<T> Complx<T>::operator+(Complx<T>&& c){
   T real = this->real() + c.real();
   T imag = this->imag() + c.imag();
   return Complx<T>(real, imag);
}

/*
lvalue subtraction operator
*/
template<typename T>
Complx<T> Complx<T>::operator-(const Complx<T>& c){
   T real = this->real() - c.real();
   T imag = this->imag() - c.imag();
   return Complx<T>(real, imag);
}

/*
rvalue subtraction operator
*/
template<typename T>
Complx<T> Complx<T>::operator-(Complx<T>&& c){
   T real = this->real() - c.real();
   T imag = this->imag() - c.imag();
   return Complx<T>(real, imag);
}

/*
lvalue multiplication operator
*/
template<typename T>
Complx<T> Complx<T>::operator*(const Complx<T>& c){
   T real = (this->real() * c.real()) - (this->imag() * c.imag());
   T imag = (this->real() * c.imag()) + (this->imag() * c.real());
   return Complx<T>(real, imag);
}

/*
rvalue multiplication operator
*/
template<typename T>
Complx<T> Complx<T>::operator*(Complx<T>&& c){
   T real = (this->real() * c.real()) - (this->imag() * c.imag());
   T imag = (this->real() * c.imag()) + (this->imag() * c.real());
   return Complx<T>(real, imag);
}

/*
lvalue division operator with a constant argument
(Whatever the hell that means)
TODO:  divide by zero exception!!!
*/
template<typename T>
Complx<> Complx<T>::operator/(const Complx<T>& c){
   T denom            = c.lenghtSquared();
   double denominator = (double)denom;
   Complx<T> conj     = c.complexConjugate();
   Complx<T> numer(this->real(), this->imag());
   T numerR = numer.real()*conj.real() - numer.imag()*conj.imag();
   T numerI = numer.real()*conj.imag() + numer.imag()*conj.real();
   double real = (double)numerR/denominator;
   double imag = (double)numerI/denominator;
   return Complx<>(real,imag);
}

/*
lvalue division operator
TODO:  divide by zero exception!!!
*/
template<typename T>
Complx<> Complx<T>::operator/(Complx<T>& c){
   Complx<T> denom     = c * c.complexConjugate();
   double denominator  = (double)denom.real();
   Complx<T> numerator = (*this) * c.complexConjugate();
   double real         = ((double)numerator.real())/denominator;
   double imag         = ((double)numerator.imag())/denominator;
   return Complx<>(real, imag);
}

/*
rvalue division operator
TODO:  divide by zero exception!!!
*/
template<typename T>
Complx<> Complx<T>::operator/(Complx<T>&& c){
   Complx<T> denom     = c * c.complexConjugate();
   double denominator  = (double)denom.real();
   Complx<T> numerator = (*this) * c.complexConjugate();
   double real         = ((double)numerator.real())/denominator;
   double imag         = ((double)numerator.imag())/denominator;
   return Complx<>(real, imag);
}

/*
lvalue equality operator
*/
template<typename T>
int Complx<T>::operator==(const Complx<T>& c){
   return ((this->real() == c.real()) && (this->imag() == c.imag()));
}

/*
rvalue equality operator
*/
template<typename T>
int Complx<T>::operator==(Complx<T>&& c){
   return ((this->real() == c.real()) && (this->imag() == c.imag()));
}

/*
lvalue greater than operator
*/
template<typename T>
int Complx<T>::operator>(const Complx<T>& c){
   return (this->lengthSquared() > c.lengthSquared());
}

/*
rvalue greater than operator
*/
template<typename T>
int Complx<T>::operator>(Complx<T>&& c){
   return (this->lengthSquared() > c.lengthSquared());
}

/*
lvalue greater than or equal to operator
*/
template<typename T>
int Complx<T>::operator>=(const Complx<T>& c){
   return((*this > c) || (*this == c));
}

/*
rvalue greater than or equal to operator
*/
template<typename T>
int Complx<T>::operator>=(Complx<T>&& c){
   return((*this > c) || (*this == c));
}

/*
lvalue less than operator
*/
template<typename T>
int Complx<T>::operator<(const Complx<T>& c){
   return (this->lengthSquared() < c.lengthSquared());
}

/*
rvalue less than operator
*/
template<typename T>
int Complx<T>::operator<(Complx<T>&& c){
   return (this->lengthSquared() < c.lengthSquared());
}

/*
lvalue less than or equal to operator
*/
template<typename T>
int Complx<T>::operator<=(const Complx<T>& c){
   return((*this < c) || (*this == c));
}



///////////////////////////Public Member Functions////////////////////
/*
*/
template <typename T>
Complx<T> Complx<T>::complexConjugate(){
   return Complx<T>((this->real()), (-1*(this->imag())));
}

/*
*/
template <typename T>
Complx<T> Complx<T>::complexConjugate() const{
   return Complx<T>((this->real()), (-1*(this->imag())));
}

/*
*/
template <typename T>
T Complx<T>::lengthSquared() const{
   T a = this->real();
   T b = this->imag();
   return (a*a) + (b*b);
}

/*
*/
template <typename T>
T Complx<T>::real() const{
   return this->real_;
}

/*
*/
template <typename T>
T Complx<T>::imag() const{
   return this->imag_;
}

///////////////////////////Private Member Functions///////////////////
/*
*/
template <typename T>
void Complx<T>::real(const T& r){
   this->real_ = r;
}

/*
*/
template <typename T>
void Complx<T>::imag(const T& i){
   this->imag_= i;
}


///////////////////////////Function Definitions///////////////////////
/*
lvalue
*/
template <typename T>
ostream& operator<<(ostream& os, const Complx<T>& c){
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
template <typename T>
ostream& operator<<(ostream& os, Complx<T>&& c){
   os<<c.real();
   if(c.imag() >= 0){
      os<<"+";
   }
   os<<c.imag()<<"i";
   return os;
}

#endif
