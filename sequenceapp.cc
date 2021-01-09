#include "Keeper.h"

int main(){
   std::cout<<"Hello World\n";
   Keeper* k = new Keeper();
   if(k != nullptr){ delete k; }
   return 0;
}
