/*********************************************************************
*********************************************************************/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>
#include <climits>

class Node
{
   public:
      Node(int );
      virtual ~Node();
      int data();
      Node* left;
      Node* right;
   private:
      void data(int );
      int _data;
};
#endif
//////////////////////////////////////////////////////////////////////
