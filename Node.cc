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
_data(INT_MIN){
   this->data(value);
}

/*
Virtual
Need to think about this to make sure that it workd.
*/
Node::~Node(){
   std::cout<<"in the Node Destructor:  "<<this->data()<<", "
      <<this->left<<", "<<this->right
      <<std::endl;
   if(this->left){
      delete this->left;
      this->left = NULL;
   }
   if(this->right){
      delete this->right;
      this->right = NULL;
   }
}

/*
*/
int Node::data(){
   return this->_data;
}

/*
*/
std::ostream& Node::print(std::ostream& os){
   if(this->left){
      this->left->print(os);
   }
   os<<this->data()<<":";
   if(this->right){
      this->right->print(os);
   }
   return os;
}

/*
*/
void Node::data(int value){
   this->_data = value;
}
/////////////////////////Function Definitions/////////////////////////
/**/
std::ostream& operator<<(std::ostream& os, Node& node){
   return node.print(os);
}

//////////////////////////////////////////////////////////////////////
