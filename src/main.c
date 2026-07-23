/**
 * @file main.c
 * @brief 飞机大战入口函数
 * @date 2026-07-22
 */

#include "head.h"

#define TEST_DATA 10


int main(int argc, char *argv[])
{

    App app;
    Plane player;
    Bullet bullet;
    Enemy enemy;

    LinkedList *enemy_list = NULL, *bullet_list = NULL;
    bullet_list = create_list(sizeof(Bullet));
    enemy_list = create_list(sizeof(Enemy));
    int hp=0;
    char score_buf[32];
    

    memset(&app, 0, sizeof(App));
    memset(&player, 0, sizeof(Plane));
    memset(&bullet, 0, sizeof(Bullet));
    memset(&enemy, 0, sizeof(Enemy));


    initSDL(&app);

    app.state = GS_MENU;

    player.x = 240;
    player.y = 600;
    player.speed = 2;
    player.fire_rate = 10;
    player.hp = 100;
    player.texture = loadTexture(&app, "../assets/playerShip.png");
    bullet.texture = loadTexture(&app, "../assets/laserBlue03.png");
    enemy.texture = loadTexture(&app,"../assets/enemyGreen2.png");
    SDL_QueryTexture(player.texture, NULL, NULL, &player.width, &player.height);
    SDL_QueryTexture(bullet.texture, NULL, NULL, &bullet.width, &bullet.height);
    // SDL_QueryTexture(enemy.texture, NULL, NULL, &enemy.width, &enemy.height);
    enemy.width = player.width;
    enemy.height = player.width;

    if(!enemy.texture)
        printf("========================");

    while (1)
    {
        prepareScene(&app);

        if (doInput(&app))
            break;
        
        switch (app.state)
        {
         case GS_MENU:
            drawText(&app, "PLANE WAR", SCREEN_WIDTH/2 - 80, 300);
            drawText(&app, "Press ENTER to Start", SCREEN_WIDTH/2 - 140, 350);
            if (app.enter)      // doKeyDown 里处理回车
            {
                app.state = GS_PLAYING;
                // 重置游戏数据
                app.score = 0;
                player.hp = 100;
                // 清空链表...
            }
            break;
        case GS_PLAYING:
                    // 键盘输入移动玩家
            move(&app, &player, player.speed);
            // printf("x = %d,y = %d\n",player.x,player.y);
            player.fire_timer++;
            enemy_spawn(enemy_list,&enemy);
            //开火初始化子弹
            if (app.fire)
                player_shoot(&player, &bullet, bullet_list);


            //绘制玩家飞机
            blit(&app, player.texture, player.x, player.y,player.height,player.width);
            //删除上一帧死亡的子弹
            llist_del_front(bullet_list,&hp,cmp_bullet_hp);
            llist_del_front(enemy_list,&hp,cmp_enemy_die_location);

            //检测子弹与敌机
            check_collision(bullet_list, enemy_list,&app);
            check_e_p(enemy_list, &player);


            // 遍历：绘制 + 移动 + 标记死亡
            bullet_update(&app, bullet_list);
            enemy_update(&app,enemy_list);

            //绘制得分

            sprintf(score_buf, "Score: %d", app.score);
            drawText(&app, score_buf, 10, 10);
            
            sprintf(score_buf, "HP: %d", player.hp);
            drawText(&app, score_buf, SCREEN_WIDTH-130, 10);
            if(player.hp<=0)
                app.state = GS_OVER;
            break;
        case GS_OVER:
          drawText(&app, "GAME OVER", SCREEN_WIDTH/2 - 80, 300);
          drawText(&app, "Press ENTER to Restart", SCREEN_WIDTH/2 - 150, 350);
          break;
        
            
        }



        presentScene(&app);

        // SDL_Delay(16);
    }

    cleanup(&app);
    return 0;
}