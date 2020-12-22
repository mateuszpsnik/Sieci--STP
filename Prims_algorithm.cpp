#include "algorithms.hpp"
#include <map>

using std::map;

int max_weight(vector<Edge> edges)
{
	int max = 0;

	for (Edge edge : edges)
		if (edge.weight() > max)
			max = edge.weight();

	return max;
}

int min_cheapest_value_position(map<int, int> cheapest_connection, vector<int> vertices, int max_value)
{
	int min_cheapest = max_value;
	int position = 0;

	for (size_t i = 0; i < vertices.size(); i++)
	{
		if (cheapest_connection[vertices[i]] < min_cheapest)
		{
			min_cheapest = cheapest_connection[vertices[i]];
			position = i;
		}	
	}

	return position;
}

bool belongs_to(int element, vector<int> vec)
{
	for (const int& i : vec)
	{
		if (element == i)
			return true;
	}
	return false;
}

Forest Prims_algorithm(vector<Edge> edges, vector<int> vertices)
{
	int max_value = max_weight(edges) + 1;

	map<int, int> cheapest_connection;
	for (const int& vertex : vertices)
		cheapest_connection[vertex] = max_value;

	map<int, Edge> cheapest_connection_edge;
	for (const int& vertex : vertices)
		cheapest_connection_edge[vertex] = Edge();

	Forest forest;

	while (vertices.size() != 0)
	{
		int position = min_cheapest_value_position(cheapest_connection, vertices, max_value);
		int vertex = vertices[position];
		vertices.erase(vertices.begin() + position);

		forest.add_vertex(vertex);
		if (cheapest_connection_edge[vertex].weight() != 0)
			forest.add_edge(cheapest_connection_edge[vertex]);

		for (auto edge : edges)
		{
			if (edge.source() == vertex || edge.destination() == vertex)
			{
				int w;
				if (edge.source() == vertex)
					w = edge.destination();
				else
					w = edge.source();

				if (belongs_to(w, vertices) && edge.weight() < cheapest_connection[w])
				{
					cheapest_connection[w] = edge.weight();
					cheapest_connection_edge[w] = edge;
				}
			}
		}
	}

	return forest;
}