#include "head.h"

void enemy_spawn(LinkedList *list, Enemy *enemy)
{   
    //定义计时器
    static int timer = 0;

    timer++;
    srand(time(NULL));
    if(timer >60)
    {
        //计时器归零
        timer = 0;

        enemy->x = rand() % (SCREEN_WIDTH - 30);
        enemy->y = -30;
        enemy->speed = 2;
        enemy->hp = 100;
        enemy->type = 0;

        insert_end(list,enemy);
    }

}
void enemy_update(App *app, LinkedList *list)
{
     Node *Tail = NULL;
    for (Tail = list->head.next; Tail != &list->head; Tail = Tail->next)
    {
        Enemy *e = (Enemy *)Tail->data;

        blit(app, e->texture, e->x, e->y,e->height,e->width);
        e->y += e->speed;
        // if (b->y < 0)
        //     b->hp = 0;
    }
}
