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
	}

	template<class T>
	void Btree<T>::PreorderTraversal()
	{
	}

	template<class T>
	void Btree<T>::PostorderTraversal()
	{
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
	void Btree<T>::Delete(const T & m_Data)
	{
	}

	template<class T>
	void Btree<T>::Search(const T & m_Data)
	{
	}

	template<class T>
	void Btree<T>::CopyTree(const Btree & Tree)
	{
	}

	template<class T>
	inline int Btree<T>::Max(int x, int y)
	{
		return 0;
	}

}
