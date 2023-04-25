Status List_Union(SqListPtr La, SqListPtr Lb) {
	Status s = fail;
	int m, n, flag;
	for (n = 1; n <= Lb->length; n++) {
		flag = 0;
		for (m = 1; m <= La->length; m++) {
			if (La->elem[m] == Lb->elem[n]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		else if (La->length < LIST_SIZE_INIT) {
			s = List_Insert(La, 1, Lb->elem[n]);
		}
	}
	return s;