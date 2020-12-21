#pragma once
#include "Edge.hpp"
#include <vector>

using std::vector;

class Tree
{
public:
	Tree(const vector<Edge>& edges);
	Tree(const Tree& t1, const Tree& t2, const Edge& connector);
	vector<Edge> edges() { return edg; }
	void add_egde(Edge e);
	bool exists_in_the_tree(int vertex);
	bool connection_exists_in_the_tree(Edge edge);
	void sort_edges();
	void sort_vertices();
private:
	vector<Edge> edg;
	vector<int> vert;
	bool exists_in_the_tree(Edge edge);
	void add_vertex(int v);
};
