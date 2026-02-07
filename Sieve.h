//////////////////////////////////////////////////////////////////////
#ifndef SIEVE_H
#define SIEVE_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Sieve{
   public:
      Sieve(int );
      ~Sieve();
      std::ostream& print(std::ostream& );
      void findPrimes();
   protected:
   private:
      int   _utai; //Up to and including
      int*  _indices;
      long* _primes;
      int   _numberOfPrimes;
      void  findIndices();
      void  findNumberOfPrimes();
      void  initializeIndices();
      void  setPrimes();
};
std::ostream& operator<<(std::ostream& os, Sieve& s);
#endif
//////////////////////////////////////////////////////////////////////
