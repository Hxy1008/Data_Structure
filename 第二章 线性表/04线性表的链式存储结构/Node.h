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

typedef struct Node  //�����Ƕ���һ�����Ľڵ�
{
	ElemType elem;
	struct Node* next;
}Node, * Ptr;
typedef Ptr* SqListPtr; //��Ϊͷָ��ָ�����ͷ�ڵ��е�nextָ������ָ���ָ��

/*  ��ʼ��  */
Status List_Init(SqListPtr L);
/*  ɾ������  */
void List_Destory(SqListPtr L);
/*  ����б�  */
void List_Clear(SqListPtr L);
/*  �ж������Ƿ�Ϊ��  */
bool List_Empty(SqListPtr L);
/*  ������  */
int List_Size(SqListPtr L);
/*  ȡ��Ԫ��  */
Status List_Retrival(SqListPtr L, int pos, ElemType* elem);
/*  ��ֵ����  */
Status List_Locate(SqListPtr L, ElemType elem, int* pos);
/*  ��λ�ò���  */
Status List_Retrieve(SqListPtr L, int pos, ElemType* elem);
/*  ����  */
Status List_Insert(SqListPtr L, int pos, ElemType elem);
/*  ɾ��Ԫ��  */
Status List_delete(SqListPtr L, int pos);
/*  �õ�ǰ��  */
Status List_Prior(SqListPtr L, int pos, ElemType* elem);
/*  �õ����  */
Status List_Next(SqListPtr L, int pos, ElemType* elem);

#endif // !_NODE_
