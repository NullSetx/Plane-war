#include "head.h"

void rand_plane(Plane *p)
{
    p->x = rand() % 400;
    p->y = rand() % 300 + 300;
    p->width = 40;
    p->height = 40;
    p->speed = 5;
    p->hp = rand() % 5 + 1;
    p->fire_rate = 10;
    p->fire_timer = 0;
}

void rand_enemy(Enemy *e)
{
    e->x = rand() % 450;
    e->y = rand() % 100;
    e->width = 30;
    e->height = 30;
    e->speed = rand() % 3 + 1;
    e->hp = rand() % 3 + 1;
    e->type = rand() % 3;
}

void rand_bullet(Bullet *b, int is_player)
{
    b->x = rand() % 480;
    b->y = rand() % 600;
    b->width = 5;
    b->height = 10;
    b->speed = rand() % 5 + 5;
    b->damage = rand() % 3 + 1;
    b->level = rand() % 3 + 1;
    b->is_player = is_player;
}
