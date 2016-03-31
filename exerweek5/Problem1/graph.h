#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

class Graph {
public:
	Graph(std::vector<std::pair<double, double> >&);
	~Graph();
	int get_size() { return size; }
	double get_dist(int i, int j) { return dist_table[i * size + j]; }
	std::pair<double, double> get_point(int i) { return point_array.at(i); }

private:
	std::vector<std::pair<double, double> > point_array;
	double* dist_table;
	int size;
};

#endif