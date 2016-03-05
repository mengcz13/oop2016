#ifndef CHICKEN_H
#define CHICKEN_H
#include <iostream>
using namespace std;

class Egg {
	public:
		void display() { cout << "This is an egg!" << endl; }
};

class Nest {
	public:
		void display() { cout << "This is a nest!" << endl; }
	private:
		Egg egg;
};

class Hen {
	public:
		void display() { cout << "This is a hen!" << endl; }
	private:
		Nest nest;
};

#endif
