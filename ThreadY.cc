//////////////////////////////////////////////////////////////////////
#include "ThreadY.h"
#include <chrono>

using namespace std;

//
//
//
ThreadY::ThreadY(){}

//
//
//
ThreadY::~ThreadY(){}

//
//
//
void ThreadY::doThis(int threadNum, mutex& theMutex){
   thread::id id(this_thread::get_id());
   {
      lock_guard<mutex> lg(theMutex);
      cout<<"ThreadY, Thread Num:  "<<threadNum
        <<" id: "<<hex<<id<<endl;
      this_thread::sleep_for(chrono::milliseconds(2000));
   }
}
//////////////////////////////////////////////////////////////////////
