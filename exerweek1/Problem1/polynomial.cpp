#include "func.h"

double naive_polynomial(double x, double* series, int n) {
	double res = 0;
	for (int i = 0; i < n; ++i) {
		double xs = 1;
		for (int j = 0; j < i; ++j) {
			xs *= x;
		}
		res += (xs * series[i]);
	}
	return res;
}

double jsq_polynomial(double x, double* series, int n) {
	double res = 0;
	for (int i = n - 1; i >= 0; --i) {
		res *= x;
		res += series[i];
	}
	return res;
}

double polynomial(double x, double* series, int n, int algo) {
	if (algo == NAIVE) {
		return naive_polynomial(x, series, n);
	}
	else if (algo == JSQ){
		return jsq_polynomial(x, series, n);
	}
}
