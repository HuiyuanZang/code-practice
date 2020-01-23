#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS          26
#define MAX_WORD_SIZE      30

#define TO_LOWER(c)      \
        ((c) >= 'A' && (c) <= 'Z')?(c) + 'a' -'A':(c)

#define CHAR_TO_IDEX(c) (int)(TO_LOWER(c) - 'a')



typedef enum TrieNodeType_E{
    Trie_END;
    Trie_NOEND;
}TireNodeType_e;

typedef struct TrieNode_T{
    TireNodeType_e type; //if no this type, have to check if all children are NULL or not 
    unsigned frequency;
    int index2heap;
    struct TriedNode_T *child[MAX_CHARS]; //array of pointer to trie node NOTE: struct TriedNode_t
}TrieNode_t;

typedef struct MinHeapNode_T{
    TrieNode_t *node;
    unsigned frequency;
    char *word;
}MinHeapNode_t;


typedef struct MinHeap_T{
    unsigned capacity;
    unsigned size;
    MinHeapNode_t *nodes;
}MinHeap_t;


static char tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return a + 'a' - 'A';
    else 
        return c;
}
/*
 * @ Breif:Is a less than b?
 *         if a < b then return 1
 *         else return 0
 */
static int less_than(MinHeapNode_t *a, MinHeapNode_t *b)
{
    return a->frequency < b->frequency?1:0;
}

static void swap(MinHeapNode_t *node1,int index1, MinHeapNode_t *node2,int index2)
{
    MinHeapNode_t tmp;
    tmp = *node1;
    *node1 = *node2;
    *node2 = tmp;
    node1->node.index2heap = index2;
    node2->node.index2heap = index1;
}
static TrieNode_t *create_trienode()
{
    TrieNode_t node = (TriedNode_t *) malloc(sizeof(TrieNode_t));
    if(node)
    {
        node->type = Trie_NOEND;
        node->frequency = 0;
        node->index2heap = -1;
        for ( int i = 0; i<MAX_CHARS; i++ )
        {
            node->child[i] = NULL;
        }
    }
    return node;
}
static MinHeap_t *create_heap(unsigned capacity)
{
    MinHeap_t *heap = (MinHeap_t *) malloc(sizeof(MinHeap_t));
    if ( heap )
    {
        heap->capacity = capacity;
        heap->size = 0;
        heap->nodes = (MinHeapNode_t *)malloc(sizeof(MinHeapNode_t)*capacity);
        if(!heap->nodes)
        {
            free(heap);
            heap = NULL;
        }
    }
    return heap;
}

static void heapify(MinHeap_t *heap, int index)
{
    int tmp;
    int left  = 2*index + 1;
    int right = 2*index + 2;
    //case 1, if node[index] hasn't left and right child
    if ( left > size-1 )
    {
        return;
    }
    //case 2, if node[index] has left child but no right child
    if ( left == size )
    {
        //if node[index] > heap->nodes[left], swap
        if(less_than(&heap->nodes[left],&heap->nodes[index]) > 0)
        {   
            swap(heap->nodes+index,index,heap->nodes+left,left);
        }
        return;
    }
    //case 3 if node has both left and right child (right >= size)
    //compare node[left] and node[right] first, find the smaller child,
    //then compare with node[index]
    tmp = less_than(&heap->nodes[left],&heap->nodes[right])>0?left:right;
    if ( less_than(heap->nodes[tmp],heap->nodes[index]) > 0 )
    {
        swap(heap->nodes+tmp,tmp,heap->nodes+index,index);
        heapify(heap,tmp);
    }
} 

static MinHeapNode_t *addWord_Heap(MinHeap_t *heap, TriedNode_t *node, const char *word)
{
    if (node->index2heap == -1)
    {
    }
    else//Trie node already in heap
    {
        heap->nodes[node->index2heap]->frequency++;
        heapify(heap,node->index2heap);
    }
}

static TrieNode_t *addword_Trie(TrieNode_t *root, const char *word)
{
    TrieNode_t *node = root;
    int len = strlen(word);
    //create root, root doesn't contian any character
    if (!root)
    {
        printf("Error:Trie root is NULL!\n");
        return NULL;
    }
    for ( int i = 0; i<len; i++ )
    {
        int index = CHAR_TO_INDEX(word[i]);
        if( !node->child[index] )
            node->child[index] = create_trienode();
        node = node->child[index];
    }
    node->frequency++;
    if ( node->type != Trie_END)
    {
        node->type = Trie_END;
    }
    return node;
}



int main(int argc, char *argv[])
{

}
