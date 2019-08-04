//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void worker1(){
   for(int i = 0; i < 30; i++){
      cout<<i<<" worker1()\n";
      this_thread::sleep_for(chrono::milliseconds(1000));
   }
}

void worker2(){
   for(int i = 0; i < 30; i++){
      cout<<i<<" worker2()\n";
      this_thread::sleep_for(chrono::milliseconds(2000));
   }
}

int main(){
   cout<<"Hello World\n";
   thread w1(worker1);
   thread w2(worker2);
   cout<<"\nIn the main()\n";
   w1.join();
   w2.join();
   return 0;
}
//////////////////////////////////////////////////////////////////////
