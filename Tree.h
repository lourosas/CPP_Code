/*********************************************************************
*********************************************************************/
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <iomanip>
#include "Node.h"

class Tree
{
   public:
      Tree();
      virtual ~Tree();
      int insert(int );
      int remove(int );
      int peek(int );
      std::ostream& print(std::ostream& );
   private:
      int insert(Node*& , int );
      Node* max(Node* );
      Node* maximum(Node*& );
      Node* min(Node* );
      Node* minimum(Node*& );
      int remove(Node*, Node* , int );
      Node* remove(Node*, int );
      //int remove(Node*&, Node* , int );
      //int remove(Node*&, Node*& , int );
      int peek(Node* , int );
      void transplant(Node*&, Node*, Node* );
      Node* _root;
      int   _size;
};
std::ostream& operator<<(std::ostream&, Tree& );
#endif
//////////////////////////////////////////////////////////////////////
