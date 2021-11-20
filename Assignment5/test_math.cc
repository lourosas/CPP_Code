#include <iostream.h>
#include "MathTools.h"

//Function prototypes
void make_primes(int );
void test_primes();

int main()
{
   const int PRIMES = 20;

   /*cout<<"\n\n\nHello World!\n";
   make_primes(PRIMES);
   cout<<"\n\n20! = "<<MathTools::fact(PRIMES)<<endl;
   test_primes();*/
   cout<<endl<<MathTools::fibSeriesNumber(10)<<endl;
   return 1;
}

void make_primes(int primes)
{
   if(MathTools::setUpPrimes(primes))
   {
      cout<<"\nIt Worked!!\n";
      MathTools::displayPrimes();
   }
   else
      cout<<"\nDid Not Work!!\n";
}

void test_primes()
{
   char to_continue = 'y';
   int entered;

   do{
      cout<<"\nEnter a number: ";cin>>entered;
      if(MathTools::isPrime(entered))
         cout<<"\n\nThe number: "<<entered<<" is a prime\n";
      else
         cout<<"\n\nThe number: "<<entered<<" is NOT a prime\n";
      cout<<"\nThe next prime from "<<entered<<" is:  "
         <<MathTools::getNextPrime(entered)<<endl;
      cout<<"\n\nTo Continue 'y' or 'Y': ";cin>>to_continue;
   }while(to_continue == 'y' || to_continue =='Y');
   cout<<endl<<endl;
}
