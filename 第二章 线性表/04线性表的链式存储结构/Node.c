#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#pragma warning(disable: 4996)



typedef enum Status 
{
	success, fail, fatal, range_error
}Status;

typedef int ElemType;

typedef struct Node  //�����Ƕ���һ�����Ľڵ�
{
	ElemType elem;
	struct Node* next;
}Node, *Ptr;

typedef Ptr* SqListPtr; //��Ϊͷָ��ָ�����ͷ�ڵ��е�nextָ������ָ���ָ��

/*  ��ʼ��  */
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
/*  ɾ������  */
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
/*  ����б�  */
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
/*  �ж������Ƿ�Ϊ��  */
bool List_Empty(SqListPtr L)
{
	return ((*L)->next == NULL);
}
/*  ������  */
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
/*  ȡ��Ԫ��  */
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
/*  ��ֵ����  */
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
/*  ��λ�ò���  */
Status List_Retrieve(SqListPtr L, int pos, ElemType* elem);
/*  �ڵ�pos��Ԫ��ǰ����  */
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
/*  ɾ����pos��Ԫ��  */
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
/*  �õ�ǰ��  */
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
/*  �õ����  */
Status List_Next(SqListPtr L, int pos, ElemType* elem);