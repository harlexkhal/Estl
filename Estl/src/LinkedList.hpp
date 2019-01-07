#pragma once
#include "LinkedList.h"

namespace Estl {
	
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
		return (HeadNode == nullptr);
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
	void List<T>::PopFirst()
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
		NodeLink<T>* TrackNode = HeadNode;
		for (int i = 0; i <= pos; i++)
		{
			if (i == pos)
			{
				return TrackNode->DATA;
			}

			TrackNode = TrackNode->Next;
		}
	}

	template <class T>
	List<T>::~List()
	{
		NodeLink<T>* TrackNode = HeadNode;

		if (IsEmpty())
			std::cerr << "Error, Can't Destroy an Empty List" << std::endl; assert(false);

		
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

	template <class T>
	NodeLink<T>* List<T>::GetHeadNode()const
	{
		return HeadNode;
	}

	template <class T>
	void List<T>::DestroyList()
	{
		this->~List();
	}

	template <class T>
	void List<T>::ReverseList()
	{
		if (HeadNode != CurrNode)
		{
			NodeLink<T>* TrackHeadNode = HeadNode;
			NodeLink<T>* AheadHelpNode = HeadNode;
			NodeLink<T>* BehindHelpNode = nullptr;
			HeadNode = HeadNode->Next;
			AheadHelpNode->Next = BehindHelpNode;
			AheadHelpNode->Prev = HeadNode;
			BehindHelpNode = AheadHelpNode;
			AheadHelpNode = HeadNode;

			while (HeadNode != nullptr)
			{
				HeadNode = HeadNode->Next;
				AheadHelpNode->Next = BehindHelpNode;
				AheadHelpNode->Prev = HeadNode;
				BehindHelpNode = AheadHelpNode;
				AheadHelpNode = HeadNode;
			}
			HeadNode = CurrNode;
			CurrNode = TrackHeadNode;
			PrevLinkNode = CurrNode;
			NextLinkNode = CurrNode;
		}

		else
		{
			std::cerr << "Unable to Reverse just a single item on the List, would cause complications" << std::endl;
			assert(false);
		}
	}
}