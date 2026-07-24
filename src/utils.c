/**
 * @file utils.c
 * @brief 通用工具函数（比较、打印回调）
 * @date 2026-07-22
 */

#include "head.h"

void ls_enemy(const void *data)
{
    if(data == NULL) return;
    Enemy *enemy = (Enemy *)data;
    printf("x= %d y= %d H= %d W=%d speed= %d HP = %d type = %d \n ",\
        enemy->x,enemy->y,enemy->height,enemy->width,enemy->speed,enemy->hp,enemy->type);

    putchar(10);
}

void ls_bullet(const void *data)
{
    if(data == NULL) return;
    Bullet *bullet = (Bullet*) data;
    printf("x= %d y= %d H= %d W=%d speed= %d damage = %d leve= %d is_player = %d \n ",\
        bullet->x,bullet->y,bullet->height,bullet->width,\
        bullet->speed,bullet->damage,bullet->level,bullet->is_player);
}

void ls_score(const void *data)
{   
    static int count = 0;
    if(data ==NULL) return;
    Score *score = (Score *)data;
    if(count==0)
    {
        printf("\tuser\tscore\n");
        count++;
    }
    printf("\t%s\t%d\n",score->name,score->score);
}

int cmp_leve(const void *data1,const void *key)
{
    Bullet *a = (Bullet *)data1;
    int *b= (int *)key;

    if(a->level==*b) return 1;
    return 0;
}

int cmp_bullet_hp(const void *data1,const void *key)
{
    Bullet *a = (Bullet *)data1;
    int *b= (int *)key;

    if(a->hp==*b) return 1;
    return 0;
}

int cmp_enemy_die_location(const void *data1, const void *key)
{
    Enemy *a = (Enemy *)data1;
    int *b= (int *)key;

    if(a->hp==*b) 
    {

        return 1;  
    }
    if(a->y>SCREEN_HEIGHT) return 1;
    return 0;
}

int sort_age(const void *d1, const void *d2)
{
	return (((Score *)d1)->score - ((Score *)d2)->score);
}