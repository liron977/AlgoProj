#include "Algorithm.h"
#include "Utils.h"
void Algorithm::shortPathAlgorithm()
{
	int n, s, t;
	Utils utils;

	utils.getGraphData(n, s, t);

	// for vertex v the value d[v] is the length of the shortest path from the source vertex to v ,and infinity if there isn't such path
	int *d = new int[n];
	// p represent the path from source discovered by BFS algorithm 
	// for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT) if it doesn't has one
	int* p = new int[n];

	Graph g(n);//Create graph
	if(!g.IsVertexInGraph(s)|| !g.IsVertexInGraph(t))
	{
		utils.invalidInputMessage();
	}
	g.ReadGraph();
	g.BFS(&p, &d, s);//BFS on the original graph (G) from vertex s.
	g.removeEdgeOfNonConsecutiveNumbersVertex(d);//remove from the graph any arc which does not satisfy the condition: d[v]=d[u]+1.
	
	Graph gTranspose(n);
	g.createTransposeGraph(gTranspose);//G transpose
	
	int* pTranspose = new int[n];
	int* dTranspose = new int[n];
	
	gTranspose.BFS(&pTranspose, &dTranspose, t);//BFS on the graph G transpose from vertex t.
	gTranspose.deleteInaccessibleEdgeFromSource(dTranspose);//Remove inaccessible Edge From t (H transpose).

	Graph h(n);
	gTranspose.createTransposeGraph(h);//Transpose to H transpose(create H).
	h.printGraph();
	delete[] p;
	delete[] d;
	delete[] dTranspose;
	delete [] pTranspose;
}
void Algorithm::executeShortPathAlgorithm() {


	auto start = chrono::high_resolution_clock::now();
	ios_base::sync_with_stdio(false);
	shortPathAlgorithm();
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout<<"Time taken by function shortPathAlgorithm is : "<< fixed <<time_taken << setprecision(9)<< " sec"<< endl;
	
}