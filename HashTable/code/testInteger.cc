#include "Integer.h"

int main(){
   std::cout<<"Hello World\n";
   Integer i(3);
   Object o;
   Object* o2 = new Integer(73);
   std::cout<<i<<std::endl<<o<<std::endl<<*o2<<std::endl;
   delete o2;
   return 1;
}
