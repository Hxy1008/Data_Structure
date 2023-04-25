#ifndef _STACKLIST_
#define _STACKLIST_
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
Status Stack_Init(StackListPtr s);
/*  销毁  */
void Stack_Destory(StackListPtr s);
/*  求栈长  */
int Stack_Length(StackListPtr s);
/*  求栈顶元素  */
Status Stack_Top(StackListPtr s, StackEntry* item);
/*  判断栈是否为空  */
bool Stack_Empty(StackListPtr s);
/*  清空栈  */
Status Stack_Clear(StackListPtr s);
/*  入栈  */
Status Stack_Push(StackListPtr s, StackEntry item);
/*  出栈  */
Status Stack_Pop(StackListPtr s, StackEntry* item);
#endif