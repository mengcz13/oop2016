#include "header.h"
#include <string>

int main() {
	string infilename = "ContactEmail.txt";
	string raoutname = "reviewer.txt";
	string teoutname = "team.txt";
	ReviewerAssigner ras;
	ras.load(infilename);
	ras.set_reviewer_num(3);
	ras.choose();
	ras.output(raoutname);
	TeamAssigner tas;
	tas.load(infilename);
	tas.assign();
	tas.output(teoutname);
	return 0;
}
