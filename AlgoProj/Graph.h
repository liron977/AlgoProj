#ifndef _GRAPH_H
#define _GRAPH_H

#include <string>
#include "LinkedList.h"
#include <fstream>
#include <cstring>
#include <string>
using namespace std;


#define INDEX_IN_GRAPH -1

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
	void RemoveEdge(int u, int v);
	void ReadGraph(int n);
	void printGraph();
	bool isEmpty();

	// geters  
	int GetEdgeCapcity(int u, int v) const;
	LinkedList* GetAdjList() const;
	int GetVertexNum() const;

	//setters 
	void SetAdjList(LinkedList* newAdjList);
	void SetVertexNum(int newVertexNum);
	void SetEdgeCapacity(int u, int v, int newCapacity);

	//operators overloading 
	/*bool operator ==(const Graph& other) const;
	bool operator !=(const Graph& other) const;
	const Graph& operator= (const Graph& other);*/


private:
	// members
	LinkedList* adjList = nullptr; // we assume all capacities are integers  
	int vertexNum;

	//private function
	void DeleteAdjList();

	string inputFileName;


};
#endif

