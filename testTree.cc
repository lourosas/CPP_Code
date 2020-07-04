//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "Tree.h"

int main(int argc, char* argv[]){
   std::cout<<argc<<", "<<argv[0]<<"\nHello World\n";
   Tree t;
   for(int i = 0; i < 10; i++){
      std::cout<<i<<", "<<t.insert(i)<<std::endl;
   }
}
//////////////////////////////////////////////////////////////////////
