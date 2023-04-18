#ifndef _LIST_UNION_JIBEN_
#define _LIST_UNION_JIBEN_
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#include<stdio.h>
#include<stdlib.h>

typedef enum Status{
    success,fail,fatal,range_error
}Status;

typedef struct shuzu {
    int zhi;
    int geshu;
} ElemType;
typedef struct SqList
{
    ElemType *elem;
    int length;
    int list_size;
}SqList, *Ptr;
typedef Ptr SqListPtr;
//初始化
Status List_Init(SqListPtr L);
//按位置查找
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);
// 按值查找
Status List_Locate(SqListPtr L, ElemType elem, int *pos);
// 插入操作
Status List_Insert(SqListPtr L, int pos, ElemType elem);
// 删除操作
Status List_Delete(SqListPtr L, int pos);
int List_Len(SqListPtr L);
#endif