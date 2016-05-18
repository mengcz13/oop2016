#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

struct Mat {
	int row;
	int col;
	double* _data;
};

void multiple_Mat(struct Mat* a, struct Mat* b, struct Mat* res) {
	if (a->col != b->row)
		return;
	res->row = a->row;
	res->col = b->col;
	int i = 0, j = 0, k = 0;
#pragma omp parallel for private(j, k) schedule(static)
	for (i = 0; i < res->row; ++i) {
		for (j = 0; j < res->col; ++j) {
			for (k = 0; k < a->col; ++k) {
				res->_data[i * res->row + j] += (a->_data[i * a->row + k] * b->_data[k * b->row + j]);
			}
		}
	}
}

int main() {
	int size = 1000;
	double* data = (double*)malloc(size * size * sizeof(double));
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < size * size; ++i)
		data[i] = (double)rand() / RAND_MAX;
	struct Mat ma = {size, size, data};
	struct Mat mb = {size, size, data};
	double* data2 = (double*)malloc(size * size * sizeof(double));
	struct Mat res = {size, size, data2};
	struct timeval ts, te;
	struct timezone tz;
	gettimeofday(&ts, &tz);
	multiple_Mat(&ma, &mb, &res);
	gettimeofday(&te, &tz);
	double tsec = te.tv_sec - ts.tv_sec + (te.tv_usec - ts.tv_usec) / 1000000.0;
	printf("%lf\n", tsec);
	return 0;
}
