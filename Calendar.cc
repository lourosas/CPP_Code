//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include "Calendar.h"

int Calendar::daysInMonths[Calendar::MONTHS] =         {31,28,31,30,
                                                         31,30,31,31,
                                                         30,31,30,31};
int Calendar::daysInMonthsLeapYear[Calendar::MONTHS] = {31,29,31,30,
                                                         31,30,31,31,
                                                         30,31,30,31};
std::string Calendar::listOfMonths[Calendar::MONTHS] = {"JANUARY",
                                                        "FEBRUARY",
                                                        "MARCH",
                                                        "APRIL",
                                                        "MAY",
                                                        "JUNE",
                                                        "JULY",
                                                        "AUGUST",
                                                        "SEPTEMBER",
                                                        "OCTOBER",
                                                        "NOVEMBER",
                                                        "DECEMBER"};


/**/
Calendar::Calendar()
: _year(0),
  _month(0),
  _day(0),
  _dayOfMonth(0),
  _hour(0),
  _minute(0),
  _second(0),
  _unixTime(0),
  _isLeapYear(false){}

/**/
Calendar::Calendar(std::string input)
: _year(0),
  _month(0),
  _day(0),
  _dayOfMonth(0),
  _hour(0),
  _minute(0),
  _second(0),
  _unixTime(0),
  _isLeapYear(false){
   this->parseDate(input);
}

/**/
Calendar::Calendar(const Calendar& cal)
: _year(cal._year),
  _month(cal._month),
  _day(cal._day),
  _dayOfMonth(cal._dayOfMonth),
  _hour(cal._hour),
  _minute(cal._minute),
  _second(cal._second),
  _unixTime(cal._unixTime),
  _isLeapYear(cal._isLeapYear){}

/**/
Calendar::~Calendar(){}

////////////////////////Operator Overloading//////////////////////////
/**/
Calendar& Calendar::operator=(const Calendar& rhs){
   //More to come on this....
   return *this;
}

/**/
Calendar Calendar::operator-(const Calendar& rhs){
   //More to come on this...
   Calendar cal;
   return cal;
}

///////////////////Public Member Functions////////////////////////////
/**/
bool Calendar::isLeapYear(){ return this->_isLeapYear; }

/**/
std::ostream& Calendar::print(std::ostream& os) const{
   //This will need to change to some kind of "default format"
   os<<std::setfill('0')
     <<std::setw(2)<<this->_month<<"/"
     <<std::setw(2)<<this->_dayOfMonth<<"/"
     <<std::setw(2)<<this->_year<<"  "
     <<std::setw(2)<<this->_hour<<":"
     <<std::setw(2)<<this->_minute<<":"
     <<std::setw(2)<<this->_second;
   return os;
}

/**/
void Calendar::setDate(std::string input){
   this->parseDate(input);
}

/**/
void Calendar::setTime(std::string input){}

/////////////////Private Member Functions/////////////////////////////
/**/
void Calendar::parseDate(std::string input){
   std::vector<std::string> inputVect;
   //more to come on parsing the string!!!
   std::string convert = input;
   for(int i = 0; i < convert.length(); i++){
      convert[i] = toupper(convert[i]);
   }
   //try an istringstream or ostringstream...
   std::istringstream iss(convert);
   std::string indata;
   while(iss>>indata){
      inputVect.push_back(indata);
   }
   if(inputVect.size() > 1){
      std::vector<std::string>::iterator it = inputVect.begin();
      while(it != inputVect.end()){
         std::string current = *it;
         std::cout<<current<<std::endl;
         //now, have to look at the data
         //Find the Month (or try to)
         for(int i = 0; i < (int)MONTHS; i++){
            std::size_t found = current.find(listOfMonths[i]);
            if(found != str::string::npos){
         
            }
         }
         ++it;
      }
   }
}

/**/
void Calendar::setIsLeapYear(bool isLeapYear){
   this->_isLeapYear = isLeapYear;
}
//////////////////////////////////////////////////////////////////////
