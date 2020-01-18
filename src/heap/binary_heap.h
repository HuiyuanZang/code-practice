#ifndef __BINARY_HEAP__
#define __BINARY_HEAP__


#include <stddef.h>

#ifdef __cplusplus
extern "c" {
#endif


#defind PARENT_NODE(i)       (((i) - 1)>>1)
#defind LEFTCHILD_NODE(i)    (((i)<<1) + 1)
#defind RIGHTCHILD_NODE(i)   (((i)<<1) + 2)

//enum could be signed in C 
typedef enum BinaryHeapRet_E{
     BINARYHEAP_OK = 0;
	 BINARYHEAP_NO_MOMORY = -1;
	 BINARYHEAP_NO_FOUND = -2;
	 BINARYHEAP_NULL_POINTER = -3;
}BinaryHeapRet_e;

typedef struct BinaryHeap_T{
    /*******attribues of heap********/
    int *array;
	size_t size;       //the size of node
	size_t capacity; //the size of array


    /*******methods of heap**********/

	//default methods
    int (*root)(const struct BinaryHeap_T * const heap); //get Max or Min of heap depending on Min-heap or Max-heap
	size_t (*size)(const struct BinaryHeap_T *const heap);
	size_t (*capacity)(const struct BinaryHeap_T *const heap);
	BinaryHeapRet_e  (*resize_capacity)(struct BinaryHeap_T *heap,size_t n);
    int (*is_empty)(const struct BinaryHeap_T *const heap); // is there no any node in heap
    int (*parent)(int node);
	int (*lchild)(int node);
	int (*rchild)(int node);

	//overwrite methods  by Min-heap or Max-heap
	BinaryHeapRet_t  (*insert_key)(struct BinaryHeap_T *heap,int key); //insert a new value into the heap
	int (*extract_root)(struct BinaryHeap_T *heap);          //extract root from heap and return the value of root
	void (*delete)(struct BinaryHeap_T *heap, int node);   //delete a node i from heap
	void (*change_key)(struct BinaryHeap_T *heap, int node, int key); //update key of node with new one then heapify
	void (*heapify)(struct BinaryHeap_t *heap,int i);

}BinaryHeap_t;


BinaryHeap_t* create_heap(size_t cap);

void release_heap(BinaryHeap_t *heap);

#ifdef __cplusplus
}
#endif


#endif 
