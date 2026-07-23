#ifndef HEAD_H
#define HEAD_H

// ===== 系统库 =====
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ===== SDL2 =====
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// ===== 基础模块（无依赖） =====
#include "share.h"
#include "defs.h"
#include "linked_list.h"

// ===== 数据结构（SDL_Texture 依赖） =====
#include "plane.h"
#include "enemy.h"
#include "bullet.h"

// ===== 功能模块（依赖上面的结构体） =====
#include "render.h"
#include "utils.h"
#include "test_utils.h"
#include "collision.h"
#endif
