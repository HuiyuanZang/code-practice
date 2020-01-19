/*
*Given two list, try to find if 1st list is presented in 2nd list
*/

#include <stdio.h>
#include <stdlib.h>


// A Linked List node 
typedef struct Node_T
{ 
    int data; 
    struct Node_T* next; 
}Node; 
  
static Node *find_element(Node *list, Node *node)
{
    while(list&&node&&(list->data != node->data))
	{
	    list = list->next;
	}
	return list;
}

 
static Node *findList(Node* list1, Node* list2) 
{ 
    Node *node1;
	Node *node2;
	Node *cur;
    
	if(!list1 || !list2)
	{
	    return NULL;
	}
	//find if the first element of 2nd list exists in 1st list
    cur = node1 = find_element(list1,list2);
	while(node1)
	{
	    node2 = list2;
	    while(node2&&(node1->data == node2->data))
		{
			//if node is the tail of list1, but list2 hasn't finished
			if(!node1->next && node2->next)
			    return NULL;
			//if compare all element of list2 areadly done 
			if(!node2->next)
			    return cur;
			node1 = node1->next;
			node2 = node2->next;
        }
	    cur = node1 = find_element(cur->next,list2);
	}
	return NULL;
} 
  
/* Function to print nodes in a given linked list */
static void printList(Node* node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
  
// Function to add new node to linked lists 
static Node *newNode(int key) 
{ 
    Node *temp = (Node *)malloc(sizeof(Node)); 
    temp-> data= key; 
    temp->next = NULL; 
    return temp; 
} 
  
/* Driver program to test above functions*/
int main(int argc, char *argv[] )
{ 
    /* Let us create two linked lists to test 
    the above functions. Created lists shall be 
        a: 1->2->3->4 
        b: 1->2->1->2->3->4*/
    Node *ret;
    Node *a = newNode(1); 
    a->next = newNode(2); 
    a->next->next = newNode(3); 
    a->next->next->next = newNode(4);

  
    Node *b = newNode(1); 
    b->next = newNode(2); 
    b->next->next = newNode(1); 
    b->next->next->next = newNode(2); 
    b->next->next->next->next = newNode(3); 
    b->next->next->next->next->next = newNode(4); 
  
    ret = findList(b,a);
    
    printf("ret = %p ret->data = %d \n",ret,ret?ret->data:-1);

  
    return 0; 
} 



