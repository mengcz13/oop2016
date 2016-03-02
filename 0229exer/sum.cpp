#include "functions.h"

int sum(int* array, int len) {
    int s = 0;
    for (int i = 0; i < len; ++i) {
        s += array[i];
    }
    return s;
}
