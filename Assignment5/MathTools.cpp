//The implementation code of the MathTools class
//By Lou Rosas
//Class implementation of the MathTools.h file

#include "MathTools.h"
#include "LinkedList.h"
//#include "Generic.h"
#include <math.h>

//Must declare statics in the implementation file!!
LinkedList<long> MathTools::primes;

//Public Methods
/*******************************************************************
* The public method to set up the Prime Number linked list
* Calls:  MathTools::makePrimesList()
*******************************************************************/
int MathTools::setUpPrimes(int number)
{
   int return_value = 0;
   int input_number = number;
   
   //If not a proper number input ASSUME the user made a mistake
   //and sets the number of primes in the list to 10.  This minimal
   //number can be changed as needed.
   if(input_number <= 0)
      input_number = MINIMAL;
   
   //Call MathTools::makePrimesList() to actually make the list
   //of prime numbers   
   return_value = makePrimesList(input_number);   
   return return_value;
}

/********************************************************************
* This method gets the Next prime number given the input number.
* It allows for any number of input:  The input number DOES NOT
* have to be prime.  This method also accounts for numbers < 1.
********************************************************************/
int MathTools::getNextPrime(int number)
{
   int return_number = 1;
   
   //If the number is not greater than 0, send back 1 (since that
   //would be the next or closest prime)
   if(number > 0)
   {
      //Good Programming practice:  never alter an input argument
      return_number = number;
      if(return_number == 1 || return_number == 2)
         return_number += 1;
      //If the number is not 1 or 2, determine if the number
      //is even or odd.  If even, add 1 to the number, if odd,
      //add 2.  From this point on, the only primes are odd:  no
      //reason to check for even numbered primes.
      else
      {
         do{
            if(!(return_number % 2))
               return_number += 1;
            else
               return_number += 2;
         }while(!(isPrime(return_number)));
      }
      
   }
   return return_number;
}


/*******************************************************************
* This method is to check whether the input number is prime.  This
* method is a hybird of two methodologies of finding the prime:
* looking to see if the number is in the primes list previously set
* and determining if the number is is prime by itteration.  The
* itteration method is actually the only thing that is needed, but
* the attempt to find the number in the primes list was added by me
* for the sake of my forbidden pride and an attempt to use the 
* primes list in some fashion.
*******************************************************************/
bool MathTools::isPrime(int is_prime)
{
   bool return_value = FALSE;
   
   //If the number is not greater than 0, it is not prime
   if(is_prime > 0)
   {
      //Numbers 1, 2 and 3 are prime, just return true
      if(is_prime > 3)
      {
         //Even numbers > 2 are not prime.
         if(is_prime % 2)
	 {
	    int last_index = primes.getSize() - 1;
	    //If the primes list does not exist OR the number
	    //in question is larger than the last entry in the list,
	    //Use the iteration method.
	    if((last_index < 0) || 
	        (is_prime > primes.peek(last_index)))
	    {
	       int prime = is_prime % 2;
	       for(int x = 3; prime && x < is_prime/2; x+=2)
	          prime = is_prime % x;
	       return_value = (bool)(!(!prime));
	    }
	    //If the number is the last entry in the list,
	    //no reason to itterate through the entire list.
	    else if(is_prime == primes.peek(last_index))
	       return_value = TRUE;
	    //There is a list that exeists, and the number
	    //could be in the list, check the enteries in the
	    //list to find out
	    else
	    {
	       int counter = 0;
	       while((primes.peek(counter)<=is_prime) 
	              && !return_value)
	       {
	          if(primes.peek(counter) == is_prime)
		     return_value = TRUE;
		  ++counter;
	       }
	    }
	 }
	 else
	    return_value = FALSE;
      }
      else
         return_value = TRUE;
   }
   return return_value;
}


/********************************************************************
* This method computes and returns the factorial of an input number
********************************************************************/
long double MathTools::fact(int value)
{
   long double factorial;
   
   if(value == 0 || value == 1)
      factorial = 1;
   else
      factorial = value * fact(value - 1);
      
   return factorial;
}


/********************************************************************
* This method prints out the data in the primes LinkedList
********************************************************************/
void MathTools::displayPrimes()
{
   cout<<endl<<primes<<endl;
}


/********************************************************************
* This method will get the appropriate number in the Fibinacci
* series given the position in that series as input
* i.e.-- MathTools::fibSeriesNumber(6) returns 8 (1 indexed based)
********************************************************************/
int MathTools::fibSeriesNumber(int position)
{
   int series_value   = 1;
   int current_value;
   int previous_value = 0;
   
   for(int i = 2; i <= position; i++)
   {
      current_value = series_value;
      series_value = current_value + previous_value;
      previous_value = current_value;
   }
   return series_value;
}


//Private Method
/********************************************************************
* This method actually makes the Prime number list.  The number of
* primes in the list is based on the input to the method.
********************************************************************/
int MathTools::makePrimesList(int number)
{
   int counter        = 0;
   int current_number = 1;
   int list_counter;
   int setup_number   = number;
   BOOLEAN is_prime;
   int return_number;

   //This method ASSUMES if the input is < 1, the number is faulty,
   //and sets a default number of 10 primes to be added to the list.
   //This minimal number can change as needed.
   if(setup_number < 1)
      setup_number = MINIMAL;
   //Add as many primes to the list as requested.
   while(counter < setup_number)
   {
      //Initialize the list counter to start at the position
      //1 in the list
      list_counter = 1;
      //Set is_prime to true at the begining of each outer
      //itteration
      is_prime = TRUE;
      //IF the current_number is 1 or 2, it is by default prime,
      //don't bother to check.
      if(current_number > 2)
      {
         //Itterate through the entire list, stop the list upon
	 //reaching the end of the list or the current value in
	 //question is not prime: by attempting a % on the value
	 //and the number in the current position in the list.
	 //According to theory, a number is prime, if all the primes
	 //less than the number are not factors of the number.
	 //Therefore, go through all the primes in the list, if
	 //one of the primes divides into the number evenly, that
	 //number is not a prime.
         while((list_counter < primes.getSize()) && (is_prime))
	 {
	    if(!(current_number % primes.peek(list_counter)))
	       is_prime = FALSE;
	    else
	       ++list_counter;
	 }
	 //If the number is a prime, add it to the list and return
	 //the result of adding the value to the list:
	 //0: unsuccessful, 1: successful
	 if(is_prime)
	 {
	    return_number = primes.add((long)current_number);
	    ++counter;
	 }
	 //For any number > 2, only check the odds for prime.
	 current_number += 2;
      }
      else
      {
         return_number = primes.add(current_number);
	 ++current_number;
	 ++counter;
      }
   }
   return return_number;
}
