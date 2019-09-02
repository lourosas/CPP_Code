#include <iostream>
#include <stdexcept>
#include <ctime>
#include "Calendar.h"

using namespace std;

int main(){
   std::cout<<"\n\n\nHello World\n\n\n";
   Calendar cal;
   //cal.print(std::cout)<<endl;
   std::cout<<cal<<std::endl;
   try{
      //cal.setDate("August 31, 2019");
      //cal.setDate("August 31, 2019, 12:18:38");
      cal.setDate("August 31, 19, 12:18:37");
      //cal.setDate("22/7/2019 12:18", cal.BRITISH);
      std::cout<<cal<<std::endl;
      cal.setDate();
      std::cout<<cal<<std::endl;
      struct tm _time = {0};
      _time.tm_sec    = 0;
      _time.tm_min    = 30;
      _time.tm_hour   = 16;
      _time.tm_year   = 2019 - 1900;
      _time.tm_mday   = 2;
      _time.tm_mon    = 8;
      cal.setDate(mktime(&_time));
      std::cout<<cal<<std::endl;
   }
   catch(std::exception& e){
      std::cout<<e.what()<<std::endl;
   }
   return 0;
}
