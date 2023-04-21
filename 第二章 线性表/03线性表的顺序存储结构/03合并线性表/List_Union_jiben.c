#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#include<stdio.h>
#include<stdlib.h>

typedef enum Status{
    success,fail,fatal,range_error
}Status;

typedef struct shuzu{
    int zhi;
    int geshu;
}ElemType;

typedef struct SqList
{
    ElemType *elem;
    int length;
    int list_size;
}SqList, *Ptr;
typedef Ptr SqListPtr;
//初始化
Status List_Init(SqListPtr L)
{
    Status s = success;
    L->list_size = LIST_INIT_SIZE;
    L->elem = (ElemType *)malloc(sizeof(ElemType) * L->list_size);
    if(L->elem == NULL){
        s = fatal;
    }
    return s;
}
//按位置查找
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_error;
    if(L){
        if((pos -1 >= 0)&&(pos - 1 < L->length)){
            *elem = L->elem[pos-1];
            s = success;
        }
    }
    else{
        s = fatal;
    }
    return s;

}
// 按值查找
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
    Status s = range_error;
    int i;
    if(L){
        for(i = 0;i < L->list_size;i++){
            if(elem.zhi == L->elem[i].zhi){
                *pos = i+1;
                s = success;
                break;
            }
        }
    }
    else{
        s = fatal;
    }
    return s;
}
// 插入操作
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
    Status s = range_error;
    int i;
    if(L){
        // if(L->length + 1 > L->list_size){
        //     L->list_size = L->list_size + LIST_INCREMENT;
        //     L->elem = realloc(L->elem, sizeof(ElemType) * L->list_size);
        // }
        if((pos - 1 >= 0)&&(pos - 1 <= L->length)){
            if(L->length < L->list_size){
                for(i=L->length - 1;i>=pos-1;i=i-1){
                    L->elem[i+1] = L->elem[i];
                    L->elem[pos - 1] = elem;
                }
                L->length++;
                s = success;
            }
        }
        else{
            s = fail;
        }
    }
    else{
        s = fatal;
    }
    return s;
}
// 删除操作
Status List_Delete(SqListPtr L, int pos)
{
    Status s = range_error;
    if(L){
        if((pos-1)>= 0&&(pos-1 < L->length)){
            if(L->length > 0){
                for(int i = pos;i < L->length;i++){
                    L->elem[i-1] = L->elem[i];
                }
                s = success;
                L->length--;
            }
        }
        else s = fail;
    }
    else s = fatal;
    return s;
}
int List_Len(SqListPtr L) 
{
    return L->length;
}


