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
      this->_size++;
      level = this->_size;
   }
   return level;
}

/*
*/
int Tree::remove(Node*& node, int data){
   int level  = -1;
   Node* temp = NULL;
   if(node == this->_root){}//delete root
   else{
      if(data < node->left->data()){
         level = this->remove(node->left, data);
      }
      else if(data > node->right->data()){
         level = this->remove(node->right, data)
      }
      else if(data == node->left->data()){
         temp = node->left;
      }
      else if(data == node->right->data()){
         temp = node->right;
      }
      node->left = temp->left;
      Node* temp2 = node->right;
      while(temp2){
         temp2 = temp2->right;
      }
      temp2->right = temp->right;
      temp->left   = NULL;
      temp->right  = NULL;
      delete temp;
      this->size--;
      level = this->_size;
   }

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
   return isFound;
}

/*
*/
std::ostream& Tree::print(std::ostream& os){
   os<<std::endl<<this->_size<<std::endl<<*(this->_root)<<std::endl;
   return os;
}
///////////////////////Function Definitions///////////////////////////
/**/
std::ostream& operator<<(std::ostream& os, Tree& tree){
   return tree.print(os);
}
//////////////////////////////////////////////////////////////////////
