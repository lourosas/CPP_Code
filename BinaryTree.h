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
      Node<T>* maximum(TreeNode<T>*& );
      Node<T>* minimum(TreeNode<T>*& );
      int peek(TreeNode<T>*, T);
      int remove(TreeNode<T>*, TreeNode<T>*, T);
      void transplant(TreeNode<T>*&, TreeNode<T>*, TreeNode<T>*);
      TreeNode<T>* _root;
      int          _size;
};

//////////////////////////////////////////////////////////////////////
/*
*/
template <class T>
BinaryTree<T>::BinaryTree() :
_root(NULL),
_size(0){}

/*
Virtual
*/
template <class T>
BinaryTree<T>::~BinaryTree(){}

/*
Virtual
*/
template <class T>
T BinaryTree<T>::get(T t){
   T returnValue;

   returnValue;
}

/*
Virtual
*/
template <class T>
int BinaryTree<T>::insert(T t){
   int return_value = 0;
   return return_value;
}

/*
Virtual
*/
template <class T>
int BinaryTree<T>::peek(T t){
   return 0;
}

/*
Virtual
*/
template <class T>
int BinaryTree<T>::remove(T t){
   int return_value = 0;

   return return_value;
}

/*
*/
template <class T>
std::ostream& BinaryTree<T>::print(std::ostream& os){
   os<<std::endl<<this->_size<<std::endl<<*(this->_root)<<std::endl;
   return os;
}

#endif
//////////////////////////////////////////////////////////////////////
