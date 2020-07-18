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
      int value = rand() % 10000;
      std::cout<<"Value = "<<value<<", "<<t.insert(value)
         <<" (size)"<<std::endl;
   }
   std::cout<<"Tree:  "<<t;
   std::cout<<std::endl<<std::endl;
   srand((unsigned)time(&timer));
   for(int i = 0; i < 5; i++){
      int value = rand() % 10000;
      std::cout<<"Remove Value = "<<value<<", "<<t.remove(value)
         <<std::endl;
   }
   std::cout<<"Tree:  "<<t;
}
//////////////////////////////////////////////////////////////////////
