//A generic Node Class by Lou Rosas
//Part of the continuation of CIS 278 and my desire to create
//a general data structure tool set.

#ifndef NODE_H
#define NODE_H

template <class Type>
class Node
{
   public:
      Type data;        //The actual data in the Node
      Node<Type>* next; //Pointer to the next Node object
                        //Default:  NULL
};
#endif
