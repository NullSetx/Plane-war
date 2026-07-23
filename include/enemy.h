#ifndef _P_ENEMY_H__
#define _P_ENEMY_H__

#include <SDL2/SDL.h>

typedef struct App App;
typedef struct LinkedList LinkedList;

typedef struct Enemy {
    int x, y; //坐标
    int width, height; //碰撞体积
    int speed;  //速度
    int hp; //血量
    int type;       // 敌机类型（不同血量/速度）
    SDL_Texture *texture;
} Enemy;

void enemy_spawn(LinkedList *list, Enemy *enemy);
void enemy_update(App *app, LinkedList *list);

#endif
