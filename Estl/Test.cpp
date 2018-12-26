#include <iostream>
#include <string>
#include "Estl.h"

int main()
{
	Estl::List<std::string> m;
	m.PushBack("hello");
	m.PushBack("cPP");
	m.PushBack("Test");
	m.PushBack("Lets just do more...Enjoying this");
	Estl::List<std::string> n;
	n = m;
	
	Estl::ListIterator<std::string> iterator(m.GetHeadNode());

	++iterator;
	++iterator;
	std::cout<<*iterator;

		std::cin.get();
}