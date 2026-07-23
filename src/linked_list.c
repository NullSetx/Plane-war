/**
 * @file main.c
 * @brief 链表 操作函数实现 增删改查 遍历销毁
 * @date 2026-07-22
 */

#include "head.h"

//初始化头节点
LinkedList *create_list(int size)
{
    LinkedList *handle= (LinkedList*)malloc(sizeof(LinkedList));
    handle->size = size;
    handle->num = 0;
    handle->head.data = NULL;
    handle->head.next = &handle->head;
    handle->head.prev = &handle->head;

    return handle;
}

//尾插法
int insert_end(LinkedList *handle,void *data)
{
    //分配空间，两次一结构体节点，一次节点内的data
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node==NULL) return -1;
    new_node->data = (void*)malloc(handle->size);
    if(new_node->data==NULL) return -1;
    memcpy(new_node->data,data,handle->size);

    //连接操作
    new_node->next = &handle->head;
    new_node->prev = handle->head.prev;
    handle->head.prev->next = new_node;
    handle->head.prev = new_node;
    handle->num++;
    return 0;

}

//从后遍历链表
void list_travel_next(LinkedList *handle, llist_op_t *op)
{
    Node *tail;
    for (tail = handle->head.next; tail != &handle->head; tail = tail->next)
        op(tail->data);
}

//从前删除节点
void llist_del_front(LinkedList *handle, void *key, llist_cmp_t *cmp)
{
    Node *tail = NULL;
    //寻找待删除节点
    for(tail = handle->head.next;tail!=&handle->head;tail=tail->next)
    {
        if(cmp(tail->data,key))
        {
            tail->prev->next = tail->next;
            tail->next->prev = tail->prev;
            free(tail->data);   // 先释放数据
            free(tail);         // 再释放节点
            handle->num--;
            return;
        }
    }
}

//销毁链表
void llist_destroy(LinkedList **handle)
{
    Node *tail, *save;

    for (tail = (*handle)->head.next; tail != &(*handle)->head; tail = save)
    {
        save = tail->next;
        free(tail->data);   // 先释放节点中的数据
        free(tail);         // 再释放节点本身
    }
    free(*handle);
    *handle = NULL;
}
