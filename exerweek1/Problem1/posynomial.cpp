#include "func.h"

double posynomial(double x, double* series, int n, int algo) {
	if (x == 0) {
		cout << "DIV 0 ERROR!" << endl;
		return 0;
	}
	else {
		return polynomial(1.0 / x, series, n, algo);
	}
}
