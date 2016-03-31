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

// StudentInfo类, 存储学生信息
class StudentInfo {
	public:
		void load(string);
	protected:
		vector<Student> studentinfo;
		int len;
};

// ReviewerAssigner类, 继承StudentInfo并添加选择器
class ReviewerAssigner : public StudentInfo {
	public:
		ReviewerAssigner() { srand(time(NULL)); }
		void choose();
		void output(string);
		void set_reviewer_num(int n) { rnum = n; }
	private:
		int rnum;
};

// TeamAssigner类, 继承StudentInfo并添加随机置乱器
class TeamAssigner : public StudentInfo {
	public:
		TeamAssigner() { srand(time(NULL)); }
		void assign();
		void output(string);
};
#endif
