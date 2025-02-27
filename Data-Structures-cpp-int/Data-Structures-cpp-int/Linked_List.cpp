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
	if (this->_first)// if there is a first node add the new node to the last node
	{
		Linked_List_Node* curr = this->_first;

		for (int i = 0; i < this->_len - 1; i++)
		{
			curr = curr->getNext();
		}

		curr->setNext(new Linked_List_Node(data));
	}
	else// new node is the first node
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

int Linked_List::getIndex(const int toSearch)
{
	Linked_List_Node* curr = this->_first;
	int index = 0;

	while (curr)
	{
		if (curr->getData() == toSearch)
			return index;

		index++;
		curr = curr->getNext();
	}

	return -1;
}

int Linked_List::count(const int toSearch)
{
	Linked_List_Node* curr = this->_first;
	int count = 0;

	while (curr)
	{
		if (curr->getData() == toSearch)
			count++;
		
		curr = curr->getNext();
	}

	return count;
}

int Linked_List::getLen() const
{
	return this->_len;
}

Linked_List_Node* Linked_List::getFirst() const
{
	return this->_first;
}

int& Linked_List::operator[](const int index) // one for changing
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

const int& Linked_List::operator[](const int index) const // one for using without changing
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

std::ostream& operator<<(std::ostream& os, const Linked_List& l)
{
	Linked_List_Node* curr = l.getFirst();

	if (curr)
	{
		while (curr && curr->getNext())// if it's not the last node
		{
			os << curr->getData() << ", ";
			curr = curr->getNext();
		}

		os << curr->getData() << "."; // adding the last node
	}
	else
	{
		os << "List is empty.";
	}

	return os;
}
