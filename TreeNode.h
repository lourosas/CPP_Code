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
TreeNode::Node(T t) :
left(NULL),
right(NULL){
   this->data(t);
}

/*
Virtual
*/
#endif
//////////////////////////////////////////////////////////////////////
