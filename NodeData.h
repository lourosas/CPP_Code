//A Class by Lou Rosas for CIS 269 Assignment 1
//Due 02/01/03

#ifndef NODE_DATA_H
#define NODE_DATA_H

#include <stddef.h>
#include <stdlib.h>
#include <iostream.h>

class NodeData
{
   public:
      //Constructor of no arguments
      NodeData();
      
      //Generic Constructor
      NodeData(size_t );

      //Destructor
      ~NodeData();

      //A simple set up the data method (nothing else is needed)
      void*  setData(const size_t );

      //Get the pointer attribute of the object
      void* getPtr() const;

      //Get the size attribute of the object.  This indicates
      //the amount of memory allocated when the node data object
      //was first created.  This memory is located at the address
      //stored by the ptr attribute in the object.
      size_t getSize() const;

      //Destroy the NodeData object
      size_t destroyNodeData();
      
      //Overload the Assignment Operator
      NodeData& operator=(const NodeData& );

      //Overloaded relational operators
      bool operator==(NodeData& );
      
      //Print method
      void print();

   private:
      //Size of the memory allocated in the setData() call
      size_t size;

      //pointer to the memory allocated in the setData() call
      void*  ptr;
};
//Overload the insertion operator
ostream& operator<<(ostream&, NodeData& );

#endif
