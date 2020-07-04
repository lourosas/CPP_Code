/*
*/
//////////////////////////////////////////////////////////////////////
#include <iomanip>
#include <iostream>
#include <climits>
#include "Tree.h"
#include "Node.h"

/**/
Tree::Tree() : 
_root(NULL),
_size(0)
{}

/*
Virtual
This will take some thought--A LOT OF THOUGHT
*/
Tree::~Tree(){
   std::cout<<"\nin the Tree destructor\n";
   if(this->_root){
      delete this->_root;
   }
}

/*
Insert should tell you where in the Tree (kinda) the value is inserted
*/
int Tree::insert(int data){
   int return_value = -1;
   if(!this->peek(data)){
      return_value = this->insert(this->_root, data);
   }
   return return_value;
}

/*
*/
int Tree::remove(int data){
   int return_value = -1;
   if(this->peek(data)){
      return_value = this->remove(this->_root, data);
   }
   return return_value;
}

/*
*/
int Tree::peek(int data){
   return this->peek(this->_root, data);
}

/*
*/
int Tree::insert(Node*& node, int data){
   int level = -1;

   return level;
}

/*
*/
int Tree::remove(Node*& node, int data){
   int level = -1;

   return level;
}

/*
*/
int Tree::peek(Node* node, int data){
   int isFound = 0;

   return isFound;
}

//////////////////////////////////////////////////////////////////////
