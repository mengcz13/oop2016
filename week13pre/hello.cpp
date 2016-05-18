#include <stdio.h>

int main() {
#pragma omp parallel
	printf("Hello OpenMP!\n");
	return 0;
}
