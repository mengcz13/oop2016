#include "Graph.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
	if (argc != 3) {
		cerr << "Usage: ./testmain <input> <output>" << endl;
		return -1;
	}
	vector<Point> pv;
	int pointnum = 0;
	ifstream input(argv[1]);
	input >> pointnum;
	for (int i = 0; i < pointnum; ++i) {
		Point point;
		input >> point.x >> point.y;
		pv.push_back(point);
	}
	vector<Edge> ev;
	for (int i = 0; i < pointnum; ++i) {
		for (int j = i + 1; j < pointnum; ++j) {
			double dx = pv[i].x - pv[j].x;
			double dy = pv[i].y - pv[j].y;
			Edge edge(i, j, sqrt(dx * dx + dy * dy));
			ev.push_back(edge);
		}
	}
	Graph graph(pv, ev);

	// Timer start
	clock_t t = clock();
	graph.MST_Kruskal();
	// Timer end
	t = clock() - t;
	double timecost = (double)t / CLOCKS_PER_SEC;

	graph.print(argv[2]);
	cout << "MST on full graph: " << endl 
		<< "MST Weight: " << graph.get_total_weight() << endl
		<< "Time cost for Kruskal Algorithm: " << timecost * 1000 << "ms" << endl;
	return 0;
}
