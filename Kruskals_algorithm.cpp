#include "algorithms.hpp"
#include "Forest.hpp"
#include <algorithm>
#include <functional>

struct Compare_Edges_by_weight_descending
{
	bool operator() (Edge edge1, Edge edge2)
	{
		return edge1.weight() > edge2.weight();
	}
};

Forest Kruskals_algorithm(vector<Edge> edges, vector<int> vertices)
{
	Forest forest(vertices);

	// sorting in descending order to use pop_back() later
	std::sort(edges.begin(), edges.end(), Compare_Edges_by_weight_descending());

	while (edges.size() != 0)
	{
		Edge e = edges.back();
		edges.pop_back();

		// skips to the next iteration
		// if Edge e exists in any tree
		if (forest.exists_in_any_tree(e))
			continue;

		int source_position = 0;
		int destination_position = 0;

		for (size_t i = 0; i < forest.trees_vector().size(); i++)
		{
			// if in some tree 'i' exists the vertex e.source()
			// then save the position of this tree to source_position
			if (forest.trees_vector()[i].exists_in_the_tree(e.source()))
				source_position = i;

			// if in some tree 'i' exists the vertex e.destination()
			// then save the position of this tree to destination_position
			if (forest.trees_vector()[i].exists_in_the_tree(e.destination()))
				destination_position = i;
		}


		// create a new tree connecting the pair found 
		// in the loop above
		Tree t1 = forest.trees_vector()[source_position];
		Tree t2 = forest.trees_vector()[destination_position];
		Tree t(t1, t2, e);

		forest.delete_tree(source_position);

		if (destination_position > source_position)
			destination_position--;

		forest.delete_tree(destination_position);
		forest.add_tree(t);
		forest.add_edge(e);
	}

	return forest;
}