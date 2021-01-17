#include "Request.h"

/**/
Request::Request():
   _response(0),
   _quit(0),
   _sleepTime(0){}


/**/
Request::~Request(){}

/**/
void Request::quit(int quit_){ this->_quit = quit_; }

/**/
void Request::sleepTime(int sleepTime_){
   this->_sleepTime = sleepTime_;
}

/**/
void Request::run(){}
