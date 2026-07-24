/**
 * @file enemy.c
 * @brief 敌机生成、奖励、更新
 * @date 2026-07-22
 */

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

        enemy->x = enemy->width + rand() % (SCREEN_WIDTH - 2 * enemy->width);
        enemy->y = -30;
        enemy->speed = 1 + rand() % 4;
        enemy->hp = ENEMY_HP;
        enemy->type = 0;
        enemy->fire_rate = 60 + rand() % 120;  // 1~3秒一发
        enemy->fire_timer = 0;

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

void enemy_shoot(Enemy *enemy, Bullet *tpl, LinkedList *bullet_list)
{
    if (enemy->fire_timer >= enemy->fire_rate)
    {
        tpl->x = enemy->x + enemy->width / 2;
        tpl->y = enemy->y + enemy->height;
        tpl->speed = 4;
        tpl->is_player = 0;
        tpl->hp = 1;
        tpl->damage = 10;
        insert_end(bullet_list, tpl);
        enemy->fire_timer = 0;
    }
}

void enemy_update(App *app, LinkedList *enemy_list, LinkedList *bullet_list, Bullet *tpl)
{
    Node *Tail = NULL;
    for (Tail = enemy_list->head.next; Tail != &enemy_list->head; Tail = Tail->next)
    {
        Enemy *e = (Enemy *)Tail->data;
        if (!e->hp)
            continue;

        blit(app, e->texture, e->x, e->y, e->height, e->width);
        e->y += e->speed;

        e->fire_timer++;
        enemy_shoot(e, tpl, bullet_list);
    }
}
