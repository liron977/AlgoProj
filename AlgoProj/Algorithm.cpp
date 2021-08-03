#include "Algorithm.h"
#include "Utils.h"
void Algorithm::shortPathAlgorithm()
{
	int n, s, t;
	Utils utils;
	
	utils.getGraphData(n, s, t);

	// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path
	int *d = new int[n];
	// p represent the path from source discovered by BFS algorithm 
	// for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT) if it doesn't has one
	int* p = new int[n];

	Graph g(n);
	if(!g.IsVertexInGraph(s)|| !g.IsVertexInGraph(t))
	{
		utils.invalidInputMessage();
	}
	g.ReadGraph();
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
	delete[] p;
	delete[] d;
	delete[] dTranspose;
	delete [] pTranspose;
}
//void Algorithm::algorithmFirstSteps(int& n,int& s, int& t,Graph& g2)
//{
//	Utils utils;
//
//	utils.getGraphData(n, s, t);
//
//	// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path
//	int* d = new int[n];
//	// p represent the path from source discovered by BFS algorithm 
//	// for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT) if it doesn't has one
//	int* p = new int[n];
//
//	Graph g(n);
//	if (!g.IsVertexInGraph(s) || !g.IsVertexInGraph(t))
//	{
//		utils.invalidInputMessage();
//	}
//	g.ReadGraph();
//	g.BFS(&p, &d, s);
//	g.removeEdgeOfNonConsecutiveNumbersVertex(d);
//	delete[] p;
//	delete[] d;
//	g2 = g;
//	return g;
//}


void Algorithm::executeShortPathAlgorithm() {


	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	shortPathAlgorithm();
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << "Time taken by function shortPathAlgorithm is : " << fixed
		<< time_taken << setprecision(9);
	myfile << " sec" << endl;
	myfile.close();
}