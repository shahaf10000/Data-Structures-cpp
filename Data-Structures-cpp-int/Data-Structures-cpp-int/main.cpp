#define _CRTDBG_MAP_ALLOC // for mem check
#include <stdlib.h>
#include <crtdbg.h>

#include "Linked_List.h"

void testLinkedList();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);// mem check

	testLinkedList();
}

void testLinkedList()
{
	Linked_List list;

	std::cout << list << std::endl;

	list.addNewNode(20);
	list.addNewNode(15);
	list.addNewNode(5);

	std::cout << list.getLen() << std::endl;

	for (int i = 0; i < list.getLen(); i++)
	{
		std::cout << "arg in index " << i << ": " << list[i] << std::endl;
	}
	
	std::cout << "printing list: " << std::endl << list << std::endl;

	list.remove(20);

	std::cout << "printing list: " << std::endl << list << std::endl;

	list.addNewNode(20);
	list.remove(5);

	std::cout << "printing list: " << std::endl << list << std::endl;

	std::cout << list.getLen() << std::endl;
}
