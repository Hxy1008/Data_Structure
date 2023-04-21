#include"ADT_list_xianxing.h"
#pragma warning(disable:4996)

int main(int argc, char* argv[]) {
	Status s;
	SqList L;
	SqListPtr L1 = &L;
	s = List_delete(L1,5);
	printf("%d\n", s);
}