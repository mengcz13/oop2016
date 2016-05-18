#include <stdio.h>
#include <omp.h>
#define N 100000000
#define CHUNK 100000
int main(int argc, char** argv) {
	int* array = new int[N];
#pragma omp parallel for schedule(static,CHUNK)
	for (int i = 0; i < N; ++i)
		array[i] = i;
	double ressum = 0;
#pragma omp parallel for schedule(static,CHUNK) reduction(+:ressum)
	for (int i = 0; i < N; ++i)
		ressum += (double)array[i];
	printf("Sum: %lf\n", ressum);
	return 0;
}
