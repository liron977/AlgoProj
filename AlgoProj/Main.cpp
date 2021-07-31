
#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int n, u, v;
	cin >> n;
	cin >> u;
	cin >> v;
	Graph g(n);
	g.ReadGraph(n);
	g.printGraph();

}