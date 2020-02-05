#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RB_TREE_NODE_BLACK  0
#define RB_TREE_NODE_RED    1



typedef struct _RB_TREE_T{
    int key;
    void  *data;
    size_t data_size;
    unsigned char colour;
    struct _RB_TREE_T *parent;
    struct _RB_TREE_T *left;
    struct _RB_TREE_T *right;
}RBTree_t;

/*@Brief: Given node's colour is red and its uncle is red as well, that means node's grandpa is black
 *        then change node's parent 
 *
 */

static RBTree_t *recolour(RBTree_t *node)
{
    RBTree_t *parent = node->parent;
    RBTree_t *uncle;
    RBTree_t *grandpa;
    if ( !parent )
    {
        printf("node is root\n");
        return node;
    }
    uncle = parent->left == node ? parent->right:parent->left;
    if ()
    grandpa = parent->parent;
    while(  ( grandpa ) &&
            ( parent && parent->colour == RB_TREE_NODE_RED ) && 
            ( uncle && uncle->colour == RB_TREE_NODE_RED) ) 
    {
        parent->colour = RB_TREE_NODE_BLACK;
        uncle->colour = RB_TREE_NODE_BLACK;
        grandpa->colour = RB_TREE_NODE_RED;
    }
}
static inline int is_left(RBTree_t *node)
{
    if ( node->parent)
       return node == node->parent->left;
    return 0;
}
static inline int is_right(RBTree_t *node)
{
    if ( node->parent )
        return node == node->parent->right;
    return 0;
}
static inline int is_root(RBTree_t *node)
{
    return node->parent?0:1;
}
static RBTree_t *my_uncle(RBTree_t *node)
{
    if( node->parent && node->parent->parent )
    {
        if (is_right(node->parent))
            return node->parent->parent->left;
        else 
            return node->parent->parent->right;
    }
    return NULL;
}
staic RBTree_t *my_sibling(RBTree_t *node)
{
    if ( node->parent )
    {
        if (is_right(node))
            return node->parent->left;
        else
            return node->parent->right;
    }
    return NULL;
}
static void ll_rotate(RBTree_t *node)
{
}
static void lr_rotate(RBTree_t *node)
{
}
static void rr_rotate(RBTree_t *node)
{
}
static void rl_rotate(RBTree_t *node)
{
}

/*@Brief:
 * step1, create a new node, make node's colour as red
 * step2, find the right place to put node, if the key already existed, overwrite the old  data
 * step3, check colour
 * step4, 
 *
 */


int insert(RBTree_t **rbtree,int key, void *data, size_t size )
{
    RBTree_t *node;
    RBTree_t *tmp = *rbtree;
    RBTree_t *parent;

    if( !data || size == 0 )
    {
        printf("Error:input parameters is invalid!\n ");
        return -1;
    }
    node =  (RBTree_t *) malloc(sizeof(RBTree_t));
    if ( !node )
    {
        printf("Error: Cannot allocate memory for RBNode!\n");
        return -1;
    }
    node->data = malloc(size);
    if ( !node->data )
    {
        printf("Error: Cannot allocate memory for node data!\n")
        free(node);
        return -1;
    }
    memcp(node->data,data,size);

    node->data_size = size;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->key = key;
    node->colour = RB_TREE_NODE_RED;

    if ( !(*rbtree) )
    {
        node->colure = RB_TREE_NODE_BLACK;
        *rbtree = node;
        return 0;
    }
    do
    {
        // if key is same, overwrite old data
        // no need to change other properties
        if ( tmp->key = key )
        {
            if (tmp->data)
            {
                free(tmp->data);
            }
            tmp->data = malloc(size);
            memcp(tmp->data,data,size);
            tmp->data_size = size;
            free(node->data);
            free(node);
            return 1;
        }
        //binary search tree , lookup left sub tree
        parent = tmp;
        if ( tmp->key > key )
        { 
            tmp = tmp->left;
        }
        else // lookup right sub-tree
        {
            tmp = tmp->right;
        }
    }
    while ( tmp )



int remove(RBTree_t rbtree, int key)
{

}

void *lookup(RBTree_t rbtree, int key)
{

}



int main (int argc, char *argv[])
{
    return 0;
}
