#include <iostream> // cout, endl
#include <cstring> // strlen , strcpy
using namespace std;

// No copy constuctor is defined so the default copy constructor is made, while only copies the value of the pointer itself. The same to '='.

class bug {
	char* data_;
public:
	bug(const char *str) {
		data_ = new char[strlen(str)+1];
		strcpy(data_, str);
	}

	// Fix: add user-defined copy constructor and overload '='
	bug(const bug& bugc) {
		const char* str = bugc.data_;
		data_ = new char[strlen(str)+1];
		strcpy(data_, str);
	}

	bug& operator = (const bug& bugc) {
		if (data_ != NULL)
			delete []data_;
		const char* str = bugc.data_;
		data_ = new char[strlen(str)+1];
		strcpy(data_, str);
		return (*this);
	}
	// Fix end

	~bug() {
		delete data_;
	}
	void show() {
		cout << data_ << endl;
	}
};

void test(bug str1) {
	str1.show();
	bug str2("tsinghua");
	str2.show();
	str2 = str1; // Memory leak!
	str2.show(); // str1 and str2 points to the same address, causing double free!
}

int main () {
	bug str1 ("2011");
	str1.show();
	test(str1);
	str1.show();
	return 0;
}