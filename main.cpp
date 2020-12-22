#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <chrono>
#include "Edge.hpp"
#include "Tree.hpp"
#include "algorithms.hpp"
#include "Forest.hpp"
#include "files_manipulation.hpp"

using std::chrono::high_resolution_clock;
using std::chrono::time_point;
using std::chrono::duration;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	vector<Edge> edges; 
	vector<int> vertices; 

	cout << "Do you want to generate a text file? (y/n)";
	char c;
	cin >> c;
	if (c == 'y')
		generate_text_file();

	generate_edges_vertices(edges, vertices);

	time_point<high_resolution_clock> start_K, finish_K, start_P, finish_P;

	start_K = high_resolution_clock::now();
	Forest forest = Kruskals_algorithm(edges, vertices);
	finish_K = high_resolution_clock::now();
	start_P = high_resolution_clock::now();
	forest = Prims_algorithm(edges, vertices);
	finish_P = high_resolution_clock::now();
	
	start_P = high_resolution_clock::now();
	Forest Prim = Prims_algorithm(edges, vertices);
	finish_P = high_resolution_clock::now();

	start_K = high_resolution_clock::now();
	Forest Kruskal = Kruskals_algorithm(edges, vertices);
	finish_K = high_resolution_clock::now();

	duration<double> Kruskal_time = finish_K - start_K;
	duration<double> Prim_time = finish_P - start_P;

	Kruskal.sort_edges();
	Prim.sort_edges();

	write_out_results(Kruskal, Prim, Kruskal_time.count(), Prim_time.count());
}