#include "Response.h"

/**/
Response::Response() :
_quit(0),
_sleepTime(1000){}

/**/
Response::~Response(){}

/**/
void Response::quit(int quit_){
   this->_quit = quit_;
}

/**/
void  Response::sleepTime(int sleep_){
   this->_sleepTime = sleep_;
}

/**/
void Response::trigger(){}

/**/
void run(){}
