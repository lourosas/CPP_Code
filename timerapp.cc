#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Timer.h"

int main(){
   std::cout<<"Hello World\n";
   Timer* t0 = new Timer(1000);
   //Timer* t1 = new Timer(500);
   std::thread th0(&Timer::run, t0);
   //std::thread th1(&Timer::run, t1);
   std::this_thread::sleep_for(std::chrono::seconds(2));
   t0->start(1);
   std::this_thread::sleep_for(std::chrono::seconds(5));
   t0->quit(0);
   std::this_thread::sleep_for(std::chrono::seconds(5));
   t0->quit(1);
   std::this_thread::sleep_for(std::chrono::seconds(5));
   t0->quit(0);
   //t0->quit(0);
   //t1->start(1);
   if(t0 != nullptr){ delete t0; }
   //if(t1 != nullptr){ delete t1; }
   th0.join();
   //th1.join();
   return 0;
}
