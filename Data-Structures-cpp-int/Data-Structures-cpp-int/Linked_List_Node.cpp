#include "Linked_List_Node.h"

Linked_List_Node::Linked_List_Node(const int data) : _data(data), _next(nullptr)
{
}

Linked_List_Node::Linked_List_Node(Linked_List_Node* node) : _data(node->_data), _next(node->_next)
{
}

int& Linked_List_Node::getData()
{
	return this->_data;
}

const int& Linked_List_Node::getData() const
{
	return this->_data;
}

Linked_List_Node* Linked_List_Node::getNext() const
{
	return this->_next;
}

void Linked_List_Node::setData(const int data)
{
	this->_data = data;
}

void Linked_List_Node::setNext(Linked_List_Node* next)
{
	this->_next = next;
}
