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

	cout << "Enter the edges in this form:" << endl;
	cout << "source destination weight" << endl;

	for (size_t i = 0; i < 5; i++)
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

	for (auto& e : edges)
		cout << e << endl;
}