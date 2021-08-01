#include "Graph.h"
#include <fstream>
#include <cstring>
#include <iostream>

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
//	delete[] adjList;
	
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
	return (u >= 1 && u <= this->vertexNum);
}

// add edge (u,v)  
int Graph::AddEdge(int u, int v)
{
	//TODO-Checks internal loops 
	if (IsVertexInGraph(u))
	{
		if (!adjList[u-1].isExist(v))
		{
			adjList[u-1].InsertToEnd(v);
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
		adjList[i].DeleteAllElements();
	}
	vertexNum = 0;
	//adjList = nullptr;
	
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
//operators overloading
//bool Graph::operator==(const Graph& other) const
//{
//	if (this->vertexNum != other.vertexNum)
//	{
//		return false;
//	}
//
//	for (int i = 0; i < this->vertexNum; i++)
//	{
//		for (int j = 0; j < this->vertexNum; j++)
//		{
//			if (this->adjMatrix[i][j] != other.adjMatrix[i][j])
//			{
//				return false;
//			}
//		}
//	}
//
//	return true;
//}
//
//bool Graph::operator!=(const Graph& other) const
//{
//	return !(*this == other);
//}
//
//const Graph& Graph::operator=(const Graph& other)
//{
//	if (this != &other) // check self- assignment
//	{
//		//delete current adjMatrix 
//		DeleteAdjMatrix();
//
//		this->vertexNum = other.vertexNum;
//		adjMatrix = new int* [this->vertexNum];
//		for (int i = 0; i < this->vertexNum; ++i)
//			adjMatrix[i] = new int[this->vertexNum];
//
//		// Copy other's adjMatrix
//		for (int i = 0; i < this->vertexNum; i++)
//		{
//			memcpy(adjMatrix[i], other.adjMatrix[i], sizeof(int) * this->vertexNum);
//		}
//	}
//	return *this;
//}
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
void Graph::ReadGraph(int n)
{
	int num1, num2;
	for (int i = 0; i < 28; i+=2)
	{
		cin >> num1;
		cin >> num2;
		AddEdge(num1, num2);

	}
	//char str[256];
	//cin >> inputFileName;
	//size_t found = inputFileName.find(".txt");
	//if (found == string::npos)
	//	inputFileName += ".txt";
	////ifstream myReadFile(inputFileName, ios::in);
	//std::fstream myReadFile(inputFileName, std::ios_base::in);
	//if (!myReadFile.is_open()) {//If the file does not exist or any other reason why the file can not be opned 
	//	cout<<"wrong";
	//}
	//int count = 0, j = 0, i = 0;
	//int num;
	//char curr_char,curr;
	//int temp;
	//	for (j = 0; j < n; j++)
	//	{
	//		myReadFile >> num;
	//		myReadFile.get(curr_char);
	//		if (myReadFile.eof())
	//			int x = 1;
	//		while (((curr_char != ' ') && (curr_char != '\n') && (!myReadFile.eof()))) //here we get each of the number characters
	//		{

	//			str[i] = curr_char;
	//			myReadFile.get(curr_char);
	//			i++;
	//		}
	//		str[i] = '\n';
	//		if (str[0] == '\n')
	//		{
	//			continue;
	//		}
	//		num = int(atof(str)); //we got a valid number and change its type to int 
	//		if (j % 2 == 0 && j != 0)
	//		{
	//			AddEdge(num, temp);
	//		}
	//		i = 0;
	//		temp = num;
	//}
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
	//int vertexNum = graph.GetVertexNum();

	//// for vertex v the value pArr[v] is the parent of v in BFS tree , and -1 (NO_PARENT)if it doesn't has one . There is no vertex '0' therefor pArr[0] is non relevant (used for readability)
	//// for vertex v the value dArr[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path .There is no vertex '0' therefor dArr[0] is non relevant (used for readability)
	int* pArr = *p;
	int* dArr = *d;

	for (int i = 0; i <= vertexNum; i++) // run over all vertexs .( There is no vertex '0' used to readability)
	{
		dArr[i] = numeric_limits<int>::max();
		pArr[i] = NO_PARENT;
	}

	Q.EnQueue(sourceVertex);
	dArr[sourceVertex-1] = 0;

	while (!Q.IsEmpty())
	{
		u = Q.DeQueue();
		//uAdjList = GetAdjList(u-1);
		currListNode = (adjList[u-1]).First();

		while (currListNode != nullptr)
		{
			v = currListNode->GetData();
			if (dArr[v-1] == numeric_limits<int>::max())
			{
				dArr[v-1] = dArr[u-1] + 1;
				pArr[v-1] = u;
				Q.EnQueue(v);
			}
			currListNode = currListNode->GetNext();
		}

		//delete uAdjList;
	}
}
void Graph::removeEdgeOfNonConsecutiveNumbersVertex(int* d)
{
	Node* currNode;
	for (int i = 0; i < vertexNum; i++)
	{
		currNode = adjList[i].First();
		while (currNode!=NULL)
		{
			if (d[currNode->GetData()-1] != d[i] + 1)
			{
				currNode=RemoveEdge(i, currNode->GetData());

			}
			else
			{
				currNode = currNode->GetNext();
			}
				
		}
	}
}
void Graph::Algo(int source)
{
	// p represent the path from source discovered by BFS algorithm 
// for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT) if it doesn't has one .There is no vertex '0' therefor p[0] is non relevant (used for readability)
	int* p = new int[vertexNum];

	// for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path .There is no vertex '0' therefor d[0] is non relevant (used for readability)
	int* d = new int[vertexNum ];

	BFS(&p, &d, source);
	removeEdgeOfNonConsecutiveNumbersVertex(d);



}
void Graph::createTransposeGraph(Graph& newTransposeGraph)
{
	LinkedList* newTransposeAdjList = new LinkedList[vertexNum];
	Node* currNode;
	for (int i = 0; i < vertexNum; i++)
	{
		currNode = adjList[i].First();
		while (currNode!=NULL)
		{
			newTransposeAdjList[currNode->GetData() - 1].InsertToEnd(i + 1);
			currNode = currNode->GetNext();
		}
	}
	newTransposeGraph.SetAdjList(newTransposeAdjList);

}
void Graph::deleteUnaccessableEdgeFromSource(int* d)
{
	for (int i = 0; i < vertexNum; i++)
	{
		if (d[i] == numeric_limits<int>::max())
		{
			for (int j = 0; j < vertexNum; j++)
			{
				if (!adjList[j].IsEmpty())
				{
					adjList[j].deleteNode(i + 1);
				}
				
			}
			adjList[i].MakeEmpty();
	
		}
	}
}