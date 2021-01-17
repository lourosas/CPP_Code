#include "Response.h"

/**/
Response::Response() :
_quit(0),
_triggered(0),
_sleepTime(500){}

/**/
Response::~Response(){}

/**/
void Response::quit(int quit_){
   this->_quit = quit_;
}

/**/
void Response::run(){
   while(!this->_quit){
      std::unique_lock<std::mutex> lock(this->_mutex);
      while(!this->_triggered){
         this->_cv.wait(lock);
      }
      std::cout<<"\n\nResponse::run()\n";
      this->_triggered = 0;
      while(this->_cv.wait_for(lock,std::chrono::microseconds(1))==
            std::cv_status::no_timeout){}
   }
}

/**/
void  Response::sleepTime(int sleep_){
   this->_sleepTime = sleep_;
}

/**/
void Response::trigger(){
   std::unique_lock<std::mutex> lock(this->_mutex);
   this->_triggered = 1;
   this->_cv.notify_one();
}
