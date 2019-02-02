#include<stdio.h>
#define MAX_TERMS 20
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;// row number
	int cols;// column number
	int terms;   // element number
} SparseMatrix;

//transpose operation
SparseMatrix sparse_matrix_transpose(SparseMatrix a){
	SparseMatrix b;
	int i = 0;
	int j,k;

	//��� a�ǿ�Ұ������ b�������Ѵ�(������� row value�� column value�����ιٲ㼭����)
	for(i=0;i<a.terms;i++){             
		b.data[i].col = a.data[i].row;
		b.data[i].row = a.data[i].col;
		b.data[i].value = a.data[i].value;
	}

	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;

	SparseMatrix c;   //��ȯ�������ӽñ���ü

	//�����������ľ˰���(row-wise manner�������ϱ�����)
	for(j=0;j<b.terms;j++){      
		for(k=0;k<b.terms-1;k++){
			if(b.data[k].row>b.data[k+1].row){
				c.data[0] = b.data[k];
				b.data[k] = b.data[k+1];
				b.data[k+1] = c.data[0];
			}
		}
	}

	return b;     //��ġ����� return

}

void main(){
	SparseMatrix B = {{{0,0,2},{0,1,3},{1,0,8},{1,1,9},{1,2,1},{2,0,7},{2,2,5}},3,3,7};
	SparseMatrix BT;
	BT = sparse_matrix_transpose(B);
	
	int i,j,k;
	int flag = 0;

	// dense matrix form���� B�� BT ��������
	printf("orginal matrix B\n");
	for(i=0;i<B.rows;i++){
		for(j=0;j<B.cols;j++){
			for(k=0;k<B.terms;k++){
				if(B.data[k].row == i && B.data[k].col == j){
					printf("%d ",B.data[k].value);
					flag = 1;
				}
			}
			if(flag == 0)
			printf("0 ");
			flag = 0;
		}
		printf("\n");
	}

	printf("transpose matrix B^T\n");
		for(i=0;i<BT.rows;i++){
		for(j=0;j<BT.cols;j++){
			for(k=0;k<BT.terms;k++){
				if(BT.data[k].row == i&&BT.data[k].col == j){
					printf("%d ",BT.data[k].value);
					flag = 1;
				}
			}
			if(flag == 0)
			printf("0 ");
			flag = 0;
		}
		printf("\n");
	}
}

