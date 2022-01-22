/*
 * This file is part of the CPP_Code Dsistribution
 * Copyright (c) 2022 Lou Rosas
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>
 */
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include "Integer.h"
#include "List.h"
#include "LinkedList.h"
#include "ChainedHashTable.h"

int main(){
   /*
   time_t t;
   srand((unsigned)time(&t));
   std::cout<<"\n\nHello World\n\n\n";
   ChainedHashTable<Integer, Integer> cht;
   Integer x(302);
   std::cout<<"\n"<<cht.insert(x,x)<<"\n";
   for(int i = 0; i < 50; ++i){
      int v = rand()%5000;
      Integer x(v);
      std::cout<<"\n"<<x.value()<<",  "<<cht.insert(x,x);
   }
   std::cout<<"\n\n"<<cht.containsKey(x.key())<<"\n\n"
     <<cht.containsKey(Integer(-7))<<"\n"<<cht.keySize()<<"\n\n";
   int size = 0;
   Integer* keys = cht.keys(size);
   std::cout<<size<<"\n"<<keys<<"\n\n";
   for(int i = 0; i < size; ++i){
      std::cout<<keys[i].key()<<", ";
   }
   std::cout<<"\n\n";
   size = 0;
   Integer* vals = cht.values(size);
   std::cout<<size<<"\n"<<vals<<"\n\n";
   for(int i = 0; i < size; ++i){
      std::cout<<vals[i].value()<<", ";
   }
   std::cout<<"\n\n";
   */

   //LinkedList<Integer>* array = new LinkedList<Integer>[101];
   List<Integer>* array = new LinkedList<Integer>[2];
   LinkedList<Integer> temp = (LinkedList<Integer>)array[0];
   temp.insert(Integer(12));
   temp.insert(Integer(14));
   temp = array[1];
   temp.insert(Integer(2));
   temp.insert(Integer(24));
   /*
   ChainedHashTable<Integer, Integer> ht(array, 101);
   int inserted = ht.insert(x,x);
   std::cout<<"\n\n"<<inserted<<"\n\n";
   inserted = ht.insert(x,x);
   std::cout<<"\n\n"<<inserted<<"\n\n";
   */
   delete[] array;
   /*
   List<Integer>* temp = new LinkedList<Integer>();
   temp->add(Integer(12));
   temp->add(Integer(14));
   temp->print(std::cout);
   delete temp;
   array = nullptr;
   */
   return 1;
}
