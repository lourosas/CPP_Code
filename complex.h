/********************************************************************
********************************************************************/
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <iomanip>

using namespace std;

class Complex
{
   public:
      Complex();
      Complex(int, int);
      Complex(Complex& );       //lvalue
      //Complex(const Complex& ); //lvalue
      Complex(Complex&& );      //rvalue

      virtual ~Complex();

      //Complex& operator=(const Complex& );
      Complex& operator=(Complex& );
      Complex& operator=(Complex&& );

      Complex operator+(const Complex& );
      Complex operator+(Complex&& );
      Complex operator-(const Complex& ); //lvalue
      Complex operator-(Complex&& );      //rvalue
      Complex operator*(const Complex& ); //lvalue
      Complex operator*(Complex&& );      //rvalue
      Complex operator/(const Complex& ); //lvalue
      Complex operator/(Complex&& );      //rvalue

      //Getting rid of the constants as an attempt to
      //understand the lvalue/rvalue difference
      Complex& operator+=(const Complex& );//lvalue
      Complex& operator+=(Complex&& );     //rvalue
      Complex& operator-=(const Complex& );//lvalue
      Complex& operator-=(Complex&& );     //rvalue
      Complex& operator*=(const Complex& );//lvalue
      Complex& operator*=(Complex&& );     //rvalue
      Complex& operator/=(const Complex& );//lvalue
      Complex& operator/=(Complex&& );     //rvalue
      
      int operator==(const Complex& );    //lvalue
      int operator==(Complex&& );         //rvalue
      int operator>(const Complex& );     //lvalue
      int operator>(Complex&& );          //rvalue
      int operator>=(const Complex& );    //lvalue
      int operator>=(Complex&& );         //rvalue
      int operator<(const Complex& );     //lvalue
      int operator<(Complex&& );          //rvalue
      int operator<=(const Complex& );    //lvalue
      int operator<=(Complex&& );         //rvalue

      Complex complexConjugate();
      int lengthSquared() const;
      //int lengthSquared();
      /*
      ostream& print(ostream& ) const;
      */
      int real() const;
      int imag() const;
   private:
      int _real;
      int _imag;
      void real(int );
      void imag(int );
};
ostream& operator<<(ostream& os, const Complex& c);
//rvalue?
ostream& operator<<(ostream& os, Complex&& c);
#endif
