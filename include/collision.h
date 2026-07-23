#ifndef _COLLISION_H_
#define _COLLISION_H_

typedef struct App App;
typedef struct LinkedList LinkedList;

typedef void (plane_op_t)(const void *);

int rect_collide(Bullet *b, Enemy *e);
void check_collision(LinkedList *bullet_list, LinkedList *enemy_list,App *app);
void check_e_p(LinkedList *enemy_list,Plane *player);


#endif 