#include <iostream>
#include "Integer.h"
#include "OpenAddressingHashTable.h"

int main(){
   std::cout<<"Hello World\n";
   OpenAddressingHashTable<Integer, Integer> oht;
   Integer i(3);
   //Integer x = oht.retrieve(i);
   //std::cout<<oht.retrieve(i).value()<<std::endl;
   oht.insert(i, i);
   return 1;
}
