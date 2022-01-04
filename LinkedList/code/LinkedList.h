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
 * along with this program. If not, see <http://www.gnu.org/licenses/>
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
      void          clear();
      int           contains(const T&);
      T&            get(int);
      int           getIndex(const T&);
      int           isEmpty();
      T&            peek();
      T&            peek(int );
      T&            peekEnd();
      std::ostream& print(std::ostream& );
      T&            remove(int );
      int           remove(const T&);
      int           size() const;
      void          sort();
      void          sortReverse();
      enum{FALSE, TRUE};
      enum{INSERTION_ERROR = -0XF,
           NOT_INSERTED = -1,
           ALREADY_INSERTED = 0};
   protected:
      void size(int );
   private:
      void destroyLinkedList();
      void merge(int,int,int);
      void mergeReverse(int, int, int);
      void mergeSort(int, int, int);
      LinkedListNode<T>* head;
      LinkedListNode<T>* tail;
      T               _data;
      int             _size;
};
//Overload the insertion Operator
template<class T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& list);

////////////////////////Class Implementations/////////////////////////
//Public Member Functions
/*
Construtor of no arguments
*/
template<class T>
LinkedList<T>::LinkedList()
 : head(nullptr),
   tail(nullptr),
   _size(0){}

/*
Copy Constructor
*/
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
   if(this->head){
      this->destroyLinkedList();
      this->head = nullptr;
   }
   for(int i = 0; i < rhs.size(); ++i){
      this->add(rhs.get(i));
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

/**/
template<class T>
int LinkedList<T>::add(const T& input){
   int added = NOT_INSERTED;
   if(this->contains(input) != TRUE){
      LinkedListNode<T>* temp = new LinkedListNode<T>();
      temp->data = input;
      temp->next = nullptr;
      //Add to the BACK of the Linked List...
      if(this->head == nullptr){
         this->head = temp;
         this->tail = this->head;
      }
      else{
         this->tail->next = temp;
         this->tail = temp;
      }
      temp = nullptr;
      ++this->_size;
      added = this->_size;
   }
   return added;
}

/**/
template<class T>
int LinkedList<T>::add(const T& input, int index){
   int added = NOT_INSERTED;
   if(this->contains(input) != TRUE){
      LinkedListNode<T>* current  = nullptr;
      LinkedListNode<T>* previous = nullptr;
      LinkedListNode<T>* temp     = nullptr;
      if((index >= this->_size) || (this->head == nullptr)){
         added = this->add(input);
      }
      else{
         current = this->head;
         for(int i = 0; i < index; ++i){
            previous = current;
            current  = current->next;
         }
         temp = new LinkedListNode<T>();
         if(temp != nullptr){
            temp->data = input;
            temp->next = current;
            if(previous == nullptr){
               this->head = temp;
            }
            else{
               previous->next = temp;
            }
            ++this->_size;
            added = this->_size;
         }
         current  = nullptr;
         previous = nullptr;
         temp     = nullptr;
      }
   }
   return added;
}

/**/
template<class T>
void LinkedList<T>::clear(){
   this->destroyLinkedList();
}


/**/
template<class T>
int LinkedList<T>::contains(const T& input){
   int found = FALSE;
   LinkedListNode<T>* temp = this->head;
   while(temp && !found){
      found = (temp->data == input);
      temp  = temp->next;
   }
   return found;
}

/**/
template<class T>
T& LinkedList<T>::get(int index){
   if(index < this->_size){
      LinkedListNode<T>* temp = this->head;
      for(int i = 0; i < index; ++i){
         temp = temp->next;
      }
      return temp->data;
   }
   else{
      int error = NOT_INSERTED;
      throw error;
   }
}

/**/
template<class T>
int LinkedList<T>::getIndex(const T& input){
   int index = NOT_INSERTED;
   int found = FALSE;
   int idx   = 0;
   try{
      while(idx < this->size() && !found){
         if(this->get(idx) == input){
            found = TRUE;
            index = idx;
         }
         ++idx;
      }
   }
   catch(int x){
      index = NOT_INSERTED;
   }
   return index;
}

/**/
template<class T>
int LinkedList<T>::isEmpty(){
   return(!(this->size()));
}

/**/
template<class T>
T& LinkedList<T>::peek(){
   try{
      return(this->peek(0));
   }
   catch(int x){
      throw x;
   }
}

/**/
template<class T>
T& LinkedList<T>::peek(int index){
   try{
      return(this->get(index));
   }
   catch(int x){
      throw x;
   }
}

/**/
template<class T>
T& LinkedList<T>::peekEnd(){
   if(!(this->isEmpty())){
      return this->tail->data;
   }
   else{
      int error = NOT_INSERTED;
      throw error;
   }
}

/**/
template<class T>
std::ostream& LinkedList<T>::print(std::ostream& os){
   for(int i = 0; i < this->size(); ++i){
      try{
         os<<this->get(i);
         if(i < (this->size() - 1)){
            os<<", ";
         }
      }
      catch(int x){}
   }
   return os;
}

/**/
template<class T>
T& LinkedList<T>::remove(int index){
   if(index < this->_size){
      LinkedListNode<T>* current  = this->head;
      LinkedListNode<T>* previous = nullptr;
      for(int i = 0; i < index; ++i){
         previous = current;
         current  = current->next;
      }
      if(previous == nullptr){
         this->head = current->next;
      }
      else{
         previous->next = current->next;
         if(current == this->tail){
            this->tail = previous;
         }
      }
      this->_data   = current->data;
      current->next = nullptr;
      delete current;
      current       = nullptr;
      previous      = nullptr;
      --this->_size;
      return this->_data;
   }
   else{
      int error = NOT_INSERTED;
      throw error;
   }
}

/**/
template<class T>
int LinkedList<T>::remove(const T& toRemove){
   int removed = this->contains(toRemove);
   if(removed){
      int index = this->getIndex(toRemove);
      this->remove(index);
   }
   return removed;
}

/**/
template<class T>
int LinkedList<T>::size() const{
   return this->_size;
}

/**/
template<class T>
void LinkedList<T>::sort(){
   this->mergeSort(0,this->size(),(int)FALSE);
}

//Private Member Functions
/*
*/
template<class T>
void LinkedList<T>::destroyLinkedList(){
   LinkedListNode<T>* temp = nullptr;
   this->tail              = nullptr;

   while(this->head){
      temp = this->head;
      this->head  = temp->next;
      temp->next  = nullptr;
      delete temp;
      temp = nullptr;
   }
   this->_size      = 0;
}

/*
As far as I can tell, just keep track of pointers...for pointer
arithmetic...make it simple for now
*/
template<class T>
void LinkedList<T>::merge(int left, int middle, int right){
   LinkedListNode<T>* begining      = this->head;
   LinkedListNode<T>* leftEnd       = this->head;
   LinkedListNode<T>* rightBegining = this->head;
   int n1 = middle - left + 1; // Left  Counter
   int n2 = right - middle;    //Right Counter
   T* L = new T[n1];
   T* R = new T[n2];

   for(int i = 0; i < left; ++i){
      begining = begining->next;
   }
   for(int i = 0; i < middle; ++i){
      leftEnd = leftEnd->next;
   }
   for(int i = 0; i < right; ++i){
      rightBegining = rightBegining->next;
   }
   LinkedListNode<T>* temp = begining;
   for(int i = 0; i < n1; ++i){
      L[i] = temp->data;
      temp = temp->next;
   }
   temp = rightBegining;
   for(int i = 0; i < n2; ++i){
      R[i] = temp->data;
      temp = temp->next;
   }
   temp = begining;
   int i = 0;
   int j = 0;
   for(int k = 0; k < n1 + n2; ++k){
      if((i < n1) && (L[i] <= R[j])){
         temp->data = L[i];
         ++i;
      }
      else if(j < n2){
         temp->data = R[j];
         ++j;
      }
      temp = temp->next;
   }
   delete [] L;
   delete [] R;
}

/**/
template<class T>
void LinkedList<T>::mergeReverse(int left, int middle, int right){}

/**/
template<class T>
void LinkedList<T>::mergeSort(int left, int right, int isReverse){
   if(left < right){
      int middle = (int)((left + right)/2);
      this->mergeSort(left, middle, isReverse);
      this->mergeSort(middle + 1, right,  isReverse);
      //this->mergeSort(left, middle, isReverse);
      //this->mergeSort(middle+1, right-1,  isReverse);
      if(isReverse){
         this->mergeReverse(left,middle,right);
      }
      else{
         this->merge(left,middle,right);
      }
   }
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
