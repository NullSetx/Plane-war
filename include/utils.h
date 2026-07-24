#ifndef __UTILS_H__
#define __UTILS_H__

void ls_enemy(const void *data);
void ls_bullet(const void *data);
void ls_score(const void *data);
int cmp_leve(const void *data1, const void *key);
int cmp_bullet_hp(const void *data1, const void *key);

int cmp_enemy_die_location(const void *data1, const void *key);
//排序比较函数
int sort_age(const void *d1, const void *d2);

#endif
