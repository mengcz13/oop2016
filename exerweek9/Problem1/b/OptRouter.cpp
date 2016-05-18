#include "BaseRouter.h"
#include "OptRouter.h"
#include <cstdio>

using namespace std;

bool OptRouter::route(void) {
	if (!BaseRouter::route())
		return false;
	int p = 0, q = m_path.size() - 1;
	while (p < q) {
		int t = m_path[p];
		m_path[p] = m_path[q];
		m_path[q] = t;
		++p;
		--q;
	}
	min_turn_num = get_turn_num(m_path);
	distance = m_path.size() - 1;
	current_turn_num = 0;
	temppath.clear();
	visit_graph.assign(m_row * m_col, false);
	int x = 0, y = 0;
	compXYIndex(m_sourceIndex, x, y);
	dfsat(x, y, 0);
	
	printf("\nFound shortest path with minimal turns ( %d turns) : ", min_turn_num);
	for (unsigned int i = 0; i < m_path.size(); ++i) {
		int x, y;
		compXYIndex(m_path[i], x, y);
		printf("[%d,%d] ", x, y);
	}
	printf("\n");

	return true;
}

int OptRouter::get_turn_num(vector<int>& path) {
	if (path.size() < 3)
		return 0;
	int turnnum = 0;
	for (unsigned int i = 0; i < path.size() - 2; ++i) {
		if (if_turn(path[i], path[i + 1], path[i + 2]))
			++turnnum;
	}
	return turnnum;
}

void OptRouter::dfsat(int x, int y, int depth) {
	int index = compIndex(x, y);
	temppath.push_back(index);
	visit_graph[index] = true;
	bool isturn = false;
	if (temppath.size() >= 3) {
		int bottom = temppath.size() - 1;
		isturn = if_turn(temppath[bottom], temppath[bottom - 1], temppath[bottom - 2]);
	}
	if (isturn)
		++current_turn_num;

	if (depth == distance) {
		if (index != m_targetIndex) {
			// Fail
		}
		else {
			if (current_turn_num < min_turn_num) {
				min_turn_num = current_turn_num;
				m_path = temppath;
			}
		}
		// draw back
	}
	else if (current_turn_num >= min_turn_num) {
		// draw back
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int nx = x + X[i];
			int ny = y + Y[i];
			if (0 <= nx && nx < m_col && 0 <= ny && ny < m_row && m_grids[index] != OBS && !visit_graph[compIndex(nx, ny)]) {
				dfsat(nx, ny, depth + 1);
			}
		}
		// draw back
	}

	// DRAWBACK
	temppath.pop_back();
	visit_graph[index] = false;
	if (isturn)
		--current_turn_num;
	return;
}

bool OptRouter::if_turn(int index1, int index2, int index3) {
	Point p1, p2, p3;
	compXYIndex(index1, p1.x(), p1.y());
	compXYIndex(index2, p2.x(), p2.y());
	compXYIndex(index3, p3.x(), p3.y());
	if (p1.x() == p2.x() && p2.x() == p3.x())
		return false;
	else if (p1.y() == p2.y() && p2.y() == p3.y())
		return false;
	else
		return true;
}