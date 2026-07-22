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

#define TEST_DATA 10

int main(int argc, char const *argv[]) 
{ 
    Enemy e;
    Bullet b;
    LinkedList *enemy_list = NULL,*bullet_list = NULL;
    enemy_list = create_list(sizeof(Enemy));
    bullet_list = create_list(sizeof(Bullet));
    int i;

    for(i = 0;i<TEST_DATA;i++)
    {
        rand_enemy(&e);
        insert_end(enemy_list, &e);

        rand_bullet(&b, 1);  // 1 = 玩家子弹
        insert_end(bullet_list, &b);
    }

    list_travel_next(enemy_list,ls_enemy);
    list_travel_next(bullet_list,ls_bullet);

    int leve = 3;
    llist_del_front(bullet_list,&leve,cmp_leve);

    printf("=============\n");
    list_travel_next(bullet_list,ls_bullet);

    llist_destroy(&enemy_list);
    llist_destroy(&bullet_list);
    
    return 0;
}