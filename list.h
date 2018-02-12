#ifndef LIST_NODE_H
#define LIST_NODE_H

#ifdef __cplusplus
extern "C" {
#endif 

struct list_node
{
    struct list_node *prev, *next;
};
#define LIST_HEAD_INIT(name) {&(name),&(name)}
#define LIST_HEAD(name) \
    struct list_node name = LIST_HEAD_INIT(name)


#define offsetof(type,member) (unsigned int) &((type*)0->member)

/**
 *cast a member of a structure out to the containing structure
 *@param ptr: the pointer to the member
 *@param type: the type of container struct this is embedded in
 *@param member: the name of the member within the struct
 */

#define container_of(ptr, type, member)                                \
    ({                                                                 \
         const typeof(((type *) 0)->member) *__mptr = (void *)(ptr);   \
         (type *)(__mptr - offsetof(type,member));                     \

    })

#define list_entry(ptr,type,member) \
    container_of(ptr,type,member)
static inline void INIT_LIST_HEAD(struct list_node *list)
{
    list->prev = list->next = list;
}

/**
 *Insert a new entry between known consecutive entries.This is only 
 *for internal list manipulation where know the pre|next entries already
 *so there no needs to test if prev and next is consecutive or not
 *@param new: new entry being inserted
 *@param pre: previous entry in which the new entry attampts to be inserted 
 *@param next: next entry in which the new entry attampts to be inserted 
 */
static inline void __list_add(struct list_node *new,
                              struct list_node *prev,
                              struct list_node *next)
{
    new->prev = prev;
    new->next = next;
    prev->next = new;
    next->prev = new;
}


/**
 *Insert a new entry after the head
 *@param new: new entry being inserted
 *@param head: list head 
 */
static inline void list_add(struct list_node *new, struct list_node *head)
{
    __list_add(new,head,head->next);
}

/**
 *Insert a new entry to the tail of list
 *@param new: new entry being inserted
 *@param head: list head 
 */
static inline void list_add_tail(struct list_node *new, struct list_node *head)
{
    __list_add(new,head->prev,head);
}


/**
 *Delete all entries between prev and next.It is unnecessarily consecutive connection between 
 *prev and next before acting deletion
 *@param prev: the entry(execlusive) beginning to delete 
 *@param next: the entry(execlusive) stopping to delete
 */
static inline void __list_del(struct list_node *prev, struct list_node *next)
{
    prev->next = next;
    next->prev = prev;
}


/**
 *Delete one entry
 *@param entry:the entry being deleted
 */
static inline void __list_del_entry(struct list_node *entry)
{
    __list_del(entry->prev, entry->next);
}

#define LIST_POISON1 ((void *)  0x00100100)
#define LIST_POISON2 ((void *)  0x00200200)
/**
 *Delete one entry
 *@param entry:the entry being deleted
 */
static inline void list_del(struct list_node *entry)
{
    __list_del_entry(entry);
    entry->next = (struct list_node *) LIST_POISON1;
    entry->last = (struct list_node *) LIST_POISON2;
}


/**
 *Replace old entry with new entry
 *@param old:old entry
 *@param new:new entry
 */
static inline void list_replace(struct list_node *old, struct list_node *new)
{
    new->next = old->next;
    new->next->prev = new;
    new->prev = old->prev;
    new->prev->next = new;
}


/**
 *Move one entry to another list, just after head
 *@param entry:the entry being moved
 */
static inline void list_move(struct list_node *entry, struct list_node *head)
{
    list_del(entry);
    list_add(entry,head);
}

/**
 *Move one entry to another tail of list
 *@param entry:the entry being moved
 */
static inline void list_move_tail(struct list_node *entry, struct list_node *head)
{
    list_del(entry);
    list_add_tail(entry,head);
}

static inline int list_is_last (const struct list_node *list, const struct list_node *head)
{
    return list->next == head;
}

static inline int list_empty(const struct list_node *list)
{
    return list->next == list;
}

#define list_for_each (pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * If there exists operation like list_del(pos) within loop, 
 * must use 'safe' version 
 */

#define list_for_each_safe (pos, n, head)   \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)



#define list_for_each_prev (pos,head)   \
    for (pos = (head)=>prev; pos != (head); pos = pos->prev)

#ifdef __cplusplus
}
#endif 

#endif



