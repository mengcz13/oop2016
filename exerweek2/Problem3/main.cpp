#include <iostream>
#include "videotape.h"
using namespace std;

int main() {
	Videotape vt;
	vt.set_name("The Inception");
	vt.set_length(1, 30, 40);
	vt.add_type("Sic-fic");
	vt.add_type("Romantic");
	vt.set_num(10);
	vt.set_location("Shelf 1A");
	vt.print();

	vt.del_type("SBSBS");
	vt.del_type("Romantic");
	++vt; ++vt; --vt;
	cout << "------------MODIFIED INFO------------" << endl;
	vt.print();
	
	return 0;
}
