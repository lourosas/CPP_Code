/*********************************************************************
*********************************************************************/
//////////////////////////////////////////////////////////////////////
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include <string>
#include "TreeNode.h"

template <class T>
class BinaryTree
{
   public:
      BinaryTree();
      virtual ~BinaryTree();
      virtual TreeNode<T> get(T ); //Throws:  std::string
      virtual int insert(T );      //Throws:  std::string
      virtual int peek(T );
      virtual int remove(T );      //Throws:  std::string
      std::ostream& print(std::ostream& );
   private:
      TreeNode<T> get(TreeNode<T>* , T);
      int insert(TreeNode<T>*&, T);
      TreeNode<T>* max(TreeNode<T>* );
      TreeNode<T>* maximum(TreeNode<T>*& );
      TreeNode<T>* min(TreeNode<T>* );
      TreeNode<T>* minimum(TreeNode<T>*& );
      int peek(TreeNode<T>*, T);
      int remove(TreeNode<T>*, TreeNode<T>*, T);
      TreeNode<T>* remove(TreeNode<T>* , T);
      void transplant(TreeNode<T>*&, TreeNode<T>*, TreeNode<T>*);
      TreeNode<T>* _root;
      int          _size;
};

//////////////////////////////////////////////////////////////////////
/*
*/
template <typename T>
BinaryTree<T>::BinaryTree() :
_root(NULL),
_size(0){}

/*
Virtual
*/
template <typename T>
BinaryTree<T>::~BinaryTree(){
   std::cout<<"\nIn the BinaryTree destructor\n";
   if(this->_root){
      delete this->_root;
   }
}

/*
Virtual
Throws:  std::string...
*/
template <typename T>
TreeNode<T> BinaryTree<T>::get(T t){
   TreeNode<T> returnValue;
   if(this->peek(t)){
      returnValue = this->get(this->_root, t);
      return returnValue;
   }
   throw(std::string("get():  Value not found"));
}

/*
Virtual
Throws:  std::string...
*/
template <typename T>
int BinaryTree<T>::insert(T t){
   int returnValue = -1;
   if(!(this->peek(t))){
      returnValue = this->insert(this->_root, t);
      return returnValue;
   }
   throw(std::string("insert():  value already in the Tree"));
}

/*
Virtual
*/
template <typename T>
int BinaryTree<T>::peek(T t){
   return this->peek(this->_root, t);
}

/*
Virtual
Throws:  std::string...
*/
template <typename T>
int BinaryTree<T>::remove(T t){
   int return_value = -1;
   if(this->peek(t)){
      this->_root = this->remove(this->_root, t);
      return_value = this->_size;
      return return_value;
   }
   throw(std::string("remove():  value not in tree to remove"));
}

/*
*/
template <typename T>
std::ostream& BinaryTree<T>::print(std::ostream& os){
   if(this->_root){
      os<<std::endl<<this->_size<<std::endl<<*(this->_root)<<std::endl;
   }
   else{
      os<<std::endl<<this->_size<<std::endl<<this->_root<<std::endl;
   }
   return os;
}

/////////////////////////////Private Methods//////////////////////////
/*
*/
template <typename T>
TreeNode<T> BinaryTree<T>::get(TreeNode<T>* node, T t){
   TreeNode<T> value;
   if(node){
      if(t > node->data()){
         value = this->get(node->right, t);
      }
      else if(t < node->data()){
         value = this->get(node->left, t);
      }
      else{
         value = *node;
      }
   }
   return value;
}

/*
*/
template <typename T>
int BinaryTree<T>::insert(TreeNode<T>*& node, T t){
   int returnValue = -1;
   if(node){
      if(t > node->data()){
         returnValue = this->insert(node->right, t);
      }
      else if(t < node->data()){
         returnValue = this->insert(node->left, t);
      }
   }
   else{
      node = new TreeNode<T>(t);
      ++(this->_size);
      returnValue = this->_size;
   }
   return returnValue;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::max(TreeNode<T>* node){
   TreeNode<T>* y = node;
   while(y->right){
      y = y->right;
   }
   return y;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::maximum(TreeNode<T>*& node){
   TreeNode<T>* y = node;
   while(y->right){
      node = y;
      y = y->right;
   }
   return y;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::min(TreeNode<T>* node){
   TreeNode<T>* y = node;
   while(y->left){
      y = y->left;
   }
   return y;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::minimum(TreeNode<T>*& node){
   TreeNode<T>* y = node;
   while(y->left){
      node = y;
      y = y->left;
   }
}

/*
*/
template <typename T>
int BinaryTree<T>::peek(TreeNode<T>* node, T t){
   int isFound = 0;
   if(node){
      if(t > node->data()){
         isFound = this->peek(node->right, t);
      }
      else if(t < node->data()){
         isFound = this->peek(node->left, t);
      }
      else{
         isFound = 1;
      }
   }
   return isFound;
}

/*
*/
template <typename T>
int BinaryTree<T>::remove(TreeNode<T>* parent,TreeNode<T>* node,T t){
   int           value     = -1;
   TreeNode<T>*  temp      = NULL;
   TreeNode<T>*  temp_node = NULL;

   if(node->data() == t){
      if(!(node->left)){
         this->transplant(parent, node, node->right);
      }
      else if(!(node->right)){
         this->transplant(parent, node, node->left);
      }
      else{
         TreeNode<T>* temp_parent = node->right;
         temp = this->minimum(temp_parent);
         if(node->right != temp){
            this->transplant(temp_parent, temp, temp->right);
            temp->right = node->right;
         }
         if(!parent){
            temp_node = node;
            this->transplant(parent, node, temp);
         }
         else{
            this->transplant(parent, node, temp);
         }
         temp->left = node->left;
      }
      node->left  = NULL;
      node->right = NULL;
      delete node;
      node = NULL;
      value = --(this->_size);
   }
   else{
      if(t < node->data()){
         value = this->remove(node, node->left, t);
      }
      else{
         value = this->remove(node, node->right, t);
      }
   }
   return value;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::remove(TreeNode<T>* root, T t){
   TreeNode<T>* temp = NULL;
   if(t < root->data()){
      root->left = this->remove(root->left, t);
   }
   else if(t > root->data()){
      root->right = this->remove(root->right, t);
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
         temp                = this->min(root->right);
         TreeNode<T>*  temp2 = new TreeNode<T>(temp->data());
         temp2->left         = root->left;
         temp2->right        = root->right;
         root->left          = NULL;
         root->right         = NULL;
         delete root;
         root                = temp2;
         temp2               = NULL;
         root->right         = this->remove(root->right,temp->data());
      }
   }
   return root;
}

/*
*/
template <typename T>
void BinaryTree<T>::transplant
(
   TreeNode<T>*& parent,
   TreeNode<T>* x,
   TreeNode<T>* y
){
   if(!parent){
      this->_root = y;
   }
   else if(parent->left = x){
      parent->left = y;
   }
   else{
      parent->right = y;
   }
}

//////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream& operator<<(std::ostream& os, BinaryTree<T>& tree){
   return tree.print(os);
}

#endif
//////////////////////////////////////////////////////////////////////
