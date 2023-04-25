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
}SqList, *Ptr;
typedef Ptr SqListPtr;

/*  初始化  */
Status List_Init(SqListPtr L)
{
	Status s = fail;
	if (L) {
		L->elem = (ElemType*)malloc(sizeof(ElemType) * (LIST_SIZE_INIT + 1));//为了从第一个位置开始存
		if (L->elem) {
			L->list_size = LIST_SIZE_INIT;
			L->length = 0;
			s = success;
		}
	}
}
/*  删除链表  */
void List_Destory(SqListPtr L) 
{
	if (L) {
		if (L->elem) {
			free(L->elem);
			L->elem = NULL;
			L->length = 0;
		}
	}
}
/*  清空列表  */
void List_Clear(SqListPtr L) //没有处理的数据就认为是没有就好，所以之间修改length=0即可
{
	if (L) {
		L->length = 0;
	}
}
/*  判断链表是否为空  */
bool List_Empty(SqListPtr L)
{
	if (L) {
		return (L->length == 0);
	}
	else return 0;
}
/*  链表长度  */
int List_Size(SqListPtr L)
{
	if (L) return L->length;
	else return 0;
}
/*  取出元素  */
Status List_Retrival(SqListPtr L, int pos, ElemType* elem) 
{
	Status s = range_error;
	if (L) {
		if ((pos >= 0) && (pos <= L->length)) {
			*elem = L->elem[pos];                                //从L.elem[1]开始存储，所以这里直接写pos
			s = success;
		}
	}
	else s = fatal;
	return s;
}
/*  按值查找  */
Status List_Locate(SqListPtr L, ElemType elem, int* pos)
{
	Status s = range_error;
	if (L) {
		if (L->length == 0) return s;
		else {
			for (int i = 1; i <= L->length; i++) {
				if (L->elem[i] == elem) {
					*pos = i;
					s = success;
					break;
				}
			}
		}
	}
	else s = fatal;
	return s;
}
/*  按位置查找  */
Status List_Retrieve(SqListPtr L, int pos, ElemType* elem)
{
	Status s = range_error;
	if (L) {
		if (L->length == 0) return s;
		if (pos >= 1 && pos <= L->length) {
			*elem = L->elem[pos];
			s = success;
		}
	}
	else s = fatal;
	return s;
}
/*  插入  */
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
	Status s = range_error;
	if (L) {
		if (L->length == LIST_SIZE_INIT) {
			s = fail;
			return s;
		}
		else if (pos >= 1 && pos <= L->length+1) {
			for (int i = L->length; i >= pos; i--) {
				L->elem[i + 1] = L->elem[i];
			}
			L->elem[pos] = elem;
			L->length++;
			s = success;
		}
	}
	else s = fatal;
	return s;
}
/*  删除元素  */
Status List_delete(SqListPtr L, int pos)
{
	Status s = range_error;
	if (L) {
		if (L->length == 0) return s;
		else if (pos >= 1 && pos <= L->length) {
			for (int i = pos; i <= L->length; i++) {  
				//这里要把原本length位置的数据清0所以是i<=length！！！！好像不请零也行，因为没处理的数据算不存在
				L->elem[i] = L->elem[i + 1];
				L->length--;
				s = success;
			}
		}
	}
	else s = fatal;
	return s;
}
/*  拿到前驱  */
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
	Status s = range_error;
	if (L) {
		if (pos > 1 && pos <= L->length) {
			*elem = L->elem[pos - 1];
			s = success;
		}
	}
	else s = fatal;
	return s;
}
/*  拿到后继  */
Status List_Next(SqListPtr L, int pos, ElemType* elem)
{
	Status s = range_error;
	if (L) {
		if (pos >= 1 && pos < L->length) {
			*elem = L->elem[pos + 1];
			s = success;
		}
	}
	else s = fatal;
	return s;
}
