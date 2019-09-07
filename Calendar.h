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
      enum setting{ NORMAL, DIFF };
      Calendar();
      Calendar(std::string, format form = STRING );
      Calendar(time_t , setting set = NORMAL);
      Calendar(const Calendar& );
      ~Calendar();
      Calendar& operator=(const Calendar& );
      Calendar  operator-(const Calendar& );
      int  dayOfMonth() const;
      int  dayOfYear() const;
      int  hour() const;
      bool isLeapYear() const;
      int  minute() const;
      int  month() const;
      int  second() const;
      int  year() const;
      std::ostream& print(std::ostream& ) const;
      void setDate(); //Set date/time to the current date/time
      //Set date/time to input value
      void setDate(time_t, setting set = NORMAL ); 
      //Throws: runtime_error, invalid_argument
      void setDate(std::string, format form = STRING);
      //Throws: runtime_error
      void setTime(std::string);
      long unixTime();
      long unixTime() const;
   protected:
   private:
      enum{
         ZERO = 0, ONE, TWO, THREE, MONTHS = 12, SEVENTY = 70,
         NINETEENHUNDRED = 1900 };
      //Throws:  runtime_error
      void parseStringDate(std::string );
      void parseAmericanDate(std::string );
      void parseBritishDate(std::string );
      void parseTime(std::string );
      void resetCalendar();
      void setDayOfYear();
      void setIsLeapYear();
      void setUnixTime();
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
