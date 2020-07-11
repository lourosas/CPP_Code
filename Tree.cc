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
   std::cout<<"\nnode = "<<node<<std::endl;
   if(node){
      if(data > node->data()){
         level = this->insert(node->right, data);
      }
      else if(data < node->data()){
         level = this->insert(node->left, data);
      }
   }
   else{
      node = new Node(data);
      std::cout<<"\nnode = "<<node<<std::endl;
      this->_size++;
      level = this->_size;
   }
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
   if(node){
      if(data > node->data()){
         isFound = this->peek(node->right, data);
      }
      else if(data < node->data()){
         isFound = this->peek(node->left, data);
      }
      else{
         isFound = 1;
      }
   }
   std::cout<<"\nisFound = "<<isFound<<std::endl;
   return isFound;
}

//////////////////////////////////////////////////////////////////////
