#include <stdio.h>
#include <stdlib.h>


struct list_node
{
    long item;
    struct list_node *next;
};

struct hash_entry
{
    int size;
    char *key; 
    struct list_node *head;
};



struct hash_entry*  init_hash(int table_size)
{
    struct hash_entry *table;
    int i;
    if (table_size <= 0)
    {
        printf("Error, invalidate parameter table_size(%d)", table_size);
        return NULL;
    }
    //table_size must be better to use prime 
    //table_size = prime(table_size);
    //allocate hash table 
    struct hash_entry *table = (struct hash_entry*)malloc(sizeof(struct hash_entry)*table_size);
    if (!table)
    {
        printf("Error, failed to allocate memory for hash table");
        return NULL;
    }
    
    for ( i = 0; i < table_size; i++ )
    {
        table[i]->head
    }




}
