#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include "ThreadX.h"

using namespace std;

ThreadX threadX;

enum{
   LOOPS      = 5,
   DELAY      = 2000,
   NUM_THREAD = 10
};

int main(int argc, char* argv[]){
   cout<<"\n\n\nHello World\n\n\n";
   cout<<"Num CPUs:  "<<thread::hardware_concurrency()<<endl<<endl;
   mutex writeMutex;
   //Need to understand this a little bit more
   /*
   thread t0(static_cast<void (ThreadX::*)(int)>(&ThreadX::doSomething), &threadX,1);
   thread t1(static_cast<void (ThreadX::*)(int)>(&ThreadX::doSomething), &threadX, 2);
   thread t2(static_cast<void (ThreadX::*)()>(&ThreadX::doSomething), &threadX);
   thread t3(static_cast<void (ThreadX::*)()>(&ThreadX::doSomething), &threadX);
   thread t4(static_cast<void (ThreadX::*)(int,mutex&)>(&ThreadX::doSomething),&threadX, 3, std::ref(writeMutex));
   thread t5(static_cast<void (ThreadX::*)(int,mutex&)>(&ThreadX::doSomething),&threadX, 4, std::ref(writeMutex));
   this_thread::sleep_for(chrono::milliseconds(DELAY));
   t0.join();
   t1.join();
   t2.join();
   t3.join();
   t4.join();
   t5.join();
   */
   vector<thread> th;

   for(int i = 0; i < NUM_THREAD; i++){
      th.push_back(thread(static_cast<void (ThreadX::*)(int,mutex&)>
            (&ThreadX::doSomething),&threadX,i,std::ref(writeMutex)));
   }
   try{
      vector<thread>::iterator it = th.begin();
      while(it != th.end()){
         (*it).join();
         ++it;
      }
   }
   catch(exception& e){ cout<<endl<<e.what()<<endl; }
   return 0;
}
