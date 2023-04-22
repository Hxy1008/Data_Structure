#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Node.h"
#pragma warning(disable: 4996)

int main(int argv, char* argc[]) {
	Ptr header = NULL;
	Status s = fail;
	s = List_Init(&header);
	if (header == NULL) {
		if (s != success) {
			printf("初始化失败，为空\n");
		}
		else printf("初始化成功，但头指针为空\n");
	}
	else printf("header不为空");
	return 0;
}