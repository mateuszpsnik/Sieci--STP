#include "Forest.hpp"
#include <vector>
#include <algorithm>

struct Compare_Edges
{
	bool operator() (Edge edge1, Edge edge2)
	{
		if (edge1.source() == edge2.source())
			return edge1.destination() < edge2.destination();

		return edge1.source() < edge2.source();
	}
};

bool Forest::exists_in_the_forest(Edge edge)
{
	for (const Edge& element : edg)
	{
		if (element == edge)
			return true;
	}
	return false;
}

bool Forest::exists_in_any_tree(Edge edge)
{
	for (Tree element : trees)
	{
		if (element.connection_exists_in_the_tree(edge))
			return true;
	}
	return false;
}

void Forest::add_edge(Edge e)
{
	edg.push_back(e);
}

void Forest::add_vertex(int v)
{
	vert.push_back(v);
}

void Forest::add_tree(Tree t)
{
	trees.push_back(t);
}

void Forest::delete_tree(int position)
{
	trees.erase(trees.begin() + position);
}

Forest::Forest(const vector<int>& vertices)
{
	for (const int& vertex : vertices)
	{
		add_vertex(vertex);
		trees.push_back(Tree(vertex));
	}
}

void Forest::sort_edges()
{
	std::sort(edg.begin(), edg.end(), Compare_Edges());
}

void Forest::sort_vertices()
{
	std::sort(vert.begin(), vert.end());
}