/*
 * 
 */


/*
 * Headers and Macro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLOT_TABLE_MAX   101

typedef struct NODE_T{
    void *data;
    size_t dataSize;
    struct NODE_T *prev;
    struct NODE_T *next;
}Node_t;


typedef struct ENTRY_T{
    struct NONE_T *head;
    struct NONE_T *tail;
    size_t nodeSize;
}Entry_t;



static Entry_t table[SLOT_TABLE_MAX];


/*
 * static functions declaration
 */

static unsigned  long hash(unsigned long value)
{
    return value % SLOT_TABLE_MAX;
}

/*
 * global varaible 
 */




static void init()
{
    memset(table,0x00, sizeof(Entry_t)*SLOT_TABLE_MAX);
}

/*
 * Insert  
 */
static int insert(unsigned long key, void *data, size_t dataSize)
{
    Entry_t *pEntry =  &table[hasy(key)];
    Node_t *pNode = (Node_t *) malloc(sizeof(Node_t));
    if(!node)
    {
        printf("Error: Cannot allocate %u memroy for structure Node_t\n", sizeof(Node_t));
        return -1;
    }
    pNode->data =  malloc(dataSize);
    if ( ! pNode->data )
    {
        printf("Error: Cannot allocata %u memory for data\n",dataSize);
        return -1;
    }
    memcpy(pNode->data,data,dataSize);
    if(pEntry->next == NULL)
    {

    }
    pNode->next = NULL;
    pNode->prev = pEntry->tail;
    pEntry->tail->next = pNode;
    pEntry->tail = pNode;
    pEntry->nodeSize++;

}

static int delete(unsigned long key, void *data)
{
    Entry_t *pEntry =  &table[hasy(key)];
    
    while()
    {

    }
}


int main(int argc, char *argv[])
{

}·
