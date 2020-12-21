#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "Edge.hpp"
#include "Tree.hpp"
#include "algorithms.hpp"
#include "Forest.hpp"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<Edge> input_edges()
{
	vector<Edge> edges;
	int num_of_edges;

	cout << "Enter the number of edges: ";
	cin >> num_of_edges;
	cout << "Enter the edges in this form:" << endl;
	cout << "source destination weight" << endl;

	for (size_t i = 0; i < num_of_edges; i++)
	{
		Edge e;
		cin >> e;
		edges.push_back(e);
	}

	return edges;
}

vector<int> input_vertices()
{
	vector<int> vertices;
	int num_of_vert;

	cout << "Enter the number of vertices: ";
	cin >> num_of_vert;
	cout << "Enter the vertices:" << endl;

	for (size_t i = 0; i < num_of_vert; i++)
	{
		int v;
		cin >> v;
		vertices.push_back(v);
	}

	return vertices;
}

int main()
{
	vector<Edge> edges = input_edges();
	vector<int> vertices = input_vertices();

	Forest forest = Kruskals_algorithm(edges, vertices);

	forest.sort_edges();

	for (const Edge& e : forest.edges())
	{
		cout << e << endl;
	}
}