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
void Responder::triggerResponse(){}

/**/
void Responder::respond(){}
