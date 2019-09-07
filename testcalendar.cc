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
      //Need to change the string comparison to
      //accomodate abbreviations
      //cal.setDate("September 2, 1968, 14:15:00");
      cal.setDate("September 1, 2018 12:20:30");
      //cal.setDate("04/09/2018", Calendar::BRITISH);
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
      aCal.setDate("September 4, 2019 13:20:31");
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
      Calendar bCal;
      bCal = aCal - cal;
      std::cout<<bCal<<std::endl;
   }
   catch(std::exception& e){
      std::cout<<e.what()<<std::endl;
   }
   return 0;
}
