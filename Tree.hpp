#pragma once
#include "Edge.hpp"
#include <vector>

using std::vector;

class Tree
{
public:
	Tree(vector<Edge> edges);
	Tree(Tree t1, Tree t2);
	vector<Edge> edges() { return edg; }
	void add_egde();
private:
	vector<Edge> edg;
};
