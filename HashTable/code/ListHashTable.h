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
#ifndef LIST_HASH_TABLE_H
#define LIST_HASH_TABLE_H

#include <cmath>
#include "GenericHashTable.h"
#include "List.h"
#include "LinkedList.h"

template<class Key, class Value, template<class> class L = List>
class ListHashTable : public GenericHashTable<Key,L<Value>>{
   public:
      ListHashTable(){}
      virtual ~ListHashTable(){}

      virtual int    contains(Value){ return 0; }
      virtual int    containsKey(Key){ return 0; }
      virtual int    insert(Key key, Value value){ return 0; }
      virtual Key*   keys(int& index){ return nullptr; }
      virtual Value  remove(Key key){
         Value v;
         return v;
      }
      virtual Value  retrieve(Key key){Value v; return v;}
   protected:
   private:
};

#endif
