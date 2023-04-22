#ifndef _NODE_
#define _NODE_
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef enum Status
{
	success, fail, fatal, range_error
}Status;

typedef int ElemType;

typedef struct Node  //这里是定义一个个的节点
{
	ElemType elem;
	struct Node* next;
}Node, * Ptr;
typedef Ptr* SqListPtr; //因为头指针指向的是头节点中的next指针域，是指针的指针

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

#endif // !_NODE_
