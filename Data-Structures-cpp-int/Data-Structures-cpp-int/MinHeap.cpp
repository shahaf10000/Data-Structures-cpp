#include "MinHeap.h"

void MinHeap::insert(const int newData)
{
	this->list.addNewNode(newData);
	trickleUp(this->list.getLen());
}

int MinHeap::remove()
{
	int lastPos = this->list[this->list.getLen() - 1];
	this->list.remove(lastPos);

	this->list[0] = lastPos;

	trickleDown(0);
}

void MinHeap::trickleUp(const int index)
{
	if (index == 0)
		return;

	int parentIndex = calcParent(index);

	if (this->list[parentIndex] > this->list[index])
	{
		this->swap(index, parentIndex);

		trickleUp(parentIndex);
	}
}

void MinHeap::trickleDown(const int index)
{
	std::pair<int, int> children = calcChild(index);
	int lastIndex = this->list.getLen() - 1;

	if (children.first == lastIndex && this->list[children.first] < this->list[index])
		// if the left child is the last index
		// and the left child is lower thn the parent swap them
	{
		this->swap(index, children.first);
		return;
	}

	if (children.second == lastIndex && this->list[children.second] < this->list[index])
		// if the right child is the last index
		// and the right child is lower thn the parent swap them
	{
		this->swap(index, children.second);
		return;
	}

	if (children.first >= lastIndex || children.second >= lastIndex)
		// if the kids are in the last indexes and they are smaller than the parent, or are not actually there
	{
		return;
	}

	if (this->list[children.first] < this->list[children.second])
	{
		if (this->list[children.first] < this->list[index])
		{
			this->swap(index, children.first);
			this->trickleDown(children.first);
		}
	}
	else
	{
		if (this->list[children.second] < this->list[index])
		{
			this->swap(index, children.second);
			this->trickleDown(children.second);
		}
	}
}

void MinHeap::swap(const int indexOne, const int indexTwo)
{
	int t = this->list[indexOne];
	this->list[indexOne] = this->list[indexTwo];
	this->list[indexTwo] = t;
}

int MinHeap::calcParent(const int childIndex)
{
	return (childIndex - 1) / 2;
}

std::pair<int, int> MinHeap::calcChild(const int parentIndex)
{
	return std::pair<int, int>(2 * parentIndex + 1, 2 * parentIndex + 2);
}
