#include "Linked_List.h"

Linked_List::Linked_List() : _first(nullptr), _len(0)
{
}

Linked_List::~Linked_List()
{
	Linked_List_Node* curr = this->_first;

	while (curr)
	{
		Linked_List_Node* toDelete = curr;
		curr = curr->getNext();
		delete toDelete;
	}
}

void Linked_List::addNewNode(const int data)
{
	if (this->_first)
	{
		Linked_List_Node* curr = this->_first;

		for (int i = 0; i < this->_len; i++)
		{
			curr = curr->getNext();
		}

		curr->setNext(new Linked_List_Node(data));
	}
	else
	{
		this->_first = new Linked_List_Node(data);
	}

	this->_len++;
}

void Linked_List::remove(const int data)
{
	Linked_List_Node* curr = this->_first;

	if (this->_first->getData() == data)// if the node to remove is the first node
	{
		this->_first = this->_first->getNext();
		delete curr;
	}
	else
	{
		while (curr->getNext()->getData() != data)
		{
			curr = curr->getNext();
		}

		Linked_List_Node* toDelete = curr->getNext();

		curr->setNext(curr->getNext()->getNext());
		delete toDelete;
	}

	this->_len--;
}

int Linked_List::getLen() const
{
	return this->_len;
}

Linked_List_Node* Linked_List::getFirst() const
{
	return this->_first;
}

int& Linked_List::operator[](const int index)
{
	Linked_List_Node* curr = this->_first;

	for (int i = 0; i < index; i++)
	{
		curr = curr->getNext();
	}

	return curr->getData();
}

const int& Linked_List::operator[](const int index) const
{
	if (index < 0 || index >= this->_len)
	{
		throw std::out_of_range("Index out of range...");
	}

	Linked_List_Node* curr = this->_first;
	for (int i = 0; i < index; i++)
	{
		curr = curr->getNext();
	}

	return curr->getData();
}

std::ostream& operator<<(std::ostream& os, const Linked_List& p)
{
	Linked_List_Node* curr = p.getFirst();

	if (curr)
	{
		while (curr && curr->getNext())
		{
			os << curr->getData() + ", ";
			curr = curr->getNext();
		}

		os << curr->getData() + ".";
	}
	else
	{
		os << "List is empty.";
	}
}
