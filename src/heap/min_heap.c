#include <stdlib.h>
#include <stdio.h>

#include "binary_heap.h"


static void swap(int *a, int *b);
static void heapify_minheap(BinaryHeap_t *heap);

BinaryHeap_t* create_minheap(size_t cap)
{
     BinaryHeap_t *minheap = create_heap(cap);
	 if(!minheap || !minheap->array)
	 {
	    release_heap(minheap);
	    return NULL;
	 }
	 minheap->heapify = heapify_minheap;
    
    
}
static void swap(int *a, int *b)
{
    int tmp = *a;
	if( *a != *b )
	{
	    *a = *b;
		*b = tmp;
	}
}
/*
*@Breif: heapify Min-heap in the subtree, the node i is root of subtree
* assumption: all subtree exception node i was already heapified.
*/
static void heapify_minheap(BinaryHeap_t *heap, int i)
{
    int left = LEFTCHILD_NODE(i);
	int right = RIGHTCHILD_NODE(i);
	//if there is no any child, no need do anything 
	if ( left >= heap->size )
	{
	    return;
	}
	//if there is left child but no right child,only compary array[i] with array[left]
	if ( left < heap->size && right >= heap->size )
	{  
         if ( heap->array[i] > heap->array[left] )
		 {
		     swap(&(heap->array[i]),&(heap->array[left]));
		 }
		 return;
	}
    //if there are both left and right child
	if ( right < heap->size )
	{
        //find who is smaller bwteen array[left]  and array[right]
        int tmp = (heap->array[left] < heap->array[right])?left:right;
		//then compare array[i] with array[tmp]
		if ( heap->array[tmp] < heap->array[i] )
		{
		    swap(&(heap->array[i]),&(heap->array[tmp]));
			heapify_minheap(heap, i);
		}
	}
}


/*
* @Brief: 
*  time complexity: O(lgn)
*/
static BinaryHeapRet_e insert_key_minheap(BinaryHeap_t *heap, int key)
{
    BinaryHeapRet_e ret = BINARYHEAP_OK;
	int i;
    if ( heap->capacity <= heap->size + 1 )
	{
	     ret = heap->resize_capacity(heap,4*heap->capacity);
	}
	if ( ret != BINARYHEAP_OK )
	{
	     printf("ERROR:failed to resize heap!\n");
		 return ret;
	}
	heap->arrary[size++] = key;
	i = size - 1;
    //bottom-up to check if any node violate the binary heap rules:
    while( i > 0 &&  heap->array[i] < heap->array[PARENT_NODE(i)] )
	{
	    swap(&(heap->array[i]),&(heap->arary[PARENT_NODE(i)]);
	    i = PARENT_NODE(i);
	}
	return ret;

}
/*
*@Brief:
* time complexity: O(lgn)
*/
static int extract_root_minheap(BinaryHeap_t *heap)
{
    int root =  heap->array[0];
	heap->array[0] = heap->array[heap->size -1];
	heap->size--;
	heapify_minheap(heap,0);
    if (heap->size < (heap->capacity>>3))
        heap->resize_capacity(heap,heap->capcity>>2);
	return root;
}
static void change_key_minheap(BinaryHeap_t *heap, int node, int key)
{
    if(node == 0)
	{
	    if( key > heap->array[0] )
		    heapify_minheap(heap,0);
	}
	else 
	{
	    if( key > heap->array[node])
		{
		    heap->array[node] = key;
			heapify_minheap(heap,node);
		}
		else if( key < heap->array[node])
		{
		    int i = node;
		    heap->array[node] = key;
            while( i != 0 && heap->array[i] < heap->array[PARENT_NODE(i)] )
			{
			    swap(&heap->array[i],&heap->array[PARENT_NODE(i)]);
				i = PARENT_NODE(i);
			}
		}
	}
}
static void delete_minheap(BinaryHeap_t *heap,int node)
{
    int key = heap->array[heap->size - 1];
	heap->size--;
    change_key_minheap(heap,node,key);
}







int main(int argc, char *argv[])
{
    BinaryHeap_t *minheap = create_heap(20);


    release_heap(minheap);
}
