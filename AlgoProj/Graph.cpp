#include "Graph.h"

#include <cstring>

//ctor
Graph::Graph(int n)
{
	MakeEmptyGraph(n);
}

//copy ctor 
//Graph::Graph(const Graph& other)
//{
//	this->vertexNum = other.vertexNum;
//
//	adjMatrix = new int* [this->vertexNum];
//	for (int i = 0; i < this->vertexNum; ++i)
//		adjMatrix[i] = new int[this->vertexNum];
//
//	// Copy other's adjMatrix
//	for (int i = 0; i < this->vertexNum; i++)
//	{
//		memcpy(adjMatrix[i], other.adjMatrix[i], sizeof(int) * this->vertexNum);
//	}
//}

//dtor
Graph::~Graph()
{
	DeleteAdjList();
}

// make empty graph with n vertexs and no edges using adjacency matrix and initialize all valaues to zero .
//adjMatrix[u-1][v-1] is capacity of the edge (u,v)
void Graph::MakeEmptyGraph(int n)
{
	// delete old adjMatrix 
	
	//DeleteAdjMatrix();/TO DO

	adjList = new LinkedList[n];
	for (int i = 0; i < n; ++i)
	{
	 adjList[i].MakeEmpty(); //initialize all objects in matrix to zero 
	}

	vertexNum = n;
}

// check if the edge (u,v) belong to the current graph . (assuming there are vertexs u and v in current graph)
bool Graph::IsAdjacent(int u, int v) const
{
	
	if (IsVertexInGraph(u))
	{
		return adjList[u].isExist(v);
	}
	return false;
}

// return pointer to linked list of the neighbours of vertex u 
LinkedList* Graph::GetAdjList(int u) const
{	
		if (IsVertexInGraph)
		{
			return &(adjList[u]);
		}	

	return NULL;
}

//check if given integer is a vertex in current graph
bool Graph::IsVertexInGraph(int u) const
{
	return (u >= 1 && u <= this->vertexNum);
}

// add edge (u,v)  
void Graph::AddEdge(int u, int v)
{
	//TODO-Checks internal loops 
	if (IsVertexInGraph(u))
	{
		if (!adjList[u].isExist(v))
		{
			adjList[u].InsertToEnd(v);
		}
	}
}

// remove edge (u,v) .(assuming there are vertexs u and v in current graph)
void Graph::RemoveEdge(int u, int v)
{
	adjList[u].deleteNode(v);
}


// delete allocated memory of adjacency list 
void Graph::DeleteAdjList()
{
	for (int i = 0; i < vertexNum; i++)
	{
		adjList[i].DeleteAllElements();
	}
	delete[] adjList;
	vertexNum = 0;
	adjList = nullptr;
}

//return the capacity of the edge (u,v) . return 0 if there isn't such edge . (assuming there are verttexs u and v in current graph)
int Graph::GetEdgeCapcity(int u, int v) const
{
	return this->adjMatrix[u + INDEX_IN_GRAPH][v + INDEX_IN_GRAPH];
}

//getters
int** Graph::GetAdjMatrix() const
{
	return adjMatrix;
}

int Graph::GetVertexNum() const
{
	return vertexNum;
}

//setters
void Graph::SetAdjMatrix(int** newAdjMatrix)
{
	this->adjMatrix = newAdjMatrix;
}

void Graph::SetVertexNum(int newVertexNum)
{
	this->vertexNum = newVertexNum;
}

void Graph::SetEdgeCapacity(int u, int v, int newCapacity)
{
	this->adjMatrix[u + INDEX_IN_GRAPH][v + INDEX_IN_GRAPH] = newCapacity;
}

//operators overloading
bool Graph::operator==(const Graph& other) const
{
	if (this->vertexNum != other.vertexNum)
	{
		return false;
	}

	for (int i = 0; i < this->vertexNum; i++)
	{
		for (int j = 0; j < this->vertexNum; j++)
		{
			if (this->adjMatrix[i][j] != other.adjMatrix[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

bool Graph::operator!=(const Graph& other) const
{
	return !(*this == other);
}

const Graph& Graph::operator=(const Graph& other)
{
	if (this != &other) // check self- assignment
	{
		//delete current adjMatrix 
		DeleteAdjMatrix();

		this->vertexNum = other.vertexNum;
		adjMatrix = new int* [this->vertexNum];
		for (int i = 0; i < this->vertexNum; ++i)
			adjMatrix[i] = new int[this->vertexNum];

		// Copy other's adjMatrix
		for (int i = 0; i < this->vertexNum; i++)
		{
			memcpy(adjMatrix[i], other.adjMatrix[i], sizeof(int) * this->vertexNum);
		}
	}
	return *this;
}



