//A Stack class by Lou Rosas
// For CIS 278:  Object Oriented Programing

#ifndef STACK_H
#define STACK_H

#include <iostream.h>
#include <iomanip.h>

template <class Type>
class Node
{
   public:
      Type data;
      Node<Type>* next;
};

template <class Type>
class Stack
{
   public:
      //Constructor with no arguments
      Stack();

      //Copy constructor
      Stack(Stack<Type>& );

      //Destructor
      ~Stack();

      //Initialize the Stack
      void initializeStack();

      //destroy the stack completely
      void destroyStack();

      //check to see if the stack is empty
      bool isEmpty();

      //assignment operator
      Stack<Type>& operator=(const Stack<Type>& );

      //Push an object onto the stack
      void push(const Type& );

      //Pop an object the top element off the stack, 
      //returning that element
      void pop(Type& );

      //Peek at the top element without removing it, 
      //returning that element
      Type peek();

      //Print method (Prints first element input in the 
      //stack to the last)
      void print();
      
      //Get the count of the stack
      int getCount();
      
   private:
      //A recursive print method
      void print(Node<Type>* );

      //A pointer to the first element in the stack
      Node<Type>* top;
};

//Class Implementation
//Public Methods
/********************************************************************
* Constructor                                                       *
* Constructor of no attributes, sets top = NULL                     *
********************************************************************/
template<class Type>
Stack<Type>::Stack()
 :top(0)
{}

/********************************************************************
* Copy Constructor                                                  *
* Copies one Stack object in memory to another stack object in a    *
* copletely separate space in memory                                *
********************************************************************/
template<class Type>
Stack<Type>::Stack(Stack<Type>& copy_stack)
{
   Node<Type>* temp, copy_temp;

   //Destroy the current stack
   this->destroyStack();
   //Copy the copy_stack object elements to this stacks elements
   copy_temp = copy_stack.top;
   //If the other stack exists, set the top element data
   //to the top element data of the copy_temp stack
   if(copy_temp)
   {
      temp = new Node<Type>();
      temp->data = copy_temp->data;
      top  = temp;
      top->next = NULL;
      copy_temp = copy_temp->next;
      while(copy_temp)
      {
         temp->next = new Node<Type>();
         temp = temp->next;
         temp->data = copy_temp->data;
         copy_temp = copy_temp->next;
      }
      temp->next = NULL;
      temp       = NULL;
   }
}

/********************************************************************
* Destructor                                                        *
* Destroys all the nodes in the stack, sets the top = NULL          *
********************************************************************/
template<class Type>
Stack<Type>::~Stack()
{
   this->destroyStack();
}

/********************************************************************
* Initialization of the stack.  Sets the stack to an empty state,   *
* setting top = NULL and the stack empty                            *
********************************************************************/
template<class Type>
void Stack<Type>::initializeStack()
{
   this->destroyStack();
}

/********************************************************************
* Destrucntion of the stack.  Sets the stack to an empty state,     *
* setting top = NULL and the stack empty                            *
********************************************************************/
template<class Type>
void Stack<Type>::destroyStack()
{
   Node<Type>* temp;
   
   while(top)
   {
      temp = this->top;
      top  = top->next;
      temp->next = NULL;
      delete temp;
      temp = NULL;
   }
   top = NULL; //just to be on the safe side
}

/********************************************************************
* Checks to see if the stack is empty                               *
********************************************************************/
template<class Type>
bool Stack<Type>::isEmpty()
{
   //The way this class is diesigned, if top contains a valid
   //address, then the stack is not empty.  If top is NULL,
   //the stack is empty.
   return (!top);
}

/********************************************************************
* Assignment opperator:  Assigns one stack to another stack. This   *
* implementation makes a "Deep Copy" of the stack to be copied.     *
********************************************************************/
template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& copy_stack)
{
   Node<Type>* temp, copy_temp;

   copy_temp = copy_stack.top;
   if(copy_temp)
   {
      temp = new Node<Type>();
      temp->data = copy_temp->data;
      this->top = temp;
      copy_temp = copy_temp->next;
      while(copy_temp)
      {
         temp->next = new Node<Type>();
         temp = temp->next;
         temp->data = copy_temp->data;
         copy_temp = copy_temp->next;
      }
      temp->next = NULL;
      temp = NULL;
   }
   return *this;
}

/********************************************************************
* Push an object onto the stack                                     *
********************************************************************/
template<class Type>
void Stack<Type>::push(const Type& the_data)
{
   Node<Type>* temp;

   temp = new Node<Type>();
   temp->data = the_data;
   temp->next = top;
   top = temp;
   temp = NULL;
}

/********************************************************************
* Pop an object off the stack, returning that object to the caller  *
* NOTE:  the user better know what they are doing in order to use   *
* this method:  they have to send in an object of the same type they*
* are attempting to pop off the stack.                              *
********************************************************************/
template<class Type>
void Stack<Type>::pop(Type& popped_type)
{
   Node<Type>*temp;

   if(top)
   {
      temp = top;
      top = top->next;
      temp->next = NULL;
      popped_type = temp->data;
      delete temp;
      temp = NULL;
   }
   else
   {
      cerr<<"\nStack is empty.\n";
   }
}


/********************************************************************
* Look at the top object on the stack without poping it off the     *
* stack.                                                            *
********************************************************************/
template<class Type>
Type Stack<Type>::peek()
{
   Type return_data;
   if(top)
   {
      return_data = top->data;
   }
   else
   {
      cerr<<"\nStack is empty.\n";
   }
   return(return_data); 
}

/********************************************************************
* Print out the stack in "reverse order" (first one entered to      *
* last one entered).  Calls print(Node<Type>* )                     *
********************************************************************/
template<class Type>
void Stack<Type>::print()
{
   if(top)
   {
      //Start from the top of the stack
      this->print(top);
   }
   else
   {
      cerr<<"\nStack is empty, nothing to print.\n";
   }
}

template<class Type>
int Stack<Type>::getCount()
{
   int count = 0;
   Node<Type>* temp;
   temp = top;
   while(temp)
   {
      temp = temp->next;
      count++;
   }
   return count;
}

//private methods
/********************************************************************
* Print out the stack from the first one entered to the last entered*
* by making this method recursive.                                  *
********************************************************************/
template<class Type>
void Stack<Type>::print(Node<Type>* node)
{
   if(node->next)
   {
      this->print(node->next);
   }
   cout<<node->data<<' ';
}

#endif
