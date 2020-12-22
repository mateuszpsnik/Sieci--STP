#pragma once
#include "Forest.hpp"

void generate_text_file();

void generate_edges_vertices(vector<Edge>& edges, vector<int>& vertices);

void write_out_results(Forest Kruskal, Forest Prim, double Kruskal_time,
	double Prim_time);
