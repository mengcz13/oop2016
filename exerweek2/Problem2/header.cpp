#include "header.h"

void StudentInfo::load(string infilename) {
	ifstream in(infilename.c_str());
	len = 0;
	if (in) {
		string buffer;
		getline(in, buffer);
		while (getline(in, buffer)) {
			Student temp;
			istringstream rec(buffer);
			rec >> temp.no >> temp.email;
			studentinfo.push_back(temp);
		}
		len = studentinfo.size();
	}
	else {
		cerr << "File cannot be opened!" << endl;
	}
}

void ReviewerAssigner::choose() {
	for (int i = 0; i < rnum; ++i) {
		int select = rand() % (len - i) + i;
		swap(studentinfo[i], studentinfo[select]);	
	}
}

void ReviewerAssigner::output(string outfilename) {
	ofstream out(outfilename.c_str());
	out << "Reviewers are :" << endl;
	for (int i = 0; i < rnum; ++i) {
		out << studentinfo[i].no << '\t' << studentinfo[i].email << endl;
	}
}

void TeamAssigner::assign() {
	for (int i = 0; i < len; ++i) {
		int select = rand() % (len - i) + i;
		swap(studentinfo[i], studentinfo[select]);
	}
}

void TeamAssigner::output(string outfilename) {
	ofstream out(outfilename.c_str());
	int teamnum = 0;
	if (len % 3 == 2) {
		teamnum = len / 3 + 1;
	}
	else {
		teamnum = len / 3;
	}
	for (int i = 0; i < teamnum - 1; ++i) {
		out << "Team " << i + 1 << ":" << endl;
		for (int j = 0; j < 3; ++j) {
			out << studentinfo[i * 3 + j].no << '\t' << studentinfo[i * 3 + j].email << endl;
		}
	}
	out << "Team " << teamnum << ":" << endl;
	for (int i = 3 * (teamnum - 1); i < len; ++i) {
		out << studentinfo[i].no << '\t' << studentinfo[i].email << endl;
	}
}
