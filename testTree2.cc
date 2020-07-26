//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "TreeNode.h"
#include "BinaryTree.h"

int main(int argc, char* argv[]){
   std::cout<<argc<<", "<<argv[0]<<"\nHello World\n";
   BinaryTree<int> t;
   std::cout<<std::endl<<t;
}

//////////////////////////////////////////////////////////////////////
