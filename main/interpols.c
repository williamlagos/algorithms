#include<stdio.h>
#include<stdlib.h>
#include "interpols.h"

int main(int argc,char** argv)
{
	static unsigned int i,max,number,value,rnewton,rlagrange;
	static int xcoords[10] = {0,1,2,3,4,5,6,7,8,9};
	static int ycoords[10] = {0,1,2,3,4,5,6,7,8,9};
	static int values[10]  = {0,1,2,3,4,5,6,7,8,9};
	static int* s;

	s = calloc(max,sizeof(int));
	value = number = 5;

	fprintf(stdout,"Calculating interpolations...\n");
	rlagrange = lagrange(max,xcoords,ycoords,value);
	rnewton = newton(max,xcoords,ycoords,value);
	spline(number,xcoords,ycoords,max,values,s);

	fprintf(stdout,"Resultado da Interpolacao de Lagrange: %d\n",rlagrange);
	fprintf(stdout,"Resultado da Interpolacao de Newton: %d\n",rnewton);
	fprintf(stdout,"Resultado da Interpolacao de Spline Cubica:\n");
	for(i = 0; i < max; i++)
		fprintf(stdout,"%d",s[i]);

	free(s);

	return EXIT_SUCCESS;
}
