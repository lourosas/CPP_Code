#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include "ThreadB.h"

using namespace std;

ThreadB threadB;

int main(){
   cout<<"\n\n\nHello World\n\n\n";
   cout<<"Num CPUs:  "<<thread::hardware_concurrency()<<endl<<endl;

   thread t0(
      static_cast<void (ThreadB::*)()>(&ThreadB::doSomething),
      &threadB);
   this_thread::sleep_for(chrono::seconds(10));
   threadB.setRun(true);
   this_thread::sleep_for(chrono::seconds(20));
   threadB.setRun(false);
   t0.join();
   return 0;
}
