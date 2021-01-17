#include <cstdlib>
#include <ctime>
#include "Request.h"

/**/
Request::Request():
   _response(0),
   _quit(0),
   _sleepTime(1000){
   this->_response = new Response();
}


/**/
Request::~Request(){
   if(this->_response != nullptr){
      delete this->_response;
   }
}

/**/
void Request::quit(int quit_){ this->_quit = quit_; }

/**/
void Request::run(){
   std::thread th(&Response::run, this->_response);
   std::srand(std::time(nullptr));
   while(!this->_quit){
      std::unique_lock<std::mutex> lock(this->_mutex);
      std::cout<<"\nRequest::run()";
      std::this_thread::sleep_for(
                         std::chrono::milliseconds(this->_sleepTime));
      if(std::rand() % 10000 > 8000){
         this->_response->trigger();
      }
      while(this->_cv.wait_for(lock,std::chrono::microseconds(1)) ==
            std::cv_status::no_timeout){}
   }
   this->_response->trigger();
   this->_response->quit(1);
   std::cout<<std::endl;
   th.join();
}

/**/
void Request::sleepTime(int sleepTime_){
   this->_sleepTime = sleepTime_;
}

