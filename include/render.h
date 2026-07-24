#ifndef __RENDER_H__
#define __RENDER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "defs.h"

typedef struct Plane Plane;

typedef struct App {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
    int enter;
    int fire;
    int esc;
    int score;//得分
    int sortstate;
    GameState state;//游戏状态
    TTF_Font *font;
} App;

void initSDL(App *app);
SDL_Texture *loadTexture(App *app, char *filename);
void prepareScene(App *app);
void presentScene(App *app);
void blit(App *app, SDL_Texture *texture, int x, int y, int h, int w);
void move(const App *app, Plane *plane, const int speed);
void cleanup(App *app);
int doInput(App *app);
void doKeyDown(App *app, SDL_KeyboardEvent *event);
void doKeyUp(App *app, SDL_KeyboardEvent *event);
//绘制字体
void drawText(App *app, const char *text, int x, int y);
//绘制排行榜
void lb_draw(App *app, LinkedList *list, int x, int y);

#endif
