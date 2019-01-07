#include <iostream>
#include <string>
#include "Estl.h"

int main()
{
	
		Estl::List<std::string> m;
		m.PushBack("hello");
		m.PushBack("cPP");
		m.PushBack("lol");
		m.PushBack("Finally it did Work");
		m.PushBack("After so many debugging Efforts");
		m.PushBack("The Estl Api project");
		m.PushBack("Home made stl Lib school project");
		m.PushBack("I feel we should Add more to this Linked list");
		m.PushBack("Adding some more Data would be fun");
		m.PushBack("it helps to discover if there are any bugs with the List");
		
		
		Estl::List<std::string> n;
		
		n = m;
		m.ReverseList();
		

		Estl::ListIterator<std::string> iterator(m.GetHeadNode());
		std::cout << *iterator << std::endl;
		++iterator;
		++iterator;
		std::cout << *iterator << std::endl;

		
	
		std::cin.get();
}