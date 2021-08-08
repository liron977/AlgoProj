#ifndef  _QUEUE_H
#define _QUEUE_H

#include  <stdlib.h>
#include <iostream>
using namespace std;

#include "Node.h"


// queue class using linked list 
class Queue
{
public:
	//ctor - uses dummy node as first element 
	Queue();
	//dtor- free memory 
	~Queue();
	// empty queue 
	void makeEmpty();
	// check if queue is empty 
	bool isEmpty() const;
	// insert item to queue
	void enQueue(int item);

	int deQueue();

private:
	// members
	Node* head = nullptr, * tail;
};

#endif // ! _QUEUE_H

