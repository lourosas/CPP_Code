/*********************************************************************
*********************************************************************/
//////////////////////////////////////////////////////////////////////
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <iomanip>
#include <climits>

template <typename T>
class TreeNode{
   public:
      TreeNode(T );
      virtual ~TreeNode();
      T data();
      std::ostream& print(std::ostream& );
      TreeNode<T>* left;
      TreeNode<T>* right;
   private:
      void data(T );
      T _data;
};


//////////////////////////////////////////////////////////////////////
/*
*/
template <typename T>
TreeNode<T>::TreeNode(T t) :
left(NULL),
right(NULL){
   this->data(t);
}

/*
Virtual
*/
template <typename T>
TreeNode<T>::~TreeNode(){
   std::cout<<" In the TreeNode Destructor:  "<<this->data()<<", "
      <<this->left<<", "<<this->right<<std::endl;
   if(this->left){
      delete this->left;
      this->left = NULL;
   }
   if(this->right){
      delete this->right;
      this=>right = NULL;
   }
}

/*
*/
template <typename T>
T TreeNode<T>::data(){
   return this->_data;
}

/*
*/
template <typename T>
std::ostream& TreeNode<T>::print(std::ostream& os){
   if(this->left){
      this->left->print(os);
   }
   os<<this->data()<<":";
   if(this->right){
      this->left->print(os);
   }
   return os;
}

/*
*/
template <typename T>
std::ostream& operator<<(std::ostream& os, TreeNode<T>& node){
   return node.print(os);
}

#endif
//////////////////////////////////////////////////////////////////////
