#include "graph.h"
#include <cmath>
#include <cstring>
using namespace std;

Graph::Graph(vector<pair<double, double> >& pointvec) {
	size = pointvec.size();
	dist_table = new double[size * size];
	memset(dist_table, 0, sizeof(double) * size * size);
	point_array = pointvec;
	for (int i = 0; i < size; ++i)
		for (int j = i + 1; j < size; ++j) {
			double dx = point_array.at(i).first - point_array.at(j).first;
			double dy = point_array.at(i).second - point_array.at(j).second;
			dist_table[i * size + j] = sqrt(dx * dx + dy * dy);
		}
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < i; ++j) {
			dist_table[i * size + j] = dist_table[j * size + i];
		}
}

Graph::~Graph() {
	delete []dist_table;
}