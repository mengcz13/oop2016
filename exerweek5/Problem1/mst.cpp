#include "mst.h"
#include <iostream>
using namespace std;

MST::~MST() {
	delete []visit_table;
}

void MST::computeMST() {
	int next = 0;
	visit_table[next] = 1;
	while (mst_vec.size() < graph.get_size() - 1) {
		for (int i = 0; i < graph.get_size(); ++i) {
			if (visit_table[i] != 1) {
				Edge_with_weight tempedge;
				tempedge.start = next;
				tempedge.end = i;
				tempedge.weight = graph.get_dist(next, i);
				candi_edge.push(tempedge);
			}
		}
		Edge_with_weight next_edge;
		do {
			next_edge = candi_edge.top();
			candi_edge.pop();
		}while (visit_table[next_edge.end] == 1);
		mst_vec.push_back(next_edge);
		min_weight += next_edge.weight;
		next = next_edge.end;
		visit_table[next] = 1;
	}
}

void MST::print_MST() {
	cout << "Min weight:" << min_weight << endl;
	for (vector<Edge_with_weight>::iterator it = mst_vec.begin(); it != mst_vec.end(); ++it) {
		pair<double, double> p1 = graph.get_point((*it).start);
		pair<double, double> p2 = graph.get_point((*it).end);
		cout << it - mst_vec.begin() << ": " ;
		cout << '(' << p1.first << ',' << p1.second << ')' << " -- ";
		cout << '(' << p2.first << ',' << p2.second << ')' <<  "    weight: " << (*it).weight <<endl;
	}
	cout << "Min weight:" << min_weight << endl;
}