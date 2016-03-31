#include "graph.h"
#include "mst.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXPOS = 10000;
const int POINTNUM = 20;

inline double get_rand_between_0_1() {
	return (double)rand() / (double)RAND_MAX;
}

int main(int argc, char const **argv)
{
	vector<pair<double, double> > pointvec;
	srand(time(NULL));
	while (pointvec.size() < POINTNUM) {
		double x = get_rand_between_0_1() * MAXPOS;
		double y = get_rand_between_0_1() * MAXPOS;
		bool exist = false;
		for (vector<pair<double, double> >::iterator it = pointvec.begin(); it != pointvec.end(); ++it) {
			if ((*it).first == x && (*it).second == y) {
				exist = true;
				break;
			}
		}
		if (!exist) {
			pointvec.push_back(pair<double, double>(x, y));
		}
	}
	MST mst(pointvec);
	mst.computeMST();
	mst.print_MST();
	return 0;
}