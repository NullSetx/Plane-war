/**
 * @file main.c
 * @brief 飞机大战入口函数
 * @date 2026-07-22
 */

#include "head.h"

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

    LinkedList *enemy_list = NULL, *bullet_list = NULL;
    bullet_list = create_list(sizeof(Bullet));
    int hp=0;

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Plane));
    memset(&bullet, 0, sizeof(Bullet));
    initSDL(&app);
    player.x = 100;
    player.y = 100;
    player.speed = 2;
    player.fire_rate = 10;
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
        player.fire_timer++;
        //开火初始化子弹
        if (app.fire)
            player_shoot(&player, &bullet, bullet_list);


        //绘制玩家飞机
        blit(&app, player.texture, player.x, player.y,player.height,player.width);
        //删除上一帧死亡的子弹
        llist_del_front(bullet_list,&hp,cmp_bullet_hp);

        // 遍历：绘制 + 移动 + 标记死亡
        bullet_update(&app, bullet_list);
        // for (Tail = bullet_list->head.next; Tail != &bullet_list->head; Tail = Tail->next)
        // {
        //     Bullet *b = (Bullet *)Tail->data;
        //     // if (b->hp == 0)
        //     // {
        //     //     Node *del = Tail;
        //     //     Tail = Tail->next;
        //     //     // 摘链
        //     //     del->prev->next = del->next;
        //     //     del->next->prev = del->prev;
        //     //     free(b);
        //     //     free(del);
        //     //     bullet_list->num--;
        //     //     continue;
        //     // }
        //     blit(&app, b->texture, b->x, b->y,b->height,b->width);
        //     b->y -= b->speed;
        //     if (b->y < 0)
        //         b->hp = 0;
        // }
        presentScene(&app);

        // SDL_Delay(16);
    }

    cleanup(&app);
    return 0;
}