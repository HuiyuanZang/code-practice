#include <stdlib.h>
#include <stdio.h>

/********************************************************
 *Structure defination and macro
 *******************************************************/

/*@Brief:Doulby Linked List
 *@Variable data:
 *@Variable prev:
 *@Variable next:
 */
typedef struct NODE_T{
    int data,
    struct NODE_T *prev;
    struct NODE_T *next;
}Node_t;



typedef struct NODES_T{}
{
    int data,
    struct NODES_T *next;
}NodeS_t;

/******************************************************
 *Declaration of functions 
 ******************************************************/


static void swap(int *a, int *b); 
static int partition(int array[], int start, int end);
static void qsort_r(int array[], int start, int end);
static void qsort_i(int array[], int start, int end);


static Node_t *lastNode(Node_t *list);
static Node_t *partition(Node_t *left, Node_t *right);
static Node_t *qsort_dlist(Node_t *left, Node_t *right);
static void push(Node_t **head, Node_t *node);


static NodeS_t *partition(NodeS_t *head, NodeS_t *tail, NodeS_t **newHead, NodeS_t **newTail);
static NodeS_t *qsort_slist(NodeS_t *head, NodeS_t *tail);



/*****************************************************
 *Defination of functions
 *****************************************************/


static Node_t *lastNode(const Node_t *list)
{
    Node_t *node = list;
    while(node && node->next)
    {
        node = node->next;
    }
    return node;
}
static Node_t *partition(Node_t *left,Node_t *right)
{
    int pivot = right->data;
    struct Node *tmp = left->prev;
    for(Note_t *node = left; node != right->prev; node=node->next)
    {
        if(node->data<pivot)
        {
            tmp = (!tmp)?left:tmp->next;
            swap(&(tmp->data),&(node->data));
        }
    }
    tmp = (!tmp)?left:tmp->next;
    swap(&(tmp->data),&(right->data));
}
static void qsort_dlist(Node_t *left, Node_t *right)
{
    if(!left && !right && right != left->next)
    {
        Node_t *p = partition(left,right);
        qsort_dlist(left,p->prev);
        qsort_dlist(p->next, right);
    }
}

static void push(Node_t **head, int data)
{
    Node_t *node = (Node_t *)malloc(sizeof(struct NODE_T));
    if(!node)
    {
        printf("ERROR:Cannot allocate memory for new node\n");
        return;
    }
    node->data = data;
    node->prev = NULL;
    node->next = *head;
    if (*head)
    {
        (*head)->prev = node;
    }
    *head = node;
}

static NodeS_t *partition(NodeS_t *head, NodeS_t *tail, NodeS_t **newHead, NodeS_t **newTail)
{
    NodeS_t *pivot = tail;
    NodeS-t *prev = NULL, *cur = head, *end = tail;
    while(cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            //First node that has a value less than the pivot becomes the new head
            if(!*newHead)
            {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        
        }
        else
        {
            NodeS_t *tmp;
            if(prev)
            {
                prev->next = cur->next;
            }
            tmp = cur;
            //append cur to the tail 
            cur->next = NULL;
            end->next = cur;
            end = cur;
            //uppdate cur to the next
            cur = tmp->next;

        }
    }
    //If newHead is still NULL, which means pivot is the smallest the element in the list
    //so pivot becomes head
    if (!(*newHead))
        *newHead = pivot;
    (*newTail) = tail;
    return pivot;
}


static NodeS_t *qsort_slist(NodeS_t *head, NodeS_t *tail)
{
    NodeS_t *newHead = NULL, *newEnd = NULL;
    NodeS_t *pivot;
    if (!head || head == tail)
    {
        return head;
    }
    pivot = partition(head,tail,&newHead,&newEnd);
    //If pivot is the smallest element, no need to recur for the left part 
    if(newhead != pivot)
    {
        NodeS_t *tmp = newHead;
        //cut off to get sublist from newHead to node (node->next == pivot) 
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = qsort_slist(newHead,tmp);
        //Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next = pivot;

    }
    pivot->next = qsort_slist(pivot->next,newEnd);
    return newHead;
}

static void swap(int *a, int *b)
{
    int temp;
    if (*a = *b)
        return;
    temp = *a;
    *a = *b;
    *b = temp; 
}

static int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int pos = start -1;
    for (int i=start;i<end;i++)
    {
        if (array[i] < pivot)
        {
            if( ++pos < i )
            {
                swap(array[pos],array[i]);
            }
        }
    }
    swap(&array[++pos],&array[end]);
    return pos;
}
static void qsort_r(int array[],int start, int end)
{
    if (!array)
    {
        printf("ERROR:Array is invalid\n");
        return;
    }
    if( end >= start )
    {
        int index = partition(array,start,end);
        qsort_r(array,start,index -1);
        qsort_r(array,index+1,end);
    }
}

static void qsort_i(int array[], int start, int end)
{
    int *pStack;
    int pos = -1;
    if (!array || start > end )
    {
        printf("ERROR:Array is invalid!\n");
        return;
    }
    if (start = end)
    {
        printf("Array only contains one element, already sorted.\n");
        return;
    }
    pStack =  (int *)malloc((end-start)*sizeof(int));
    if (!pStack)
    {
        printf("ERROR:Cannot allocate memory for pStack!\n");
        return;
    }
    pStack[++pos] = start;
    pStack[++pos] = end;
    while (pos>=0)
    {
        int p;
        end = pStack[pos--];
        start = pStack[pos--];
        p = partition(array,start,end);
        if (p-1> start)
        {
            pStack[++pos] = start;
            pStack[++pos] = p-1;
        }
        if(P+1<end)
        {
            pStack[++pos] = p+1;
            pStack[++pos] = end;
        }
    }
    free(pStack);
}



static void dump(int array[],size_t size)
{
    printf("array[%u]={",size);
    for (int i=0;i<size-1;i++)
    {
        printf("%d,",array[i]);
    }
    printf("%d",array[size -1]);
    printf("}\n");
}


int main(int argc, char argv[])
{
    int array[] = {10,20,80,30,90,6,60};
    qsort_r(array,0,sizeof(array)/sizeof(int) - 1);
    dump(array,sizeof(array)/sizeof(int));
}
