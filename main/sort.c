#include<stdio.h>
#include "sort.h"

void sort()
{
	static unsigned int i;
	int list[10] = { 0, 4, 8, 1, 3, 5, 7, 9, 2, 6 };
	fprintf(stdout, "Vetor: [");
	for (i = 0; i < 9; i++)
		fprintf(stdout, "%d,", list[i]);
	fprintf(stdout, "%d]\n", list[i]);
	heapsort(list, 10);
	fprintf(stdout, "Vetor ordenado com heapsort: [");
	for (i = 0; i < 9; i++)
		fprintf(stdout, "%d,", list[i]);
	fprintf(stdout, "%d]\n", list[i]);
}