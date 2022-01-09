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
#ifndef LIST_H
#define LIST_H

#include <iostream>

template<class T>
class List{
   public:
      List(){}
      virtual ~List(){}
      virtual int add(const T&)                  = 0;
      virtual int add(const T&,int)              = 0;
      virtual void clear()                       = 0;
      virtual int contains(const T&)             = 0;
      virtual T& get(int)                        = 0;
      virtual int getIndex(const T&)             = 0;
      virtual int isEmpty()                      = 0;
      virtual T& peek()                          = 0;
      virtual T& peek(int)                       = 0;
      virtual T& peekEnd()                       = 0;
      virtual std::ostream& print(std::ostream&) = 0;
      virtual T& remove(int)                     = 0;
      virtual int remove(const T&)               = 0;
      virtual int size() const                   = 0;
      virtual void sort()                        = 0;
      virtual void sortReverse()                 = 0;
   protected:
      virtual void size(int)                     = 0;
   private:
};
#endif
