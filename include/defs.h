#ifndef DEFS_H
#define DEFS_H

// ===== 窗口大小 =====
#define SCREEN_WIDTH   480
#define SCREEN_HEIGHT  720

// ===== 玩家 =====
#define PLAYER_SPEED     2    // 玩家移动速度（像素/帧）
#define PLAYER_HP        100   // 玩家生命值
#define PLAYER_FIRE_RATE 10   // 射击间隔（帧数，越小越快）

// ===== 子弹 =====
#define BULLET_SPEED      8    // 子弹飞行速度
#define BULLET_DAMAGE     5    // 子弹伤害值

// ===== 敌机 =====
#define ENEMY_SPEED_MIN   1    // 敌机最小速度
#define ENEMY_SPEED_MAX   3    // 敌机最大速度
#define ENEMY_HP          30    // 敌机生命值
#define ENEMY_SPAWN_RATE  120  // 敌机生成间隔（帧数）

//======游戏状态=======
typedef enum { GS_MENU, GS_PLAYING, GS_OVER } GameState;

#endif // DEFS_H