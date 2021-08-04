#ifndef _NODE_H
#define _NODE_H



class Node
{
public:
	//object functions
	Node();
	Node(int  item, Node* ptr = nullptr);
	~Node();

	//getters
	int getData() const;
	Node* getNext() const;

	//setters
	void setData(int newData);
	void setNext(Node* next);

	void insertAfter(Node* newNode);
	Node* deleteAfter();


private:
	// members
	int  data; //Data field.
	Node* next; //Points to next node in list.
};

#endif // _NODE_H