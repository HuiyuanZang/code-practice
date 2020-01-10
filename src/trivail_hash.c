
/*
 * The purpose of the code is to show handle the key range from -(KEY_MAX) to (KEY_MAX)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



#define KEY_MAX     10


typedef struct NODE_T
{
    unsigned long key;
    unsigned long dataLink;
    size_t        dataSize;
}Node_t; 

static Node_t table[KEY_MAX+1][2];


static void initilise()
{
    memset(table,0x00, sizeof(Node_t)*2);
}

static int  insert(long key, void *data, size_t dataSize )
{
    Node_t node;
    if (key<0)
    {
        node = table[abs(key)][0];
    }
    else
    {
        node = table[key][1];
    }
    //In order to overwrite old node, release all memory for old node 
    if (node.dataLink&& dataSize != 0)
    {
        free(node.dataLink);
        node.dataLink = NULL;
        dataSize = 0;
    }
    if (node.dataLink =(unsigned long) malloc(dataSize))
    {
        memcpy((void *)node.dataLink, data, dataSize );
        node.dataSize = dataSize;
        return 0;
    }
    else
    {
        printf("Error: Cannot allocate Memory\n");
        return -1;
    }
}
staic void delete(key)
{

    Node_t node;
    if (key<0)
    {
        node = table[abs(key)][0];
    }
    else
    {
        node = table[key][1];
    }
    if (node.dataLink&& dataSize != 0)
    {
        free(node.dataLink);
        node.dataLink = NULL;
        dataSize = 0;
    }
}

static Node_t* search(long key)
{

    Node_t node;
    if (key<0)
    {
        node = table[abs(key)][0];
    }
    else
    {
        node = table[key][1];
    }
    if (node.dataLink && dataSize != 0)
    {
        return &node;
    }
    else 
        return NULL;
}



int main(int argc, char *argv[])
{

}
