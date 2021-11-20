//The Implementation file of the NodeData Class
//A Class by Lou Rosas for CIS 269 Assignment 1
//Due 02/01/03

#include "NodeData.h"

//Constructor of no arguments
NodeData::NodeData()
 : size(0), ptr(0)
{}

//Generic Constructor
NodeData::NodeData(size_t current_size)
 :size(0), ptr(0)
{
   if(!(this->setData(current_size)))
   {
      cout<<"\nUnable to allocate memory, size = 0, pointer = NULL";
   }
}

//Destructor
NodeData::~NodeData()
{
   this->destroyNodeData();
}

//A Simple setup data method
void* NodeData::setData(size_t data_size)
{
   if(this->ptr)
   {
      free(this->ptr);
      this->ptr = NULL;
      this->size = 0;
   }
   if(data_size > 0)
   {
      if(this->ptr = malloc(data_size))
      {
         size = data_size;
      }
      else
      {
         this->ptr  = NULL;
         this->size = 0;
      }
   }
   return (this->ptr);
}

//This method returns the pointer attribute of the Object
void* NodeData::getPtr() const
{
   return (this->ptr);
}

//This method returns the size of the memory allocated
//outside the LinkedList
size_t NodeData::getSize() const
{
   return (this->size);
}

//Destroy the NodeData Object
size_t NodeData::destroyNodeData()
{
   size_t temp;
   temp = this->size;
   if(this->ptr)
   {   
      free(this->ptr);
      this->ptr = NULL;
      this->size = 0;
   }
   return temp;
}

//Overloaded Assignment operator
NodeData& NodeData::operator=(const NodeData& copy_data)
{
   size_t temp = copy_data.getSize();
   if(!(this->setData(temp)))
   {
      cout<<"\nUnable to allocate memory, return NULL";
   }
   return *this;
}

//Overload the equals relational operator
bool NodeData::operator==(NodeData& compare_data)
{
   return ((this->size == compare_data.getSize())&&
           (this->ptr  == compare_data.getPtr() ));
}

//A simple print method
void NodeData::print()
{
   if(this->ptr)
   {
      cout<<"("<<this->ptr<<", "<<this->size<<")";
   }
   else
   {
      cerr<<"\nNull Pointer, nothing to print";
   }
}

//Overload the insertion operator
ostream& operator<<(ostream& os, NodeData& nt)
{
   nt.print();
   return os;
}
