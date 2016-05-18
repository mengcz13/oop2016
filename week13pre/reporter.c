#include <stdio.h>
#include <omp.h>

char name[4][100] = {"大陆记者", "香港记者", "西方记者", "华莱士"};

int main() {
	int i = 0, j = 0;
#pragma omp parallel for private(j) schedule(guided)
	for (i = 1; i < 13; ++i) {
		j = omp_get_thread_num();
		printf("我是%s, +%ds\n", name[j], i);
	}
	return 0;
}
