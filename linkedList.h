/* linkedList.h - header file for simple linked list of strings */
#define OK 0
#define FAIL -1
#define TRUE 1
#define FALSE 0

/* Define Linked List Structure of Node, and List */
struct  Node
{
	void *elem; //!< data element
	struct Node *link; //!< link to next node
};
typedef struct Node NODE;


struct SLList
{
	int size; //!< size of the list
	struct Node *head; //!< head of list
};
typedef struct SLList SLLIST;

/* function declarations */
/** Create a node in the list 
 * @param val pointer to data referenced by this node 
 * 	val - the */
NODE * createNode(void * val);
		
/** destroy a Node
 * @param node - the NODE to destroy
 * @param freeElem - if nonzero, free the element referenced
 */
void destroyNode(NODE * node, int freeElem);

/** Create a  Singly Linked List
 *  This uses a sentinel for the head node */ 
SLLIST * createList();

/** destroy a list 
 * @param list reference for this list
 * @param freeElem if nonzero, also free memory associated with user data
*/
void destroyList(SLLIST *list, int freeElem);
	
/** Insert an element to the front SLLIST
 * @param list the list to manipulate
 * @param elem  data to record
 * @return OK if successful, FAIL otherwise
 */
int insertElem(SLLIST * list, void * elem); 

/** Insert an element to the front SLLIST
 * @param list the list to manipulate
 * @param elem  data to record
 * @param idx index where to insert
 * @return OK if successful, FAIL otherwise
 */
int insertElemIndex(SLLIST * list, void * elem, int idx);

/** Remove the first element of the list 
 * @param list the list to manipulate
 * @return data stored, NULL if list does not exist,is empty or idx is invalid 
 */
void * removeElem(SLLIST * list);

/** Remove the first element of the list 
 * @param list the list to manipulate
 * @param idx index to remove
 * @return data stored, NULL if list does not exist,is empty or idx is invalid 
 */
void * removeElemIndex(SLLIST * list, int idx);
