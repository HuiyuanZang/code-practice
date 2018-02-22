#include <stdio.h>
#include <stdlib.h>

#define max(a,b)({             \
    typeof((a)) __a = (a);       \
    typeof((b)) __b = (b);       \
    (__a > __b)?__a:__b;      \
        })

struct Node;
struct Node 
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

static int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

static struct Node* create_node(int key)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (node)
    {
        node->key = key;
        node->left = node->right = NULL;
        node->height = 1;
    }
    else 
    {
        printf("Error,cannot allocat memory for new node!!!");
    }
    return node;
}

/**
 *         node                              x       
 *         / \                              / \
 *        x   T1                           y   node
 *       / \       RRotate(x)-->          / \  / \
 *      y   T2                           T3 T4 T2 T1
 *     / \
 *    T3 T4 
 */

static struct Node* right_rotate(struct Node *node)
{
    struct Node *x  = node->left;
    struct Node *T2   = x->right;
    
    node->left = T2;
    x->right = node;
   
    node->height = max(height(node->left),height(node->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}

/**
 *         node                              x       
 *         / \                              /  \
 *        T1  x                           node  y
 *           / \       LRotate(x)-->      / \   / \
 *          T2  y                       T1  T2 T3 T4 
 *             / \
 *            T3 T4 
 */
static struct Node* left_rotate(struct Node *node)
{
    struct Node *x = node->right;
    struct Node *T2 = x->left;
    
    node->right = T2;
    x->left = node;
    
    node->height = max(height(node->left),height(node->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}

static int get_balance(struct Node *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct Node* insert_node(struct Node *node, int key)
{
    int balance;
    //1 perform the normal BST insertion
    if (node == NULL)
    {
        return  create_node(key);
    }
    if ( key > node->key ) 
    {
       node->right  = insert_node(node->right,key);
    }
    else if ( key < node->key )
    { 
       node->left = insert_node(node->left,key);
    }
    else
    {
       return node;
    }
    //2 update height of this ancestor node
    node->height =  1 + max(height(node->left),height(node->right));

    //3 Get the balance factor of this ancestor node to check whether this 
    //node became unbalanced
    balance =  get_balance(node);

    //4 If this node become unbalanced, then there are 4 cases
    //Left Left Case
    if (balance > 1 && key < node->left->key)
    {
        return right_rotate(node);
    }
    //Right Right Case
    if (balance < -1 && key > node->right->key)
    {
        return left_rotate(node);
    }
    //Left Right Case 
    if (balance > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    //Right Left Case
    if (balance < -1 && key < node->left->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    // return the unchanged node pointer
    return node;
}


static struct Node* leftmost_node(struct Node *node)
{
    struct Node *current = node;
    if (current == NULL)
    {
        return current;
    }
    while ( current->left != NULL )
        current = current->left;
    return current;
}

struct Node* remove_node(struct Node *node, int key)
{
    int balance;
    if (node == NULL)
    {
        return node;
    }
    if (key > node->key)
    {
        node->right = remove_node(node->right, key);
    }
    else if (key < node->key)
    {
        node->left = remove_node(node->left,key);
    }
    else
    {
        //node with only one child or no child
        if ( (node->left == NULL) || (node->right == NULL) )
        {
            struct Node *tmp = node->left?node->left:node->right;
            //No child 
            if ( tmp == NULL )
            { 
                tmp = node;
                node = NULL;
            }
            else//One child case
            {   //Copy the contents of the non-empty child to node
                //then non-empty child become redundant
              /*  node->key = tmp->key;
                node->height = tmp->height;
                node->left = tmp->left;
                node->right = tmp->right;
               */
                *node = *tmp;
            }
            free(tmp);
        }
        else //node with both non-empty child 
        {
            //find the smallest or leftmost in the right subtree of node
            struct Node *tmp = leftmost_node(node->right);
            //replace node's the content with leftmost of right subtree's content,
            //except height, pointer of left and pointer of right
            node->key = tmp->key;
            node->right = remove_node(node->right,tmp->key);
        }
    }

    //If the tree had only one node then return 
    if (node == NULL)
    {
        return node;
    }

    //2 update height of this ancestor node
    node->height =  1 + max(height(node->left),height(node->right));

    //3 Get the balance factor of this ancestor node to check whether this 
    //node became unbalanced
    balance =  get_balance(node);

    //4 If this node become unbalanced, then there are 4 cases
    //Left Left Case
    if ( balance > 1 && get_balance(node->left) >= 0)
    {
        return right_rotate(node);
    }
    //Right Right Case
    if ( balance < -1 && get_balance(node->right) <= 0)
    {
        return left_rotate(node);
    }
    //Left Right Case 
    if ( balance > 1 && get_balance(node->left) < 0 )
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    //Right Left Case
    if ( balance < -1 && get_balance(node->right) > 0 )
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    // return the unchanged node pointer
    return node;

}
static void traversal(struct Node *node)
{
    if(node)
    {
        printf("%d ", node->key);
        traversal(node->left);
        traversal(node->right);
    }
}

int main (int argc, char **argv)
{
    struct Node *root = NULL;
    root = insert_node(root,10);
    root = insert_node(root,20);
    root = insert_node(root,30);
    root = insert_node(root,40);
    root = insert_node(root,50);
    root = insert_node(root,11);
    root = insert_node(root,25);
    printf("\n");
    traversal(root);
    printf("\n");
    root = remove_node(root,10);
    printf("\n");
    traversal(root);
    printf("\n");
    return 0;
}







