//////////////////////////////////////////////////////////////////////
#ifndef CALENDAR_H
#define CALENDAR_H
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
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
      int  dayOfYear();
      bool isLeapYear();
      std::ostream& print(std::ostream& ) const;
      void setDate(); //Set date/time to the current date/time
      void setDate(time_t ); //Set date/time to the input value
      void setDate(std::string, format form = STRING);
      void setTime(std::string);
   protected:
   private:
      enum{
         ZERO = 0, ONE, TWO, THREE, MONTHS = 12,
         NINETEENHUNDRED = 1900 };
      void parseStringDate(std::string );
      void parseAmericanDate(std::string );
      void parseBritishDate(std::string );
      void parseTime(std::string );
      void resetCalendar();
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
