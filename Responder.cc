#include "Responder.h"

/**/
Responder::Responder() :
_quit(0),
_response(0){}

/**/
Responder::Responder(const Responder& rhs){
   this->_quit     = rhs._quit;
   this->_response = rhs._response;
}

/**/
Responder::~Responder(){}

/**/
Responder& Responder::operator=(const Responder& rhs){
   this->_quit      = rhs._quit;
   this->_response  = rhs._response;
   return *this;
}

/**/
void Responder::quit(int quit){
   this->_quit = quit;
}

/**/
void Responder::triggerResponse(){
   std::unique_lock<std::mutex> lock(this->_mutex);
   this->_response = 1;
   this->_cv.notify_one();
}

/**/
void Responder::respond(){
   while(!this->_quit){
      std::unique_lock<std::mutex> lock(this->_mutex);
      while(!this->_response){
         this->_cv.wait(lock);
      }
      std::cout<<"\nConcurency Sucks in C++\n";
      this->_response = 0;
      while(this->_cv.wait_for(lock,std::chrono::microseconds(1))==
            std::cv_status::no_timeout){}
   }
   std::cout<<"Responder::respond():quit";
}
