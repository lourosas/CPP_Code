#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>
#include "ThreadA.h"
#include "ThreadZ.h"

using namespace std;

ThreadZ threadZ;
ThreadA threadA;

int main(){
   cout<<"\n\n\nHello World\n\n\n";
   cout<<"Num CPUs:  "<<thread::hardware_concurrency()<<endl<<endl;
   mutex m;
   condition_variable cv;

   thread t0(static_cast<void (ThreadZ::*)(mutex&,condition_variable&)>
              (&ThreadZ::doSomething),&threadZ,std::ref(m),std::ref(cv));
   thread t1(static_cast<void (ThreadA::*)(mutex&,condition_variable&,ThreadZ&)>
          (&ThreadA::doWaits),&threadA,std::ref(m),std::ref(cv),std::ref(threadZ));

   t0.join();
   t1.join();
   return 0;
}
