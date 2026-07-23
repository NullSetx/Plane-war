#ifndef __P_LINKED_LIST_H__
#define __P_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (llist_op_t)(const void *);
typedef int  (llist_cmp_t)(const void *, const void *);

typedef struct Node {
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node head;
    int size;
    int num;
} LinkedList;

LinkedList *create_list(int size);
int insert_end(LinkedList *handle, void *data);
void list_travel_next(LinkedList *handle, llist_op_t *op);
void llist_del_front(LinkedList *handle, void *key, llist_cmp_t *cmp);
void llist_destroy(LinkedList **handle);

#endif
