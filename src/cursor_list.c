
#include <stdio.h>
#include <>

#define SPACE_SIZE 10

typedef long ELEMENT;
typedef unsigned long POSITION;

typedef struct node
{
    ELEMENT   element;
    POSITION  next;
}CURSOR_NODE;


static CURSOR_NODE list[SPACE_SIZE];

static POSITION cursor_alloc()
{
    POSIITION p;
    p = list[0].next;
    list[0].next = list[p].next;
    return p;
}
static void cursor_free(POSITION p)
{
    list[p].next = list[0].next;
    list[0].next = p;
}



int main (int argc, char *argv[])
{

}



