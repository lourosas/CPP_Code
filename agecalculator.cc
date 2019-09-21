//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <stdexcept>
#include <cstring>
#include "Calendar.h"

std::string name;

void playDate()
{
   bool errorFound;
   int  badCount = 0;
   Calendar date;
   Calendar current;
   char cBday[256];
   std::string bday;
   do{
      errorFound = false;
      try
      {
         std::cout<<"\n\nEnter your birthdate in 'Month, Day Year' "
           <<"format: (Like January 1, 2001)\n";
         std::cin.getline(cBday, 256);
         bday = cBday;
         date.setDate(bday);
         current.setDate();
         Calendar currentLength = current - date;
         std::cout<<std::endl<<name
           <<", you have been alive for:  "<<currentLength.year()
           <<" years, "
           <<currentLength.dayOfYear()<<" days, "
           <<currentLength.hour()
           <<" hours, "<<currentLength.minute()<<" minutes, "
           <<currentLength.second()<<" seconds\n";
         badCount = 0;
      }
      catch(std::runtime_error& e){
         std::cout<<"Please enter the date in the approriate format "
           <<"with a Month, Day and Year\n\n";
         ++badCount;
         errorFound = true;
      }
      catch(std::invalid_argument& e){
         std::cout<<"Please enter the date in the approriate format "
           <<"with a Month, Day and Year\n\n";
         ++badCount;
         errorFound = true;
      }
   }while(errorFound && badCount < 3);
   if(badCount){
      std::cout<<"\n\nIt appears you are having trouble entering your "
        <<"birthday, exiting\n\n";
   }
}

void splashScreen()
{
   std::cout<<"\nIn this program, you will enter your birthdate, to "
      <<"\ndetermine how long you have been alive\n";
}

int main()
{
   char cname[256];
   std::cout<<"\n\n\nHello World!\n\n\n";
   std::cout<<"What is your name:  ";
   std::cin.getline(cname, 256);
   name = cname;
   std::cout<<"Hello "<<name<<std::endl;
   splashScreen();
   playDate();
   return 0;
}
//////////////////////////////////////////////////////////////////////
