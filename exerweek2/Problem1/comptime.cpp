#include <iostream>
#include <ctime>
#include "func.h"
using namespace std;

// test_time测试运算时间函数, calc为函数指针
double test_time(double& res, double x, double* series, int n, int algo, double (*calc)(double, double*, int, int)) {
	clock_t start = clock();
	for (int i = 0; i < 10000; ++i)
		for (int j = 0; j < 10000; ++j)
			res = calc(x, series, n, algo);
	clock_t end = clock();
	return ((double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
	double x = 3.1415926;
	int n = 10;
	double series[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	double (*funca[2])(double, double*, int, int) = {polynomial, posynomial};
	int algos[2] = {NAIVE, JSQ};
	double rest[4];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			double res = 0;
			double ttime = test_time(res, x, series, n, algos[j], funca[i]);
			rest[(i << 1) + j] = ttime;
			cout << ttime << '	' << res << endl;
		}
	}
	cout << "Polynomial Improvement: " << (rest[0] - rest[1]) / rest[0] << endl;
	cout << "Posynomial Improvement: " << (rest[2] - rest[3]) / rest[2] << endl;
	return 0;
}
