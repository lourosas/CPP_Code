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
   Calendar date;
   Calendar current;
   char cBday[256];
   std::string bday;
   std::cout<<"\n\nEnter your birthdate in 'Month, Day Year' "
      <<"format: (Like January 1, 2001)\n";
   std::cin.getline(cBday, 256);
   bday = cBday;
   try
   {
      date.setDate(bday);
      current.setDate();
      Calendar currentLength = current - date;
      std::cout<<std::endl<<name<<std::endl
         <<"You have been alive:  "<<currentLength.year()<<" years, "
         <<currentLength.dayOfYear()<<" days, "<<currentLength.hour()
         <<" hours, "<<currentLength.minute()<<" minutes, "
         <<currentLength.second()<<" seconds\n";
   }
   catch(std::runtime_error& e){  }
   catch(std::invalid_argument& e){ }
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
