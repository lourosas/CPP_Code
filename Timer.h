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
      void run();
      void start(int );
   private:
      void sleepTime(int );
      private int                     _sleepTime;
      private int                     _start;
      private std::mutex              _mutex;
      private std::condition_variable _cv;
};
#endif;

