#include"List_Union_jiben.h"
Status List_Union(SqListPtr La, SqListPtr Lb) {
    Status s = range_error;
    int i, j, len = List_Len(Lb);
    ElemType elem;
    for (i = 0; i < len - 1; i++){
        elem = Lb->elem[i];
        for (j = 0; j < List_Len(La); j++) {
            if (elem.zhi = La->elem[j].zhi) {
                La->elem[j].geshu++;
            }
            else {
                List_Insert(La, 0, elem);
            }
        }
    }
    s = success;
    
    return s;
}

int main() {
    SqList L1, L2;
    List_Init(&L1);
    List_Init(&L2);
    ElemType elem1, elem2, elem3;
    elem1.zhi = 1;
    elem1.geshu = 1;
    elem2.zhi = 2;
    elem2.geshu = 1;
    elem3.zhi = 3;
    elem3.geshu = 1;

    List_Insert(&L1, 0, elem1);
    printf("L1.elem[0].geshu = %d\n", L1.elem[0].geshu);
    List_Insert(&L1, 0, elem2);
    List_Insert(&L2, 0, elem2);
    List_Insert(&L2, 0, elem3);
    List_Union(&L1, &L2);
    printf("L1.elem[2].geshu = %d\n", L1.elem[0].geshu);
}