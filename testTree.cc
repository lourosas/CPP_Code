//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Node.h"
#include "Tree.h"

int main(int argc, char* argv[]){
   std::cout<<argc<<", "<<argv[0]<<"\nHello World\n";
   Tree t;
   time_t timer;
   srand((unsigned)time(&timer));
   for(int i = 0; i < 10; i++){
      int value = rand() % 1000;
      std::cout<<"Value = "<<value<<", "<<t.insert(value)
         <<" (size)"<<std::endl;
   }
}
//////////////////////////////////////////////////////////////////////
