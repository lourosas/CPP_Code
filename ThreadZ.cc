#include "ThreadZ.h"

//
//
//
ThreadZ::ThreadZ():count(0), done(false){}

//
//
//
ThreadZ::~ThreadZ(){}

//
//
//
void ThreadZ::doSomething(std::mutex& m,std::condition_variable& cv){
   std::this_thread::sleep_for(std::chrono::seconds(DELAY));

   std::unique_lock<std::mutex> lk(m);
   while(!this->done){
      std::cout<<"Notifying..."<<this->getCount()<<std::endl;
      lk.unlock();
      cv.notify_one();
      std::this_thread::sleep_for(std::chrono::seconds(1));
      lk.lock();
      this->count++;
   }
}

//
//
//
int ThreadZ::getCount() const{
   return this->count;
}

//
//
//
void ThreadZ::setDone(bool isDone){
   this->done = isDone;
}

//
//
//
void ThreadZ::setCount(int count){
   this->count = count;
}
