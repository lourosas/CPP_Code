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
      Responder(const Responder& );
      ~Responder();
      Responder& operator=(const Responder& );
      void quit(int );
      void triggerResponse();
   protected:
   private:
      void respond();
      int                     _quit;
      int                     _response;
      std::mutex              _mutex;
      std::condition_variable _cv;
};
#endif
