#ifndef INTERPOLS_H_
#define INTERPOLS_H_

#define FOREVER while(1)

static int* differences;
static int* errorcondit;

int newton(unsigned int max,int* xcoords,int* ycoords,int value);
int lagrange(unsigned int max,int* xcoords,int* ycoords,int value);
void natural_spline(unsigned int number,int* xcoords,int* ycoords,int* derived);
void spline(unsigned int number,int* xcoords,int* ycoords,unsigned int max,int* values,int* s);

#endif
