#include <iostream>
#include "Integer.h"

int main(){
   std::cout<<"Hello World\n";
   Integer i(3);
   Integer o;
   Integer* o2 = new Integer(73);
   std::cout<<o2->key()<<"\t"<<o2->value()<<std::endl<<std::endl;
   std::cout<<*o2<<std::endl<<std::endl;
   //std::cout<<i<<std::endl<<o<<std::endl<<*o2<<std::endl;
   delete o2;
   std::cout<<i<<std::endl<<o<<std::endl;
   o = i;
   std::cout<<o<<std::endl;
   return 1;
}
