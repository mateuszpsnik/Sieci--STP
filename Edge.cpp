#include "Edge.hpp"

ostream& operator<<(ostream& out, const Edge& e)
{
	out << e.src << " " << e.dest << " " << e.w;
	return out;
}

istream& operator>>(istream& in, Edge& e)
{
	in >> e.src;
	in >> e.dest;
	in >> e.w;
	return in;
}

bool operator==(const Edge& e1, const Edge& e2)
{
	if (e1.dest == e2.dest && e1.src == e2.src)
		return true;
	if (e1.dest == e2.src && e1.src == e2.dest)
		return true;
	return false;
}

