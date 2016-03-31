#ifndef FUNC_H
#define FUNC_H

#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

const int NAIVE = 0;
const int JSQ = 1;
double naive_polynomial(double x, double* series, int n); // O(n^2)算法
double jsq_polynomial(double x, double* series, int n); // O(n)秦九韶算法
double polynomial(double x, double* series, int n, int algo = JSQ); // algo: 算法选择开关
double posynomial(double x, double* series, int n, int algo = JSQ);

#endif
