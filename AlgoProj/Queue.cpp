#include "Queue.h"

//ctor - uses dummy node as first element 
Queue::Queue()
{
	MakeEmpty();
}

//dtor- free memory 
Queue::~Queue()
{
	Node* currNode;
	Node* nextNode;

	currNode = this->head;

	while (currNode)
	{
		nextNode = currNode->GetNext();
		delete currNode;

		currNode = nextNode;
	}
}

// empty queue 
void Queue::MakeEmpty()
{
	Node* currNode;
	Node* nextNode;

	if (head != nullptr)
	{
		//empty current queue and free memory , and keeep only dummy head 	
		currNode = this->head->GetNext();
		while (currNode)
		{
			nextNode = currNode->GetNext();
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

// check if queue is empty 
bool Queue::IsEmpty() const
{
	return (head == tail);
}

// insert item to queue
void Queue::EnQueue(int item)
{
	Node* newNode = new Node(item);
	tail->InsertAfter(newNode);
	tail = newNode;
}

// remove first item in queue 
int Queue::DeQueue()
{
	if (IsEmpty())
	{
		cout << "Error! empty queue" << endl;
		exit(1);
	}

	Node* temp = head->DeleteAfter();
	int item = temp->GetData();
	if (tail == temp)
	{
		tail = head;
	}
	delete temp;
	return item;
}
