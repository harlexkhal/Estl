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
		m.PushBack("so so much fun");
		m.PushBack("Lets Store Enough Data in here");
		
		Estl::List<std::string> n;

		
		n = m;

		Estl::ListIterator<std::string> iterator(m.GetHeadNode());

		std::cout << *iterator << std::endl;
		++iterator;
		++iterator;
		std::cout << *iterator << std::endl;

		
	
		std::cin.get();
}