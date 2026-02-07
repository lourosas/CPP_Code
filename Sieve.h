  1 //////////////////////////////////////////////////////////////////////
  2 #ifndef SIEVE_H
  3 #define SIEVE_H
  4
  5 #include <iostream>
  6 #include <iomanip>
  7 #include <string>
  8
  9 using namespace std;
 10
 11 class Sieve{
 12    public:
 13       Sieve(int );
 14       ~Sieve();
 15       std::ostream& print(std::ostream& );
 16       void findPrimes();
 17    protected:
 18    private:
 19       int   _utai; //Up to and including
 20       int*  _indices;
 21       long* _primes;
 22       int   _numberOfPrimes;
 23       void  findIndices();
 24       void  findNumberOfPrimes();
 25       void  initializeIndices();
 26       void  setPrimes();
 27 };
 28 std::ostream& operator<<(std::ostream& os, Sieve& s);
 29 #endif
 30 //////////////////////////////////////////////////////////////////////
