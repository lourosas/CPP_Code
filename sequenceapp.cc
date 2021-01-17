#include "Keeper.h"
#include "Responder.h"
#include "Request.h"
#include "Response.h"

int main(){
   std::cout<<"Hello World\n";
   /*
   Responder* r = new Responder();
   //Keeper* k  = new Keeper(*r);
   Keeper* k  = new Keeper(r);
   k->sleepTime(2000);
   std::thread th0(&Keeper::run, k);
   std::thread th1(&Responder::respond, r);
   std::this_thread::sleep_for(std::chrono::seconds(10));
   //r->triggerResponse();
   k->quit(1);
   r->quit(1);
   if(r != nullptr){ delete r;}
   if(k != nullptr){ delete k; }
   th1.join();
   th0.join();
   */
   Request* r = new Request();
   std::thread th0(&Request::run, r);
   std::this_thread::sleep_for(std::chrono::hours(24));
   r->quit(1);
   if(r != nullptr){ delete r; }
   th0.join();
   return 0;
}
