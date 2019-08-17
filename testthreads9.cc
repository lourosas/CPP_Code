#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include "ThreadX.h"
#include "ThreadY.h"

using namespace std;

ThreadX threadX;
ThreadY threadY;

enum{
   LOOPS       = 5,
   DELAY       = 2000,
   NUM_THREADS = 10
};

int main(){
   cout<<"\n\n\nHello World\n\n\n";
   cout<<"Num CPUs:  "<<thread::hardware_concurrency()<<endl<<endl;
   mutex theMutex;
   vector<thread> th;

   for(int i = 0; i < NUM_THREADS; i++){
      th.push_back(thread(static_cast<void (ThreadX::*)(int,mutex&)>
             (&ThreadX::doSomething),&threadX,i,std::ref(theMutex)));
      th.push_back(thread(static_cast<void (ThreadY::*)(int,mutex&)>
                  (&ThreadY::doThis),&threadY,i,std::ref(theMutex)));
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
