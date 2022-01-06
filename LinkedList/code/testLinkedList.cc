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
   ll.add(x);
   x = 4305;
   ll.add(x);
   x = 5007;
   ll.add(x);
   x = 6007;
   ll.add(x);
   x = 3333;
   ll.add(x);

   std::cout<<"\n"<<ll<<"\n";
   ll.sort();
   std::cout<<"\n"<<ll<<"\n";


   return 1;
}
