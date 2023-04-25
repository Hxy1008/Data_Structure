#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_STACK_SIZE (int)100
typedef enum Status{
    success, fail, overflow, underflow, fatal
}Status;
typedef int StackEntry;
typedef struct stacklist{
    int top;
    int stack_size;
    StackEntry* item;
}StackList, *StackListPtr;
/*  初始化  */
Status Stack_Init(StackListPtr s)
{
    Status outcome = overflow;
    if(s){
        s->top = -1;
        s->stack_size = MAX_STACK_SIZE;
        s->item = (StackEntry*)malloc(sizeof(StackEntry)*s->stack_size);
        if(s->item){
            outcome = success;
        }
    }
    return outcome;
}
/*  销毁  */
void Stack_Destory(StackListPtr s)
{
    if(s){
        s->top = -1;
        s->stack_size = 0;
        free(s->item);
        s = NULL;
    }
}
/*  求栈长  */
int Stack_Length(StackListPtr s)
{
    if(s){
        if(s->top == -1) return 0;
        else return (s->top + 1);
    }
    else return -1;
}
/*  求栈顶元素  */
Status Stack_Top(StackListPtr s, StackEntry* item)
{
    Status outcome = underflow;
    if(s){
        if(s->top == -1) return outcome;
        else{
            *item = s->item[s->top];
            outcome = success;
        }
    }
    else outcome = fatal;
    return outcome;
}
/*  判断栈是否为空  */
bool Stack_Empty(StackListPtr s)
{
    if(s){
        if(s->top == -1) return true;
        else return false;
    }
}
/*  清空栈  */
Status Stack_Clear(StackListPtr s)
{
    Status outcome = success;
    if(s){
        s->top = -1;
    }
    else outcome = fail;
    return outcome;
}
/*  入栈  */
Status Stack_Push(StackListPtr s, StackEntry item)
{
    Status outcome = overflow;
    if(s){
        if(s->top == MAX_STACK_SIZE - 1) return outcome;
        else{
            s->top++;
            s->item[s->top] = item; 
            s = success;
        }
    }
    else outcome = fatal;
    return outcome;
}
/*  出栈  */
Status Stack_Pop(StackListPtr s, StackEntry* item)
{
    Status outcome = underflow;
    if(s){
        if(s->top == -1) return outcome;
        else{
            *item = s->item[s->top];
            s->top--;
            outcome = success;
        }
    }
    else outcome = fatal;
    return outcome;
}

