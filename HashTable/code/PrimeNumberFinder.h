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
      int  lastPrime();
      int  numberOfPrimes() const;
      int  primeAt(int);
      int  size() const;
      virtual std::ostream& print(std::ostream& );
   protected:
   private:
      int* _prime;
      int* _isPrime;
      int  _size;
      int  _primes;
};
std::ostream& operator<<(std::ostream&, PrimeNumberFinder& );
#endif
//////////////////////////////////////////////////////////////////////
