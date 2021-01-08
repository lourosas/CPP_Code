#ifndef KEEPER_H
#define KEEPER_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Responder.h"

class Keeper{
   public:
      Keeper();
      Keeper(Responder );
      ~Keeper();
      void quit(int );
      void run();
      void sleepTime(int );
   protected:
   private:
      Responder               _responder;
      int                     _quit;
      int                     _sleepTime;
      std::mutex              _mutex;
      std::condition_variable _cv;
};
#endif

