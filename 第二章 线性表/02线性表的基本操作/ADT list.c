#include<stdio.h>
enum Status{
    success,fail,fatal,range_error
};

enum SqListPtr{

};
enum ElemType{

};
// 初始化与销毁
Status List_Init(SqListPtr L){

    
}
void List_Clear(SqListPtr L){}
void List_Destory(SqListPtr L){}
// 引用型操作
bool List_Empty(SqListPtr L){}
int List_Size(SqListPtr L){}
Status List_Retrival(SqListPtr L, int pos, ElemType *elem){}
Status List_Locate(SqListPtr L, ElemType elem , int *pos){}
Status List_Prior(SqListPtr L, int pos, ElemType *elem){}
Status List_Next(SqListPtr L, int pos, ElemType *elem){}
// 加工型操作
Status List_Inesrt(SqListPtr L, int pos, ElemType elem){}
Status List_Delete(SqListPtr L, int pos){}
