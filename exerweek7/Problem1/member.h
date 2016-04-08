#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
public:
	Member() : name("???"), age(0) {}
	Member(const std::string& member_name, int member_age) : name(member_name), age(member_age) {}
	void printInfo() const;
private:
	std::string name;
	int age;
};

#endif