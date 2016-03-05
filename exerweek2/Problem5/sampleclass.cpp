#include "sampleclass.h"

void SampleClass::showMap() {
	cout << "Class Address: " << this << endl;
	cout << "public: " << endl;
	cout << "public_v1: " << &public_v1 << endl;
	cout << "public_v2: " << &public_v2 << endl;
	cout << "protected: " << endl;
	cout << "protected_v3: " << &protected_v3 << endl;
	cout << "private: " << endl;
	cout << "private_v4: " << &private_v4 << endl;
}
