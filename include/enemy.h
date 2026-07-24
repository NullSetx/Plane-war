#ifndef _P_ENEMY_H__
#define _P_ENEMY_H__

#include <SDL2/SDL.h>

typedef struct App App;
typedef struct LinkedList LinkedList;

typedef struct Bullet Bullet;

typedef struct Enemy {
    int x, y; //坐标
    int width, height; //碰撞体积
    int speed;  //速度
    int hp; //血量
    int type;  // 敌机类型（不同血量/速度）
    int fire_rate;   // 射击间隔（帧）
    int fire_timer;  // 射击计时器
    SDL_Texture *texture;
} Enemy;


//敌人生成
void enemy_spawn(LinkedList *list, Enemy *enemy);
//敌人更新（移动+射击）
void enemy_update(App *app, LinkedList *enemy_list, LinkedList *bullet_list, Bullet *tpl);
//敌人射击
void enemy_shoot(Enemy *enemy, Bullet *tpl, LinkedList *bullet_list);
//奖励函数
void reward(App *app,LinkedList *list,Enemy *reward);

#endif
