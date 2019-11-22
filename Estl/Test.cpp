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
		m.Insert(0, "A");
		m.InsertLast("Cool");
		m.PushBack("awesome");

		m.DeleteElement(7);
		Estl::List<std::string>* o = new Estl::List<std::string>;
	
		m[0] = "chai";

		std::cout << m[0] << std::endl;

		std::string Array[] = { "F","L","A" };
		Estl::BubbleSort(Array,3);
		std::cout << Array[0] << std::endl;

		Estl::SelectionSort(Array, 3);
		std::cout << Array[1] << std::endl;

		Estl::Vector<std::string> vec(2);
		vec.push_back("this is awesome");
		vec.push_back("nice");
		vec.push_back("awesome");
		vec.push_back("blossom");
		vec.push_back("mind");

		std::cout << vec[4] << std::endl;

		Estl::Btree<int> Tree;
		Tree.Insert(5);
		Tree.Insert(7);
		Tree.Insert(2);
		Tree.InorderTraversal();
		Tree.Delete(2);
		Tree.PostorderTraversal();
		
		std::cin.get();
}