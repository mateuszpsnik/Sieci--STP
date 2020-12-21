#pragma once

#include "Tree.hpp"

class Forest
{
public:
	Forest(const vector<int>& vertices);
	vector<Edge> edges() { return edg; }
	vector<Tree> trees_vector() { return trees; }
	void add_edge(Edge e);
	void add_vertex(int v);
	void add_tree(Tree t);
	void delete_tree(int position);
	bool exists_in_the_forest(Edge edge);
	bool exists_in_any_tree(Edge edge);
	void sort_edges();
	void sort_vertices();
private:
	vector<Edge> edg;
	vector<int> vert;
	vector<Tree> trees;
};