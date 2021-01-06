#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mutex;
std::condition_variable cv;
int ready = 0;

/**/
void printThreadId()
{
   std::unique_lock<std::mutex> lock(mutex);
   while(!ready)
   {
      cv.wait(lock);
   }
   std::cout<<"\nprintThreadId() value:  "
     <<std::this_thread::get_id()<<std::endl;
   std::this_thread::sleep_for(std::chrono::milliseconds(2000));
   ready = 0;
   cv.notify_one();
}

/**/
void triggerPrint()
{
   std::unique_lock<std::mutex> lock(mutex);
   /*
   while(ready)
   {
      cv.wait(lock);
   }
   */
   std::cout<<"\ntriggerPrint() value:  "
     <<std::this_thread::get_id()<<std::endl;
   std::this_thread::sleep_for(std::chrono::milliseconds(10000));
   ready = 1;
   cv.notify_one();  
}

int main()
{
   std::cout<<"Hello World\n";
   std::thread th(printThreadId);
   //std::thread th1(triggerPrint); //Get rid of as needed...
   triggerPrint();
   std::this_thread::sleep_for(std::chrono::milliseconds(5000));
   std::cout<<"\nmain() value: "
     <<std::this_thread::get_id()<<std::endl;
   th.join();
   //th1.join();

   return 0;
}
