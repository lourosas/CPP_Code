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
   Integer test((int)rand()%5000);
   oht.insert(test.key(), test.value());

   std::cout<<oht;
   std::cout<<std::endl<<test<<std::endl;
   if(oht.containsKey(test)){
      try{
         //Integer v = oht.retrieve(test);
         Integer v = oht.remove(test);
         std::cout<<std::endl<<v<<std::endl<<std::endl;
      }
      catch(int x){
         std::cout<<std::endl<<x<<std::endl<<std::endl;
      }
   }

   test = (int)5403;
   try{
      //Integer v = oht.retrieve(test);
      Integer v = oht.remove(test);
      std::cout<<std::endl<<v<<std::endl<<std::endl;
   }
   catch(int x){
      std::cout<<std::endl<<"Exception Occured:  "<<x;
      if(x == oht.NO_ENTRY_EXCEPTION){
         std::cout<<"\n\n"<<test.value()<<" NOT in the Hash Table\n\n";
      }
   }

   std::cout<<oht<<std::endl;
   
   oht.insert(test.key(), test.value());
   std::cout<<oht<<std::endl;
   return 1;
}
