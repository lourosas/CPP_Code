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
      std::ostream& print(std::ostream& );
      Node* left;
      Node* right;
   private:
      void data(int );
      int _data;
};
std::ostream& operator<<(std::ostream& , Node& );
#endif
//////////////////////////////////////////////////////////////////////
