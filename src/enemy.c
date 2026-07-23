#include "head.h"

void enemy_spawn(LinkedList *list, Enemy *enemy)
{
    // 定义计时器
    static int timer = 0;

    timer++;

    if (timer > ENEMY_SPAWN_RATE)
    {
        // 计时器归零
        timer = 0;

        enemy->x = rand() % (SCREEN_WIDTH - 30);
        enemy->y = -30;
        enemy->speed = 1 + rand() % 4;
        enemy->hp = ENEMY_HP;
        enemy->type = 0;

        insert_end(list, enemy);
    }
}

void reward(App *app, LinkedList *list, Enemy *reward)
{
    static int last_milestone = 0;
    int milestone = app->score / 500;

    if (milestone > last_milestone)
    {
        last_milestone = milestone;

        reward->type = 9;
        reward->y = -30;
        reward->speed = 2 + rand() % 4;
        reward->hp = 200;

        insert_end(list, reward);
    }
}

void enemy_update(App *app, LinkedList *list)
{
    Node *Tail = NULL;
    for (Tail = list->head.next; Tail != &list->head; Tail = Tail->next)
    {
        Enemy *e = (Enemy *)Tail->data;

        blit(app, e->texture, e->x, e->y, e->height, e->width);
        e->y += e->speed;
        // if (b->y < 0)
        //     b->hp = 0;
    }
}
