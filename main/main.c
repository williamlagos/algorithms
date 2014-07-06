#include<stdio.h>
#include<stdlib.h>

void main(int argc, char** argv)
{
	fprintf(stdout, "Hello World!\n");
	int keypress = getchar();
	exit(EXIT_SUCCESS);
}