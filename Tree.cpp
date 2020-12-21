#include "Tree.hpp"
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

// checks if the vertex given as an argument is already
// in the tree
bool Tree::exists_in_the_tree(int vertex)
{
	for (auto element : vert)
	{
		if (element == vertex)
			return true;
	}
	return false;
}

bool Tree::exists_in_the_tree(Edge edge)
{
	for (Edge element : edg)
	{
		if (element == edge)
			return true;
	}
	return false;
}

bool Tree::connection_exists_in_the_tree(Edge edge)
{
	if (!exists_in_the_tree(edge.source()))
		return false;
	if (!exists_in_the_tree(edge.destination()))
		return false;

	return true;
}

void Tree::add_egde(Edge e)
{
	edg.push_back(e);

	int source = e.source();
	int destination = e.destination();

	if (!exists_in_the_tree(source))
		vert.push_back(source);

	if (!exists_in_the_tree(destination))
		vert.push_back(destination);
}

void Tree::add_vertex(int v)
{
	vert.push_back(v);
}

Tree::Tree(const vector<Edge>& edges)
{
	for (const Edge& edge : edges)
	{
		add_egde(edge);
	}
}

Tree::Tree(const Tree& t1, const Tree& t2, const Edge& connector)
{
	for (const Edge& e : t1.edg)
		add_egde(e);

	for (const Edge& e : t2.edg)
	{
		if (!exists_in_the_tree(e))
			add_egde(e);
	}

	add_egde(connector);
}

void Tree::sort_edges()
{
	std::sort(edg.begin(), edg.end(), Compare_Edges());
}

void Tree::sort_vertices()
{
	std::sort(vert.begin(), vert.end());
}