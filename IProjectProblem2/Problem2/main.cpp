#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "Graph.h"
#include <ctime>
using namespace std;
typedef CGAL::Exact_predicates_inexact_constructions_kernel         K;
typedef CGAL::Triangulation_vertex_base_with_info_2<unsigned, K>    Vb;
typedef CGAL::Triangulation_data_structure_2<Vb>                    Tds;
typedef CGAL::Delaunay_triangulation_2<K, Tds>                      Delaunay;
typedef Delaunay::Point                                             CGALPoint;

int main(int argc, char** argv) {
	if (argc != 3) {
		cout << "Usage: ./main <inputfile> <outputfile>" << endl;
		return -1;
	}
	ifstream inputfile(argv[1]);
	int pointnum = 0;
	inputfile >> pointnum;
	vector<Point> pv;
	pv.reserve(pointnum);
	vector< pair<CGALPoint, unsigned> > point_with_info;
	point_with_info.reserve(pointnum);
	for (int i = 0; i < pointnum; ++i) {
		Point point;
		inputfile >> point.x >> point.y;
		pv.push_back(point);
		point_with_info.push_back( make_pair(CGALPoint(point.x, point.y), i) );
	}
	inputfile.close();

	// Timer start
	clock_t t = clock();
	Delaunay dt;
	dt.insert(point_with_info.begin(), point_with_info.end());
	Delaunay::Finite_edges_iterator ite;
	vector<Edge> ev;
	for (ite = dt.finite_edges_begin(); ite != dt.finite_edges_end(); ++ite) {
		Delaunay::Face_handle fhd = (*ite).first;
		int rank = (*ite).second;
		int start = fhd->vertex(Delaunay::cw(rank))->info();
		int end = fhd->vertex(Delaunay::ccw(rank))->info();
		double dx = pv[start].x - pv[end].x;
		double dy = pv[start].y - pv[end].y;
		Edge edge(start, end, sqrt(dx * dx + dy * dy));
		ev.push_back(edge);
	}
	Graph graph(pv, ev);

	graph.MST_Kruskal();
	// Timer end
	t = clock() - t;
	double timecost = (double)t / CLOCKS_PER_SEC;

	graph.print(argv[2]);
	cout << "MST with Delaunay: " << endl 
		<< "MST Weight: " << graph.get_total_weight() << endl
		<< "Time cost for Delaunay Triangulation and Kruskal Algorithm: " << timecost * 1000 << "ms" << endl;
	return 0;
}
