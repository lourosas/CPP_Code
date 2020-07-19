/*********************************************************************
*********************************************************************/
//////////////////////////////////////////////////////////////////////
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <iomanip>
#include <climits>

template <class T>
class TreeNode{
   public:
      Node(T );
      virtual ~Node();
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
template <class T>
TreeNode<T>::Node(T t) :
left(NULL),
right(NULL){
   this->data(t);
}

/*
Virtual
*/
template <class T>
TreeNode<T>::~Node(){
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
template <class T>
T TreeNode<T>::data(){
   return this->_data;
}

/*
*/
template <class T>
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
template <class T>
std::ostream& operator<<(std::ostream& os, TreeNode<T>& node){
   return node.print(os);
}

#endif
//////////////////////////////////////////////////////////////////////
