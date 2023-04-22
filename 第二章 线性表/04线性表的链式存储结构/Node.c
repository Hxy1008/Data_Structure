#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable: 4996)



typedef enum Status 
{
	success, fail, fatal, range_error
}Status;

typedef int ElemType;

typedef struct Node  //这里是定义一个个的节点
{
	ElemType elem;
	struct Node* next;
}Node, *Ptr;

typedef Ptr* SqListPtr; //因为头指针指向的是头节点中的next指针域，是指针的指针

/*  初始化  */
Status List_Init(SqListPtr L)
{
	Status s = fail;
	Ptr p;
	if (*L == NULL) {
		p = (Ptr)malloc(sizeof(Node));
		if (p == NULL) return s;
		else {
			*L = p;
			(*L)->next = NULL;
			s = success;
		}
	}
	return s;
}
/*  删除链表  */
void List_Destory(SqListPtr L)
{	
	//Ptr p;
	//if(*L){
	//	p = (*L)->next;
	//	while (p) {
	//		(*L)->next = p->next;
	//		free(p);
	//		p = (*L)->next;
	//	}
	List_Clear(L);
	if (*L) {
		free(*L);
		*L = NULL;
	}
	//}
}
/*  清空列表  */
void List_Clear(SqListPtr L)
{
	Ptr p;
	if (*L) {
		p = (*L)->next;
		while (p) {
			(*L)->next = p->next;
			free(p);
			p = (*L)->next;
		}
	}
}
/*  判断链表是否为空  */
bool List_Empty(SqListPtr L)
{
	return ((*L)->next == NULL);
}
/*  链表长度  */
int List_Size(SqListPtr L)
{
	int len = 0;
	Ptr p = (*L)->next;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}
/*  取出元素  */
Status List_Retrival(SqListPtr L, int pos, ElemType* elem)
{
	Status s = range_error;
	int i = 1;
	Ptr p = (*L)->next;
	while (p && i < pos) {
		++i;
		p = p->next;
	}
	if (p && i == pos) {
		*elem = p->elem;
		s = success;
	}
	return s;
}
/*  按值查找  */
Status List_Locate(SqListPtr L, ElemType elem, int* pos)
{
	Status s = range_error;
	Ptr p = (*L)->next;
	int i = 1;
	while (p) {
		if (p->elem == elem) {
			*pos = i;
			s = success;
			break;
		}
		++i;
		p = p->next;
	}
	return s;
}
/*  按位置查找  */
Status List_Retrieve(SqListPtr L, int pos, ElemType* elem);
/*  在第pos个元素前插入  */
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
	Status s = fail;
	int i = 1;
	Ptr p = (*L)->next, q = (*L);
	if (*L) {
		while (p && i < pos) {
			++i;
			q = p;
			p = p->next;
		}
		if (i == pos && p) {
			p = (Ptr)malloc(sizeof(Node));
			if (p) {
				p->elem = elem;
				p->next = q->next;
				q->next = p;
				s = success;
			}
		}
	}
	return s;
}
/*  删除第pos个元素  */
Status List_delete(SqListPtr L, int pos)
{
	Status s = fail;
	Ptr p = (*L)->next, q = *L;
	int i = 1;
	while (p && i < pos) {
		q = p;
		p = p->next;
		i++;
	}
	if (p && i == pos) {
		q->next = p->next;
		free(p);
		p = NULL;
		s = success;
	}
	return s;
}
Status List_Find(SqListPtr L, int pos, SqListPtr pAddr)
{
	Status s = fail;
	Ptr p = (*L)->next;
	int i = 1;
	if (*L) {
		while (p && i < pos) {
			i++;
			p = p->next;
		}
		if (p && i == pos)
		{
			*pAddr = p;
			s = success;
		}
	}
	else s = fatal;
	return s;
}
/*  拿到前驱  */
Status List_Prior(SqListPtr L, int pos, ElemType* elem) {
	Status s = fail;
	Ptr p = NULL, q = NULL;
	if (*L) {
		s = List_Find(L, pos, p);
		if (s == success) {
			s = List_Find(L, pos - 1, q);
			if (s == success) {
				*elem = q->elem;
				s = success;
			}
		}
	}
	return s;
}
/*  拿到后继  */
Status List_Next(SqListPtr L, int pos, ElemType* elem);