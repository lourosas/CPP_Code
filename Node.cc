/*
*/
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Node.h"

/**/
Node::Node(int value) :
left(NULL),
right(NULL),
_data(INT_MIN){}

/*
Virtual
Need to think about this to make sure that it workd.
*/
Node::~Node(){
   std::cout<<"in the Node Desctructor\n";
   if(this->left){
      this->left = NULL;
   }
   if(this->right){
      this->right = NULL;
   }
}

/*
*/
int Node::data(){
   return this->_data;
}

/*
Not really needed
*/
void Node::data(int value){
   this->_data = value;
}
//////////////////////////////////////////////////////////////////////
