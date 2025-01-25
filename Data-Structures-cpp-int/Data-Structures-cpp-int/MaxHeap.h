#pragma once
#include "Linked_List.h"

class MaxHeap
{
public:
	MaxHeap() = default;
	~MaxHeap() = default;

	void insert(const int newData);
	int remove();

	void trickleUp(const int index);
	void trickleDown(const int index);

	void swap(const int indexOne, const int indexTwo);

	int static calcParent(const int childIndex);
	std::pair<int, int> static calcChild(const int parentIndex);

private:
	Linked_List list;
};

