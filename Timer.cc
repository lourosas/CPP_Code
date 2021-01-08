#include "Timer.h"

Timer::Timer() : 
_quit(0),
_sleepTime(0), 
_start(0){}

Timer::Timer(int sleepTime_) :
_sleepTime(0),
_start(0){
   this->sleepTime(sleepTime_);
}

Timer::~Timer(){}

void Timer::quit(int toQuit){
   //Apparently, do not need anything more than this...
   this->_quit = toQuit;  //I think it should be this simple
}

void Timer::run(){
   while(!this->_quit){
      std::unique_lock<std::mutex> lock(this->_mutex);
      while(!this->_start){
         this->_cv.wait(lock);
      }
      std::cout<<"\nTimer::run()\n";
      std::this_thread::sleep_for(std::chrono::milliseconds
                                                  (this->_sleepTime));
      std::cout<<"\nTimer::run()\n";
      while(this->_cv.wait_for(lock, std::chrono::milliseconds(1))
            == std::cv_status::no_timeout){}
   }
}

void Timer::start(int toStart){
   std::unique_lock<std::mutex> lock(this->_mutex);
   if(!this->_start && toStart){
      this->_start = toStart;
      this->_cv.notify_one();
   }
   else{
      this->_start = toStart;
      //this->_cv.notify_one();
   }
}

void Timer::sleepTime(int time){
   this->_sleepTime = time;
}
