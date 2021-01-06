#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class Timer{
   public:
      Timer();
      Timer(int );
      ~Timer();
      void quit(int );
      void run();
      void start(int );
   private:
      void sleepTime(int );
      int                     _quit;
      int                     _sleepTime;
      int                     _start;
      std::mutex              _mutex;
      std::condition_variable _cv;
};
#endif

