//A generic math tool class by Lou Rosas
//Part of the word for CIS 269 and my desire to create
//a generic set of tools for everyday programming
//A class by Lou Rosas

#ifndef MATH_TOOLS_H
#define MATH_TOOLS_H

#include <math.h>
#include "LinkedList.h"
//#include "Generic.h"

class MathTools
{
   public:
      //Setup up a series of prime numbers
      static int setUpPrimes(int );

      //Get the next prime greater than the input number
      static int getNextPrime(int );

      //Check to se if a value is prime
      static bool isPrime(int );

      //A simple factorial routine
      static long double fact(int );

      //Display the primes LinkedList
      static void displayPrimes();

      //Get a Fibinacci Sequence number given the position
      //in the sequence
      static unsigned long fibSeriesNumber(int );

   private:
      //Private method to actually make the prime number list
      static int makePrimesList(int );

      //The LinkedList used to store the primes currently generated
      static LinkedList<long> primes;

      //If no number of primes is set up, set up at least 10 in the
      //LinkedList
      static const int MINIMAL = 10;
};

#endif
