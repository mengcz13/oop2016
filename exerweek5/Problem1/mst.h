#ifndef MST_H
#define MST_H

#include "graph.h"
#include <vector>
#include <cstring>
#include <queue>

struct Edge_with_weight {
	int start;
	int end;
	double weight;
	friend bool operator < (const Edge_with_weight& a, const Edge_with_weight& b) {
		return a.weight > b.weight;
	}
};

class MST {
public:
	MST(std::vector<std::pair<double, double> >& pointvec) : graph(pointvec) {
		visit_table = new int[graph.get_size()];
		memset(visit_table, 0, sizeof(int) * graph.get_size());
		min_weight = 0;
	}
	~MST();
	void computeMST();
	void print_MST();

private:
	Graph graph;
	std::vector<Edge_with_weight> mst_vec;
	int* visit_table;
	std::priority_queue<Edge_with_weight> candi_edge;
	double min_weight;
};

#endif