#pragma once
#include <iostream>

class Linked_List_Node
{
public:
	Linked_List_Node(const int data);
	Linked_List_Node(Linked_List_Node* node);

	~Linked_List_Node() = default;

	int& getData();
	const int& getData() const;
	Linked_List_Node* getNext() const;

	void setData(const int data);
	void setNext(Linked_List_Node* _next);

private:
	int _data;
	Linked_List_Node* _next;

};
