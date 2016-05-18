#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXSTEP 1000000000
#define FUNC(X) (4/(1+X*X))

int main() {
	int i = 0;
	double sum = 0, lb = 0, ub = 1;
	struct timeval ts, te;
	struct timezone tz;
	gettimeofday(&ts, &tz);
#pragma omp parallel for schedule(static) reduction(+:sum)
	for (i = 0; i < MAXSTEP; ++i) {
		sum = sum + FUNC((double)i/MAXSTEP);
	}
	sum /= MAXSTEP;
	gettimeofday(&te, &tz);
	double tsec = te.tv_sec - ts.tv_sec + (te.tv_usec - ts.tv_usec) / 1000000.0;
	printf("Calculated PI is: %.10lf\nTime: %.3f s\n", sum, tsec);
	return 0;
}
