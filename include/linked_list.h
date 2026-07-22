#ifndef __P_LINKED_LIST_H__
#define __P_LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "share.h"

//函数指针
typedef void (llist_op_t)(const void *);
typedef int  (llist_cmp_t)(const void *, const void *);

  typedef struct Node {
      void *data;
      struct Node *prev;
      struct Node *next;
  } Node;

  // 链表结构体
  typedef struct LinkedList {
      Node head;   
      int size;
      int num;
  } LinkedList;

  //创建链表
LinkedList *create_list(int size);
//插入链表 尾插法；
int insert_end(LinkedList *handle,void *data);
//遍历从后遍历
void list_travel_next(LinkedList *handle, llist_op_t *op);
//从前删除
void llist_del_front(LinkedList *handle, void *key, llist_cmp_t *cmp);
//销毁链表
void llist_destroy(LinkedList **handle);

#endif // __P_LINKED_LIST_H__