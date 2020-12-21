#pragma once
#include <iostream>

using std::ostream;
using std::istream;

class Edge
{
public:
	Edge() {}
	Edge(int source, int destination, int weight) 
		: src(source), dest(destination), w(weight) {}
	constexpr int source() { return src; }
	constexpr int destination() { return dest; }
	constexpr int weight() { return w; }
	friend ostream& operator<<(ostream& out, const  Edge& e);
	friend istream& operator>>(istream& in, Edge& e);
	friend bool operator==(const Edge& e1, const Edge& e2);
private:
	int src{ 0 };
	int dest{ 0 };
	int w{ 0 };
};
