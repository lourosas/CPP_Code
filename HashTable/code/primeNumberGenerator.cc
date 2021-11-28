#include <iostream>
#include <cmath>

int main(){
   int isPrime[100];
   int prime[100];
   for(int i = 0; i < 100; ++i){
      prime[i]   = 0;
      isPrime[i] = 0;
   }
   prime[0]          = 2;
   isPrime[prime[0]] = 1;
   std::cout<<"\nHello World\n\n\n";
   int i = 0;
   //Need to mark all multiples
   while(prime[i]*prime[i] < 100){
      int j = prime[i];
      int k = 1;
	   while(j*k < 100){
         if(j*k >= (prime[i]*prime[i])){
            isPrime[j*k] = 2;
         }
         ++k;
      }
	   ++i;
      while((j < 100) && (isPrime[j])){ ++j; }
      if(j < 100){
         prime[i] = j;
         isPrime[j] = 1;
      }
   }
   //Basically now, just count up the "0,s"
   std::cout<<i<<std::endl;
   for(int k = prime[i]; k < 100; ++k){
      if(!isPrime[k]){
         isPrime[k] = 1;
         prime[++i] = k;
      }
   }
   for(int i = 0; i < 100; ++i){
      std::cout<<prime[i]<<" ";
   }
   std::cout<<std::endl<<std::endl;
   for(int j = 0; j < 100; ++j){
      std::cout<<isPrime[j]<<" ";
   }
   std::cout<<std::endl<<std::endl;
   return 1;
}
