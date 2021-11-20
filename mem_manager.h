//CIS 269
//The Memory Manager Header file
//Lou Rosas

#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H

#include <stddef.h>
#include <stdlib.h>
#include <iostream.h>
#include "LinkedList.h"
#include "Node.h"
#include "NodeData.h"
//Globals
static NodeData current_data;
static LinkedList<NodeData> ll;

//Function Prototypes
void  startMem();         //Initializes the LinkedList
void  stopMem();          //Frees the remaining used memory

/*********************************************************
* Allocate a memory of the size requested. Add its entry *
* to the Linked List and return the pointer.             *
*********************************************************/
void* mallocMem(size_t ); 

/********************************************************
* Search for a pointer in the Linked List.  If located  *
* free the memory and remove from the Linked List.      *
********************************************************/
void  freeMem(void* );

/********************************************************
* Print the Linked List                                 *
********************************************************/
void  print_list();

#endif
