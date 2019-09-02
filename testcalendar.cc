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
      cal.setDate("September 4, 2018, 14:15:00");
      /*
      Calendar aCal;
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
      */
      Calendar aCal;
      aCal.setDate();
      long  calUnixTime =  cal.unixTime();
      long acalUnixTime = aCal.unixTime();
      std::cout<<cal<<std::endl<<aCal<<std::endl
        <<difftime(acalUnixTime, calUnixTime)<<std::endl;
      time_t time = (time_t)(difftime(acalUnixTime, calUnixTime));
      std::cout<<time<<std::endl;
      struct tm* ptm = gmtime(&time);
      std::cout
        <<"sec:   "<<ptm->tm_sec<<std::endl
        <<"min:   "<<ptm->tm_min<<std::endl
        <<"hour:  "<<ptm->tm_hour<<std::endl
        <<"mDay:  "<<ptm->tm_mday<<std::endl
        <<"mon:   "<<ptm->tm_mon<<std::endl
        <<"year:  "<<ptm->tm_year<<std::endl
        <<"wday:  "<<ptm->tm_wday<<std::endl
        <<"yday:  "<<ptm->tm_yday<<std::endl
        <<"dst:   "<<ptm->tm_isdst<<std::endl;
   }
   catch(std::exception& e){
      std::cout<<e.what()<<std::endl;
   }
   return 0;
}
