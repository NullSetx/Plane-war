#ifndef _COLLISION_H_
#define _COLLISION_H_


int rect_collide(Bullet *b, Enemy *e);
void check_collision(LinkedList *bullet_list, LinkedList *enemy_list);

#endif 