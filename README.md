# 飞机大战

C语言 + SDL2 实现的飞机射击游戏，使用双向循环链表（`void *` 泛型）管理子弹和敌机。

## 控制

| 按键 | 功能 |
|---|---|
| W/A/S/D | 移动 |
| J | 射击 |
| U | 排行榜升降序切换 |
| ESC | 退出游戏 |
| Enter | 开始 / 重新开始 |

## 构建

```bash
make          # 编译（输出到 build/）
make clean    # 清理
./build/plane-war  # 运行
```

## 依赖

- SDL2
- SDL2_image
- SDL2_ttf
- pkg-config

macOS 安装：

```bash
brew install sdl2 sdl2_image sdl2_ttf pkg-config
```

## 文件结构

```
plane-war/
├── Makefile
├── README.md
├── assets/                # 图片素材、字体、排行榜数据
├── include/               # 头文件
│   ├── head.h             #   集中 include，避免循环引用
│   ├── defs.h             #   全局常量、枚举
│   ├── share.h            #   调试宏（ERRP）
│   ├── linked_list.h      #   双向循环链表（void * 泛型）
│   ├── plane.h            #   玩家结构体 + 函数声明
│   ├── enemy.h            #   敌机结构体
│   ├── bullet.h           #   子弹结构体
│   ├── render.h           #   App 结构体 + SDL2 渲染声明
│   ├── collision.h        #   碰撞检测声明
│   ├── leaderboard.h      #   排行榜结构体 + 函数声明
│   ├── utils.h            #   打印、比较回调
│   └── test_utils.h       #   随机测试数据
├── src/                   # 源文件
│   ├── main.c             #   入口 + 游戏主循环（状态机）
│   ├── linked_list.c      #   链表操作实现
│   ├── plane.c            #   玩家初始化、射击
│   ├── enemy.c            #   敌机生成、奖励、更新
│   ├── bullet.c           #   子弹更新与绘制
│   ├── render.c           #   SDL2 初始化、输入、纹理/字体绘制
│   ├── collision.c        #   AABB 碰撞检测
│   ├── leaderboard.c      #   排行榜读写、排序、更新
│   ├── utils.c            #   比较回调、打印回调
│   └── test_utils.c       #   随机测试数据生成
└── build/                 # 编译产物（gitignore）
```

## 游戏流程

```
GS_MENU ──Enter──> GS_PLAYING ──HP≤0──> GS_OVER ──Enter──> GS_PLAYING
                      ↑                                    │
                      └──────────── ESC ───────────────────┘
```

- **GS_MENU** — 显示排行榜和操作提示，按 Enter 开始
- **GS_PLAYING** — 移动、射击、碰撞检测，每 500 分出现回血道具
- **GS_OVER** — 保存分数到排行榜，按 Enter 重新开始，ESC 退出
