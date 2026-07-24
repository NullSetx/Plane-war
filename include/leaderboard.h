#ifndef LEADERBOARD_H
#define LEADERBOARD_H

  #include "linked_list.h"

  #define MAX_NAME_LEN 16



  typedef struct {
      int score;
      char name[MAX_NAME_LEN];
  } Score;

  //更新排行榜
  void lb_update(LinkedList *list,Score *Sc,int score,const char *name,const char *filename);

  // 按分数从高到低插入
  void lb_insert(LinkedList *list,Score *SC,int score, const char *name);
  // 从文件加载
  void lb_load(LinkedList *list, const char *filename);
  // 保存到文件
  void lb_save(LinkedList *list, const char *filename);
  // 销毁
  void lb_destroy(LinkedList *list);

  #endif