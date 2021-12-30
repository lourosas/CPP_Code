/*
 * This file is part of the CPP_Code Dsistribution
 * Copyright (c) 2021 Lou Rosas
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include "Integer.h"
#include "LinkedList.h"

int main(){
   std::cout<<"\n\nHello World\n\n";
   LinkedList<Integer> ll;
   std::cout<<ll.isEmpty()<<std::endl;
   Integer x(3405);
   //ll.add(x, 40);
   ll.add(x);
   x = 4305;
   ll.add(x);
   //ll.add(x, 0);
   x = 5007;
   ll.add(x);
   //ll.add(x, 1);
   x = 6007;
   ll.add(x);
   //ll.add(x, 2);
   x = 3333;
   ll.add(x);

   std::cout<<"\nWhat the fuck!!\n\n"<<ll.isEmpty();

   try{
      std::cout<<"\n"<<ll.peekEnd().value()<<"\n"<<ll.peek().value()
        <<"\n"<<ll.peek(3).value();
   }
   catch(int x){
      std::cout<<"\n"<<x<<"\n";
   }
   try{
      std::cout<<"\n\n"<<ll.peek(67)<<"\n\n";
   }
   catch(int x){ std::cout<<"\n\n"<<x<<"\n\n"; }
   std::cout<<"\n"<<ll<<"\n";
   try{
      std::cout<<ll.remove(1)<<"\n";
   }
   catch(int x){ std::cout<<"\n\n"<<x<<"\n\n"; }
   std::cout<<"\n"<<ll<<"\n";

   return 1;
}
