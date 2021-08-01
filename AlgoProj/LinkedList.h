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

	void MakeEmpty();
	bool IsEmpty() const;
	Node* First() const;
	Node* Last() const;
	void print(int key) const;
	bool isExist(int value) const;
	void InsertToEnd(int value);
	Node* deleteNode(int value);
	void DeleteAllElements();
	int getLength()const ;

private:
	// members
	Node* head = nullptr;
	Node* tail;

	//private functions

};

#endif//! _LIST_H
