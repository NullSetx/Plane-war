#ifndef PLANE_H
#define PLANE_H

#include <SDL2/SDL.h>

#define MAX_NAME_LEN 16

typedef struct App App;

typedef struct Bullet Bullet;
typedef struct LinkedList LinkedList;

typedef struct Plane {
    int x, y;
    int width, height;
    int speed;
    int hp;
    int score;
    int fire_rate;
    int fire_timer;
    char name[MAX_NAME_LEN];
    SDL_Texture *texture;
} Plane;

void initPlayer(App *app, Plane *player);
//玩家射击
void player_shoot(Plane *player, Bullet *tpl, LinkedList *bullet_list);

#endif
