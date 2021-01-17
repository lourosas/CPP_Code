#ifndef RESPONSE_H
#define RESPONSE_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class Response{
   public:
      Response();
      virtual ~Response();
      void quit(int );
      void run();
      void sleepTime(int );
      void trigger();
   protected:
   private:
      int                      _quit;
      int                      _triggered;
      int                      _sleepTime;
      std::mutex               _mutex;
      std::condition_variable  _cv;
};

#endif
