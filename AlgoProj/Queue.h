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
	//object functions
	Queue();
	~Queue();
	void makeEmpty();
	bool isEmpty() const;
	void enQueue(int item);
	int deQueue();

private:
	// members
	Node* head = nullptr, * tail;
};

#endif // ! _QUEUE_H

