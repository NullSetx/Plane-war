
#include "head.h"

void player_shoot(Plane *player, Bullet *tpl, LinkedList *bullet_list)
  {
      if (player->fire_timer >= player->fire_rate)
      {
          tpl->x = player->x + player->width / 2;
          tpl->y = player->y - player->height / 2;
          tpl->speed = 8;
          tpl->level = 1;
          tpl->is_player = 1;
          tpl->hp = 1;
          insert_end(bullet_list, tpl);
          player->fire_timer = 0;
      }
  }