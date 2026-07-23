#include "head.h"


void bullet_update(App *app, LinkedList *list)
{   
    Node *Tail = NULL;
    for (Tail = list->head.next; Tail != &list->head; Tail = Tail->next)
    {
        Bullet *b = (Bullet *)Tail->data;
        // if (b->hp == 0)
        // {
        //     Node *del = Tail;
        //     Tail = Tail->next;
        //     // 摘链
        //     del->prev->next = del->next;
        //     del->next->prev = del->prev;
        //     free(b);
        //     free(del);
        //     bullet_list->num--;
        //     continue;
        // }
        blit(app, b->texture, b->x, b->y,b->height,b->width);
        b->y -= b->speed;
        if (b->y < 0)
            b->hp = 0;
    }
}