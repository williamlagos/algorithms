#include<stdio.h>
#include<stdlib.h>
#include "equations.h"

int main(int argc,char** argv)
{
	int initial,inf_limit,sup_limit,eq_grade;
	unsigned int tolerance,itermax;
	int eq_vector[5] = {5,4,3,2,1};
	solution_t rregula_falsi,rbisection,rsecant,rnewton;

	initial = 2;
	eq_grade = 5;
	inf_limit = 0;
	sup_limit = 10;
	tolerance = itermax = 10;

	fprintf(stdout,"Resolvendo algumas equacoes...\n");
	rregula_falsi = regula_falsi(inf_limit,sup_limit,tolerance,itermax,eq_vector,eq_grade);
	rbisection = bisection(inf_limit,sup_limit,tolerance,itermax,eq_vector,eq_grade);
	rsecant = secant(inf_limit,sup_limit,tolerance,itermax,eq_vector,eq_grade);
	rnewton = newton(initial,tolerance,itermax,eq_vector,eq_grade);

	fprintf(stdout,"Regula Falsi:\nIteracoes: %d\nRaiz: %f\n",rregula_falsi.iterations,rregula_falsi.root);
	fprintf(stdout,"Bissecao:\nIteracoes: %d\nRaiz: %f\n",rbisection.iterations,rbisection.root);
	fprintf(stdout,"Secante:\nIteracoes: %d\nRaiz: %f\n",rsecant.iterations,rsecant.root);
	fprintf(stdout,"Newton:\nIteracoes: %d\nRaiz: %f\n",rnewton.iterations,rnewton.root);

	return EXIT_SUCCESS;
}
