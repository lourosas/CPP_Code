//Test of the mem_mabager sofware
#include "mem_manager.h"
#include <iostream.h>

int   ptr_value = 0;
void* ptr_array[100];

void setMem(size_t );
void remove_ptr(int );
void clear();

int main()
{
   startMem();

   setMem(sizeof(int));
   setMem(45);
   setMem(sizeof(float) * 43);
   print_list();
   setMem(300);
   print_list();
   
   remove_ptr(3);
   print_list();

   remove_ptr(0);
   print_list();

   remove_ptr(5);
   print_list();

   freeMem((void* ) 0x00001002);

   clear();
   return 1;
}

void setMem(size_t size)
{
   void* ptr = mallocMem(size);
   ptr_array[ptr_value] = ptr;
   ptr_value++;
   cout<<endl<<ptr;
}

void remove_ptr(int index)
{
   if(index <= ptr_value)
   {
      freeMem(ptr_array[index]);
   }
}

void clear()
{
   stopMem();
}
