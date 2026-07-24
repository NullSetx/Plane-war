/**
 * @file leaderboard.c
 * @brief 排行榜读写与更新
 * @date 2026-07-22
 */

#include "head.h"


int cmp_score(const void *a, const void *b)
{
    const Score *s1 = a;
    const Score *s2 = b;
    return s1->score - s2->score;
}

void lb_insert(LinkedList *list, Score *Sc,int score, const char *name)
{   
    Sc->score = score;
    strcpy(Sc->name,name);
    insert_end(list,Sc);

}


// 从文件加载到已有链表
void lb_load(LinkedList *list, const char *filename)
{
    int i, num, size;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) return;   // 文件不存在，首次运行，直接返回

    ERRP(1 != fread(&num, sizeof(num), 1, fp),fread num,goto ERR1);
    ERRP(1 != fread(&size, sizeof(size), 1, fp),fread size,goto ERR1);

    Score tmp;
    for (i = 0; i < num; i++)
    {
        ERRP(1 != fread(&tmp, size, 1, fp),fread score,goto ERR1);
        insert_end(list, &tmp);
    }

ERR1:
    fclose(fp);
}
// 保存到文件
void lb_save(LinkedList *list, const char *filename)
{   
    Node *tail = NULL;
    FILE *fp = fopen(filename,"w");
    ERRP(NULL==fp, fopen ,goto ERP1);

    ERRP(1!=fwrite(&list->num,sizeof(list->num),1,fp), fwrite num,goto ERP2);
    ERRP(1!=fwrite(&list->size,sizeof(list->size),1,fp),fwrite size,goto ERP2);
    for (tail = list->head.next; tail != &list->head; tail = tail->next)
        fwrite(tail->data, list->size, 1, fp);

    fclose(fp);


ERP2:
    fclose(fp);
ERP1:
    return;
}


// 单局得分插入链表
void lb_update(LinkedList *list, Score *Sc, int score, const char *name, const char *filename)
{
    // lb_load(list, filename);          // 读旧排行
    lb_insert(list, Sc, score, name); // 插入新分数
    lb_save(list, filename);          // 写回文件
    list_travel_next(list,ls_score);
}