#include "Keeper.h"

/**/
/*
Keeper::Keeper() :
_responder(0),
_quit(0),
_sleepTime(0)
{}
*/

/**/
Keeper::Keeper(Responder* responder) :
_responder(0),
_quit(0),
_sleepTime(0)
{
   this->_responder = responder;
}

/**/
Keeper::~Keeper(){
   /*
   if(this->_responder != nullptr){
      this->_responder = nullptr;
   }
   */
}

/**/
void Keeper::quit(int quit_){
   this->_quit = quit_;
}

/**/
void Keeper::run(){
   while(!this->_quit){
      std::cout<<"\nWhat the fuck?";
      std::unique_lock<std::mutex> lock(this->_mutex);
      if(this->_responder != nullptr){
         this->_responder->triggerResponse();
      }
      std::this_thread::sleep_for(
                         std::chrono::milliseconds(this->_sleepTime));
      while(this->_cv.wait_for(lock,std::chrono::microseconds(1))==
            std::cv_status::no_timeout){}
   }
   this->_responder->quit(1);
   this->_responder->triggerResponse();
}

/**/
void Keeper::sleepTime(int time){
   this->_sleepTime = time;
}
