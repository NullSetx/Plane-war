#ifndef __RENDER_H__
#define __RENDER_H__

#include <SDL2/SDL.h>
#include "defs.h"

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

void initSDL(void);


#endif // __RENDER_H__