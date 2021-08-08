#ifndef _NODE_H
#define _NODE_H



class Node
{
public:

	//Constructor
	Node();
	//Constructor,gets a value and a pointer to node
	Node(int  item, Node* ptr = nullptr);
	//default dtor
	~Node();

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

	//Insert newNode after current node.
	void insertAfter(Node* newNode);
	//delete node after current node(and return node to delete) 
	Node* deleteAfter();


private:
	int  data; //Data field.
	Node* next; //Points to next node in list.
};

#endif // _NODE_H