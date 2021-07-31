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
	int GetData() const;
	Node* GetNext() const;

	//setters
	void setData(int newData);
	void setNext(Node* next);

	void InsertAfter(Node* newNode);
	Node* DeleteAfter();


private:
	// members
	int  data; //Data field.
	Node* next; //Points to next node in list.
};

#endif // _NODE_H