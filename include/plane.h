#ifndef PLANE_H
#define PLANE_H

#include <SDL2/SDL.h>

typedef struct Bullet Bullet;
typedef struct LinkedList LinkedList;

typedef struct Plane {
    int x, y;
    int width, height;
    int speed;
    int hp;
    int fire_rate;
    int fire_timer;
    SDL_Texture *texture;
} Plane;

void player_shoot(Plane *player, Bullet *tpl, LinkedList *bullet_list);

#endif
