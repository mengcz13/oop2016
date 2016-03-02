#include "functions.h"

const int DIV = 10086;

int mul(int* array, int len) {
    int m = 1;
    for (int i = 0; i < len; ++i) {
        m *= array[i];
		m %= DIV;
    }
    return m;
}
