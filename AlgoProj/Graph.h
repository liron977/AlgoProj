#ifndef _GRAPH_H
#define _GRAPH_H

#include "LinkedList.h"

#include <cstring>

#define INDEX_IN_GRAPH -1

class Graph
{
public:
	//object functions
	Graph(int n);
	Graph(const Graph& other);
	~Graph();

	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v) const;
	LinkedList* GetAdjList(int u) const;

	bool IsVertexInGraph(int u) const;

	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);

	// geters  
	int GetEdgeCapcity(int u, int v) const;
	int** GetAdjMatrix() const;
	int GetVertexNum() const;

	//setters 
	void SetAdjMatrix(int** newAdjMatrix);
	void SetVertexNum(int newVertexNum);
	void SetEdgeCapacity(int u, int v, int newCapacity);

	//operators overloading 
	bool operator ==(const Graph& other) const;
	bool operator !=(const Graph& other) const;
	const Graph& operator= (const Graph& other);


private:
	// members
	int* adjList = nullptr; // we assume all capacities are integers  
	int vertexNum;

	//private function
	void DeleteAdjMatrix();
};
#endif

