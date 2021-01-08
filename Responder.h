#ifndef RESPONDER_H
#define RESPONDER_H
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class Responder{
   public:
      Responder();
      ~Responder();
      void quit(int );
      void triggerResponse()
   protected:
   private:
      int                     _quit;
      std::mutex              _mutex;
      std::condition_variable _cv;
      void respond();
};
#endif
