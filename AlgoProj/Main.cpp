
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
	//g.printGraph();
	//g.Algo(u);
	int* p = new int[n];

	// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path .There is no vertex '0' therefor d[0] is non relevant (used for readability)
	int* d = new int[n];
	g.BFS(&p, &d, u);
	g.removeEdgeOfNonConsecutiveNumbersVertex(d);

	//cout << "--------------------------------------" << endl;
	//g.printGraph();
	Graph gt(n);
	g.createTransposeGraph(gt);
	int* pt = new int[n];

	// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path .There is no vertex '0' therefor d[0] is non relevant (used for readability)
	int* dt = new int[n];
	gt.BFS(&pt, &dt, v);
	gt.deleteUnaccessableEdgeFromSource(dt);
	//cout << "--------------------------------------" << endl;
	//gt.printGraph();
	Graph gt2(n);
	gt.createTransposeGraph(gt2);

	//cout <<"--------------------------------------" <<endl;
	gt2.printGraph();

}