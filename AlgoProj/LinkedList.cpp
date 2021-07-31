#include "LinkedList.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

//ctor 
LinkedList::LinkedList()
{
	MakeEmpty();
}

// dtor 
LinkedList::~LinkedList()
{
	DeleteAllElements();
}

// make empty linked list 
void LinkedList::MakeEmpty()
{
	if (head != nullptr)
	{
		DeleteAllElements();
	}
	this->head = nullptr;
	this->tail = nullptr;
}

// check if linked list is empty 
bool LinkedList::IsEmpty() const
{
	return (this->head == nullptr);
}

// return first element in linked list
Node* LinkedList::First() const
{
	return this->head;
}

// return last element in linked list 
Node* LinkedList::Last() const
{
	return this->tail;
}

//insert new node with the value  'value' to the end of the linked list
void LinkedList::InsertToEnd(int value)
{
	Node* temp = new Node(value);

	if (IsEmpty())
	{
		this->head = temp;
	}
	else
	{
		tail->setNext(temp);
	}
	tail = temp;
}

//delete all elements in linked list 
void LinkedList::DeleteAllElements()
{
	Node* currNode = this->head;
	Node* nextNode;

	while (currNode)
	{
		nextNode = currNode->GetNext();
		delete currNode;

		currNode = nextNode;
	}
}

// print linked list's values
void LinkedList::Print() const
{
	Node* currentNode = this->head;
	while (currentNode)
	{
		cout << currentNode->GetData();

		currentNode = currentNode->GetNext();
		if (currentNode != nullptr)
			cout << ", ";

	}
}


