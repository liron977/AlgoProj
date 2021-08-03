#ifndef _GRAPH_H
#define _GRAPH_H

#include <string>
#include "LinkedList.h"
#include "Queue.h"
#include <fstream>
#include <cstring>
#include <string>

using namespace std;


#define INDEX_IN_GRAPH -1
#define NO_PARENT -1

class Graph
{
public:
	//object functions
	Graph(int n);
	//Graph(const Graph& other);
	~Graph();

	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v) const;
	LinkedList* GetAdjList(int u) const;

	bool IsVertexInGraph(int u) const;

	int AddEdge(int u, int v);
	Node* RemoveEdge(int u, int v);
	void ReadGraph();
	void printGraph();
	bool isEmpty();
	void createTransposeGraph(Graph& newTransposeGraph);
	void deleteUnaccessableEdgeFromSource(int* d);
	void removeEdgeOfNonConsecutiveNumbersVertex(int* d);

	// geters  
	
	LinkedList* GetAdjList() const;
	int GetVertexNum() const;

	//setters 
	void SetAdjList(LinkedList* newAdjList);
	void SetVertexNum(int newVertexNum);
	void BFS(int** p, int** d, int sourceVertex);
	void Algo(int source);



	//operators overloading 
	/*bool operator ==(const Graph& other) const;
	bool operator !=(const Graph& other) const;
	const Graph& operator= (const Graph& other);*/


private:
	// members
	LinkedList* adjList = nullptr; // we assume all capacities are integers  
	int vertexNum;
	
	//const int INFINITY_VAL = numeric_limits<int>::max();// max value of int is bigger than any int value , therefor we can refer it as infinity  
	//const int MINUS_INFINITY_VAL = numeric_limits<int>::min();// min value of int is smaller than any int value , therefor we can refer it as minus infinity  

	
	//private function
	void DeleteAdjList();

	string inputFileName;



};
#endif

