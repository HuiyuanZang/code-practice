#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "binary_heap.h" 

static int get_root(const BinaryHeap_t *const heap);
static size_t get_size(const BinaryHeap_t *const heap);
static size_t get_capacity(const BinaryHeap_t *const heap);
static size_t is_empty();
static int get_parent(const BinaryHeap_t *const heap, int node);
static int get_leftchild(const BinaryHeap_t *const heap, int node);
static int get_rightchild(const BinaryHeap_t *const heap, int node);




BinaryHeap_t* create_heap(size_t cap)
{
    BinaryHeap *heap = (BinaryHeap *) malloc(sizeof(struct BinaryHeap_T));
	if(!heap)
	    return NULL;
	memset(heap,0x00,sizeof(struct BinaryHeap_T));
    heap->array = (int *)malloc(cap*sizeof(int));
	if(!heap->array)
	    return NULL;

	heap->size = 0
	heap->capability = cap;

	heap->root = get_root;
	heap->size = get_size;
	heap->capacity = get_capacity;
    heap->is_empty = is_empty;
    heap->parent = get_parent;
    heap->lchild = get_leftchild;
    heap->rchild  = get_rightchild;
}

void release_heap(BinaryHeap_t *heap)
{
    if( heap )
	{
	   if (heap->array)
	   {
	       free(heap->array);
		   heap->array = NULL;
	   }
	   free(heap);
	   heap=NULL;
	}
}

//PRECONDITION: heap != NULL and heap->array != NULL
static int get_root(const BinaryHeap_t *const heap)
{
    return heap->array[0];
}

static size_t get_size(const BinaryHeap_t *const heap)
{
    return heap->size;
}

static size_t get_capacity(const BinaryHeap_t *const heap)
{
    return heap->capacity;
}
static int is_empty(const BinaryHeap_t *const heap)
{
    return heap->size==0?0:1;
}
)
static int get_parent(const BinaryHeap_t *const heap, int node)
{
    return heap->array[PARENT_NODE(node)];
}
static int get_leftchild(const BinaryHeap_t *const heap, int node)
{
    return heap->array[LEFTCHILD_NODE(node)];
}
static int get_rightchild(const BinaryHeap_t *const heap, int node)
{
    return heap->array[RIGHTCHILD_NODE(node)];
}
