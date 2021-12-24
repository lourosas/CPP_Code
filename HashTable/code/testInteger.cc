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

int main(){
   std::cout<<"Hello World\n";
   Integer i(3);
   Integer o;
   Integer* o2 = new Integer(73);
   std::cout<<o2->key()<<"\t"<<o2->value()<<std::endl<<std::endl;
   std::cout<<*o2<<std::endl<<std::endl;
   //std::cout<<i<<std::endl<<o<<std::endl<<*o2<<std::endl;
   delete o2;
   std::cout<<i<<std::endl<<o<<std::endl;
   o = i;
   std::cout<<o<<std::endl;
   return 1;
}
