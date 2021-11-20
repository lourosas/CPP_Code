#include "BasicHashTable.h"
#include "BasicHashElement.h"
#include "MathTools.h"
#include <iostream.h>
#include <string.h>

float rehash = .95;
BasicHashTable<int> bht;
BasicHashTable<int> bht2(rehash);
int currentData = 0xFFFFFFFF;

int main()
{
   char  id_number[9];
   int   data = 0xFFFFFFFF;
   char  to_continue;
   cout<<"\nHello World!\n\n";
   if(bht.isEmpty())
      cout<<"\nbht IS empty!!\n";
   
   bht.insert(535698, 100);
   bht.insert(123456, 98);
   bht.insert(654321, 89);
   bht.insert(235641, 85);
   bht.insert(415263, 79);
   
   cout<<endl<<bht<<endl;
   
   bht2 = bht;
   
   cout<<endl<<bht2<<endl;
   
   bht2.insert(253641, 100);
   cout<<endl<<bht2<<endl;
   
   BasicHashTable<int> bht3(bht2);
   cout<<endl<<bht3<<endl;
   
   bht3.insert(253642, 10);
   cout<<endl<<bht3<<endl;
   
   return 1;
}
