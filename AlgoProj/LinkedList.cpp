#include "LinkedList.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

//ctor 
LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}



// dtor 
LinkedList::~LinkedList()
{
	makeEmpty();
}
//
// make empty linked list 
void LinkedList::makeEmpty()
{
	if (head != nullptr)
	{
		deleteAllElements();
	}
	this->head = nullptr;
	//this->head = NULL;
	this->tail = nullptr;
}

// check if linked list is empty 
bool LinkedList::isEmpty() const
{
	return (this->head == nullptr);
}

// return first element in linked list
Node* LinkedList::getHead() const
{
	return this->head;
}

// return last element in linked list 
Node* LinkedList::getTail() const
{
	return this->tail;
}

//insert new node with the value  'value' to the end of the linked list
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

//delete all elements in linked list 
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


// print linked list's values1
void LinkedList::print(int key) const
{
	Node* currentNode = this->head;
	while (currentNode)
	{
		cout << "     ";
		cout << key;
		cout << "     ";
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
	// Else Search for the key to be deleted,
	// keep track of the previous node as we
	// need to change 'prev->next' */
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
int LinkedList::getLength()const
{
	int count = 0;
	Node* currentNode = this->head;
	while (currentNode)
	{
		count++;
		currentNode = currentNode->getNext();
	}
	return count;
}
