#include <fstream>
#include <cstdlib>
#include <ctime>
#include "files_manipulation.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

void generate_text_file()
{
	int num_of_edges, num_of_vert, max_weight;

	cout << "Enter the number of vertices: ";
	cin >> num_of_vert;

	cout << "Enter the number of edges: ";
	cin >> num_of_edges;

	cout << "Enter the maximal weight: ";
	cin >> max_weight;

	cout << "Enter the destination filename: ";
	string filename;
	cin >> filename;

	fstream output;
	output.open(filename, fstream::out);

	output << num_of_vert << endl;

	for (size_t i = 0; i < num_of_vert; i++)
		output << i << " ";
	output << endl;

	std::srand((int)std::time(0));

	Tree edges(0);

	for (size_t i = 0; i < num_of_edges; i++)
	{
		int source = std::rand() % num_of_vert;
		int destination = std::rand() % num_of_vert;
		int weight = std::rand() % max_weight + 1;

		Edge edge(source, destination, weight);

		if (destination != source && !edges.exists_in_the_tree(edge))
			edges.add_edge(edge);
	}

	output << edges.edges().size() << endl;

	for (auto& edge : edges.edges())
		output << edge << endl;
}

void generate_edges_vertices(vector<Edge>& edges, vector<int>& vertices)
{
	cout << "Enter the filename: ";
	string filename;
	cin >> filename;

	fstream input;
	input.open(filename, fstream::in);

	int num_of_edges, num_of_vert;

	input >> num_of_vert;
	for (size_t i = 0; i < num_of_vert; i++)
	{
		int vertex;
		input >> vertex;
		vertices.push_back(vertex);
	}

	input >> num_of_edges;
	for (size_t i = 0; i < num_of_edges; i++)
	{
		Edge edge;
		input >> edge;
		edges.push_back(edge);
	}
}

void write_out_results(Forest Kruskal, Forest Prim, double Kruskal_time,
	double Prim_time)
{
	int cost_K = 0;
	int cost_P = 0;

	cout << "Enter where you want to save the results: ";
	string filename;
	cin >> filename;

	fstream output;
	output.open(filename, fstream::out);

	output << "Kruskal's algorithm:" << endl;
	output << "Edges left:" << endl;

	for (auto edge : Kruskal.edges())
	{
		cost_K += edge.weight();
		output << edge << endl;
	}
		
	output << "Cost: " << cost_K << endl;
	output << "Time: " << Kruskal_time << endl;

	output << "Prim's algorithm:" << endl;
	output << "Edges left:" << endl;

	for (auto edge : Prim.edges())
	{
		cost_P += edge.weight();
		output << edge << endl;
	}

	output << "Cost: " << cost_P << endl;
	output << "Time: " << Prim_time << endl;
}