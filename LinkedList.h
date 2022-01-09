//A LinkedList Class by Lou Rosas
//Part of the continuation of CIS 278 and my desire to create
//a general data structure tool set.

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream.h>
#include <iomanip.h>
#include "Node.h"

template <class Type>
class LinkedList
{
   public:
      //Constructor with no argumets
      LinkedList();

      //Copy Constructor
      LinkedList(LinkedList<Type>& );

      //Destructor
      ~LinkedList();

      //Add Data To the Stack.  Default:  FIFO
      int add(const Type& );

      //Add Data to the stack at selected index
      int add(const Type& , int );

      //Add Data to the Begining of the Linked List
      //By default should always return 0
      int addBegining(const Type& );

      //Public method to destroy the Linked List
      void destroyList();

      //Returns the Index of the given Object
      int getIndex(const Type& );

      //Returns the size of the LinkedList
      //(the number of Node Objects)
      int getSize();

      //Returns true if the LinkedList is empty
      bool isEmpty();

      //Peek at the Node Object data in the first
      //Node in the LinkedList (returns the data
      //without removeing the Node from the LinkedList)
      Type& peek();

      //Peek at a specified Node Object data at
      //a selected index (returns the data without
      //removing the Node from the LinkedList)
      Type& peek(int );

      //Peek at the Last Node in the LinkedList
      //(returns the data without removing the Node
      //from the LinkedList)
      Type& peekEnd();

      //Print out the LinkedList (First to Last order)
      void print();

      //Return AND remove the first Node in the LinkedList
      void remove(Type& );

      //Return AND remove the Node at the specified index
      //in the LinkedList
      void remove(Type& , int );

      //Return AND remove the Node at the end of the
      //LinkedList
      void removeEnd(Type& );

      //Remove the specified Node in the LinkedList.
      //If not there, don't remove anything
      void removeNode(const Type& );

      //Sort the LinkedList from Least to Greatest
      //(This is an extra feature)
      void sort();

      //Sort the LinkedList from Greatest to Least
      //(Extra feature and in reverse of the default
      //sort() method)
      void sortReverse();

      //Assignment Operator
      LinkedList<Type>& operator=(const LinkedList<Type>& );


   private:
      //Called by the Destructor, easy algorithmeic way to
      //destroy the entire LinkedList
      void destroyLinkedList();

      //Return the front pointer of the LinkedList
      Node<Type>* getFront() const;

      //Sort the list either in the forward manner or in the
      //rebese manner
      void sort(bool );

      //A pointer to the head of the LinkedList
      Node<Type>* front;

      static const int FRONT = 0;
};
//Overload the insertion operator
template <class Type>
ostream& operator<<(ostream& , LinkedList<Type>& );


//Class Implementation
//Public Methods
/********************************************************************
* Constructor                                                       *
* Constructor of no attributes, sets head = NULL                    *
********************************************************************/
template <class Type>
LinkedList<Type>::LinkedList()
 :front(0)
{
}

/********************************************************************
* Copy Constructor                                                  *
* Copies one LinkedList Object in memory to another LinkedList      *
* Object, completely separate in memory,                            *
********************************************************************/
template <class Type>
LinkedList<Type>::LinkedList(LinkedList<Type>& copy_list)
 :front(0)
{
   Node<Type>* temp_1;//the copy_list.front address
   Node<Type>* temp_2;//current object.front address

   temp_1 = copy_list.getFront();
   //Don't do anything if the copy_list does not have any nodes
   if(temp_1)
   {
      temp_2 = new Node<Type>();
      temp_2->data = temp_1->data;
      temp_2->next = NULL;
      this->front = temp_2;
      temp_1 = temp_1->next;
      while(temp_1)
      {
         temp_2->next = new Node<Type>();
         temp_2 = temp_2->next;
         temp_2->next = NULL;
         temp_2->data = temp_1->data;
         temp_1 = temp_1->next;
      }

      //Null out both temp_1 and temp_2(just to be on the safe side)
      temp_1 = NULL;
      temp_2 = NULL;
   }

}

/********************************************************************
* Destructor                                                        *
* Destroys all the Node Objects in the LinkedList                   *
********************************************************************/
template <class Type>
LinkedList<Type>::~LinkedList()
{
   //Call destroyLinkedList() to destroy the list
   this->destroyLinkedList();
}

/********************************************************************
* Add data to the end of the LinkedList                             *
* By Default: FIFO                                                  *
********************************************************************/
template <class Type>
int LinkedList<Type>::add(const Type& the_data)
{
   int temp_index = this->getSize();
   //A zero-referenced LinkedList. This will put at the end.
   return(this->add(the_data,temp_index));
}

