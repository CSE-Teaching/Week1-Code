/** This is the C version of Singly Linked List 
 * a linked list and then reversing
 * Author: Philip Papadopoulos
 */

#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 
#include "linkedList.h"

/** Create a node in the list 
 * @param val pointer to data referenced by this node 
 * 	val - the */
NODE * createNode(void * val)
{
	NODE * rNode;
	rNode = (NODE *) malloc(sizeof(NODE));
	rNode->elem = val; 
	rNode->link = (NODE *) NULL;
	return rNode;
}
		
/** destroy a Node
 * @param node - the NODE to destroy
 * @param freeElem - if nonzero, free the element referenced
 */
void destroyNode(NODE * node, int freeElem)
{
	if (! node ) return;
	if (freeElem && node -> elem)
		free( node -> elem );
	free(node);
} 

/** Create a  Singly Linked List
 *  This uses a sentinel for the head node */ 
SLLIST * createList()
{
	SLLIST *rval;
	rval = (SLLIST *) malloc(sizeof(SLLIST));
	rval -> size = 0;
	rval -> head = createNode( (void *) NULL); 
	return rval;
}

/** destroy a list 
 * @param list reference for this list
 * @param freeElem if nonzero, also free memory associated with user data
*/
void destroyList(SLLIST *list, int freeElem)
{
	if (!list) return;
	NODE * node, *tmp;
	node = list -> head;
	while (node)  // destroy the linked list of nodes
	{
		tmp = node;
		node = node -> link;
		destroyNode(tmp, freeElem);
	}
	free(list);
}
	
	
/** Insert an element to the front SLLIST
 * @param list the list to manipulate
 * @param elem  data to record
 * @return OK if successful, FAIL otherwise
 */
int insertElem(SLLIST * list, void * elem) // Add element at head of list
{
	return insertElemIndex(list, elem, 0);
}	

/** Insert an element to the front SLLIST
 * @param list the list to manipulate
 * @param elem  data to record
 * @param idx index where to insert
 * @return OK if successful, FAIL otherwise
 */
int insertElemIndex(SLLIST * list, void * elem, int idx)
{
	int i;
	if (!list || !elem) return FAIL;
	NODE * new;
	NODE * head = list->head;
	for (i = 0; i < idx; i ++)
		head = head->link;
	if (!head) return FAIL;
	
	new = createNode(elem);
	new->link = head->link; 
	head->link = new;
	list -> size ++;
	return OK;
}	
/** Remove the first element of the list 
 * @param list the list to manipulate
 * @return data stored, NULL if list does not exist,is empty or idx is invalid 
 */
void * removeElem(SLLIST * list)
{
	return removeElemIndex(list, 0);
}

/** Remove the first element of the list 
 * @param list the list to manipulate
 * @param idx index to remove
 * @return data stored, NULL if list does not exist,is empty or idx is invalid 
 */
void * removeElemIndex(SLLIST * list, int idx)
{
	int i;
	if (! list) return (void *) NULL;
	NODE * r;
	void * rval;
	NODE * head = list->head;
	for (i = 0; i < idx; i ++)
		head = head->link;

	if (!head) return (void *) NULL;

	if (r =  head -> link)
	{
		rval = r->elem;
		head->link =  r->link;
		destroyNode(r, FALSE); // does NOT free the malloc'ed elem
		list -> size --;
		return rval;
	}
	return (void *) NULL;
}

