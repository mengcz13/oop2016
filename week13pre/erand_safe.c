#include <stdio.h>
#include <stdlib.h>

int main() {
	double array[4][100];
	int i = 0, j = 0;
#pragma parallel for schedule(dynamic, 1) private(j)
	for (i = 0; i < 4; ++i) {
		unsigned short Xi[3] = {0, 0, i * i * i};
		for (j = 0; j < 100; ++j) {
			array[i][j] = erand48(Xi);
		}
	}

	for (i = 0; i < 4; ++i) {
		printf("Line %d:\n", i);
		for (j = 0; j < 100; ++j)
			printf("%lf ", array[i][j]);
		printf("\n");
	}
	return 0;
}
