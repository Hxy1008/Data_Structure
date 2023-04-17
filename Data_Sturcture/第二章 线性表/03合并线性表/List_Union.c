Status List_Union(SqlListPtr La, SqListPtr Lb){
    ElemType elem;
    Status status;
    int i, j, len = List_Size(Lb);
    for(i=1;i<len;i++){
        List_Retrieve(Lb, i, &elem);
        status = List_Locate(La,elem,&j);
        if(status != success){
            status = List_Insert(La, 1, elem);
            if(status != success){
                break;
            }
        }
        else{
            List_Add(La,j,1);
        }
    }
    return status;
}