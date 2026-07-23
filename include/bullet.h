#ifndef _P_BULLET_H_
#define _P_BULLET_H_

#include <SDL2/SDL.h>

typedef struct App App;
typedef struct LinkedList LinkedList;

typedef struct Bullet {
    int x, y;
    int width, height;
    int speed;
    int damage;
    int level;
    int hp;
    int is_player;
    SDL_Texture *texture;
} Bullet;

void bullet_update(App *app, LinkedList *list);

#endif
