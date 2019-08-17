//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

enum{
   LOOPS       =    5,
   DELAY       = 2000,
   NUM_THREADS =    3
};

void func(int threadNum, mutex& theMutex){
   thread::id id(this_thread::get_id());
   cout<<"Launched in thread "<<threadNum<<" , id: "<<hex<<id<<endl;
   {
   lock_guard<mutex> lg(theMutex);
   for(int i = 0; i < LOOPS; ++i){
      //lock_guard<mutex> lg(theMutex);
      cout<<"thread: "<<threadNum<<" id:  "<<id<<" , count = "
         <<i<<endl;
      this_thread::sleep_for(chrono::milliseconds(DELAY));
   }
   }
}

int main(int argc, char* argv[]){
   cout<<"\n\n\nHello World\n\n\n";
   cout<<"Num CPUs:  "<<thread::hardware_concurrency()<<endl;
   
   vector<thread> th;
   mutex writeMutex;

   for(int i = 0; i < NUM_THREADS; i++){
      th.push_back(thread(func,i,ref(writeMutex)));
   }

   try{
      vector<thread>::iterator it = th.begin();
      while(it != th.end()){
         //thread t = *it;
         //t.join();
         (*it).join();
         ++it;
      }
   }
   catch(exception& e){
      cout<<endl<<e.what()<<endl;
   }
   return 0;
}
//////////////////////////////////////////////////////////////////////
