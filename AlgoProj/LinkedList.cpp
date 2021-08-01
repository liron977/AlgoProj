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
	//this->head = nullptr;
	this->head = NULL;
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
void LinkedList::print(int key) const
{
	Node* currentNode = this->head;
	while (currentNode)
	{
		//cout << "     ";
		cout << key;
		cout << " ";
		cout << currentNode->GetData() << endl;

		currentNode = currentNode->GetNext();

	}
}
bool LinkedList::isExist(int value) const
{
	Node* currentNode = this->head;
	while (currentNode!=NULL)
	{
		if (currentNode->GetData() == value)
		{
			return true;
		}
		currentNode = currentNode->GetNext();
		
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
	if (currentNode != NULL&&currentNode->GetData() == value)
	{
		this->head=head->GetNext();
		if (temp->GetNext()== NULL)
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
		while (temp != NULL && temp->GetData() != value)
		{
			prev = temp;
			temp=temp->GetNext();
		}

		// If key was not present in linked list
		if (temp == NULL)
			return NULL;

		// Unlink the node from linked list
		prev->setNext(temp->GetNext());
		if (temp->GetNext() == NULL)
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
		currentNode = currentNode->GetNext();
	}
	return count;
}
