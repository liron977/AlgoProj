// T
#include "Algorithm.h"
#include <fstream>
#include <iostream>

using namespace std;
//The program find the short path from a single vertex to a target vertex.
//The graph built in a data structure of a list of neighborhoods.
//The BFS process uses queue to switch between all vertices.
//We also use 2 arrays :
//Array d - contains the length of the shortest path from source vertex to v, and infinity if there isn't such path
//Array p - represent the path from source discovered by BFS algorithm, ertex v the value p[v] is the parent of v in BFS tree, and -1 (NO_PARENT) if it doesn't has one.
//The program also print the run time 
//in order to activate the program you need to insert the number of vertices,source vertex ,target vertex
//and edges,press control 'Z' to start the process(short path from a single vertex to a target vertex)


//The class are :
//	Algorithm
//	Graph
//	LinkedList
//	Main
//	Node
//	Queue
//	Utils
//	you can see the role of each class in the header file
int main()
{
	Algorithm algo;
	algo.executeShortPathAlgorithm();	
}
