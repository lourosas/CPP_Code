#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Response.h"

class Request{
   public:
      Request();
      virtual ~Request();
      void quit(int );
      void sleepTime(int);
   protected:
   private:
      void run();
      Response*               _response;
      int                     _quit;
      int                     _sleepTime;
      std::mutex              _mutex;
      std::condition_variable _cv;
      std::thread             _th;
};

#endif
