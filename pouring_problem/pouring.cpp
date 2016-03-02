#include <iostream>
#include <cstdlib>
using namespace std;

class Tanks {
private:
	int tanknum;
	int* tank_array;
	int* capa_array;
	int maxdepth;
	int* record;
	int rectail;

public:
	Tanks(int n, int* ta, int* ca) : tanknum(n), tank_array(ta), capa_array(ca), maxdepth(0), record(NULL), rectail(0) {};
	int get_tanknum() {return tanknum;}
	void just_trans(int i, int j, const int& vol);
	void transfer(int i, int j, int& vol);
	int hash();
	void dfs(int maxd, int maxrecord);
	void search(int n);
};

void Tanks::just_trans(int i, int j, const int& vol) {
	tank_array[i] -= vol;
	tank_array[j] += vol;
}

void Tanks::transfer(int i, int j, int& vol) {
	vol = 0;
	if (tank_array[i] > 0 && tank_array[j] < capa_array[j]) {
		int capaleft = capa_array[j] - tank_array[j];
		vol = ((tank_array[i] < capaleft) ? tank_array[i] : capaleft);
		just_trans(i, j, vol);
	}
	else {
		return;
	}
}

int Tanks::hash() {
	int ha = 0;
	for (int i = 0;i < tanknum; ++i) {
		ha <<= 8;
		ha += tank_array[i];
	}
	return ha;
}

void Tanks::dfs(int maxd, int maxrecord) {
	maxdepth = maxd;
	record = new int[maxrecord];
	search(0);
	delete []record;
}

void Tanks::search(int n) {
	if (false) {
		return;
	}
	else {
		int curha = this -> hash();
		bool exist = false;
		for (int i = 0; i < rectail; ++i) {
			if (record[i] == curha) {
				exist = true;
				break;
			}
		}
		if (exist) {
//			for (int i = 0; i < tanknum; ++i) {
//				 cout << tank_array[i] << ' ';
//			}
//			cout << "n = " << n << endl;
			return;
		}
		else {
			for (int i = 0; i < tanknum; ++i) {
				cout << tank_array[i] << ' ';
			}
			cout << "n = " << n << endl;
			record[rectail++] = curha;
			for (int i = 0; i < tanknum; ++i) {
				for (int j = 0; j < tanknum; ++j) {
					if (i != j) {
						int vol = 0;
						transfer(i, j, vol);
						if (vol != 0) {
							search(n + 1);
							just_trans(j, i, vol);
						}
					}
				}
			}
		}
	}
}

int main() {
	int tn = 3;
	int* ta = new int[tn];
	int* ca = new int[tn];
	ta[0] = 8; ta[1] = 0; ta[2] = 0;
	ca[0] = 8; ca[1] = 5; ca[2] = 3;
	Tanks tanks(tn, ta, ca);
	tanks.dfs(1000, 100000);
	delete []ta;
	delete []ca;
}
