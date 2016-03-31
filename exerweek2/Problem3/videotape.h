#ifndef VIDEOTAPE_H
#define VIDEOTAPE_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Videotape {
	public:
		Videotape();
		~Videotape();

		void set_name(const string& newname) { name = newname; }
		const string& get_name() { return name; }

		void set_length(int h, int m, int s) { length = 3600 * h + 60 * m + s; }
		void get_length(int& h, int& m, int& s) { h = length / 3600; m = (length % 3600) / 60; s = length % 60; }

		void set_type(list<string>& typearray) { type = typearray; }
		const list<string>& get_type() { return type; }
		void add_type(const string& newtype) { type.push_back(newtype); }
		int del_type(const string& tartype);

		void set_num(int newnum) { num = newnum; }
		int get_num() { return num; }
		Videotape& operator ++ () { ++num; return (*this); }
		Videotape& operator -- () { --num; return (*this); }

		void set_location(const string& newloc) { location = newloc; }
		const string& get_location() { return location; }
		
		void print();	
	private:
		string name; // 录像带名称
		int length; // 录像带时长, 秒
		list<string> type; // 录像带类型(爱情, 动作...)
		int num; // 录像带库存数量
		string location; // 录像带位置
};
#endif 
