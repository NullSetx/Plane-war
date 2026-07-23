#include "head.h"

// 矩形重叠判断
static int rect_hit(int x1, int y1, int w1, int h1,
                    int x2, int y2, int w2, int h2)
{
    return (x1 < x2 + w2 && x1 + w1 > x2 &&
            y1 < y2 + h2 && y1 + h1 > y2);
}

// 子弹 vs 敌机
int rect_collide(Bullet *b, Enemy *e)
{
    return rect_hit(b->x, b->y, b->width, b->height,
                    e->x, e->y, e->width, e->height);
}

// 玩家 vs 敌机
int plane_hit_enemy(Plane *p, Enemy *e)
{
    return rect_hit(p->x, p->y, p->width, p->height,
                    e->x, e->y, e->width, e->height);
}

void check_collision(LinkedList *bullet_list, LinkedList *enemy_list, App *app)
{
    Node *bn;
    for (bn = bullet_list->head.next; bn != &bullet_list->head; bn = bn->next)
    {
        Bullet *b = (Bullet *)bn->data;
        if (!b->hp)
            continue;

        Node *en;
        for (en = enemy_list->head.next; en != &enemy_list->head; en = en->next)
        {
            Enemy *e = (Enemy *)en->data;
            if (!e->hp)
                continue;

            if (rect_collide(b, e))
            {
                b->hp = 0;
                e->hp -= b->damage;
                app->score += (int)(b->damage * 1.5);
                // printf("HIT! damage=%d, score=%d\n", b->damage, app->score);
            }
        }
    }
}

void check_e_p(LinkedList *list, Plane *player)
{
    Node *node;
    for (node = list->head.next; node != &list->head; node = node->next)
    {
        Enemy *e = (Enemy *)node->data;
        if (plane_hit_enemy(player, e))
        {
            if (e->type == 9)
            {
                if (player->hp == 100)
                {
                    continue;
                }
                else
                {
                    player->hp += 20;
                    e->hp = 0;
                }
                continue;
            }
            player->hp -= 20;
            e->hp = 0;
        }
    }
}
