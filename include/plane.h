#ifndef PLANE_H
#define PLANE_H

#include <SDL2/SDL.h>

typedef struct Plane {
    int x, y;       // 坐标
    int width, height; // 碰撞体积
    int speed;      // 移动速度
    int hp;         // 生命值
    int fire_rate;  // 射击间隔（帧数）
    int fire_timer; // 射击计时器
    SDL_Texture *texture;
} Plane;

#endif
