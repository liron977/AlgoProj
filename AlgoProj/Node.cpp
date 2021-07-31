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

//default dtor
Node::~Node() {}

// getters 
int Node::GetData() const
{
	return this->data;
}

Node* Node::GetNext() const
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

//Insert newNode after current node.
void Node::InsertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}

//delete node after current node(and return node to delete) 
Node* Node::DeleteAfter()
{
	Node* temp = next;
	if (next == nullptr)
		return nullptr;
	next = temp->next;
	return(temp);
}

