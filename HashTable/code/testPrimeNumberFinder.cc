#include <fstream>
#include "PrimeNumberFinder.h"

int main(){
   std::cout<<"Hello World\n\n";
   PrimeNumberFinder pnf(1000);
   pnf.findPrimes();
   //std::cout<<pnf<<std::endl;
   std::ofstream os("primes.txt", std::ofstream::out);
   if(os){ os<<pnf<<std::endl;}
   os.close();
   std::cout<<pnf.size()<<std::endl<<pnf.numberOfPrimes()<<std::endl
     <<std::endl<<pnf.lastPrime()<<std::endl
     <<pnf.primeAt(pnf.numberOfPrimes()/2)
     <<std::endl;
   return 1;
}
