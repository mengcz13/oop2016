#ifndef FUNC_H
#define FUNC_H

#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

const int NAIVE = 0;
const int JSQ = 1;
double naive_polynomial(double x, double* series, int n);
double jsq_polynomial(double x, double* series, int n);
double polynomial(double x, double* series, int n, int algo = JSQ);
double posynomial(double x, double* series, int n, int algo = JSQ);

#endif
