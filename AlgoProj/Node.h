#ifndef _NODE_H
#define _NODE_H


//This fille represents the node of the linkedlist with we used for the list of neighborhoods
class Node
{
public:

	//Constructor
	Node();

	//Constructor,gets a value and a pointer to node
	Node(int  item, Node* ptr = nullptr);

	//Insert newNode after current node,the input is a new node to added 
	void insertAfter(Node* newNode);

	//delete node after current node(and returns node to delete) 
	Node* deleteAfter();

	//getters:
	
	//the function returns the value of the node
	int getData() const;

	//the function returns a pointer to the next node
	Node* getNext() const;

	//setters:
	
	//the function gets a value,and update the currect value of the node to the value that was recives by the function
	void setData(int newData);

	//the function gets a node,and update the member 'Next' of the node to the value that was recives by the function
	void setNext(Node* next);

	


private:
	int  data; //Data field.
	Node* next; //Points to next node in list.
};

#endif // _NODE_H