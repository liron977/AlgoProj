#include "Algorithm.h"

void Algorithm::shortPathAlgorithm()
{
	int n, s, t;
	cin >> n;
	cin >> s;
	cin >> t;
	// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path
	int* d = new int[n];
	// p represent the path from source discovered by BFS algorithm 
	// for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT) if it doesn't has one
	int* p = new int[n];

	Graph g(n);
	g.ReadGraph(n);



	g.BFS(&p, &d, s);
	g.removeEdgeOfNonConsecutiveNumbersVertex(d);

	Graph gTranspose(n);
	g.createTransposeGraph(gTranspose);
	int* pTranspose = new int[n];

	int* dTranspose = new int[n];
	gTranspose.BFS(&pTranspose, &dTranspose, t);
	gTranspose.deleteUnaccessableEdgeFromSource(dTranspose);

	Graph h(n);
	gTranspose.createTransposeGraph(h);
	h.printGraph();

}