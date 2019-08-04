/////////////////////////////////////////////////////////////////////
#ifndef THREAD_X_H
#define THREAD_X_H
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>

class ThreadX{
   public:
      ThreadX();
      ~ThreadX();
      void doSomething();
      void doSomething(int );
      void doSomething(int, std::mutex& );
      enum{ DELAY = 3000 };
   private:
};

#endif
/////////////////////////////////////////////////////////////////////
