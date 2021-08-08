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
	//Ctor
	Graph(int n);
	//Dtor
	~Graph();

	//make empty graph with n vertexs and no edges using adjacency list and initialize all valaues to zero,the input is the number of vertexs
	void MakeEmptyGraph(int n);
	//// check if the edge (u,v) belong to the current graph.the input is edge
	bool IsAdjacent(int u, int v) const;
	// return pointer to linked list of the neighbours of vertex u ,the input is vertex
	LinkedList* GetAdjList(int u) const;
	//check if given integer is a vertex in current graph the input is vertex
	bool IsVertexInGraph(int u) const;
	// add edge (u,v) to graph,the input is 2 vertex 
	int AddEdge(int u, int v);
	// remove edge (u,v) from graph, the input is vertex 
	Node* RemoveEdge(int u, int v);
	//The function builds the graph from the input file
	void ReadGraph();
	//The function print the graph
	void printGraph();
	//The function verify if the number of vertexs in graph is empty  
	bool isEmpty();
	//The function create the transpose graph(if in G we have the edge(u,v) in g transpose we will have instead the edge (v,u)
	//The function recives an object in oreder to save the transpose graph 
	void createTransposeGraph(Graph& newTransposeGraph);
	//The function recives an array,and delete all the unaccessable edge from the source
	void deleteUnaccessableEdgeFromSource(int* d);
	//The function recives an array,and delete all the inaccessible edges of a non consecutive vertices
	void removeEdgeOfNonConsecutiveNumbersVertex(int* d);

	// geters:

	//The function returns the neighborhoods list
	LinkedList* GetAdjList() const;
	//The function returrn the number of vertexs in graph 
	int GetVertexNum() const;

	//setters:
	//The function gets an array of linked lists (neighborhoods list) and set it instead of the exist neighborhoods list
	void SetAdjList(LinkedList* newAdjList);
	//The function return 2 output parameters :arrays p and d 
    //for vertex v the value p[v] is the parent of v in BFS tree , and -1 (NO_PARENT)if it doesn't has one
    // for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path 
	void BFS(int** p, int** d, int sourceVertex);

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

