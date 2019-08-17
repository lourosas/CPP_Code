//////////////////////////////////////////////////////////////////////
#ifndef THREAD_Y_H
#define THREAD_Y_H
#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>

class ThreadY{
   public:
      ThreadY();
      ~ThreadY();
      void doThis(int, std::mutex& );
   private:
};

#endif
//////////////////////////////////////////////////////////////////////
