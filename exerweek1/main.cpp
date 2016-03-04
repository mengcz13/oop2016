#include <iostream>
#include <cstdlib>
#include <cmath>
#include "func.h"
using namespace std;

int main(int argc, char** argv) {
	int n = argc - 2;
	double* series = new double[n];
	for (int i = 0; i < n; ++i) {
		series[i] = (double)atof(argv[i + 1]);
	}
	double x = (double)atof(argv[argc - 1]);
	cout << "Polynomial result: " << polynomial(x, series, n) << endl;
	if (x != 0) {
		cout << "Posynomial result: " << posynomial(x, series, n) << endl;
	}
	else {
		cout << "DIV 0 ERROR!" << endl;
	}
	delete []series;
	return 0;
}
