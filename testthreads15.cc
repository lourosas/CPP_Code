#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;

std::condition_variable cv;
std::mutex cv_m;
int i     = 0;
bool done = false;

void worker_thread(){
   this_thread::sleep_for(chrono::seconds(1));
   cout<<"Notifiying falsely..."<<i<<endl;

   unique_lock<mutex> lk(cv_m);
   lk.unlock();
   cv.notify_one();
   lk.lock();

   while(!done){
      ++i;
      cout<<"Notifying..."<<i<<endl;
      lk.unlock();
      cv.notify_one();
      this_thread::sleep_for(chrono::seconds(1));
      lk.lock();
   }
}

int main(){
   cout<<"\n\n\nHello World\n\n\n";
   cout<<"Num CPUs:  "<<thread::hardware_concurrency()<<endl;
   thread t1(worker_thread);

   unique_lock<mutex> lk(cv_m);
   cout<<"Waiting...\n";
   cv.wait(lk, []{ return i == 10; });
   cout<<"...finished waiting.  i = "<<i<<endl;
   done = true;

   t1.join();
   return 0;
}
