#include "ThreadB.h"

using namespace std;

//
//
//
ThreadB::ThreadB() : 
toRun(false),
going(true){}

//
//
//
ThreadB::~ThreadB(){}

//
//
//
void ThreadB::doSomething(){
   while(this->going){
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      thread::id id(this_thread::get_id());
      std::cout<<"id:  "<<hex<<id<<std::endl;
      while(this->toRun){
         std::cout<<"ThreadB::doSomething()\n";
         this_thread::sleep_for(std::chrono::milliseconds(1500));
         this->going = false;
      }
   }
}

//
//
//
void ThreadB::setRun(bool toRun){
   this->toRun = toRun;
}
