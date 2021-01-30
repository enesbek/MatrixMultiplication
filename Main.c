#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float **matrixMatrixMultiply(float **, float**, int);

int main(void){
	int sizeofMatrix;
	printf("Enter the Matrix size: ");
	scanf("%d", &sizeofMatrix);
	puts("");
	
	float **A; 
	float **B;
	A = (float **)malloc(sizeof(float *)*sizeofMatrix);
	B = (float **)malloc(sizeof(float *)*sizeofMatrix);
	// Createing 2 pointer array to make matrix

	int i,j;
	for(i = 0; i < sizeofMatrix; i++){
		A[i] = (float *)malloc(sizeof(float)*sizeofMatrix);
		B[i] = (float *)malloc(sizeof(float)*sizeofMatrix);
	} // Arrays turns to matrix
	
	srand(time(0));
	for(i = 0; i < sizeofMatrix; i++){
		for(j = 0; j < sizeofMatrix; j++){
			A[i][j] = (float)(rand()%10);
			B[i][j] = (float)(rand()%10);
		}
	}// Filled matrixs with random numbers
	
	matrixMatrixMultiply(A, B, sizeofMatrix);
	
	return 0;
}

float **matrixMatrixMultiply(float **A, float **B, int M){
	int i,j,k;
	float **C;
	C = (float **)malloc(sizeof(float *)*M);
	
	for(i= 0; i<M; i++ )
		C[i] = (float *)malloc(sizeof(float)*M);		
		
	for(i = 0; i < M; i++)
		for(j = 0; j < M; j++)
			C[i][j] = 0;
	// Created a new matrix for multiplication
	
	clock_t start = clock();  
	// fillingg C matrix with A * B 
	for(i = 0; i < M; i++)
		for(j = 0; j < M; j++)
			for(k = 0; k < M; k++)
				C[i][j] += A[i][k] * B[k][j];
	// filled C matrix with A * B 
	clock_t end = clock();
	double a = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Running time for i-j-k: %.2lf\n", a);
	puts("---------------------------------------------");
	
	start = clock();  
	for(i = 0; i < M; i++){
		for(k = 0; k < M; k++){
			for(j = 0; j < M; j++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	end = clock();
	a = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Running time for i-k-j: %.2lf\n", a);
	puts("---------------------------------------------");
	
	start = clock();  
	for(j = 0; j < M; j++){
		for(i = 0; i < M; i++){
			for(k = 0; k < M; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	end = clock();
	a = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Running time for j-i-k: %.2lf\n", a);
	puts("---------------------------------------------");
	
	start = clock();  
	for(j = 0; j < M; j++){
		for(k = 0; k < M; k++){
			for(i = 0; i < M; i++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	end = clock();
	a = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Running time for j-k-i: %.2lf\n", a);
	puts("---------------------------------------------");
	
	start = clock();  
	for(k = 0; k < M; k++){
		for(i = 0; i < M; i++){
			for(j = 0; j < M; j++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	end = clock();
	a = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Running time for k-i-j: %.2lf\n", a);
	puts("---------------------------------------------");
	
	start = clock();  
	for(k = 0; k < M; k++){
		for(j = 0; j< M; j++){
			for(i = 0; i < M; i++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	end = clock();
	a = (double)(end - start)/CLOCKS_PER_SEC;
	printf("Running time for k-j-i: %.2lf\n", a);
	// These all filling methods are different and they have different running time
	return C;
	
}
