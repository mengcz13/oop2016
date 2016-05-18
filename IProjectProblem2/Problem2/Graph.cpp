#include "Graph.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

inline void UnionFind::connect(int x, int y) {
	int xroot = findset(x), yroot = findset(y);
	if (setsize[xroot] < setsize[yroot]) {
		parent[xroot] = yroot;
		setsize[yroot] += setsize[xroot];
	}
	else {
		parent[yroot] = xroot;
		setsize[xroot] += setsize[yroot];
	}
}

inline int UnionFind::findset(int x) {
	if (parent[x] == -1)
		return x;
	else {
		int root = findset(parent[x]);
		parent[x] = root;
		return root;
	}
}

inline bool UnionFind::isconnected(int x, int y) {
	return (findset(x) == findset(y));
}

void Graph::MST_Kruskal() {
	if (edgeheap.size() < pointvec.size() - 1) {
		cerr << "Not connected graph!" << endl;
		return;
	}
	while (mstedge.size() < pointvec.size() - 1) {
		const Edge& edgetop = edgeheap.top();
		if (!uf.isconnected(edgetop.start, edgetop.end)) {
			uf.connect(edgetop.start, edgetop.end);
			mstedge.push_back(edgetop);
		}
		edgeheap.pop();
	}
	int piece = 0;
	for (int i = 0; i < uf.size; ++i) {
		if (uf.parent[i] == -1)
			++piece;
	}
	assert(piece == 1);
}
void Graph::print(char* outputfile) {
	ofstream output(outputfile);
	total_weight = 0;
	for (int i = 0; i < mstedge.size(); ++i) {
		total_weight += mstedge[i].length;
	}
	output << "Total weight: " << total_weight << endl;
	for (int i = 0; i < mstedge.size(); ++i) {
		const Point& s = pointvec[mstedge[i].start];
		const Point& e = pointvec[mstedge[i].end];
		output << '(' << s.x << ',' << s.y << ')' << "--" << '(' << e.x << ',' << e.y << ')' << '\t' << mstedge[i].length << endl;
	}
	output.close();
}
