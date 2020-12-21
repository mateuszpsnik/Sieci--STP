#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "Edge.hpp"
#include "Tree.hpp"

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

int main()
{
	int vertices;
	cout << "Enter the number of vertices: ";
	cin >> vertices;

	vector<Edge> edges = input_edges();

	Tree t(edges);

	t.sort_edges();
	t.sort_vertices();

	int begin;
	int end;

	cout << "begin and end:";
	cin >> begin >> end;

	for (auto& i : t.vertices())
		cout << i << " ";

	cout << endl;

	for (auto& e : t.edges())
		cout << e << endl;

	cout << "connection exists: " << t.connection_exists_in_the_tree(Edge(begin, end, 1));
}