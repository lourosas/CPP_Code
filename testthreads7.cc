#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex theMutex;
condition_variable cv;
string data;
bool ready     = false;
bool processed = false;

void worker_thread()
{
   //Wait until main() sends data
   unique_lock<mutex> lg(theMutex);
   cv.wait(lg, []{return ready;});

   //after the wait, we own the lock
   cout<<"Worker thread is processing data\n";
   data += " after processing ";

   this_thread::sleep_for(chrono::milliseconds(2000));

   //send the data back to main()
   processed = true;
   cout<<"Worker thread signals data processing is completed\n";

   this_thread::sleep_for(chrono::milliseconds(3000));

   //Manual unlocking is done before notifying, to avoid waking up
   //the waiting thread only to block again (see notify_one() for
   //details)
   lg.unlock();
   cv.notify_one();
}

int main()
{
   thread theThread(worker_thread);

   data = "Example Data";
   //Send data to the worker thread
   {
      lock_guard<mutex> lg(theMutex);
      ready = true;
      cout<<"main() signals data is ready for some processing\n";
   }

   cv.notify_one();

   //wait for the worker
   {
      unique_lock<mutex> lg(theMutex);
      cv.wait(lg, []{return processed;});
   }
   cout<<"Back in the main(), data = "<<data<<"\n";
   
   theThread.join();
   return 0;
}
