Status List_Merge(SqListPtr La, SqListPtr Lb, SqListPtr Lc){
    Elem Type elem1, elme2;
    status = Lisst_Init(Lc);
    int i=1, j=1, k=1;
    int n = List_Size(La), m = List_Size(Lb);
    while(i<=n && j<=m){
        List_Retrieve(La, i, &elem1);
        List_Retrieve(Lb, i, &elem2);
        if(elem1 < elem2){
            status = List_Insert(Lc,k,elem1); 
            i++;
        }
        eles{
            status = List_Insert(Lc,k,elem2);
            j++;
        }
        k++;
    }
    while(i<=n){
        List_Retrieve(La, i, &elem1);
        status = List_Insert(Lc,k,elem1);
        i++;
        k++;
    }
    while(j<=m){
    List_Retrieve(Lb, j, &elem2);
    status = List_Insert(Lc,k,elem2);
    j++;
    k++;
    }
    return status;
}