#include "Node.h"

//Constructors
Node::Node()
{
	next = nullptr;
}

Node::Node(int item, Node* ptr)
{
	setData(item);
	setNext(ptr);
}


Node::~Node()
{
 
}

// getters 
int Node::getData() const
{
	return this->data;
}

Node* Node::getNext() const
{
	return this->next;
}

// setters
void Node::setData(int newData)
{
	this->data = newData;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

void Node::insertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}


Node* Node::deleteAfter()
{
	Node* temp = next;
	if (next == nullptr)
		return nullptr;
	next = temp->next;
	return(temp);
}

