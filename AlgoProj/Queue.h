#ifndef  _QUEUE_H
#define _QUEUE_H

#include  <stdlib.h>
#include <iostream>
using namespace std;

#include "Node.h"


//This fille represents the queue for using for the BFS
class Queue
{
public:
	//ctor - uses dummy node as first element 
	Queue();

	//dtor- free memory 
	~Queue();

	// empty queue 
	void makeEmpty();

	//check if queue is empty ,if the queue is empty the function reeturns true,otherwise-false
	bool isEmpty() const;

	// insert item to queue
	void enQueue(int item);

	//Pull item from the queue and returns it
	int deQueue();

private:
	// members
	Node* head = nullptr, * tail;
};

#endif // ! _QUEUE_H

