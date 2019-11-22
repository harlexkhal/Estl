#include "Btree.h"

namespace Estl
{
	template<class T>
	Btree<T>::Btree()
	{
		Root = nullptr;
	}

	template<class T>
	Btree<T>::~Btree()
	{
	}

	template<class T>
	inline Btree<T>::Btree(const Btree & Tree)
	{
	}

	template<class T>
	Btree<T> Btree<T>::operator=(const Btree & Tree)
	{
		return Btree();
	}

	template<class T>
	bool Btree<T>::IsEmpty()
	{
		return ( Root == nullptr);
	}

	template<class T>
	void Btree<T>::InorderTraversal()
	{
		InorderTraversal(Root);
	}

	template<class T>
	void Btree<T>::PreorderTraversal()
	{
		PreorderTraversal(Root);
	}

	template<class T>
	void Btree<T>::PostorderTraversal()
	{
		PostorderTraversal(Root);
	}

	template<class T>
	int Btree<T>::TreeHeight(const Btree & Tree)
	{
		return 0;
	}

	template<class T>
	int Btree<T>::TreeNodeCount()
	{
		return 0;
	}

	template<class T>
	int Btree<T>::TreeLeavesCount()
	{
		return 0;
	}

	template<class T>
	void Btree<T>::DestroyTree()
	{
	}

	template<class T>
	void Btree<T>::Insert(const T & InsertData)
	{
		if (Root == nullptr)
		{
			Root = new Node<T>;
			Root->Data = InsertData;
			Root->Llink = nullptr;
			Root->Rlink = nullptr;
		}

		else
		{
			Node<T>* Current = Root;
			Node<T>* Trail = nullptr;

			while (Current != nullptr)
			{
				Trail = Current;

				if (Trail->Data > InsertData)
					Current = Current->Llink;

				else if (Trail->Data == InsertData)
					assert(false), std::cerr << "Duplicates Are Not Allowed" << std::endl;

				else
					Current = Current->Rlink;
			}
			
			Current = new Node<T>;
			Current->Data = InsertData;
			if (Trail->Data > InsertData)
				Trail->Llink = Current;
			else
				Trail->Rlink = Current;

			Current->Rlink = nullptr; //---Safety---
			Current->Llink = nullptr; //---Safety---
		}
	}

	template<class T>
	void Btree<T>::Delete(const T& m_Data)
	{
		Node<T>* Current = Root;
		Node<T>* Trail = nullptr;
		bool Found = false;
		while (Current != nullptr && !Found)
		{
			if (Current->Data == m_Data)
				Found = true;

			else
			{
				Trail = Current;
				if (Current->Data > m_Data)
					Current = Current->Llink;
				else
					Current = Current->Rlink;
			}
		}

		if (Current == nullptr || !Found)
			std::cerr << "The Element to be deleted does not exist in the Tree" << std::endl;
		else
			if (Trail->Data > m_Data)
				DeleteNode(Trail->Llink);  //It should normally make sense for me to throw in the address of Current here,
			else                           //since Trail->Llink is still the same as Current. but don't be fooled by c++ pointers
				DeleteNode(Trail->Rlink);  //you can be punished for this. because the Trail->Llink would still be pointing at an
	}									   //address Current which you are about to release. so its best to send the Trail->Llink
										   //or Trail->Rlink which holds the address and delete its reference to the pointer. also
										   //making Trail->Llink ref pointer nullptr which really terminates what its actually 
										   //pointing to.			   	
	

	template<class T>
	void Btree<T>::Search(const T & m_Data)
	{
	}

	template<class T>
	void Btree<T>::PreorderTraversal(Node<T>*& P)
	{
		if (P != nullptr)
		{
			std::cout << P->Data << " ";
			PreorderTraversal(P->Llink);
			PreorderTraversal(P->Rlink);
		}
	}

	template<class T>
	void Btree<T>::InorderTraversal(Node<T> *&P)
	{
		if (P != nullptr)
		{
			InorderTraversal(P->Llink);
			std::cout << P->Data << " ";
			InorderTraversal(P->Rlink);
		}
	}

	template<class T>
	void Btree<T>::PostorderTraversal(Node<T>*& P)
	{

		if (P != nullptr)
		{
			PostorderTraversal(P->Llink);
			PostorderTraversal(P->Rlink);
			std::cout << P->Data << " ";
		}
	}

	template<class T>
	void Btree<T>::CopyTree(const Btree & Tree)
	{
	}

	template<class T>
	void Btree<T>::DeleteNode(Node<T> *&P)
	{
		Node<T>* Current;
		Node<T>* Trail;
		if (P == nullptr)
			std::cerr << "Error: The node to be deleted does not exist." << std::endl;

		else if (P->Llink == nullptr && P->Rlink == nullptr)
		{
			Current = P;
			P = nullptr;
			delete Current;
		}

		else if (P->Llink == nullptr)
		{
			Current = P;
			P = P->Rlink;
			delete Current;
		}

		else if (P->Rlink == nullptr)
		{
			Current = P;
			P = P->Llink;
			delete Current;
		}

		else
		{
			Current = P->Rlink;
			Trail = nullptr;

			while (Current->Llink != nullptr)
			{
				Trail = Current;
				Current = Current->Llink;
			}
			P->Data = Current->Data;

			if (Trail == nullptr)
				P->Rlink = Current->Rlink;
			else
				Trail->Llink = Current->Rlink;
			
			delete Current;
		}
	}

	template<class T>
	inline int Btree<T>::Max(int x, int y)
	{
		return 0;
	}

}
