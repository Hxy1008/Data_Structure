#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"StackList.h"
#pragma warning(disable: 4996)

int main(int argv, char* argc[]){
    Status outcome;
    StackList S1;
    StackListPtr s = &S1;
    outcome = Stack_Init(s);
    if(outcome == 0) printf("yes!\n");
    for (int i = 0; i <= 9; i++) {
        Stack_Push(s, i);
    }
    printf("%d\n", S1.item[9]);
}

