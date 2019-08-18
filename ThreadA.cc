#include "ThreadA.h"

//
//
//
ThreadA::ThreadA(){}

//
//
//
ThreadA::~ThreadA(){}

//
//
//
void ThreadA::doWaits
(
   std::mutex& m,
   std::condition_variable& cv,
   ThreadZ& tz
){
   std::unique_lock<std::mutex> lk(m);
   std::cout<<"Waiting...\n";
   cv.wait(lk, [&tz]{ return tz.getCount() == 1; });
   std::cout<<"...finished waiting. value = "<<tz.getCount()
     <<std::endl;
   tz.setDone(true);
}
