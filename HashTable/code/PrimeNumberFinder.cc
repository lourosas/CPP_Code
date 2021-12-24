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
#include "PrimeNumberFinder.h"
//////////////////////////////////////////////////////////////////////
/**/
PrimeNumberFinder::PrimeNumberFinder()
  :_prime(nullptr),
   _isPrime(nullptr),
   _size(100),
   _primes(0)
{
   this->_prime = new int[_size];
   if(this->_prime == nullptr ){
      exit(1);
   }
   this->_isPrime = new int[_size];
   if(this->_isPrime == nullptr){
      exit(1);
   }
   for(int i = 0; i < this->_size; ++i){
      this->_prime[i]   = 0;
      this->_isPrime[i] = 0;
   }
}

/**/
PrimeNumberFinder::PrimeNumberFinder(int size)
  :_prime(nullptr),
   _isPrime(nullptr),
   _size(size),
   _primes(0)
{
   this->_prime = new int[_size];
   if(this->_prime == nullptr ){
      exit(1);
   }
   this->_isPrime = new int[_size];
   if(this->_isPrime == nullptr){
      exit(1);
   }
   for(int i = 0; i < this->_size; ++i){
      this->_prime[i]   = 0;
      this->_isPrime[i] = 0;
   }
}

/*
virtual
*/
PrimeNumberFinder::~PrimeNumberFinder(){
   if(this->_prime){
      delete [] this->_prime;
   }
   if(this->_isPrime){
      delete [] this->_isPrime;
   }
}

/**/
void PrimeNumberFinder::findPrimes(){
   this->_prime[0]                 = 2;
   this->_isPrime[this->_prime[0]] = 1;
   ++this->_primes;
   int i = 0;
   //Mark all the multiples
   while((this->_prime[i]*this->_prime[i]) < this->_size){
      int j = this->_prime[i];
      int k = 1;
      while(j*k < this->_size){
         if(j*k >= (this->_prime[i]*this->_prime[i])){
            this->_isPrime[j*k] = 2;
         }
         ++k;
      }
      ++i;
      while((j < this->_size) && (this->_isPrime[j])){
         ++j;
      }
      if(j < this->_size){
         this->_prime[i]   = j;
         this->_isPrime[j] = 1;
         ++this->_primes;
      }
   }
   //Now, basically go ahead and count up the "0's"
   for(int k = this->_prime[i]; k < this->_size; ++k){
      if(!this->_isPrime[k]){
         this->_isPrime[k] = 1;
         this->_prime[++i] = k;
         ++this->_primes;
      }
   }
}

/**/
int PrimeNumberFinder::lastPrime(){
   int lp = this->_prime[this->_primes - 1];
   lp = (!lp) ? -1 : lp;
   return lp;
}

/**/
int PrimeNumberFinder::numberOfPrimes() const{
   return this->_primes;
}

/**/
int PrimeNumberFinder::primeAt(int index){
   int p = -1;
   if(index < this->_primes && index > -1){
      p = this->_prime[index];
      p = (!p) ? -1: p;
   }
   return p;
}

/**/
int PrimeNumberFinder::size() const{
   return this->_size;
}

/*
virtual
*/
std::ostream& PrimeNumberFinder::print(std::ostream& os){
   for(int i = 0; i < this->_size; ++i){
      os<<this->_prime[i]<<" ";
   }
   os<<std::endl<<std::endl;
   for(int i = 0; i < this->_size; ++i){
      os<<this->_isPrime[i]<<" ";
   }
   os<<std::endl<<std::endl;
   os<<"Size:  "<<this->_size<<std::endl<<"Number of Primes: "
     <<this->_primes<<std::endl<<std::endl;
   return os;
}
///////////////////////Function Declaration///////////////////////////
std::ostream& operator<<(std::ostream& os, PrimeNumberFinder& pnf)
{
   return(pnf.print(os));
}
//////////////////////////////////////////////////////////////////////
