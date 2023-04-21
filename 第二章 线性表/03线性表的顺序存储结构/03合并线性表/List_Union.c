#include"List_Union_jiben.h"
Status List_Union(SqListPtr La, SqListPtr Lb){
    Status s = range_error;
    int i, j, len;
    for(i=1;i<len;i++){
        List_Retrieve(Lb, i, &elem);
        s = List_Locate(La,elem,&j);
        if(s != success){
            s = List_Insert(La, 1, elem);
            if(s != success){
                break;
            }
        }
        else{
            List_Add(La,j,1);
        }
    }
    return s;
}