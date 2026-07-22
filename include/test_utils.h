#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include "plane.h"
#include "enemy.h"
#include "bullet.h"

void rand_plane(Plane *p);
void rand_enemy(Enemy *e);
void rand_bullet(Bullet *b, int is_player);

#endif
