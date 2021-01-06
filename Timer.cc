#include "Timer.h"

Timer::Timer() : 
_sleepTime(0), 
_start(0){}

Timer::Timer(int sleepTime_) :
_sleepTime(0),
_start(0){
   this->sleepTime(sleepTime_);
}

Timer::~Timer(){}

void Timer::run(){}

void Timer::start(int toStart){
   std::unique_lock<std::mutex> lock(this->_mutex);
   if(!this->_start && toStart){
      this->_start = toStart;
      this->_cv.notify_one();
   }
   else{
      this->_start = toStart;
   }
}
