#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

struct Student {
	string no;
	string email;
};

class StudentInfo {
	public:
		void load(string);
	protected:
		vector<Student> studentinfo;
		int len;
};

class ReviewerAssigner : public StudentInfo {
	public:
		ReviewerAssigner() { srand(time(NULL)); }
		void choose();
		void output(string);
		void set_reviewer_num(int n) { rnum = n; }
	private:
		int rnum;
};

class TeamAssigner : public StudentInfo {
	public:
		TeamAssigner() { srand(time(NULL)); }
		void assign();
		void output(string);
};
#endif
