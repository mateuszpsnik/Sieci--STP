#include "Edge.hpp"

ostream& operator<<(ostream& out, const Edge& e)
{
	out << "source: " << e.src << " destination: " << e.dest
		<< " weight: " << e.w;
	return out;
}

istream& operator>>(istream& in, Edge& e)
{
	//std::cout << "Enter source: ";
	in >> e.src;
	//std::cout << "Enter destination: ";
	in >> e.dest;
	//std::cout << "Enter weight: ";
	in >> e.w;
	return in;
}

bool operator==(const Edge& e1, const Edge& e2)
{
	if (e1.dest == e2.dest && e1.src == e2.src && e1.w == e2.w)
		return true;
	return false;
}

