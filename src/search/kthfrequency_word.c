#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHARS          26
#define MAX_WORD_SIZE      30

#define TO_LOWER(c)      \
        ((c) >= 'A' && (c) <= 'Z')?(c) + 'a' -'A':(c)

#define CHAR_TO_INDEX(c) (int)(TO_LOWER(c) - 'a')



typedef enum TrieNodeType_E{
    Trie_END,
    Trie_NOEND
}TireNodeType_e;

typedef struct TrieNode_T{
    TireNodeType_e type; //if no this type, have to check if all children are NULL or not 
    unsigned frequency;
    int index2heap;
    struct TrieNode_T *child[MAX_CHARS]; //array of pointer to trie node NOTE: struct TriedNode_t
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


static int tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 'a' - 'A');
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
    node1->node->index2heap = index2;
    node2->node->index2heap = index1;
}
static TrieNode_t *create_trienode()
{
    TrieNode_t *node = (TrieNode_t *) malloc(sizeof(TrieNode_t));
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
    if ( left > heap->size - 1 )
    {
        return;
    }
    //case 2, if node[index] has left child but no right child
    if ( left == heap->size )
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
    if ( less_than(&heap->nodes[tmp],&heap->nodes[index]) > 0 )
    {
        swap(&heap->nodes[tmp],tmp,&heap->nodes[index],index);
        heapify(heap,tmp);
    }
} 
static void heapify_upward(MinHeap_t *heap, int index)
{
    int parent = (index-1)/2;
    while ( parent >= 0 )
    {
        if( less_than(&heap->nodes[index], &heap->nodes[parent]) > 0)
        {
            swap(&heap->nodes[index],index,&heap->nodes[parent],parent);
            parent = (parent-1)/2;
        }
        else 
            break;
    }
}


static void addTrieNode_Heap(MinHeap_t *heap, TrieNode_t *node, const char *word)
{
    //Trie node hasn't been in heap
    if (node->index2heap == -1)
    {
        //the heap is full and the frequency of word is more than the root of heap
        //the root should be the kth most frequency word
        //we need replace root with new word
        if (heap->size == heap->capacity)
        {
            //before any assign new one, release old resource,
            //detach original trie node with heap
            heap->nodes[0].node->index2heap = -1;
            free(heap->nodes[0].word);
            //
            heap->nodes[0].frequency = node->frequency;
            heap->nodes[0].node = node;
            heap->nodes[0].word = strdup(word);
            node->index2heap = 0;

            heapify(heap,0);
        }
        else//else,add new node to the latest postion
        {
            heap->nodes[heap->size].frequency = node->frequency;
            heap->nodes[heap->size].word = strdup(word);
            heap->nodes[heap->size].node = node;
            node->index2heap = heap->size;
            heap->size++;
            heapify_upward(heap,heap->size - 1 );
        }
    }
    else//Trie node already in heap
    {
        heap->nodes[node->index2heap].frequency++;
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

static void add(MinHeap_t *heap, TrieNode_t *root, const char *word)
{
    TrieNode_t *node = addword_Trie(root, word);
    addTrieNode_Heap(heap,node,word);
}

static void dump_heap(MinHeap_t *heap)
{
    for (int i=0; i<heap->size; i++)
    {
        printf("%s:[%d]\n", heap->nodes[i].word, heap->nodes[i].frequency);
    }
}


int main(int argc, char *argv[])
{

}
