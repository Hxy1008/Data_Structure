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
			printf("��ʼ��ʧ�ܣ�Ϊ��\n");
		}
		else printf("��ʼ���ɹ�����ͷָ��Ϊ��\n");
	}
	else printf("header��Ϊ��");
	return 0;
}