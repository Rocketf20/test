#include <stdio.h>
#include <stdlib.h>
void multiply(int*** a, int*** b, int*** c, int aRow, int aCol, int bRow, int bCol);
///I am going to try to parallelize matrix multiplication
void multiply(int*** a, int*** b,int*** c, int aRow, int aCol,int bRow,int bCol) {
	int sum = 0;
	for (int i = 0; i < aRow; i++) {
		for (int j = 0; j < bCol; j++) {
			for (int k = 0; k < aCol; k++) {
				sum += *(*(*(a+i)+k)) * *(*(*(b+k)+j));
			}
			*(*(*(c+i)+j)) = sum;
		}
	}	
	return;
}
void printMatrix(int*** a,int aRow,int aCol) {
	for (int i = 0; i < aRow; i++) {
		for (int j = 0; j < aCol; j++) {
			printf("%d", *(*(*(a+i)+j)));
		}
		printf("\n");
	}
	return;
}
void start(int aRow, int aCol, int bRow, int bCol) {
	int** a = malloc(sizeof(int) * aRow * aCol);
	int** b = malloc(sizeof(int) * bRow * bCol);
	int** c = malloc(sizeof(int) * aRow * bCol);
	for (int i = 0; i < aRow; i++) {
		for (int j = 0; j < aCol; j++) {
			*(*(a+i)+j) = rand() % 255;
		}
	}
	for (int i = 0; i < bRow; i++) {
		for (int j = 0; j < bCol; j++) {
			*(*(b+i)+j) = rand() % 255;
		}
	}
	multiply(&a,&b, &c, aRow, aCol, bRow, bCol);
	printMatrix(&a,aRow,aCol);
	printMatrix(&b,bRow,bCol);
	printMatrix(&c,aRow,bCol);
	free(a);
	free(b);
	free(c);
	return;
}

void main() {
	start(3,3,3,3);
}
