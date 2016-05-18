#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include <cmath>

struct Point {
	double x;
	double y;
	Point():x(0), y(0) {}
	Point(double x1, double y1):x(x1), y(y1) {}
};

struct Edge {
	int start;
	int end;
	double length;
	Edge():start(0), end(0), length(0) {}
	Edge(int s, int e, double l):start(s), end(e), length(l) {}
};

struct EdgeGreater {
	bool operator() (const Edge& e1, const Edge& e2) {
		return (e1.length > e2.length);
	}
};

struct UnionFind {
	int* parent;
	int* setsize;
	int size;
	UnionFind(int s): size(s) {
		parent = new int[size];
		setsize = new int[size];
		for (int i = 0; i < size; ++i) {
			parent[i] = -1;
			setsize[i] = 1;
		}
	}
	~UnionFind() { delete []parent; delete []setsize; }
	void connect(int x, int y);
	int findset(int x);
	bool isconnected(int x, int y);
};

class Graph {
public:
	Graph(std::vector<Point> pv, std::vector<Edge> ev) : pointvec(pv), edgeheap(EdgeGreater(), ev), uf(pv.size()), total_weight(0) {}
	void MST_Kruskal();
	void print(char*);
	const double get_total_weight() { return total_weight; }
private:
	std::vector<Point> pointvec;
	std::priority_queue<Edge, std::vector<Edge>, EdgeGreater> edgeheap;
	std::vector<Edge> mstedge;
	UnionFind uf;
	double total_weight;
};
#endif