/********************************************************************
* Add data to the specified index in the LinkedList                 *
********************************************************************/
template <class Type>
int LinkedList<Type>::add(const Type& the_data, int index)
{
   int index_value  = index;
   int current_size = this->getSize();

   Node<Type>* temp;
   Node<Type>* previous;
   Node<Type>* current;

   if(index_value > current_size)
   {
      index_value = current_size;
   }

   previous = NULL;
   temp     = NULL;
   current  = this->front;

   for(int counter = 0; counter < index_value; counter++)
   {
      previous = current;
      current  = current->next;
   }
   temp = new Node<Type>();
   temp->data = the_data;
   temp->next = current;
   if(!previous)
   {
      this->front = temp;
   }
   else
   {
      previous->next = temp;
   }

   previous = NULL;
   temp     = NULL;
   current  = NULL;

   return index_value;
}

/********************************************************************
* Add data to the begining of the LinkedList                        *
********************************************************************/
template <class Type>
int LinkedList<Type>::addBegining(const Type& the_data)
{
   const int temp_index = 0;
   //Since the LinkedList is zero referenced, this will put at the
   //begining
   return(this->add(the_data,temp_index));
}

/********************************************************************
* A public version of the destroy LinkedList method                 *
********************************************************************/
template <class Type>
void LinkedList<Type>::destroyList()
{
   this->destroyLinkedList();
}

/********************************************************************
* Return the index of the given object. Returns -1 by default.      *
********************************************************************/
template <class Type>
int LinkedList<Type>::getIndex(const Type& compare_data)
{
   int index = -1; //The default value
   int size  = this->getSize();
   Node<Type>* temp = this->getFront();

   int  counter = 0;
   bool found   = false;
   while(temp && (counter < size) && !found)
   {
      if(compare_data == temp->data)
      {
         found = true;
         index = counter;
      }
      temp = temp->next;
      counter++;
   }
   return index;
}


/********************************************************************
* Return the number of nodes (size) of the LinkedList               *
********************************************************************/
template <class Type>
int LinkedList<Type>::getSize()
{
   int size = 0; //Initialize the size value to 0
   Node<Type>* temp;

   if(front)
   {
      temp = front;
      while(temp)
      {
         ++size;
         temp = temp->next;
      }
   }
   return size;
}



/********************************************************************
* Returns true if the LinkedList is empty, false if not.            *
********************************************************************/
template <class Type>
bool LinkedList<Type>::isEmpty()
{
   return((bool)(!this->getSize()));
}

/********************************************************************
* Peek at the data in the first Node                                *
********************************************************************/
template <class Type>
Type& LinkedList<Type>::peek()
{
   return(this->peek(FRONT));
}

/********************************************************************
* Peek at the data in the selected node at the given index          *
********************************************************************/
template <class Type>
Type& LinkedList<Type>::peek(int index)
{
   Node<Type>* temp;
   Node<Type>* bad_data = new Node<Type>();
   int         count = 0;

   if(front)
   {
      if(index > this->getSize() - 1  || index < FRONT)
      {
         cerr<<"\nIndex requested out of range, bad data returned.";
         return bad_data->data;
      }
      else
      {
         temp = front;
         while(count < index)
         {
            temp = temp->next;
            ++count;
         }
         return(temp->data);
      }
   }
   else
   {
      cerr<<"\nLinked list is empty, bad data returned.";
      return bad_data->data;
   }
}


/********************************************************************
* Peek at the data in the last Node                                 *
********************************************************************/
template <class Type>
Type& LinkedList<Type>::peekEnd()
{
   int return_index = this->getSize() - 1;
   return(this->peek(return_index));
}


/********************************************************************
* Print out the linked list in order (first to last).               *
********************************************************************/
template <class Type>
void LinkedList<Type>::print()
{
   Node<Type>* temp;

   if(front)
   {
      temp = front;
      while(temp)
      {
         if(temp->next)
            cout<<temp->data<<", ";
         else
            cout<<temp->data;
         temp = temp->next;
      }
      cout<<endl;
      temp = NULL;
   }
   else
   {
      cerr<<"\nLinked list is empty, nothing to print";
   }
}

/********************************************************************
* Return the data of a the fist Node and remove the Node from the   *
* LinkedList                                                        *
********************************************************************/
template <class Type>
void LinkedList<Type>::remove(Type& return_data)
{
   this->remove(return_data, FRONT);
}

/********************************************************************
* Return the data of the given Node at a given index and remove the *
* Node from the LinkedList                                          *
********************************************************************/
template <class Type>
void LinkedList<Type>::remove(Type& return_data, int index)
{
   Node<Type>* current;
   Node<Type>* previous;

   int counter = 0;
   int index_value = index;

   current  = NULL;
   previous = NULL;

   if(front)
   {
      if((index_value > (this->getSize() - 1)) || (index < FRONT))
      {
         cerr<<"\nIndex requested out of range, nothing removed";
         cerr<<" bad data returned.";
      }
      else
      {
         current = this->front;
         while(counter < index_value)
         {
            previous = current;
            current  = current->next;
            ++counter;
         }
         if(!previous)
         {
            this->front = current->next;
         }
         else
         {
            previous->next = current->next;
         }
         current->next = NULL;
         return_data = current->data;
         delete current;
      }
   }
   else
   {
      cerr<<"\nLinked List is empty, bad data returned.";
   }

   current  = NULL;
   previous = NULL;
}

