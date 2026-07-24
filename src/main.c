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
    Enemy heart;
    Score score;

    LinkedList *enemy_list = NULL, *bullet_list = NULL,*leadferboard = NULL;
    leadferboard = create_list(sizeof(Score));
    bullet_list = create_list(sizeof(Bullet));
    enemy_list = create_list(sizeof(Enemy));
    int hp = 0;
    char score_buf[32];
    char hp_buf[32];
    char filename[] = "../assets/data.txt";

    memset(&app, 0, sizeof(App));
    memset(&bullet, 0, sizeof(Bullet));
    memset(&enemy, 0, sizeof(Enemy));
    memset(&score, 0, sizeof(Score));

    initSDL(&app);
    srand(time(NULL));

    app.state = GS_MENU;
    //初始化玩家
    initPlayer(&app, &player);

    bullet.texture = loadTexture(&app, "../assets/laserBlue03.png");
    enemy.texture = loadTexture(&app, "../assets/enemyGreen2.png");
    heart.texture = loadTexture(&app, "../assets/heart-64.png");
    SDL_QueryTexture(player.texture, NULL, NULL, &player.width, &player.height);
    SDL_QueryTexture(bullet.texture, NULL, NULL, &bullet.width, &bullet.height);
    SDL_QueryTexture(heart.texture, NULL, NULL, &heart.width, &heart.height);

    // SDL_QueryTexture(enemy.texture, NULL, NULL, &enemy.width, &enemy.height);
    enemy.width = player.width;
    enemy.height = player.width;

    lb_load(leadferboard,filename);
    while (1)
    {
        prepareScene(&app);

        if (doInput(&app))
            break;

        switch (app.state)
        {
        case GS_MENU:
            //排序，默认降序，按u切换升序
            llist_sort(leadferboard, cmp_score, app.sortstate % 2 ? ASCENDING : DESCENDING);
            lb_draw(&app, leadferboard, 120, 200);
            drawText(&app, "PLANE WAR", SCREEN_WIDTH / 2 - 70, 500);
            drawText(&app, "Press ENTER to Start", SCREEN_WIDTH / 2 - 140, 550);
            drawText(&app, "WASD - Move  J - Fire", SCREEN_WIDTH / 2 - 140, 580);
            drawText(&app, "U - Sort  ESC - Quit", SCREEN_WIDTH / 2 - 130, 610);
            if (app.enter) // doKeyDown 里处理回车
            {
                app.state = GS_PLAYING;
                // 重置游戏数据
                app.score = 0;
                player.hp = 100;
                player.x = 240;
                player.y = 600;
                llist_clear(enemy_list);
                llist_clear(bullet_list);
            }
            break;
        case GS_PLAYING:

            // player.score = app.score;
            // 键盘输入移动玩家
            move(&app, &player, player.speed);
            // printf("x = %d,y = %d\n",player.x,player.y);
            player.fire_timer++;
            enemy_spawn(enemy_list, &enemy);
            // 开火初始化子弹
            if (app.fire)
                player_shoot(&player, &bullet, bullet_list);

            // 绘制玩家飞机
            blit(&app, player.texture, player.x, player.y, player.height, player.width);
            // 删除上一帧死亡的子弹
            llist_del_front(bullet_list, &hp, cmp_bullet_hp);
            llist_del_front(enemy_list, &hp, cmp_enemy_die_location);

            reward(&app, enemy_list, &heart);
            // 检测子弹与敌机
            check_collision(bullet_list, enemy_list, &app);
            check_e_p(enemy_list, &player);

            // 遍历：绘制 + 移动 + 标记死亡
            bullet_update(&app, bullet_list);
            enemy_update(&app, enemy_list);

            // 绘制得分
            //  printf("SCORE = %d\n",app.score);
            sprintf(score_buf, "Score: %d", app.score);
            drawText(&app, score_buf, 10, 10);

            sprintf(hp_buf, "HP: %d", player.hp);
            drawText(&app, hp_buf, SCREEN_WIDTH - 130, 10);
            if (player.hp <= 0)
            {
                app.state = GS_OVER;
                lb_update(leadferboard, &score, app.score, player.name, filename);
            }   
            SDL_Delay(16);
            break;
        case GS_OVER:
            llist_sort(leadferboard, cmp_score, app.sortstate % 2 ? ASCENDING : DESCENDING);
            lb_draw(&app, leadferboard, 120, 200);
            drawText(&app, "GAME OVER", SCREEN_WIDTH / 2 - 70, 500);
            drawText(&app, "Press ENTER to Restart", SCREEN_WIDTH / 2 - 150, 550);
            drawText(&app, "Press ESC to Quit", SCREEN_WIDTH / 2 - 120, 580);
            if (app.enter)
            {
                app.state = GS_PLAYING;
                app.score = 0;
                player.hp = 100;
                player.x = 240;
                player.y = 600;
                llist_clear(enemy_list);
                llist_clear(bullet_list);
            }
            break;
        }

        if (app.esc)
            break;

        presentScene(&app);
    }
    //销毁链表
    llist_destroy(&enemy_list);
    llist_destroy(&bullet_list);
    llist_destroy(&leadferboard);
    cleanup(&app);
    return 0;
}