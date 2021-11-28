/**/
//////////////////////////////////////////////////////////////////////
#ifndef PRIME_NUMBER_FINDER_H
#define PRIME_NUMBER_FINDER_H

#include <iostream>
class PrimeNumberFinder{
   public:
      PrimeNumberFinder();
      PrimeNumberFinder(int );
      virtual ~PrimeNumberFinder();
      void findPrimes();
      int numberOfPrimes() const;
      int size() const;
      virtual std::ostream& print(std::ostream& );
   protected:
   private:
      int* _prime;
      int* _isPrime;
      int  _size;
      int  _primes;
};
#endif
//////////////////////////////////////////////////////////////////////
