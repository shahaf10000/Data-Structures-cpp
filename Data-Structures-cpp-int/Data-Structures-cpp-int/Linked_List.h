#pragma once
#include "Linked_List_Node.h"

class Linked_List
{
public:
	Linked_List();

	~Linked_List();

	void addNewNode(const int data);
	void remove(const int data);

	int getLen() const;
	Linked_List_Node* getFirst() const;

	int& operator[](const int index);
	const int& operator[](const int index) const;

	friend std::ostream& operator<<(std::ostream& os, const Linked_List& p);

private:
	Linked_List_Node* _first;
	int _len;

};
