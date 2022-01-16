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
   std::cout<<"\n\n";
   /*
   LinkedList<Integer>* array = new LinkedList<Integer>[101];
   ChainedHashTable<Integer, Integer> ht(array, 101);
   int inserted = ht.insert(x,x);
   std::cout<<"\n\n"<<inserted<<"\n\n";
   inserted = ht.insert(x,x);
   std::cout<<"\n\n"<<inserted<<"\n\n";
   delete[] array;
   array = nullptr;
   */
   return 1;
}
