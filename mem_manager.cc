//CIS 269
//The Memory Manger Implementation File
//Lou Rosas

#include "mem_manager.h"

//Globals
//NodeData current_data;
//LinkedList<NodeData> ll;

//Initialize the Linked List
void startMem()
{
   //The best way to Initialize the LinkedList object
   //This will put the LinkeList object back to its
   //original state.
   ll.destroyList();
}

//Free the remaining used memory in the Linked List
void stopMem()
{
   size_t size;
   while(ll.getSize() > 0)
   {
      size = (ll.peek()).getSize();
      if(size > 1)
         cout<<endl<<size<<" bytes not freed, freeing them now.\n";
      else
         cout<<endl<<size<<" byte not freed, freeing it now.\n";
      ll.remove(current_data);
   }
}

//Allocate memory of the requested size and put in LinkedList
void* mallocMem(size_t set_size)
{
   void* return_pointer;

   current_data.setData(set_size);
   ll.add(current_data);
   if(!(return_pointer = (ll.peekEnd()).getPtr()))
   {
      cerr<<"\nUnable to allocate memory, reuturning NULL";
   }
   return return_pointer;
}

//Search for a pointer, free the memory and remove from the
//Linked List
void  freeMem(void* the_ptr)
{
   int   i = 0;
   int   size = ll.getSize();
   int   index = -1;
   bool  found = false;
   void* current_pointer;
   
   while(i < size && !found)
   {
      current_pointer = (ll.peek(i)).getPtr();
      if(the_ptr == current_pointer)
      {
         found = true;
         index = i;
      }
      i++;
   }
   if(found)
   {
      cout<<"\nRemoving--"<<(ll.peek(index)).getSize()<<" bytes "
         <<"located at: "<<(ll.peek(index)).getPtr()<<endl;
      ll.remove(current_data, index);
   }
   else
   {
      cerr<<"\nPointer: "<<the_ptr<<" not found in Linked List\n";
   }
}


//Print out the Linked List
void  print_list()
{
   cout<<endl<<ll<<endl;
}
