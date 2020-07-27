//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "TreeNode.h"
#include "BinaryTree.h"

int main(int argc, char* argv[]){
   std::cout<<argc<<", "<<argv[0]<<"\nHello World\n";
   BinaryTree<int> t;
   time_t timer;
   srand((unsigned)time(&timer));
   for(int i = 0; i < 10; i++){
      int value = rand() % 10000;
      try{
         std::cout<<"Value = "<<value<<", "<<t.insert(value)
           <<" (size)"<<std::endl;
      }
      catch(std::string& exception){
         std::cout<<value<<":  "<<exception<<std::endl;
      }
   }
   std::cout<<"Tree:  "<<t<<std::endl<<std::endl;
   srand((unsigned)time(&timer));
   for(int i = 0; i < 5; i++){
      int value = rand() % 10000;
      try{
         std::cout<<"Remove Value = "<<value<<", "<<t.remove(value)
           <<std::endl;
      }
      catch(std::string& exception){
         std::cout<<value<<":  "<<exception<<std::endl;
      }
   }
   std::cout<<"\nTree:  "<<t;
}

//////////////////////////////////////////////////////////////////////
