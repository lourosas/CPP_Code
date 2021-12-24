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
#include <fstream>
#include "PrimeNumberFinder.h"

int main(){
   std::cout<<"Hello World\n\n";
   PrimeNumberFinder* pnf = new PrimeNumberFinder(1000);
   pnf->findPrimes();
   //std::cout<<pnf<<std::endl;
   std::ofstream os("primes.txt", std::ofstream::out);
   if(os){ os<<*pnf<<std::endl;}
   os.close();
   std::cout<<pnf->size()<<std::endl<<pnf->numberOfPrimes()
     <<std::endl
     <<std::endl<<pnf->lastPrime()<<std::endl
     <<pnf->primeAt(pnf->numberOfPrimes()/2)
     <<std::endl;
   delete pnf;
   pnf = new PrimeNumberFinder(10000);
   pnf->findPrimes();
   os.open("primes.txt", std::ofstream::app);
   if(os){ os<<std::endl<<*pnf<<std::endl; }
   os.close();
   return 1;
}
