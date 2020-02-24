all: simple openmp
simple: npartition.c
	gcc npartition.c -o npartition
openmp: npartition.c
	gcc npartition.c -o npartition-omp -fopenmp
