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
int Tree::peek(int data){
   return this->peek(this->_root, data);
}

/*
*/
int Tree::remove(int data){
   int return_value = -1;
   Node* parent = NULL;
   if(this->peek(data)){
      //return_value = this->remove(parent, this->_root, data);
      this->_root = this->remove(this->_root, data);
      return_value = this->_size;
   }
   return return_value;
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
Node* Tree::max(Node* node){
   Node* y = node;
   while(y->right){
      y = y->right;
   }
   return y;
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
Node* Tree::min(Node* node){
   Node* y = node;
   while(y->left){
      y = y->left;
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
//int Tree::remove(Node*& parent, Node*& node, int data){
//int Tree::remove(Node*& parent, Node* node, int data){
//it is very simple--if an input needs to be changed, it NEEDS
//to be passed by reference!!!!!
int Tree::remove(Node* parent, Node* node, int data){
   int level       = -1;
   Node* temp      = NULL;
   Node* temp_node = NULL;

   if(node->data() == data){
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
         if(!parent){
            temp_node = node;
            this->transplant(parent, temp_node, temp);
         }
         else{
            this->transplant(parent, node, temp);
         }
         temp->left = node->left;
      }
      node->left  = NULL;
      node->right = NULL;
      delete node;
      node  = NULL;
      level = --(this->_size);
   }
   else{
      if(data < node->data()){
         level = this->remove(node, node->left, data);
      }
      else{
         level = this->remove(node, node->right, data);
      }
   }
   return level;
}

/*
*/
Node* Tree::remove(Node* root, int data){
   Node* temp = NULL;
   if(data < root->data()){
      root->left = this->remove(root->left, data);
   }
   else if(data > root->data()){
      root->right = this->remove(root->right, data);
   }
   else{
      if(!(root->left)){
         temp = root;
         root = root->right;
         temp->left  = NULL;
         temp->right = NULL;
         delete temp;
         temp = NULL;
         --(this->_size);
      }
      else if(!(root->right)){
         temp = root;
         root = root->left;
         temp->left  = NULL;
         temp->right = NULL;
         delete temp;
         temp = NULL;
         --(this->_size);
      }
      else{
         temp         = this->min(root->right);
         Node* temp2  = new Node(temp->data());
         temp2->left  = root->left;
         temp2->right = root->right;
         root->left   = NULL;
         root->right  = NULL;
         delete root;
         root         = temp2;
         temp2        = NULL;
         root->right  = this->remove(root->right, temp->data());
      }
   }
   return root;
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
