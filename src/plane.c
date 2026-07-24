/**
 * @file plane.c
 * @brief 玩家射击逻辑
 * @date 2026-07-22
 */

#include "head.h"

void initPlayer(App *app, Plane *player)
{
    memset(player, 0, sizeof(Plane));
    player->x = 240;
    player->y = 600;
    player->speed = 2;
    player->fire_rate = 10;
    player->hp = 100;
    strcpy(player->name, "NullSet");

    player->texture = loadTexture(app, "../assets/playerShip.png");
    SDL_QueryTexture(player->texture, NULL, NULL, &player->width, &player->height);
}

void player_shoot(Plane *player, Bullet *tpl, LinkedList *bullet_list)
  {
      if (player->fire_timer >= player->fire_rate)
      {
          tpl->x = player->x + player->width / 2;
          tpl->y = player->y - player->height / 2;
          tpl->speed = BULLET_SPEED;
          tpl->level = 1;
          tpl->is_player = 1;
          tpl->hp = 1;
          tpl->damage = BULLET_DAMAGE;
          insert_end(bullet_list, tpl);
          player->fire_timer = 0;
      }
  }