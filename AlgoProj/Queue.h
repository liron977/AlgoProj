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
	void MakeEmpty();
	bool IsEmpty() const;
	void EnQueue(int item);
	int DeQueue();

private:
	// members
	Node* head = nullptr, * tail;
};

#endif // ! _QUEUE_H

