#include<stdio.h>
#include<stdlib.h>
#include "adjusts.h"

int main(int argc,char** argv)
{
	int* responses;
	int** variables;
	regression_t result;
	unsigned int i,j,max,quantity,var_quantity,par_quantity;

	quantity = 10;
	var_quantity = 5;
	par_quantity = 5;
	max = par_quantity;
	result.det_coefficient = 0.0;
	result.sigma = 0.0;
	result.reg_coefficient = calloc(max,sizeof(int));

	responses = calloc(max,sizeof(int));
	variables = calloc(max,sizeof(int*));
	for(i = 0; i < max; i++){
		responses[i] = rand() % RAND_FACTOR;
		variables[i] = calloc(max,sizeof(int));
		for(j = 0; j < max; j++)
			variables[i][j] = rand() % RAND_FACTOR;
	}

	fprintf(stdout,"Comecando Regressao Linear...\n");
	regression(quantity,var_quantity,par_quantity,variables,responses,&result);
	fprintf(stdout,"Resultados:\nCoeficiente de determinacao: %f \n",result.det_coefficient);
	fprintf(stdout,"Variancia residual: %f\n\nCoeficientes de regressao:\n",result.sigma);
	for(i = 0; i < max; i++)
		fprintf(stdout,"%d: %d\n",i,result.reg_coefficient[i]);

	for(i = 0; i < max; i++)
		free(variables[i]);
	free(variables);
	free(responses);
	free(result.reg_coefficient);
	return EXIT_SUCCESS;
}
