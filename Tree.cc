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
   Node* parent = NULL;
   if(this->peek(data)){
      return_value = this->remove(parent, this->_root, data);
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
Node* Tree::maximum(Node*& node){
   Node* y = node;
   while(y->right){
      node = y;
      y = y->right;
   }
   return y;
}

/*
*/
Node* Tree::minimum(Node*& node){
   Node* y = node;
   while(y->left){
      node = y;
      y = y->left;
   }
   return y;
}

/*
*/
//int Tree::remove(Node*& parent, Node*& node, int data){
//int Tree::remove(Node*& parent, Node* node, int data){
int Tree::remove(Node* parent, Node* node, int data){
   int level       = -1;
   Node* temp      = NULL;
   Node* temp_node = NULL;
   
   if(data < node->left->data()){
      level = this->remove(node, node->left, data);
   }
   else if(data > node->right->data()){
      level = this->remove(node, node->right, data);
   }
   //Found the node, now time to remove
   else{
      if(!(node->left)){
         this->transplant(parent, node, node->right);
      }
      else if(!(node->right)){
         this->transplant(parent, node, node->left);
      }
      else{
         Node* temp_parent = node->right;
         temp = this->minimum(temp_parent);
         if(node->right != temp){
            this->transplant(temp_parent, temp, temp->right);
            temp->right = node->right;
         }
         if(!parent){//Root node slightly different when moved...
            temp_node = node;
            this->transplant(parent, temp_node, temp);
         }
         else{
            this->transplant(parent, node, temp);
         }
         temp->left  = node->left;
      }
      node->left  = NULL;
      node->right = NULL;
      delete node;
      node = NULL;
      level = --(this->_size);
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


/*
*/
void Tree::transplant(Node*& parent, Node* x, Node* y){
   if(!parent){
      this->_root = y;
   }
   else if(parent->left == x){
      parent->left = y;
   }
   else{
      parent->right = y;
   }
}

///////////////////////Function Definitions///////////////////////////
/**/
std::ostream& operator<<(std::ostream& os, Tree& tree){
   return tree.print(os);
}
//////////////////////////////////////////////////////////////////////
