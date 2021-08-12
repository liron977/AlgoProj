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
//This fille contians all the graph functions 

class Graph
{
public:
	//Ctor get the number of vertexs 
	Graph(int n);
	//Dtor
	~Graph();

	//make empty graph with n vertexs and no edges using adjacency list and initialize all valaues to zero,the input is the number of vertexs
	void MakeEmptyGraph(int n);

	// check if the edge (u,v) belong to the current graph.the input is edge,if the edge isn`t related to trhe graph the function will return false,otherwise true
	bool IsAdjacent(int u, int v) const;

	//return pointer to linked list of the neighbours of vertex u ,the input is vertex
	LinkedList* GetAdjList(int u) const;

	//check if given integer is a vertex in current graph the input is vertex,if the vertex isn`t exist in the graph the function will return false,otherwise-true
	bool IsVertexInGraph(int u) const;

	//add edge (u,v) to graph,the input is 2 vertex,if the edge was added to the graph succesfully the function return 1,otherwise 0
	int AddEdge(int u, int v);

	//remove edge (u,v) from graph, the input is vertex,the function returns a pointer to the prev node in the linkedlist
	Node* RemoveEdge(int u, int v);

	//The function builds the graph from the input file
	void ReadGraph();

	//The function print the graph
	void printGraph();

	//The function verify if the number of vertexs in graph is zero,if we don`t have vertex in the current graph the function will return true,otherwise false  
	bool isEmpty();

	//The function create the transpose graph(if in G we have the edge(u,v) in g transpose we will have instead the edge (v,u)
	//The function recives an object in oreder to save the transpose graph 
	void createTransposeGraph(Graph& newTransposeGraph);

	//The function recives an array,and delete all the inaccessable edge from the source
	void deleteInaccessibleEdgeFromSource(int* d);

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
    //for vertex v the value d[v] is the length of the shortest path from sourceVertex to v ,and infinity if there isn't such path 
	void BFS(int** p, int** d, int sourceVertex);

private:
	LinkedList* adjList = nullptr;  
	int vertexNum;

	//private function:

	//delete allocated memory of adjacency list 
	void DeleteAdjList();
};
#endif

