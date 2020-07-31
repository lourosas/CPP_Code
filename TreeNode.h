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
      TreeNode();
      TreeNode(T );
      TreeNode(const TreeNode<T>& );
      virtual ~TreeNode();
      TreeNode<T>& operator=(const TreeNode<T>& );
      T data() const;
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
TreeNode<T>::TreeNode() :
left(NULL),
right(NULL){}

/*
*/
template <typename T>
TreeNode<T>::TreeNode(T t) :
left(NULL),
right(NULL){
   this->data(t);
}

/*
*/
template <typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& node) :
left(NULL),
right(NULL){
   this->_data = node._data;
}

/*
Virtual
*/
template <typename T>
TreeNode<T>::~TreeNode(){
   std::cout<<"In the TreeNode Destructor:  "<<this->data()<<", "
      <<this->left<<", "<<this->right<<std::endl;
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
template <typename T>
TreeNode<T>& TreeNode<T>::operator=(const TreeNode<T>& node){
   this->left  = NULL;
   this->right = NULL;
   this->_data = node.data();
   return *this;
}

/*
*/
template <typename T>
T TreeNode<T>::data() const{
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
      this->right->print(os);
   }
   return os;
}

/*
*/
template <typename T>
std::ostream& operator<<(std::ostream& os, TreeNode<T>& node){
   return node.print(os);
}

//////////////////////////Private Member Functions////////////////////
template <typename T>
void TreeNode<T>::data(T t){
   this->_data = t;
}

#endif
//////////////////////////////////////////////////////////////////////
