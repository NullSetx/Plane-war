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