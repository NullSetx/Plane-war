#ifndef TEST_UTILS_H
#define TEST_UTILS_H

typedef struct Plane Plane;
typedef struct Enemy Enemy;
typedef struct Bullet Bullet;

void rand_plane(Plane *p);
void rand_enemy(Enemy *e);
void rand_bullet(Bullet *b, int is_player);

#endif
