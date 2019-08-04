/////////////////////////////////////////////////////////////////////
#include "ThreadX.h"

using namespace std;

//
//
//
ThreadX::ThreadX(){}

//
//
//
ThreadX::~ThreadX(){}

//
//
//
void ThreadX::doSomething(){
   thread::id id(this_thread::get_id());
   cout<<"id:  "<<hex<<id<<endl;
}

//
//
//
void ThreadX::doSomething(int threadNum){
   thread::id id(this_thread::get_id());
   cout<<"Thread Num:  "<<threadNum<<" id:  "<<hex<<id<<endl;
}

//
//
//
void ThreadX::doSomething(int threadNum, mutex& theMutex){
   thread::id id(this_thread::get_id());
   {
   lock_guard<mutex> lg(theMutex);
   cout<<"Thread Num:  "<<threadNum<<" id:  "<<hex<<id<<endl;
   this_thread::sleep_for(chrono::milliseconds(DELAY));
   }
}

/////////////////////////////////////////////////////////////////////
