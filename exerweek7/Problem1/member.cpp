#include "member.h"
#include <iostream>
using namespace std;

void Member::printInfo() const {
	cout << name << "    " << age << endl;
}