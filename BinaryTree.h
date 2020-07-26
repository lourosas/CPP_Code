/*********************************************************************
*********************************************************************/
//////////////////////////////////////////////////////////////////////
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <iomanip>
#include "TreeNode.h"

template <class T>
class BinaryTree
{
   public:
      BinaryTree();
      virtual ~BinaryTree();
      virtual T get(T );
      virtual int insert(T );
      virtual int peek(T );
      virtual int remove(T );
      std::ostream& print(std::ostream& );
   private:
      T get(TreeNode<T>* , T);
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
BinaryTree<T>::~BinaryTree(){}

/*
Virtual
*/
template <typename T>
T BinaryTree<T>::get(T t){
   T returnValue;

   returnValue;
}

/*
Virtual
*/
template <typename T>
int BinaryTree<T>::insert(T t){
   int return_value = 0;
   return return_value;
}

/*
Virtual
*/
template <typename T>
int BinaryTree<T>::peek(T t){
   return 0;
}

/*
Virtual
*/
template <typename T>
int BinaryTree<T>::remove(T t){
   int return_value = 0;

   return return_value;
}

/*
*/
template <typename T>
std::ostream& BinaryTree<T>::print(std::ostream& os){
   os<<std::endl<<this->_size<<std::endl<<*(this->_root)<<std::endl;
   return os;
}

/////////////////////////////Private Methods//////////////////////////
/*
*/
template <typename T>
T BinaryTree<T>::get(TreeNode<T>* node, T t){
   T value;
   return value;
}

/*
*/
template <typename T>
int BinaryTree<T>::insert(TreeNode<T>*& node, T t){
   int returnValue = -1;
   return returnValue;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::max(TreeNode<T>* node){
   return NULL;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::maximum(TreeNode<T>*& node){
   return NULL;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::min(TreeNode<T>* node){
   return NULL;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::minimum(TreeNode<T>*& node){
   return NULL;
}

/*
*/
template <typename T>
int BinaryTree<T>::peek(TreeNode<T>* node, T t){
   int isFound = 0;
   return isFound;
}

/*
*/
template <typename T>
int BinaryTree<T>::remove(TreeNode<T>* parent,TreeNode<T>* root,T t){
   int value = -1;
   return value;
}

/*
*/
template <typename T>
TreeNode<T>* BinaryTree<T>::remove(TreeNode<T>* root, T t){
   return NULL;
}

/*
*/
template <typename T>
void BinaryTree<T>::transplant
(
   TreeNode<T>*& parent,
   TreeNode<T>* x,
   TreeNode<T>* y
){}

//////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream& operator<<(std::ostream& os, BinaryTree<T>& tree){
   return tree.print(os);
}

#endif
//////////////////////////////////////////////////////////////////////
