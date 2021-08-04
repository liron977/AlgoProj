#include "Graph.h"
#include "Utils.h"
#include <fstream>
#include <cstring>
#include <iostream>

//ctor
Graph::Graph(int n)
{
	MakeEmptyGraph(n);
}

//dtor
Graph::~Graph()
{

	delete[] adjList;

	//adjList = NULL;
     
	
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
	 adjList[i].makeEmpty(); //initialize all objects in matrix to zero 
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
	LinkedList* tempAdjList;
		if (IsVertexInGraph(u))
		{
			tempAdjList = new LinkedList(adjList[u]);
			return tempAdjList;
		}
	
	return NULL;
}

//check if given integer is a vertex in current graph
bool Graph::IsVertexInGraph(int u) const
{

	if(u >= 1 && u <= this->vertexNum)
	{
		return true;
	}
	return false;
}

// add edge (u,v)  
int Graph::AddEdge(int u, int v)
{
	Utils utils;
	//TODO-Checks internal loops 
	if (IsVertexInGraph(u))
	{
		if (!adjList[u-1].isExist(v))
		{
			adjList[u-1].insertToEnd(v);
			return 1;
		}
	}
	return 0;
}

// remove edge (u,v) .(assuming there are vertexs u and v in current graph)
Node* Graph::RemoveEdge(int u, int v)
{
	return (adjList[u].deleteNode(v));
}


// delete allocated memory of adjacency list 
void Graph::DeleteAdjList()
{
	for (int i = 0; i < vertexNum; i++)
	{
		adjList[i].deleteAllElements();
		
		
	}
	vertexNum = 0;
	//adjList = nullptr;
	//delete adjList;
	
}

//getters
LinkedList* Graph::GetAdjList() const
{
	return adjList;
}

int Graph::GetVertexNum() const
{
	return vertexNum;
}

//setters
void Graph::SetAdjList(LinkedList* newAdjList)
{
	this->adjList = newAdjList;
}

void Graph::SetVertexNum(int newVertexNum)
{
	this->vertexNum = newVertexNum;
}
bool Graph::isEmpty()
{
	if (vertexNum == 0)
	{
		return 1;
	}
	return 0;
}
void Graph::printGraph()
{
	cout << endl;
	for (int i = 0; i < vertexNum; i++)
	{
		adjList[i].print(i + 1);
	}
}
void Graph::ReadGraph()
{
	int u, v;
	Utils utils;
	u=utils.getInput();
	v=utils.getInput();
	
	while (!cin.eof())
	{
		if(!AddEdge(u, v))
		{
			utils.invalidInputMessage();
		}
		u = utils.getInput();
		v = utils.getInput();
		
		if (v == -1 &&u!=-1)
		{
			utils.invalidInputMessage();
		}
	}
	
	
	
}

//find path from 'sourceVertex' vertex in given graph using BFS . return 2 output parameters :arrays p and d  .
// for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT)if it doesn't has one . There is no vertex '0' therefor p[0] is non relevant (used for readability)
// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path .There is no vertex '0' therefor d[0] is non relevant (used for readability)

void Graph::BFS(int** p, int** d, int sourceVertex)
{
	Queue Q;
	int u, v;
	LinkedList* uAdjList;
	Node* currListNode;

	//// for vertex v the value pArr[v] is the parent of v in BFS tree , and -1 (NO_PARENT)if it doesn't has one . There is no vertex '0' therefor pArr[0] is non relevant (used for readability)
	//// for vertex v the value dArr[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path .There is no vertex '0' therefor dArr[0] is non relevant (used for readability)
	int* pArr = *p;
	int* dArr = *d;

	for (int i = 0; i < vertexNum; i++) // run over all vertexs .( There is no vertex '0' used to readability)
	{
		dArr[i] = numeric_limits<int>::max();
		pArr[i] = NO_PARENT;
	}

	Q.enQueue(sourceVertex);
	dArr[sourceVertex - 1] = 0;

	while (!Q.isEmpty())
	{
		u = Q.deQueue();
		currListNode = (adjList[u - 1]).getHead();

		while (currListNode != nullptr)
		{
			v = currListNode->getData();
			if (dArr[v - 1] == numeric_limits<int>::max())
			{
				dArr[v - 1] = dArr[u - 1] + 1;
				pArr[v - 1] = u;
				Q.enQueue(v);
			}
			currListNode = currListNode->getNext();
		}

		//delete uAdjList;
	}
}
void Graph::removeEdgeOfNonConsecutiveNumbersVertex(int* d)
{
	Node* currNode;
	for (int i = 0; i < vertexNum; i++)
	{
		currNode = adjList[i].getHead();
		while (currNode!=NULL)
		{
			if (d[currNode->getData()-1] != d[i] + 1)
			{
				currNode=RemoveEdge(i, currNode->getData());

			}
			else
			{
				currNode = currNode->getNext();
			}
				
		}
	}
}

void Graph::createTransposeGraph(Graph& newTransposeGraph)
{
	LinkedList* newTransposeAdjList =new LinkedList[vertexNum];
	Node* currNode;
	for (int i = 0; i < vertexNum; i++)
	{
		currNode = adjList[i].getHead();
		while (currNode!=NULL)
		{
			newTransposeAdjList[currNode->getData() - 1].insertToEnd(i + 1);
			currNode = currNode->getNext();
		}
	}
	newTransposeGraph.SetAdjList(newTransposeAdjList);
	//delete[] newTransposeAdjList;

}
void Graph::deleteUnaccessableEdgeFromSource(int* d)
{
	for (int i = 0; i < vertexNum; i++)
	{
		if (d[i] == numeric_limits<int>::max())
		{
			for (int j = 0; j < vertexNum; j++)
			{
				if (!adjList[j].isEmpty())
				{
					adjList[j].deleteNode(i + 1);
				}
				
			}
			if (!adjList[i].isEmpty()) {
				adjList[i].makeEmpty();
			}
		}
	}
}