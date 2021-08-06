#ifndef _LIST_H
#define _LIST_H
#include "Node.h"

class LinkedList
{

public:
	//object functions
	LinkedList();
	LinkedList(const Node& other);
	~LinkedList();

	void makeEmpty();
	bool isEmpty() const;
	Node* getHead() const;
	Node* getTail() const;
	void print(int key) const;
	bool isExist(int value) const;
	void insertToEnd(int value);
	Node* deleteNode(int value);
	void deleteAllElements();
	int getLength()const ;
	

private:
	// members
	Node* head = nullptr;
	Node* tail;


};

#endif//! _LIST_H
