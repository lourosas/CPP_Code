 //////////////////////////////////////////////////////////////////////
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <cmath>
 #include "Sieve.h"
 
 using namespace std;

 ////////////////////////////Public Methods////////////////////////////
 /*
 Constructor with the number of values to find the primes up to
 and including in the input.
 i.e.  Sieve(100) will find the primes from 0-100 including 100...so
 the array is one greater (101 in this case)
 */
 Sieve::Sieve(int utai)
 :_utai(utai), _indices(0), _primes(0), _numberOfPrimes(0)
 {
    std::cout<<"In the contructor\n";
    //_utai is the total number of indices (numbers) to check
    this->initializeIndices();
 }
 
 /**/
 Sieve::~Sieve(){
    std::cout<<"in the destructor 0\n";
    if(this->_indices){
       delete[] this->_indices;
    }
    if(this->_primes){
       delete [] this->_primes;
    }
    std::cout<<"in the destructor 1\n";
 }
 
 /**/
 std::ostream& Sieve::print(std::ostream& os){
    os<<"\nNumber of Primes: "<<this->_numberOfPrimes;
    os<<"\n\n";
    for(int i = 0; i < this->_utai + 1; ++i){
       os<<this->_indices[i]<<", ";
    }
    os<<"\n\nPrimes:\n";
    for(int i = 0; i < this->_numberOfPrimes; ++i){
       os<<this->_primes[i]<<" ";
    }
    os<<"\n";
    return os;
 }
 
 /**/
 void Sieve::findPrimes(){
    this->findIndices();
    this->setPrimes();
 }
 //////////////////////////Protected Methods///////////////////////////
 ///////////////////////////Private Methods////////////////////////////
 
 /**/
 void Sieve::findIndices(){
    int lim = sqrt(this->_utai) + 1;
    for(int i = 2; i < lim; ++i){
       for(int j = i*i; j <= this->_utai; j += i){
          if(this->_indices[j]){
              this->_indices[j] = 0; //Not a prime
          }
       }
    }
 }
 /**/
 void Sieve::findNumberOfPrimes(){
    this->_numberOfPrimes = 0;
    if(this->_indices){
       for(int i = 0; i <= this->_utai; ++i){
          this->_numberOfPrimes += (this->_indices[i]) ? 1 : 0;
       }
    }
 }
 
 /**/
 void Sieve::initializeIndices(){
    if(this->_indices){
       delete [] this->_indices;
    }
    //Up to and including--0->utai + 1 0 counts as one
    this->_indices = new int[this->_utai + 1];
    for(int i = 0; i < this->_utai + 1; ++i){
       this->_indices[i] = 1; //Initialize everything to prime...
       if(!i || i == 1){
          this->_indices[i] = 0; //No need to even Sieve
       }
    }
 }
 
 
 /**/
 void Sieve::setPrimes(){
    int index = 0;
    this->findNumberOfPrimes();
    this->_primes = new long[this->_numberOfPrimes];
    for(int i = 0; i <= this->_utai; ++i){
       if(this->_indices[i]){
          //Hopefully, will not core dump from out of bounds...
          this->_primes[index++] = i;
       }
    }
 }
 //////////////////////////////////////////////////////////////////////
 std::ostream& operator<<(std::ostream& os, Sieve& s)
 {
    return s.print(os);
 }
 //////////////////////////////////////////////////////////////////////

