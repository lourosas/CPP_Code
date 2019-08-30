#ifndef THREAD_A_H
#define THREAD_A_H
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include "ThreadZ.h"

class ThreadA{
   public:
      ThreadA();
      ~ThreadA();
      void doWaits(std::mutex&, std::condition_variable&, ThreadZ& );
   private:
};
#endif
