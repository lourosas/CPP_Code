//////////////////////////////////////////////////////////////////////
#ifndef CALENDAR_H
#define CALENDAR_H
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <chrono>
#include <string>
#include <cstring>

class Calendar{
   public:
      enum format{STRING, AMERICAN, BRITISH};
      Calendar();
      Calendar(std::string, format form = STRING );
      Calendar(const Calendar& );
      ~Calendar();
      Calendar& operator=(const Calendar& );
      Calendar  operator-(const Calendar& );
      bool isLeapYear();
      std::ostream& print(std::ostream& ) const;
      void setDate(std::string, format form = STRING);
      void setTime(std::string);
   protected:
   private:
      enum{ MONTHS = 12 };
      void parseStringDate(std::string );
      void parseAmericanDate(std::string);
      void parseBritishDate(std::string);
      void setDayOfYear();
      void setIsLeapYear();
      int _year;
      int _month;
      int _day;
      int _dayOfMonth;
      int _hour;
      int _minute;
      int _second;
      long _unixTime;
      bool _isLeapYear;
      static int daysInMonths[MONTHS];
      static int daysInMonthsLeapYear[MONTHS];
      static std::string listOfMonths[MONTHS];
};

std::ostream& operator<<(std::ostream&, const Calendar& );

#endif
//////////////////////////////////////////////////////////////////////
