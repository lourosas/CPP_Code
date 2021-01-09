#include "Keeper.h"

/**/
Keeper::Keeper() :
_quit(0),
_sleepTime(0){}

/**/
Keeper::Keeper(Responder responder) :
_quit(0),
_sleepTime(0){
   this->_responder = responder;
}

/**/
Keeper::~Keeper(){}

/**/
void Keeper::quit(int quit_){
   this->_quit = quit_;
}

/**/
void Keeper::run(){
   std::unique_lock<std::mutex> lock(this->_mutex);
   while(!this->_quit){
      this->_responder.triggerResponse();
      std::this_thread::sleep_for(
                         std::chrono::milliseconds(this->_sleepTime));
      while(this->_cv.wait_for(lock,std::chrono::microseconds(500))==
            std::cv_status::no_timeout){}
   }
}

/**/
void Keeper::sleepTime(int time){
   this->_sleepTime = time;
}
