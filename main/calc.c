/* 														*
 * Calculate - program to calculate linear systems by	*
 * iterative methods like Gauss-Jacobi and Gauss-Seidel *
 * 														*
 * William Oliveira de Lagos <william.lagos1@gmail.com> *
 *														*/

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include "calc.h"

int main(int argc, char** argv)
{
	iterations = 10;
	static unsigned int i;
	static int max = ORDER;
	static int tolerance = 5;
	static int** matrix1 = NULL;
	static int** matrix2 = NULL;

	matrix1 = (int**) malloc(max * sizeof(int*));
	matrix2 = (int**) malloc(max * sizeof(int*));
	random_matrix(matrix1);
	random_matrix(matrix2);

	static int vector1[ORDER] = {5,8,2,3,1};
	static int vector2[ORDER] = {5,8,2,3,1};

	gauss_jacobi(ORDER,matrix1,vector1,tolerance,iterations);
	fprintf(stdout,"Erro condicional de Gauss-Jacobi: %d\n",errorconds);
	gauss_seidel(ORDER,matrix2,vector2,tolerance,iterations);
	fprintf(stdout,"Erro condicional de Gauss-Seidel: %d\n",errorconds);

	for(i = 0; i < max; i++) free(matrix1[i]);
	for(i = 0; i < max; i++) free(matrix2[i]);
	free(matrix1);
	free(matrix2);
	return EXIT_SUCCESS;
}

void random_matrix(int** matrix){
	fprintf(stdout,"Gerando matriz randomica:\n");
	static int i,j;
	static int maxx = ORDER;
	static int maxy = ORDER;
	for(i = 0; i < maxx; i++){
		matrix[i] = (int*) malloc(maxy * sizeof(int));
		fprintf(stdout,"[");
		for(j = 0; j < maxy; j++){
			matrix[i][j] = rand() % RNDFACT + 1;
			if(j < maxy - 1) fprintf(stdout,"%d,",matrix[i][j]);
			else fprintf(stdout,"%d",matrix[i][j]);
		}
		fprintf(stdout,"]\n");
	}
}
