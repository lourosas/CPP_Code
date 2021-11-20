//The test program for BasicHashTable and BasicHashElement

//#include "Generic.h"
#include "BasicHashTable.h"
#include "BasicHashElement.h"
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <strstrea.h>

int parse(char*, int* );
long folding(int* , int);

int main()
{
   char* key = "411278905392";
   int num_non_char = 0;
   for(int i = 0; i < strlen(key); i++)
   {
      if(key[i] > '9' || key[i] < '0')
         ++num_non_char;
   }
   if(!num_non_char) cout<<"\nThey are all numbers!!!";
   int   value[150];
   int counter = parse(key,value);
   for(int i = 0; i < counter; i++)
      cout<<"\nvalue["<<i<<"]: "<<value[i];
   cout<<endl<<folding(value, counter);
   cout<<"\n\n\n\nType any key to continue:  "; getch();
   return 1;
}

int parse(char* key, int* result)
{
   char* temp = new char[strlen(key) + 1];
   strcpy(temp,key);
   bool is_odd_size = (bool)(strlen(temp) % 2);

   int counter = 0;

   int temp_value;
   char* current_string = temp + (strlen(key) - 2);
   cout<<"\ntemp: "<<temp<<"\nstrlen(temp): "<<strlen(temp);
   while(current_string >= temp)
   {
      istrstream is(current_string, 2);

      is>>temp_value;
      cout<<"\ncurrent_string: "<<current_string
        <<"\ntemp_value: " <<temp_value;
      result[counter] = temp_value;

      current_string -= 2;
      counter++;
   }
   if(is_odd_size)
   {
      cout<<"\ntemp is odd!";
      current_string = temp;
      istrstream is(current_string, 1);
      is>>temp_value;
      cout<<"\ncurrent_string: "<<current_string
        <<"\ntemp_value: " <<temp_value;
      result[counter] = temp_value;

      counter++;
   }
   delete [] temp;
   temp = NULL;
   current_string = NULL;
   for(int i = 0; i < counter; i++)
      cout<<"\nresult["<<i<<"]: "<<result[i];
   return counter;
}

long folding(int* numbers, int indices)
{
   int counter = 0;

   long return_value = -1;

   int temp;
   int temp1 = 0;
   int temp2 = 1;

   while(counter < indices)
   {
      if(counter < 2)
      {
         temp1 += numbers[counter];
      }
      else
      {
         temp2 *= numbers[counter];
      }
      ++counter;
   }
   temp = temp1;
   if(counter > 2)
   {
      temp += temp2;
   }
   return_value = temp;
   cout<<"\ntemp: "<<temp<<"\ntemp1: "<<temp1<<"\ntemp2: "<<temp2;

   return return_value;
}



