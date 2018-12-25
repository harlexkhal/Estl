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
	Estl::List<std::string> n = m;
	
	std::cout << n[3] << std::endl;

		std::cin.get();
}