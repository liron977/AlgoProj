#ifndef _LIST_H
#define _LIST_H
#include "Node.h"



//This fille implementaion a linkedlist that we use for the list of neighborhoods

class LinkedList
{

public:

	//ctor 
	LinkedList();

	//dtor 
	~LinkedList();

	//make empty linked list 
	void makeEmpty();

	//check if linked list is empty,if the list is empty the function will return true,otherwise false 
	bool isEmpty() const;

	//return first element in linked list
	Node* getHead() const;

	//return last element in linked list 
	Node* getTail() const;

	//print linked list's values
	void print(int key) const;

	//the function gets a value and return true if the value exist in the list,else return false
	bool isExist(int value) const;

	//insert new node with the value 'value' to the end of the linked list
	void insertToEnd(int value);

	//delete the value from the list
	Node* deleteNode(int value);

	//delete all elements in linked list 
	void deleteAllElements();	

private:

	Node* head = nullptr;
	Node* tail;


};

#endif//! _LIST_H
