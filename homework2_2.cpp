#include<stdio.h>
#include <malloc.h>

// ���Ƿ� �迭�� ���� 3, ���� �� 3, ���� �� 3���� �Ѵ�.
int height = 3;
int row = 3;
int col = 3;

//memory allocation of 3d double array function
double *** mem_alloc_3D_double() {
	double ***arr;

	int i, j,k;
	arr = (double ***)malloc(sizeof(double **)*height);
	for (i = 0; i < height; i++) {
		arr[i] = (double **)malloc(sizeof(double *)*row);
		for (j = 0; j < row; j++) {
			arr[i][j] = (double *)malloc(sizeof(double)*col);
		}
	}
	
	//������� �迭�� ���Ƿ� ���� ����
	double count = 0.0;
	for (i = 0; i < height; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				arr[i][j][k] = ++count;
				printf("[%d][%d][%d]=%.2f\n",i,j,k, arr[i][j][k]);
			}
		}
	}
	return arr;

}

// �� 3D double array�� ���� ���� ���� �Լ�
void addition_3D(double ***a, double ***b) {
	int i, j, k;

	//�� �迭�� ���� ����� ���� �迭�� ���� �Ҵ�
	double ***c = (double ***)malloc(sizeof(double **)*height);
	for (i = 0; i < height; i++) {
		c[i] = (double **)malloc(sizeof(double *)*row);
		for (j = 0; j < row; j++) {
			c[i][j] = (double *)malloc(sizeof(double)*col);
		}
	}
	
	for (i = 0; i < height; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				c[i][j][k] = a[i][j][k] + b[i][j][k];
			}
		}
	}
	//���� ��� ���
	for (i = 0; i < height; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				printf("[%d][%d][%d]=%.2f\n",i,j,k, c[i][j][k]);
			}
		}
	}

	//��±��� �Ϸ��� �� �޸� �Ҵ� ����
	if (c != NULL) {
		free(c[0][0]);
		free(c[0]);
		free(c);
		c = NULL;

	}
	

}
void main() {
	
	printf("A�� �޸� �Ҵ�\n");
	double ***A = mem_alloc_3D_double();
	printf("B�� �޸� �Ҵ�\n");
	double ***B = mem_alloc_3D_double();

	printf("�� matrix�� �հ�\n");
	addition_3D(A, B);

	// �� �迭�� ���� �޸� �Ҵ� ����
	if (A != NULL) {
		free(A[0][0]);
		free(A[0]);
		free(A);
		A = NULL;

	}

	if (B != NULL) {
		free(B[0][0]);
		free(B[0]);
		free(B);
		B = NULL;

	}


}