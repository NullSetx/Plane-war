#include "head.h"


//矩形重叠判断
int rect_collide(Bullet *b, Enemy *e)
  {
      return (b->x < e->x + e->width  &&
              b->x + b->width > e->x   &&
              b->y < e->y + e->height  &&
              b->y + b->height > e->y);
  }

void check_collision(LinkedList *bullet_list, LinkedList *enemy_list)
{
    Node *bn;
    for (bn = bullet_list->head.next; bn != &bullet_list->head; bn = bn->next)
    {
        Bullet *b = (Bullet *)bn->data;
        if (!b->hp) continue;

        Node *en;
        for (en = enemy_list->head.next; en != &enemy_list->head; en = en->next)
        {
            Enemy *e = (Enemy *)en->data;
            if (!e->hp) continue;

            if (rect_collide(b, e))
            {
                b->hp = 0;
                e->hp -=b->damage;
            }
        }
    }
}