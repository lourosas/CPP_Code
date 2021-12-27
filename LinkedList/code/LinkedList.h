/*
A generic LinkeList class by Lou Rosas
*/
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
 /////////////////////////////////////////////////////////////////////
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <iomanip>
#include "LinkedListNode.h"

template <class T>
class LinkedList{
   public:
      //Constructor with no arguments
      LinkedList();
      //Copy Contstructor
      LinkedList(const LinkedList<T>& );
      //Destructor
      ~LinkedList();
      int           add(const T& );
      int           add(const T&, int);
      T&            get(int);
      int           getIndex(const T&);
      int           isEmpty();
      T&            peek();
      T&            peek(int );
      T&            peekEnd();
      std::ostream& print(std::ostream& );
      T&            remove(int );
      T&            remove(const T&);
      int           size() const;
      void          sort();
      void          sortReverse();
      enum{FALSE, TRUE};
      enum{ALREADY_INSERTED,INSERTION_ERROR};
   protected:
      void size(int );
   private:
      void destroyLinkedList();
      LinkedListNode<T>* head;
      LinkedListNode<T>* tail;
      int             _isOrdered;
      int             _size;
};
//Overload the insertion Operator
template<class T>
std::ostream& operator<<(ostream&, LinkedList<T>& );

////////////////////////Class Implementations/////////////////////////
//Public Member Functions
/*
Construtor of no arguments
*/
template<class T>
LinkedList<T>::LinkedList()
 : head(nullptr),
   tail(nullptr),
   _isOrdered(0),
   _size(0){}

/*
Copy Contstructor
*/
template<class T>
LinkedList<T>::LinkedList<T>(const LinkedList<T>& rhs){
   if(this->head){
      this->destroyLinkedList();
   }
}

/*
Destructor
*/
template<class T>
LinkedList<T>::~LinkedList(){
   if(this->head){
      this->destroyLinkedList();
   }
}

//Private Member Functions
/*
*/
template<class T>
LinkedList<T>::destroyLinkedList(){
   LinkedListNode<T> temp = nullptr;
   this->tail             = nullptr;

   while(this->_head){
      temp = this->_head;
      this->_head = temp->next;
      temp->next  = nullptr;
      delete temp;
      temp = nullptr;
   }

   this->_isOrdered = 0;
   this->_size      = 0;
}

////////////////////////Function Declarations/////////////////////////
/*********************************************************************
Insertion Operator
*********************************************************************/
template<class T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& ll)
{
   return (ll.print(os));
}
#endif
 /////////////////////////////////////////////////////////////////////
