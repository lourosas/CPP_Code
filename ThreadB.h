#ifndef THREAD_B_H
#define THREAD_B_H
#include <iostream>
#include <iomanip>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

class ThreadB{
   public:
      ThreadB();
      ~ThreadB();
      void doSomething();
      void setRun(bool );
   private:
      bool toRun;
      bool going;
};
#endif
