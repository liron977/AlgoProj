#ifndef _LIST_H
#define _LIST_H

#include "Node.h"

class LinkedList
{

public:
	//object functions
	LinkedList();
	~LinkedList();

	void MakeEmpty();
	bool IsEmpty() const;
	Node* First() const;
	Node* Last() const;
	void Print() const;
	bool isExist(int value) const;
	void InsertToEnd(int value);
	void deleteNode(int value);
	void DeleteAllElements();

private:
	// members
	Node* head = nullptr;
	Node* tail;

	//private functions

};

#endif//! _LIST_H
