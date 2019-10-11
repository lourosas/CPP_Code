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

std::string Calendar::listOfMonths[Calendar::MONTHS] = {"JAN",
                                                        "FEB",
                                                        "MAR",
                                                        "APR",
                                                        "MAY",
                                                        "JUN",
                                                        "JUL",
                                                        "AUG",
                                                        "SEP",
                                                        "OCT",
                                                        "NOV",
                                                        "DEC"};


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
Calendar::Calendar(time_t date, setting set)
: _year(0),
  _month(0),
  _day(0),
  _dayOfMonth(0),
  _hour(0),
  _minute(0),
  _second(0),
  _unixTime(0),
  _isLeapYear(false){
   this->setDate(date, set);
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
   this->_year       = rhs._year;
   this->_month      = rhs._month;
   this->_day        = rhs._day;
   this->_dayOfMonth = rhs._dayOfMonth;
   this->_hour       = rhs._hour;
   this->_minute     = rhs._minute;
   this->_second     = rhs._second;
   this->_unixTime   = rhs._unixTime;
   this->_isLeapYear = rhs._isLeapYear;
   return *this;
}

/**/
Calendar Calendar::operator-(const Calendar& rhs){
   //Calendar cal;
   //More to come on this...
   long rhsUnixTime = rhs.unixTime();
   time_t time=(time_t)difftime((time_t)this->_unixTime,rhsUnixTime);
   Calendar cal(time, DIFF);
   return cal;
}

///////////////////Public Member Functions////////////////////////////
/**/
int  Calendar::dayOfMonth() const{ return this->_dayOfMonth; }

/**/
int  Calendar::dayOfYear() const{ return this->_day; }

/**/
int  Calendar::hour() const{ return this->_hour; }

/**/
bool Calendar::isLeapYear() const{ return this->_isLeapYear; }

/**/
int  Calendar::minute() const{ return this->_minute; }

/**/
int  Calendar::month() const{ return this->_month; }

/**/
int  Calendar::second() const{ return this->_second; }

/**/
int  Calendar::year() const{ return this->_year; }
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

/*
Set the values to the current date/time
*/
void Calendar::setDate(){
   //Get the current UNIX Time:  the number of seconds since
   //01/01/1970, 00:00:00
   time_t aTime = time(NULL);
   this->setDate(aTime);
}

/**/
void Calendar::setDate(time_t date, setting set){
   struct tm* ptm = NULL;
   if(set != DIFF){
      //Pointer to the Time Structure
      ptm = localtime(&date);
   }
   else{
      ptm = gmtime(&date);
   }
   if(set != DIFF){
      this->_year        = ptm->tm_year + NINETEENHUNDRED;
      this->_month       = ptm->tm_mon + ONE;
      this->_dayOfMonth  = ptm->tm_mday;
      this->setIsLeapYear();
   }
   else{
      this->_year        = ptm->tm_year - SEVENTY;
      this->_month       = ptm->tm_mon;
      this->_dayOfMonth  = ptm->tm_mday - ONE;
   }
   this->_day         = ptm->tm_yday;
   this->_hour        = ptm->tm_hour;
   this->_minute      = ptm->tm_min;
   this->_second      = ptm->tm_sec;
   //Set the Unix time via the Member Function
   this->setUnixTime();
   //Try to avoid the direct set
   //this->_unixTime = date;
}

