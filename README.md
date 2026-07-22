# 飞机大战

## 文件结构

✅ = 已完成，⬜ = 待创建

```
plane-war/
├── Makefile              # 编译脚本 ✅
├── README.md
├── assets/               # 图片素材（待添加）
├── include/              # 头文件
│   ├── linked_list.h     #   通用双向循环链表 ✅
│   ├── plane.h           #   玩家飞机结构体 ✅
│   ├── enemy.h           #   敌机结构体 ✅
│   ├── bullet.h          #   子弹结构体 ✅
│   ├── render.h          #   渲染（窗口、画矩形、画飞机）⬜
│   ├── collision.h       #   碰撞检测 ⬜
│   ├── utils.h           #   打印、比较回调函数 ✅
│   ├── test_utils.h      #   随机测试数据生成 ✅
│   ├── share.h           #   调试宏 ✅
│   └── defs.h            #   全局常量定义 ✅
├── src/                  # 源文件
│   ├── main.c            #   入口 + 游戏主循环 ⬜（待重写）
│   ├── linked_list.c     #   链表操作实现 ✅
│   ├── plane.c           #   玩家飞机逻辑（移动、射击）⬜
│   ├── enemy.c           #   敌机逻辑（生成、移动）⬜
│   ├── bullet.c          #   子弹逻辑（发射、飞行）⬜
│   ├── render.c          #   渲染实现（SDL2）⬜
│   ├── collision.c       #   碰撞检测实现 ⬜
│   ├── utils.c           #   打印、比较回调实现 ✅
│   └── test_utils.c      #   随机测试数据实现 ✅
└── build/                # 编译产物（gitignore）
```

## 构建

```bash
make          # 编译
make clean    # 清理
./build/plane-war  # 运行
```

## 依赖

- SDL2（图形渲染）
- pkg-config（编译参数管理）
