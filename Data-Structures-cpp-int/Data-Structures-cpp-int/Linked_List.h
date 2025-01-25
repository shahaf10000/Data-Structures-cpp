#pragma once
#include "Linked_List_Node.h"

//////////////////////
// Class Definition //
//////////////////////

class Linked_List
{
public:
	/////////////////
	// Constructor //
	/////////////////
	Linked_List();

	~Linked_List();

	/////////////
	// methods //
	/////////////
	void addNewNode(const int data);
	void remove(const int data);

	/////////////
	// getters //
	/////////////
	int getLen() const;
	Linked_List_Node* getFirst() const;

	///////////////
	// operators //
	///////////////
	int& operator[](const int index);
	const int& operator[](const int index) const;

	friend std::ostream& operator<<(std::ostream& os, const Linked_List& p);

private:
	////////////
	// Fields //
	////////////
	Linked_List_Node* _first;
	int _len;

};
