/**
 * @file render.c
 * @brief SDL2 初始化、输入处理、纹理/字体绘制
 * @date 2026-07-22
 */

#include "head.h"

void initSDL(App *app)
{
    int rendererFlags, windowFlags;
    rendererFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    app->score = 0;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    app->window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app->window)
    {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app->renderer = SDL_CreateRenderer(app->window, -1, rendererFlags);

    if (!app->renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    // 初始化
    TTF_Init();
    //   app->font = TTF_OpenFont("/System/Library/Fonts/Menlo.ttc", 24);  // 字号24
    app->font = TTF_OpenFont("../assets//JETBRAINSMONO-REGULAR.TTF", 24);
}
// 键盘输入监听============
int doInput(App *app)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            // exit(0);
            return 1;
            break;
        case SDL_KEYDOWN:
            doKeyDown(app, &event.key);
            break;

        case SDL_KEYUP:
            doKeyUp(app, &event.key);
            break;

        default:
            break;
        }
    }
    return 0;
}

void doKeyDown(App *app, SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_W)
        {
            app->up = 1;
        }

        if (event->keysym.scancode == SDL_SCANCODE_S)
        {
            app->down = 1;
        }

        if (event->keysym.scancode == SDL_SCANCODE_A)
        {
            app->left = 1;
        }

        if (event->keysym.scancode == SDL_SCANCODE_D)
        {
            app->right = 1;
        }
        if (event->keysym.scancode == SDL_SCANCODE_J)
        {
            app->fire = 1;
        }
        if (event->keysym.scancode == SDL_SCANCODE_RETURN)
        {
            app->enter = 1;
        }
        if (event->keysym.scancode == SDL_SCANCODE_U)
        {
            app->sortstate +=1 ;
        }
        if (event->keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            app->esc = 1;
        }
    }
}

void doKeyUp(App *app, SDL_KeyboardEvent *event)
{
    if (event->repeat == 0)
    {
        if (event->keysym.scancode == SDL_SCANCODE_W)
        {
            app->up = 0;
        }

        if (event->keysym.scancode == SDL_SCANCODE_S)
        {
            app->down = 0;
        }

        if (event->keysym.scancode == SDL_SCANCODE_A)
        {
            app->left = 0;
        }

        if (event->keysym.scancode == SDL_SCANCODE_D)
        {
            app->right = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_J)
        {
            app->fire = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_RETURN)
        {
            app->enter = 0;
        }
        if (event->keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            app->esc = 0;
        }
    }
}
// 边界判断
void move(const App *app, Plane *player, const int speed)
{
    if (app->up && player->y > 0)
        player->y -= 4 * speed;

    if (app->down && player->y + player->height < SCREEN_HEIGHT)
        player->y += 4 * speed;

    if (app->left && player->x > 0)
        player->x -= 4 * speed;

    if (app->right && player->x + player->width < SCREEN_WIDTH)
        player->x += 4 * speed;
}

//===========绘图代码=========

void prepareScene(App *app)
{
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentScene(App *app)
{
    SDL_RenderPresent(app->renderer);
}


// 销毁
void cleanup(App *app)
{
    printf("退出====\n");
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
}
// 加载贴图
SDL_Texture *loadTexture(App *app, char *filename)
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(app->renderer, filename);
    if (!texture)
    {
        printf("Failed to load %s: %s\n", filename, IMG_GetError());
    }

    return texture;
}

// 绘制纹理
void blit(App *app, SDL_Texture *texture, int x, int y, int h, int w)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

    // SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(app->renderer, texture, NULL, &dest);
}

// 绘制字体
void drawText(App *app, const char *text, int x, int y)
{
    SDL_Color white = {255, 255, 255};
    SDL_Surface *surf = TTF_RenderText_Solid(app->font, text, white);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(app->renderer, surf);
    SDL_Rect dest = {x, y, surf->w, surf->h};
    SDL_RenderCopy(app->renderer, tex, NULL, &dest);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(tex);
}
//绘制排行榜
  void lb_draw(App *app, LinkedList *list, int x, int y)
  {
      char buf[64];
      int rank = 1;
      Node *cur;

      drawText(app, "-- Leaderboard --", x, y);
      y += 30;

      for (cur = list->head.next; cur != &list->head; cur = cur->next)
      {
          Score *s = (Score *)cur->data;
          sprintf(buf, "%d. %s  %d", rank, s->name, s->score);
          drawText(app, buf, x, y);
          y += 25;
          rank++;
          if (rank > 10) break;   // 只显示前10
      }
  }