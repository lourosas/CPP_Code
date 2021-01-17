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
      ~Request();
      quit(int );
      run();
      sleepTime(int);
   protected:
   private:
      Response*               _response;
      int                     _quit;
      int                     _sleepTime;
      std::mutex              _mutex;
      std::condition_variable _cv;
};

#endif
