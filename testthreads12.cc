#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex theMutex;
condition_variable cv;
string theData;
int loopValue  =     0;
bool ready     = false;
bool done      = false;

void worker_thread(){
   //Wait until main() sends data
   unique_lock<mutex> lg(theMutex);
   cv.wait(lg, []{ return ready; });

   this_thread::sleep_for(chrono::milliseconds(3000));

   //after the wait, we own the lock
   cout<<"Worker thread is going to process through the loop\n";

   cout<<"Notifying falsely...\n";
   cv.notify_one();

   loopValue = 1;
   while(!done){
      cout<<"Notifying true change...\n";
      lg.unlock();
      cv.notify_one();
      this_thread::sleep_for(chrono::milliseconds(1000));
      lg.lock();
   }
   theData += " after processing ";
}

int main(){
   thread theThread(worker_thread);

   theData = "Example Data";
   //send data to the working thread
   {
      lock_guard<mutex> lg(theMutex);
      ready = true;
      cout<<"main() signals data is ready for some processing\n";
   }

   cv.notify_one();

   //wait for the worker to get to a loopValue = 10
   //will this work??
   {
      unique_lock<mutex> lg(theMutex);
      cout<<"Waiting...\n";
      cv.wait(lg, [] { return (loopValue == 1); });
   }
   cout<<"...finished waiting...loopValue = 1\n";
   done = true;
   cout<<"Back in the main(), data = "<<theData<<endl;

   theThread.join();
   return 0;
}
