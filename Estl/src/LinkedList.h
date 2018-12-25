#pragma once
#include <cassert>

namespace Estl {

	template<class T>
	struct NodeLink {
		T DATA;
		NodeLink* Next;
		NodeLink* Prev;
	};

	template <class T>
	class List {

	public:

		List();

		List(const List& list);

		bool IsEmpty();

		List<T>& operator=(const List& list);

		void PushBack(T m_Num);

		void PopOutFromTop();

		T operator[](int pos);

		~List();

	private:
		NodeLink<T>* CurrNode;
		NodeLink<T>* NextLinkNode;
		NodeLink<T>* PrevLinkNode;
		NodeLink<T>* HeadNode;
		void Copy(NodeLink<T> *&Head);
	};



	template <class T>
	List<T>::List()
	{
		CurrNode = nullptr;
		NextLinkNode = nullptr;
		PrevLinkNode = nullptr;
		HeadNode = nullptr;
	}

	template <class T>
	void List<T>::Copy(NodeLink<T> *&Head)
	{
		if (Head == nullptr)
			return;

		if (HeadNode==nullptr)
		{
			CurrNode = new NodeLink<T>;
			HeadNode = CurrNode;
			NextLinkNode = CurrNode;
			HeadNode->Prev = PrevLinkNode;
			PrevLinkNode = HeadNode;
			CurrNode->DATA = Head->DATA;
			CurrNode->Next = nullptr;
			
		}

		else
		{
			CurrNode = new NodeLink<T>;
			NextLinkNode->Next = CurrNode;
			NextLinkNode = CurrNode;
			CurrNode->Prev = PrevLinkNode;
			PrevLinkNode = CurrNode;
			CurrNode->DATA = Head->DATA;
			CurrNode->Next = nullptr;
		}
		Head = Head->Next;
		Copy(Head);
	}


	template <class T>
	List<T>::List(const List& list)
	{
		NodeLink<T>* Track = list.HeadNode;
		Copy(Track);
	}
	
	template <class T>
	List<T>& List<T>::operator=(const List& list)
	{
		if (!this->IsEmpty())
			this->~List();

		NodeLink<T>* Track = list.HeadNode;
		Copy(Track);
		
		return *this;
	}

	template <class T>
	bool List<T>::IsEmpty()
	{
		if (HeadNode == nullptr)
			return true;

		else
			return false;
	}

	template <class T>
	void List<T>::PushBack(T m_Num)
	{
		if (IsEmpty())
		{
			CurrNode = new NodeLink<T>;
			HeadNode = CurrNode;
			NextLinkNode = CurrNode;
			HeadNode->Prev = PrevLinkNode;
			PrevLinkNode = HeadNode;
			CurrNode->DATA = m_Num;
			CurrNode->Next = nullptr;
		}
		else
		{
			CurrNode = new NodeLink<T>;
			NextLinkNode->Next = CurrNode;
			NextLinkNode = CurrNode;
			CurrNode->Prev = PrevLinkNode;
			PrevLinkNode = CurrNode;
			CurrNode->DATA = m_Num;
			CurrNode->Next = nullptr;
		}

	}

	template <class T>
	void List<T>::PopOutFromTop()
	{
		assert(!HeadNode);

		if (HeadNode == CurrNode)
		{
			NodeLink<T>* TrackNode;
			TrackNode = HeadNode;
			HeadNode = nullptr;
			delete TrackNode;
		}

		else
		{
			NodeLink<T>* TrackNode;
			TrackNode = HeadNode;
			HeadNode = HeadNode->Next;
			delete TrackNode;
		}
	}

	template <class T>
	T List<T>::operator[](int pos)
	{
		PrevLinkNode = HeadNode;
		for (int i = 0; i <= pos; i++)
		{
			if (i == pos)
			{
				return PrevLinkNode->DATA;
			}

			PrevLinkNode = PrevLinkNode->Next;
		}
	}

	template <class T>
	List<T>::~List()
	{
		NodeLink<T>* TrackNode = HeadNode;

		if (IsEmpty())
			throw "Cannot Destroy an Empty Node";

		
			while (TrackNode != nullptr)
			{
				HeadNode = HeadNode->Next;
				delete TrackNode;
				TrackNode = HeadNode;
			}
		

		CurrNode = nullptr;
		PrevLinkNode = nullptr;
		NextLinkNode = nullptr;
		HeadNode = nullptr;
	}
}