/********************************************************************
* Return the data of Node at the end of the LinkedList              *
********************************************************************/
template <class Type>
void LinkedList<Type>::removeEnd(Type& return_data)
{
   int return_index = this->getSize() - 1;
   this->remove(return_data, return_index);
}

/********************************************************************
* Remove the specific Node with the selected data in the LinkedList *
* (if it exists).  Don't destroy anything if the data is not in the *
* LinkedList.                                                       *
********************************************************************/
template <class Type>
void LinkedList<Type>::removeNode(const Type& remove_data)
{
   int index = this->getIndex(remove_data);
   if(index > -1)
   {
      Node<Type>* previous = NULL;
      Node<Type>* current  = NULL;

      int counter = 0;
      current = this->getFront();
      while(counter < index)
      {
         previous = current;
         current  = current->next;
         ++counter;
      }
      if(!previous)
      {
         this->front = current->next;
      }
      else
      {
         previous->next = current->next;
      }
      current->next = NULL;
      delete current;

      previous = NULL;
      current  = NULL;
   }
   else
   {
      cerr<<"\nRequested data not in Linked List, nothing removed.";
   }
}

/********************************************************************
* Sort the LinkedList from least-greatest                           *
********************************************************************/
template <class Type>
void LinkedList<Type>::sort()
{
   //Sort forward
   this->sort(true);
}

/********************************************************************
* Sort the LinkedList in reverse of the default sort                *
* (greatest-least)                                                  *
********************************************************************/
template <class Type>
void LinkedList<Type>::sortReverse()
{
   //Sort reverse
   this->sort(false);
}

/********************************************************************
* Assignment operator                                               *
********************************************************************/
template <class Type>
LinkedList<Type>&  LinkedList<Type>::operator=
(
   const LinkedList<Type>& list
)
{
   Node<Type>* temp_1; //the list.front address
   Node<Type>* temp_2; //current object.front address

   //If a Linked List exists, destroy it
   if(this->getFront())
   {
      this->destroyLinkedList();
   }

   temp_1 = list.getFront();
   if(temp_1)
   {
      temp_2 = new Node<Type>();
      temp_2->data = temp_1->data;
      temp_2->next = NULL;
      this->front = temp_2;
      temp_1 = temp_1->next;
      while(temp_1)
      {
         temp_2->next = new Node<Type>();
         temp_2 = temp_2->next;
         temp_2->next = NULL;
         temp_2->data = temp_1->data;
         temp_1 = temp_1->next;
      }
   }
   else
   {
      this->front = NULL;
   }

   //Null out both temp_1 and temp_2
   temp_1 = NULL;
   temp_2 = NULL;

   return *this;
}


//Private Methods
/********************************************************************
* Destroy the LinkedList                                            *
********************************************************************/
template <class Type>
void LinkedList<Type>::destroyLinkedList()
{
   Node<Type>* temp;
   while(front)
   {
      temp = this->front;
      front = front->next;
      temp->next = NULL;
      delete temp;
      temp = NULL;
   }
   front = NULL;
}


/********************************************************************
* Get the front pointer of the LinkedList                           *
********************************************************************/
template <class Type>
Node<Type>* LinkedList<Type>::getFront() const
{
   return(this->front);
}

/********************************************************************
* Sort the LinkedList in accordance to the Boolean value passed     *
* in.  True:  sort forwards  (least-greatest),                      *
*      False: sort backwards (greatest-least)                       *
********************************************************************/
template <class Type>
void LinkedList<Type>::sort(bool forward)
{
   Node<Type>* previous;
   Node<Type>* current;
   Node<Type>* temp;

   current  = NULL;
   previous = NULL;
   temp     = NULL;

   if(front)
   {
      temp = new Node<Type>();
      temp->next = NULL;

      previous = front;
      while(previous)
      {
         current = previous->next;
         while(current)
         {
            if(
                (forward && (current->data < previous->data)) ||
                (!forward && (current->data > previous->data))
              )
              {
                 temp->data     = previous->data;
                 previous->data = current->data;
                 current->data  = temp->data;
              }
              current = current->next;
         }
         previous = previous->next;
      }
      delete temp;
      temp     = NULL;
      previous = NULL;
      current  = NULL;
   }
   else
   {
      cerr<<"\nLinked List is empty, nothing to sort.";
   }
}


/********************************************************************
* Insertion operator                                                *
********************************************************************/
template <class Type>
ostream& operator<<(ostream& os, LinkedList<Type>& ll)
{
   ll.print();
   return os;
}
#endif
