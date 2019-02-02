#include<stdio.h>
#include <malloc.h>

// 임의로 배열은 높이 3, 행의 수 3, 열의 수 3으로 한다.
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
	
	//만들어진 배열에 임의로 값을 대입
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

// 두 3D double array에 대한 덧셈 연산 함수
void addition_3D(double ***a, double ***b) {
	int i, j, k;

	//두 배열의 덧셈 결과를 담을 배열을 동적 할당
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
	//덧셈 결과 출력
	for (i = 0; i < height; i++) {
		for (j = 0; j < row; j++) {
			for (k = 0; k < col; k++) {
				printf("[%d][%d][%d]=%.2f\n",i,j,k, c[i][j][k]);
			}
		}
	}

	//출력까지 완료한 뒤 메모리 할당 해제
	if (c != NULL) {
		free(c[0][0]);
		free(c[0]);
		free(c);
		c = NULL;

	}
	

}
void main() {
	
	printf("A에 메모리 할당\n");
	double ***A = mem_alloc_3D_double();
	printf("B에 메모리 할당\n");
	double ***B = mem_alloc_3D_double();

	printf("두 matrix의 합계\n");
	addition_3D(A, B);

	// 두 배열에 대한 메모리 할당 해제
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