#include <iostream>
#include <cstdlib>
#include "functions.h"
#include "ALU.h"
using namespace std;

int main(int argc, char** argv) {
    int len = argc - 1;
    int* array = new int[len];
	ALU alu;
    for (int i = 0; i < len; ++i) {
        array[i] = atoi(argv[i + 1]);
    }
	alu.array = array;
	alu.len = len;
    cout << "Sum is " << sum(array, len) << alu.get_sum() << endl;
    cout << "Mul is " << mul(array, len) << alu.get_mul() << endl;
	delete []array;
    return 0;
}
