#ifndef _ADT_LIST_XIANXING_
#define _ADT_LIST_XIANXING_
#define LIST_SIZE_INIT (int)100
#define LIST_SIZE_INCREMENT (int)10
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;
typedef enum Status {
	success, fail, fatal, range_error
}Status;
typedef struct SqList {
	ElemType* elem;
	int list_size;
	int length;
}SqList, * Ptr;
typedef Ptr SqListPtr;

/*  初始化  */
Status List_Init(SqListPtr L);
/*  删除链表  */
void List_Destory(SqListPtr L);
/*  清空列表  */
void List_Clear(SqListPtr L);
/*  判断链表是否为空  */
bool List_Empty(SqListPtr L);
/*  链表长度  */
int List_Size(SqListPtr L);
/*  取出元素  */
Status List_Retrival(SqListPtr L, int pos, ElemType* elem);
/*  按值查找  */
Status List_Locate(SqListPtr L, ElemType elem, int* pos);
/*  按位置查找  */
Status List_Retrieve(SqListPtr L, int pos, ElemType* elem);
/*  插入  */
Status List_Insert(SqListPtr L, int pos, ElemType elem);
/*  删除元素  */
Status List_delete(SqListPtr L, int pos);
/*  拿到前驱  */
Status List_Prior(SqListPtr L, int pos, ElemType* elem);
/*  拿到后继  */
Status List_Next(SqListPtr L, int pos, ElemType* elem);
#endif