/**
 * @file main.c
 * @brief 飞机大战入口函数
 * @date 2026-07-22
 */

#include <stdio.h>
#include <stdlib.h>
#include "test_utils.h"
#include "linked_list.h"
#include "utils.h"
#include "render.h"

#define TEST_DATA 10

int main(int argc, char *argv[])
{
    // Enemy e;
    // Bullet b;
    // LinkedList *enemy_list = NULL,*bullet_list = NULL;
    // enemy_list = create_list(sizeof(Enemy));
    // bullet_list = create_list(sizeof(Bullet));
    // int i;

    // for(i = 0;i<TEST_DATA;i++)
    // {
    //     rand_enemy(&e);
    //     insert_end(enemy_list, &e);

    //     rand_bullet(&b, 1);  // 1 = 玩家子弹
    //     insert_end(bullet_list, &b);
    // }

    // list_travel_next(enemy_list,ls_enemy);
    // list_travel_next(bullet_list,ls_bullet);

    // int leve = 3;
    // llist_del_front(bullet_list,&leve,cmp_leve);

    // printf("=============\n");
    // list_travel_next(bullet_list,ls_bullet);

    // llist_destroy(&enemy_list);
    // llist_destroy(&bullet_list);

    App app;
    Plane player;
    Bullet bullet;
    Node *Tail = NULL;
    LinkedList *enemy_list = NULL, *bullet_list = NULL;
    bullet_list = create_list(sizeof(Bullet));

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Plane));
    memset(&bullet, 0, sizeof(Bullet));
    initSDL(&app);
    player.x = 100;
    player.y = 100;
    player.speed = 2;
    player.texture = loadTexture(&app, "../assets/playerShip.png");
    bullet.texture = loadTexture(&app, "../assets/laserBlue03.png");
    SDL_QueryTexture(player.texture, NULL, NULL, &player.width, &player.height);
    SDL_QueryTexture(bullet.texture, NULL, NULL, &bullet.width, &bullet.height);
    while (1)
    {
        prepareScene(&app);

        if (doInput(&app))
            break;

        // 键盘输入移动玩家
        move(&app, &player, player.speed);
        if (app.fire)
        {
            bullet.x = player.x + player.width / 2;
            bullet.y = player.y - player.height / 2;
            bullet.speed = 8;
            bullet.level = 1;
            bullet.is_player = 1;
            bullet.hp = 1;
            insert_end(bullet_list, &bullet);
        }
        // 遍历子弹链表，更新位置并绘制
        for (Tail = bullet_list->head.next; Tail != &bullet_list->head; Tail = Tail->next)
        {
            Bullet *b = (Bullet *)Tail->data;
            if (b->hp)
            {
                blit(&app, b->texture, b->x, b->y);
                b->y -= b->speed;
                if (b->y < 0)
                {
                    b->hp = 0;
                }
            }
        }
        // if (bullet.y < 0)
        // {
        //     bullet.hp = 0;
        // }
        blit(&app, player.texture, player.x, player.y);

        // 遍历子弹链表，更新位置并绘制
        for (Tail = bullet_list->head.next; Tail != &bullet_list->head; Tail = Tail->next)
        {
            Bullet *b = (Bullet *)Tail->data;
            if (b->hp)
            {
                printf("bullet: %d, %d\n", b->x, b->y);
                blit(&app, b->texture, b->x, b->y);
                b->y -= b->speed;
            }
        }

        // if (bullet.hp)
        // {
        //     printf("bullet: %d, %d\n", bullet.x, bullet.y);
        //     blit(&app, bullet.texture, bullet.x, bullet.y);
        //     bullet.y -= bullet.speed;
        // }
        presentScene(&app);

        SDL_Delay(16);
    }

    cleanup(&app);
    return 0;
}