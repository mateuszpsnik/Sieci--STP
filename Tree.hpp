#pragma once
#include "Edge.hpp"
#include <vector>

using std::vector;

class Tree
{
public:
	Tree(const int& vertex);
	Tree(const vector<Edge>& edges);
	Tree(const Tree& t1, const Tree& t2, const Edge& connector);
	vector<Edge> edges() { return edg; }
	vector<int> vertices() { return vert; }
	void add_edge(Edge e);
	void add_vertex(int v);
	bool exists_in_the_tree(int vertex);
	bool exists_in_the_tree(Edge edge);
	bool connection_exists_in_the_tree(Edge edge);
private:
	vector<Edge> edg;
	vector<int> vert;
};
