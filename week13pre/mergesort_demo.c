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

void merge(int* array, int start, int p, int end, int* buffer) {
	int i = start, f1 = start, f2 = p, f = start;
	for (i = start; i < p; ++i)
		buffer[i] = array[i];
	while (f1 < p && f2 < end) {
		if (buffer[f1] > array[f2])
			array[f++] = array[f2++];
		else
			array[f++] = buffer[f1++];
	}
	if (f2 == end) {
		for (i = f1; i < p; ++i)
			array[f++] = buffer[i];
	}
}

void mergesort(int* array, int start, int end, int thread, int* buffer) {
	if (end - start <= 1)
		return;
	int p = ((start + end) >> 1);
	if (thread <= 1) {
		mergesort(array, start, p, 1, buffer);
		mergesort(array, p, end, 1, buffer);
	}
	else {
		#pragma omp parallel sections
		{
		#pragma omp section
		{
		mergesort(array, start, p, thread / 2, buffer);
		}
		#pragma omp section
		{
		mergesort(array, p, end, thread - thread / 2, buffer);
		}
		}
	}
	merge(array, start, p, end, buffer);
}

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage ./main <size>\n");
		return -1;
	}
	int num = atoi(argv[1]);
	int* array = (int*)malloc(num * sizeof(int));
	int* buffer = (int*)malloc(num * sizeof(int));
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
	mergesort(array, 0, num, 4, buffer);
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
	free(buffer);
	return 0;
}
