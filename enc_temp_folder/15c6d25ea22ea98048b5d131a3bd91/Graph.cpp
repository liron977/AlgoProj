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
	delete[]adjList;
	
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
	for (int i = 0; i < vertexNum; i++)
	{
		adjList[i].print(i + 1);
		cout << endl;
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