#include "functions.h"
#include "ALU.h"

int ALU::get_sum() {
	return sum(array, len);
}

int ALU::get_mul() {
	return mul(array, len);
}
