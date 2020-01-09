#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct LIST_NODE_T{
    int weight;
	unsigned int vertex;
	void *data;
	size_t dataSize;
	struct LIST_NODE_T *next;
}List_Node_t;

typedef struct ADJ_LIST_GRAPH_T{
    List_Node_t *head;
    List_Node_t *tail;
	size_t nodeSize;
}Adj_List_Graph_t;

static Adj_List_Graph_t *graph = NULL;
static size_t verticesSize;

static int initialize(size_t vertices)
{
    graph = (Adj_List_Graph_t *)calloc(vertices, sizeof(Adj_List_Graph_t));
	if (!graph)
	{
	    printf("Eror:Cannot allocate %u bytes memory for graph array\n",vertices);
	    return -1;
	}
	verticesSize = vertices;
	return 0;
}

static int destroy()
{
    if(!graph)
	{
	   printf("Graph is Empty\n");
	   return -1;
	}
    for (int i=0; i< verticesSize; i++ )
	{
	    List_Node_t *node = graph[i]->head;
		List_Node_t *next = NULL;
		while ( node )
		{
		    next = node->next;
			if (node->data)
			{
			    free(node->data);
				node->data = NULL;
			}
			free(node);
			node = next;
		}
	}
	free(graph);
	graph = NULL;
	
}

static List_Node_t *findEdge(unsigned int vertexA, unsigned int vertexB)
{
    List_Node_t *node;
    if (!graph)
    {
	    printf("graph hasn't been initialized yet, please initialize graph first!\n");
		return -1;
	}
	if (vertexA > verticesSize || vertexB > verticesSize)
	{
	    printf("Eror: the pair of vertex(%u,%u) is out of the range of %u*%u\n",vertexA,vertexB,verticesSize,verticesSize);
		returne -1;
	}
	List_Node_t *node = graph[vertexA]->head;
	while(node)
	{
	    if (node->vertex == vertexB)
		    return node;
	    node = node->next;
	}
	return NULL;
}

static int addEdge(unsigned int vertexA, unsigned int vertexB, void *data, size_t dataSize)
{
    List_Node_t *node = NULL;
    if (!graph)
    {
	    printf("graph hasn't been initialized yet, please initialize graph first!");
		return -1;
	}
    
	if (vertexA > verticesSize || vertexB > verticesSize)
	{
	    printf("Eror: the pair of vertex(%u,%u) is out of the range of %u*%u\n",vertexA,vertexB,verticesSize,verticesSize);
		returne -1;
	}
	//check if edge(vertexA,vertexB) exists, if so, overwrite the old data
	node = graph[vertexA]->head;
	while(node)
	{
	    if (node->vertex == vertexB)
		{
		    if(node->data)
			{
			    free(node->data);
			}
			node->data = malloc(dataSize);
			memcpy(node->data,data,dataSize);
			node->dataSize = dataSize;
		}
	    node = node->next;
	}
	//allocae new node 
    node = (List_Node_t *)calloc(1,sizeof(List_Node_t));
    if(!node)
		return -1;
	node->vertex = vertexB;
    node->data = calloc(1,dataSize);
    if(!node->data)
		return -1;
	node->dataSize = dataSize;
	//if the list is empty 
	if(!graph[vertexA]->head)
	{
		graph[vertexA]->head = node;
		graph[vertexA]->tail = node;
	}
	else//else add new node to the end of list
	{
	    graph[vertexA]->tail->next = node;
		graph[vertexA]->tail = node;
	}
    return 0;
}    

    
static List_Node_t* deleteEdge(unsigned int vetexA, unsigned int vetexB)
{

    List_Node_t *node = NULL;
	List_Node_t *prev = NULL;
    if (!graph)
    {
	    printf("graph hasn't been initialized yet, please initialize graph first!");
		return -1;
	}
    
	if (vertexA > verticesSize || vertexB > verticesSize)
	{
	    printf("Eror: the pair of vertex(%u,%u) is out of the range of %u*%u\n",vertexA,vertexB,verticesSize,verticesSize);
		returne -1;
	}
	//check if edge(vertexA,vertexB) exists, if so, overwrite the old data
	node = prev =  graph[vertexA]->head;
	while(node)
	{
	    if (node->vertex == vertexB)
		{
		    prev->next = node->next;
		    if(node->data)
			{
			    free(node->data);
				node->data = NULL;
			}
		}
		prev = node;
	    node = node->next;
	}
}

int main(int argc, char *argv[])
{
    
}
