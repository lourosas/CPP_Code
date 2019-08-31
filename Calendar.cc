//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <stdexcept>
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
Calendar::Calendar(std::string input, format form)
: _year(0),
  _month(0),
  _day(0),
  _dayOfMonth(0),
  _hour(0),
  _minute(0),
  _second(0),
  _unixTime(0),
  _isLeapYear(false){
   this->setDate(input, form);
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
void Calendar::setDate(std::string input, format form){
   switch(form){
      case STRING:
         this->parseStringDate(input);
         break;
      case AMERICAN:
         this->parseAmericanDate(input);
         break;
      case BRITISH:
         this->parseBritishDate(input);
         break;
      default: ;
   }
}

/**/
void Calendar::setTime(std::string input){}

/////////////////Private Member Functions/////////////////////////////
/**/
void Calendar::parseAmericanDate(std::string input){}

/**/
void Calendar::parseBritishDate(std::string input){}

/*
tring format:  "Month day, year"
Like:  "January 1, 2019"
*/
void Calendar::parseStringDate(std::string input){
   std::vector<std::string> inputVect;
   //more to come on parsing the string!!!
   std::string convert = input;
   for(int i = 0; i < convert.length(); i++){
      convert[i] = toupper(convert[i]);
   }
   //try an istringstream...
   std::istringstream iss(convert);
   std::string indata;
   while(iss>>indata){
      inputVect.push_back(indata);
   }
   if(inputVect.size() < 3){
      throw std::runtime_error(
                            "At Least: \"Month Day, Year format!!\"");
   }
   std::size_t found;
   std::string theMonth = inputVect.at(0);
   std::string theDay   = inputVect.at(1);
   std::string theYear  = inputVect.at(2);
   bool isFound = false;
   int i = 0;
   while(!isFound && i < (int)MONTHS){
      found = theMonth.find(listOfMonths[i]);
      if(found != std::string::npos){
         isFound = true;
         this->_month = i + 1;
      }
      ++i;
   }
   found = theDay.find(",");
   if(found != std::string::npos){
      this->_dayOfMonth = std::stoi(theDay.substr(0,found));
      //Somehow need to convert the day (_day which is the day in
      //the year)!!
   }
   found = theYear.find(",");
   if(found != std::string::npos){
      this->_year = std::stoi(theYear.substr(0,found));
   }
   if(inputVect.size() > 3){
      this->parseTime(inputVect.at(3));
   }
   this->setIsLeapYear();
   this->setDayOfYear();
}

/**/
void Calendar::parseTime(std::string theTime){
   std::size_t found;
   
   found = theTime.find(":");
   if(found != std::string::npos){
      this->_hour = std::stoi(theTime.substr(0,2));
   }
   size_t begin = found + 1;
   this->_minute = std::stoi(theTime.substr(begin,2));
   found = theTime.find(":", begin);
   if(found != std::string::npos){
      this->_second = std::stoi(theTime.substr(found+1,2));
   }
}

/*
Will set the _day field
*/
void Calendar::setDayOfYear(){
   int totalDays = 0;
   for(int i = 0; i < this->_month - 1; i++){
      if(!this->isLeapYear()){
         totalDays += Calendar::daysInMonths[i];
      }
      else{
         totalDays += Calendar::daysInMonthsLeapYear[i];
      }
   }
   totalDays += this->_dayOfMonth;
   this->_day = totalDays;
}

/**/
void Calendar::setIsLeapYear(){
   this->_isLeapYear = false; //for now
   if((!(this->_year % 400)) || 
      ((this->_year % 100)   && (!(this->_year % 4)))){
      this->_isLeapYear = true;
   }
}
//////////////////////////////////////////////////////////////////////

/*
*/
std::ostream& operator<<(std::ostream& os, const Calendar& rhs)
{
   return rhs.print(os);
}
