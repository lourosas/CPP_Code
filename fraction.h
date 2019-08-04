/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction{
   public:
      Fraction(int = 0, int = 1);
      Fraction(const Fraction& );
      ~Fraction();
      Fraction& operator=(const Fraction& );
      Fraction operator+(const Fraction& );
      Fraction operator-(const Fraction& );
      Fraction operator*(const Fraction& );
      Fraction operator*(int );
      Fraction operator/(const Fraction& );
      Fraction operator/(int );
      Fraction divide(const Fraction& );
      Fraction divide(int );
      std::ostream& print(std::ostream& ) const;
      enum{ DENOMINATOR_ZERO };
   private:
      int  findGCD();
      void reduce();
      int _numerator;
      int _denominator;
};
std::ostream& operator<<(std::ostream& os, const Fraction& f);
#endif
//////////////////////////////////////////////////////////////////////
