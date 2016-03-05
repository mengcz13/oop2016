#include "videotape.h"

Videotape::Videotape() : length(0), num(0) {}

Videotape::~Videotape() {

}

int Videotape::del_type(const string& tartype) {
	list<string>::iterator it;
	it = find(type.begin(), type.end(), tartype);
	if (it != type.end()) {
		type.erase(it);
		return 0;
	}
	else {
		cout << "No such type: " << tartype << "!" << endl;
		return -1;
	}
}

void Videotape::print() {
	cout << "Videotape Info:" << endl;
	cout << "Name: " << name << endl;
	int h = 0, m = 0, s = 0;
	this -> get_length(h, m, s);
	cout << "Length: " << h << "Hour(s)" << m << "Minute(s)" << s << "Second(s)" << endl;
	cout << "Type: ";
	for (list<string>::iterator it = type.begin(); it != type.end(); ++it) {
		cout << (*it) << " ";
	}
	cout << endl;
	cout << "Number of copies: " << num << endl;
	cout << "Location: " << location << endl;
}