/*
Throws:  runtime_error, invalid_argument
*/
void Calendar::setDate(std::string input, format form){
   try{
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
   catch(std::runtime_error& e){
      std::string error = e.what();
      error += " Calendar Reset ";
      std::cout<<e.what()<<std::endl<<"Calendar Reset\n";
      this->resetCalendar();
      throw std::runtime_error(error);
   }
   catch(std::invalid_argument& e){
      std::string error = e.what();
      error += " Calendar Reset ";
      std::cout<<e.what()<<std::endl<<"Calendar Reset\n";
      this->resetCalendar();
      throw std::runtime_error(error);
   }
}

/*
Throws:  runtime_error
*/
void Calendar::setTime(std::string input){
   try{
      this->parseTime(input);
   }
   catch(std::invalid_argument& e){
      std::string error = e.what();
      error += " Calendar Reset ";
      std::cout<<e.what()<<std::endl<<"Calendar Reset\n";
      this->resetCalendar();
      throw std::runtime_error(error);
   }
}

/**/
long Calendar::unixTime(){
   return this->_unixTime;
}

/**/
long Calendar::unixTime() const{
   return this->_unixTime;
}

/////////////////Private Member Functions/////////////////////////////
/*
TODO:  Get Rid of Magic Numbers!!!
*/
void Calendar::parseAmericanDate(std::string input){
   std::vector<std::string> inputVect;
   std::istringstream iss(input);
   std::string indata;
   std::size_t found;
   std::size_t begin;

   bool isFound = false;

   while(iss>>indata){
      inputVect.push_back(indata);
   }

   //Get the month/day/year first
   std::string mdy = inputVect.at(0);
   //will need to go ahead and setup some exception handling...
   //this one is going to be a little tougher...
   //need to account for both two and one digit dates
   //need to figure that out...
   found = mdy.find("/");
   if(found != std::string::npos){
      this->_month = std::stoi(mdy.substr(0,found));
      begin = found + 1;
   }
   found = mdy.find("/", begin);
   if(found != std::string::npos){
      int copy = found - begin;
      this->_dayOfMonth = std::stoi(mdy.substr(begin, copy));
      copy = mdy.length() - found - 1;
      this->_year = std::stoi(mdy.substr(found + 1, copy));
   }
   //Try to parse out the time component
   if(inputVect.size() > ONE){
      this->parseTime(inputVect.at(ONE));
   }
   this->setIsLeapYear();
   this->setDayOfYear();
   this->setUnixTime();
   if(this->isLeapYear()){
      if(this->dayOfMonth() > daysInMonthsLeapYear[this->month()-1]){
         std::string error("There are not ");
         error += std::to_string(this->dayOfMonth());
         error += " days in "+ listOfMonths[this->month()-1];
         throw std::runtime_error(error);
      }
   }
   else{
      if(this->dayOfMonth() > daysInMonths[this->month()-1]){
         std::string error("There are not ");
         error += std::to_string(this->dayOfMonth());
         error += " days in "+ listOfMonths[this->month()-1];
         throw std::runtime_error(error);
      }
   }
}

/**/
void Calendar::parseBritishDate(std::string input){
   std::vector<std::string> inputVect;
   std::istringstream iss(input);
   std::string indata;
   std::size_t found;
   std::size_t begin;

   bool isFound  = false;

   while(iss>>indata){ inputVect.push_back(indata); }

   //Get the day/month/year first
   std::string dmy = inputVect.at(ZERO);
   found = dmy.find("/");
   if(found != std::string::npos){
      this->_dayOfMonth = std::stoi(dmy.substr(ZERO,found));
      begin             = found + ONE;
   }
   found = dmy.find("/", begin);
   if(found != std::string::npos){
      int copy = found - begin;
      this->_month = std::stoi(dmy.substr(begin, copy));
      copy = dmy.length() - found - ONE;
      this->_year = std::stoi(dmy.substr(found+ONE, copy));
   }
   //Try to parse out the time component
   if(inputVect.size() > ONE){ this->parseTime(inputVect.at(ONE)); }
   this->setIsLeapYear();
   this->setDayOfYear();
   this->setUnixTime();
}

/*
string format:  "Month day, year"
Like:  "January 1, 2019"
TODO:  Get rid of the Magic Numbers!!!
Throws:  runtime_error
*/
void Calendar::parseStringDate(std::string input){
   bool parseTime = false;
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
   std::vector<std::string>::iterator iter = inputVect.begin();
   while(iter != inputVect.end()){
      std::string data = *iter;
      size_t found = data.find(":");
      if(found != std::string::npos){
         parseTime = true;
      }
      ++iter;
   }
   std::size_t found;
   std::string theMonth = inputVect.at(0);
   std::string theDay   = inputVect.at(1);
   std::string theYear;
   //new part of the algorithm...
   if(inputVect.size() >= 3){
      theYear = inputVect.at(2);
   }
   else{
      char* day = new char[theDay.length() + 1];
      std::strcpy(day, theDay.c_str());
      char* p = strtok(day, ",");
      int loopcounter = 0;
      while(p){
         if(!loopcounter){
            theDay = p;
         }
         else{
            theYear = p;
         }
         p = strtok(NULL,",");
         ++loopcounter;
      }
      delete [] day;
   }
   bool isFound = false;
   int i        = 0;
   while(!isFound && i < (int)MONTHS){
      found = theMonth.find(listOfMonths[i]);
      if(found != std::string::npos){
         isFound = true;
         this->_month = i + 1;
      }
      ++i;
   }
   if(!isFound){
      std::string s = theMonth + " does not exist! Please try again";
      throw std::runtime_error(s);
   }
   this->_dayOfMonth = std::stoi(theDay);
   this->_year = std::stoi(theYear);
   if(parseTime){
      this->parseTime(inputVect.at(inputVect.size()-1));
   }
   this->setIsLeapYear();
   this->setDayOfYear();
   this->setUnixTime();
   if(this->isLeapYear()){
      if(this->dayOfMonth() > daysInMonthsLeapYear[this->month()-1]){
         std::string error("There are not ");
         error += std::to_string(this->dayOfMonth());
         error += " days in "+ listOfMonths[this->month()-1];
         throw std::runtime_error(error);
      }
   }
   else{
      if(this->dayOfMonth() > daysInMonths[this->month()-1]){
         std::string error("There are not ");
         error += std::to_string(this->dayOfMonth());
         error += " days in "+ listOfMonths[this->month()-1];
         throw std::runtime_error(error);
      }
   }
}

/*
TODO:  Get rid of the Magic Numbers!!
*/
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
*/
void Calendar::resetCalendar(){
   this->_year       = 0;
   this->_month      = 0;
   this->_day        = 0;
   this->_dayOfMonth = 0;
   this->_hour       = 0;
   this->_minute     = 0;
   this->_second     = 0;
   this->_unixTime   = 0;
   this->_isLeapYear = 0;
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


/**/
void Calendar::setUnixTime(){
   //Need to create a time_t
   //and make sure it is exactly what it needs to be...
   struct tm _tm;
   _tm.tm_year = this->_year - NINETEENHUNDRED;
   _tm.tm_mon  = this->_month - ONE;
   _tm.tm_mday = this->_dayOfMonth;
   _tm.tm_yday = this->_day;
   _tm.tm_hour = this->_hour;
   _tm.tm_min  = this->_minute;
   _tm.tm_sec  = this->_second;

   time_t time = mktime(&_tm);

   this->_unixTime = time;
}
//////////////////////////////////////////////////////////////////////

/*
*/
std::ostream& operator<<(std::ostream& os, const Calendar& rhs)
{
   return rhs.print(os);
}
