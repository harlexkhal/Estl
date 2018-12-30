#pragma once
#include <cassert>
namespace Estl {

	template<class T>
	struct NodeLink 
	{
		T DATA;
		NodeLink* Next;
		NodeLink* Prev;
	};

	template <class T>
	class List  {

	public:

		List();

		List(const List& list);

		bool IsEmpty();

		List<T>& operator=(const List& list);

		void PushBack(T m_Num);
		
		void PopFirst();

		void PopLast();

		T operator[](int pos);

		NodeLink<T>* GetHeadNode()const;

		void DestroyList();

		void Insert(int pos);

		void InsertFirst();

		void InsertLast();

		void DeleteElement(int pos);

		void SortList();

		void ReverseList();

		~List();

	private:
		NodeLink<T>* CurrNode;
		NodeLink<T>* NextLinkNode;
		NodeLink<T>* PrevLinkNode;
		NodeLink<T>* HeadNode;
		void Copy(NodeLink<T> *&Head);
	};


	//****************************************
	//Basic List Iterator + Implementation...
	//****************************************

	template <class T>
	class ListIterator 
	{
	public:
		ListIterator()
		{
			Current = nullptr;
		}

		ListIterator(NodeLink<T>* HeadNode)
		{
			Current = HeadNode;
		}

		void operator++()
		{
			Current = Current->Next;
		}

		T operator*()const
		{
			return Current->DATA;
		}

	private:
		NodeLink<T>* Current;
	};
}