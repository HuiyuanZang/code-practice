#ifndef __QUEUE_H__
#define __QUEUE_H__


#ifdef __CPLUSPLUS
extern "C" {
#endif

#define QUEUE_MAX_SIZE    50


typedef struct 
{
    int size;
    int begin;
    int end;
    void *entry;
}Queue;

Queue* create_queue();



#ifdef __CPLUSPLUS
}
#endif 

#endif 
