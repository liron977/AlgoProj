#include "LinkedList.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

LinkedList::~LinkedList()
{
	makeEmpty();
}

void LinkedList::makeEmpty()
{
	if (head != nullptr)
	{
		deleteAllElements();
	}
	this->head = nullptr;
	this->tail = nullptr;
}

bool LinkedList::isEmpty() const
{
	return (this->head == nullptr);
}


Node* LinkedList::getHead() const
{
	return this->head;
}


Node* LinkedList::getTail() const
{
	return this->tail;
}


void LinkedList::insertToEnd(int value)
{
	Node* temp = new Node(value);

	if (isEmpty())
	{
		this->head = temp;
	}
	else
	{
		tail->setNext(temp);
	}
	tail = temp;
}


void LinkedList::deleteAllElements()
{
	Node* currNode = this->head;
	Node* nextNode;
	
	while (currNode)
	{
		nextNode = currNode->getNext();
			delete currNode;
		currNode = nextNode;
	}
		
}



void LinkedList::print(int key) const
{
	Node* currentNode = this->head;
	while (currentNode)
	{
		cout << "   ";
		cout << key;
		cout << "   ";
		cout << currentNode->getData() << endl;

		currentNode = currentNode->getNext();

	}
}

bool LinkedList::isExist(int value) const
{
	Node* currentNode = this->head;
	while (currentNode!=NULL)
	{
		if (currentNode->getData() == value)
		{
			return true;
		}
		currentNode = currentNode->getNext();
		
	}
	return false;
}

Node* LinkedList::deleteNode(int value)
{
	Node* currentNode = this->head;
	Node* temp = currentNode;
	Node* prev = NULL;
	// If head node itself holds
	// the value to be deleted
	if (currentNode != NULL&&currentNode->getData() == value)
	{
		this->head=head->getNext();
		if (temp->getNext()== NULL)
		{
			this->tail = NULL;
		}
		delete temp;
		return this->head;
		
	}
	else
	{
		while (temp != NULL && temp->getData() != value)
		{
			prev = temp;
			temp=temp->getNext();
		}

		// If key was not present in linked list
		if (temp == NULL)
			return NULL;

		// Unlink the node from linked list
		prev->setNext(temp->getNext());
		if (temp->getNext() == NULL)
		{
			this->tail = NULL;
			
		}
		// Free memory
		delete temp;

		return prev;
	}

}

