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
      oht.insert(x, x);
   }
   Integer test((int)rand()%5000);
   oht.insert(test, test);


   std::cout<<oht;
   std::cout<<std::endl<<test<<std::endl;
   std::cout<<std::endl<<oht.contains(test)<<std::endl<<std::endl;
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


   Integer test1 = (int)5403;
   try{
      //Integer v = oht.retrieve(test);
      Integer v = oht.remove(test1.key());
      std::cout<<std::endl<<v<<std::endl<<std::endl;
   }
   catch(int x){
      std::cout<<std::endl<<"Exception Occured:  "<<x;
      if(x == oht.NO_ENTRY_EXCEPTION){
         std::cout<<"\n\n"<<test1.value()
           <<" NOT in the Hash Table\n\n";
      }
   }

   std::cout<<std::endl<<oht.contains(test1)<<std::endl<<std::endl;

   std::cout<<oht<<std::endl;
   

   oht.insert(test, test);
   std::cout<<oht<<std::endl;

   std::cout<<"\n"<<oht.searchValues(test1.value())<<"\n\n";

   int size = -1;
   Integer* keys = oht.keys(size);
   std::cout<<size<<"\n\n"<<keys<<"\n\n";
   for(int i = 0; i < size; ++i){
      std::cout<<keys[i].key()<<", ";
   }
   Integer* values = oht.values(size);
   std::cout<<"\n\n"<<size<<"\n\n"<<values<<"\n\n";
   for(int i = 0; i < size; ++i){
      std::cout<<values[i].value()<<", ";
   }

   oht.clear();
   std::cout<<"\n"<<oht<<std::endl;

   //keys = oht.keys(size);
   //std::cout<<size<<"\n\n"<<keys<<"\n\n";
   values = oht.values(size);
   std::cout<<"\n\n"<<size<<"\n\n"<<values<<"\n\n";

   std::cout<<"\n\n";
   return 1;
}
