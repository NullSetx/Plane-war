#ifndef __RENDER_H__
#define __RENDER_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "defs.h"
#include "plane.h"

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;//player的位置
    int down;
    int left;
    int right;
    int fire;
} App;
  //初始化窗口
  void initSDL(App *app);
  SDL_Texture *loadTexture(App *app,char *filename);
  //绘制背景
  void prepareScene(App *app);
  void presentScene(App *app);
  void blit(App *app,SDL_Texture *texture, int x, int y);
  //边界判断
  void move(const App* app,Plane *plane,const int  speed);
  //销毁
  void cleanup(App *app);
  //键盘事件函数
  int doInput(App *app);
  void doKeyDown(App *app, SDL_KeyboardEvent *event);
  void doKeyUp(App *app,SDL_KeyboardEvent *event);

#endif // __RENDER_H__