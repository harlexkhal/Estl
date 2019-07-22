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

		//***********************************REMINDERS********TO DO/TO FIX*******************************
		//TODO create a --iterator, but first fix the link x.end() nullptr to a previous Node;
		//??TO DO**** KEEP TRACK OF LENGTH OR NUMBER OF ELEMENT IN THE LIST*****
		//TO DO***IF (POSITION) IS >= NUMBER OF ELEMENT OF THE LIST INSERTED DATA IN LAST POSITION OF THE LIST CHANGE <CURRLINKNODE,PREVLINKNODE,&NEXTLINKNODE DATA MEMBERS POSITION>
		//To Remove PrevLink Node Later...just discovered its an unecessary pointer...****TO DO LATER****
	

		Estl::Vector<std::string> vec(2);
		vec.push_back("this is awesome");
		vec.push_back("nice");
		vec.push_back("awesome");
		vec.push_back("blossom");
		vec.push_back("mind");

		std::cout << vec[4] << std::endl;

		std::cin.get();
}