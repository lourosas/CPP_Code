#include <iostream>
#include <cstdlib>
#include "Integer.h"
#include "OpenAddressingHashTable.h"

int main(){
   time_t t;
   srand((unsigned)time(&t));
   std::cout<<std::endl;
   std::cout<<"Hello World\n";
   OpenAddressingHashTable<Integer, Integer> oht;

   for(int i = 0; i < 45; ++i){
      int v = rand()%5000;
      Integer x(v);
      oht.insert(x.key(), x.value());
   }

   std::cout<<oht;
   
   Integer test((int)rand()%5000);
   Integer v = oht.retrieve(test);
   std::cout<<std::endl<<v<<std::endl;

   //Integer i(4);
   //Integer j(2300);
   //Integer x = oht.retrieve(i);
   //std::cout<<oht.retrieve(i).value()<<std::endl;
   /*
   try{
      std::cout<<std::endl<<oht.insert(i, j)<<std::endl;
   }
   catch(int x){
      std::cout<<x<<std::endl;
   }
   */
   return 1;
}
