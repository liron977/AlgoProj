#include "Queue.h"


Queue::Queue()
{
	makeEmpty();
}


Queue::~Queue()
{
	Node* currNode;
	Node* nextNode;

	currNode = this->head;

	while (currNode)
	{
		nextNode = currNode->getNext();
		delete currNode;

		currNode = nextNode;
	}
}


void Queue::makeEmpty()
{
	Node* currNode;
	Node* nextNode;

	if (head != nullptr)
	{
		//empty current queue and free memory , and keep only dummy head 	
		currNode = this->head->getNext();
		while (currNode)
		{
			nextNode = currNode->getNext();
			delete currNode;

			currNode = nextNode;
		}
	}
	else
	{
		head = new Node(); // create 'dummy' head 
	}
	tail = head;
}


bool Queue::isEmpty() const
{
	return (head == tail);
}


void Queue::enQueue(int item)
{
	Node* newNode = new Node(item);
	tail->insertAfter(newNode);
	tail = newNode;
}
 
int Queue::deQueue()
{
	if (isEmpty())
	{
		cout << "Error! empty queue" << endl;
		exit(1);
	}

	Node* temp = head->deleteAfter();
	int item = temp->getData();
	if (tail == temp)
	{
		tail = head;
	}
	delete temp;
	return item;
}
