#ifndef _P_BULLET_H_   
#define _P_BULLET_H_

typedef struct Bullet {
    int x, y; //坐标
    int width, height; //碰撞体积
    int speed;  //速度
    int damage; //伤害
    int level;  //子弹等级（不同伤害/速度）
    int is_player;  // 1=玩家子弹, 0=敌机子弹
} Bullet;

#endif
