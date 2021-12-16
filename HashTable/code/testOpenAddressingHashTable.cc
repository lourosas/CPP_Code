#include <iostream>
#include "Integer.h"
#include "OpenAddressingHashTable.h"

int main(){
   std::cout<<"Hello World\n";
   OpenAddressingHashTable<Integer, Integer> oht;
   Integer i(4);
   Integer j(2300);
   //Integer x = oht.retrieve(i);
   //std::cout<<oht.retrieve(i).value()<<std::endl;
   try{
      std::cout<<std::endl<<oht.insert(i, j)<<std::endl;
   }
   catch(int x){
      std::cout<<x<<std::endl;
   }
   return 1;
}
