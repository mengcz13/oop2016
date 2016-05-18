#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quicksort(int* array, int start, int end, int thread) {
	if (end - start <= 1)
		return;
	int choose = start + rand() % (end - start);
	swap(&array[start], &array[choose]);
	int p = start, i = start;
	for (i = start; i < end; ++i) {
		if (array[i] < array[start]) {
			++p;
			swap(&array[i], &array[p]);
		}
	}
	swap(&array[start], &array[p]);
	if (thread <= 1) {
		quicksort(array, start, p, 1);
		quicksort(array, p + 1, end, 1);
	}
	else {
		#pragma omp parallel sections
		{
		#pragma omp section
		{
		quicksort(array, start, p, thread / 2);
		}
		#pragma omp section
		{
		quicksort(array, p + 1, end, thread - thread / 2);
		}
		}
	}
}

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Usage ./main <size> <outputfile>\n");
		return -1;
	}
	int num = atoi(argv[1]);
	int* array = (int*)malloc(num * sizeof(int));
	int i = 0;
	srand(time(NULL));
#pragma parallel for schedule(static)
	for (i = 0; i < num; ++i)
		array[i] = i + 1;
	for (i = 0; i < num; ++i) {
		int cho = rand() % (num - i) + i;
		int t = array[cho];
		array[cho] = array[i];
		array[i] = t;
	}
	struct timeval ts, te;
	struct timezone tz;
	gettimeofday(&ts, &tz);
	quicksort(array, 0, num, 4);
	gettimeofday(&te, &tz);
	double tsec = te.tv_sec - ts.tv_sec + (te.tv_usec - ts.tv_usec) / 1000000.0;
	printf("Time cost: %.3f s\n", tsec);
	for (i = 0; i< num; ++i) {
		assert(array[i] == i + 1);
	}
	/*
	f = fopen(argv[2], "w");
	fprintf(f, "%d\n", num);
	for (i = 0; i < num; ++i)
		fprintf(f, "%d\n", array[i]);
	fclose(f);
	*/
	free(array);
	return 0;
}
