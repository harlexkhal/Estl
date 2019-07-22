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
			iterator_Head.Current = HeadNode;
			iterator_End.Current = CurrNode->Next;
			
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
			iterator_End.Current = CurrNode->Next;
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
		return (HeadNode == nullptr) || (CurrNode == nullptr);
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
			iterator_Head.Current = HeadNode;
			iterator_End.Current = CurrNode->Next;
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
			iterator_End.Current = CurrNode->Next;
		}

	}

	template <class T>
	void List<T>::PopFirst()
	{
		assert(!IsEmpty());

		if (HeadNode == CurrNode)
		{
			NodeLink<T>* TrackNode;
			TrackNode = HeadNode;
			HeadNode = nullptr;
			iterator_Head.Current = HeadNode;
			delete TrackNode;
		}

		else
		{
			NodeLink<T>* TrackNode;
			TrackNode = HeadNode;
			HeadNode = HeadNode->Next;
			iterator_Head.Current = HeadNode;
			delete TrackNode;
		}
	}

	template<class T>
	inline void List<T>::PopLast()
	{
		assert(!IsEmpty());

		if (CurrNode == HeadNode)
		{
			NodeLink<T>* TrackNode;
			TrackNode = CurrNode;
			CurrNode = nullptr;     
			NextLinkNode = nullptr; //For Safety not really necessary. just Ensuring the link is still safe
			PrevLinkNode = nullptr; //For Safety not really necessary. just Ensuring the link is still safe
			iterator_End.Current = nullptr;
			delete TrackNode;	
		}

		else
		{
			NodeLink<T>* TrackNode;
			TrackNode = CurrNode;
			CurrNode = CurrNode->Prev;
			NextLinkNode = CurrNode;
			PrevLinkNode = CurrNode;
			CurrNode->Next = nullptr;
			iterator_End.Current = CurrNode->Next;
			delete TrackNode;
		}
	}

	template <class T>
	T& List<T>::operator[](int pos)
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
		iterator_Head.Current = NULL;
		iterator_End.Current = NULL;
	}

	template <class T>
	void List<T>::DestroyList()
	{
		this->~List();
	}

	template<class T>
	inline void List<T>::Insert(int pos, T Data)
	{
		NodeLink<T>* TrackNode = HeadNode;
		NodeLink<T>* TrackAhead;
		NodeLink<T>* TrackPrevious;

		if (pos == 0)
		{
			InsertFirst(Data);
		}
		//??TO DO**** KEEP TRACK OF LENGTH OR NUMBER OF ELEMENT IN THE LIST*****
		//TO DO***IF (POSITION) IS >= NUMBER OF ELEMENT OF THE LIST INSERTED DATA IN LAST POSITION OF THE LIST CHANGE <CURRLINKNODE,PREVLINKNODE,&NEXTLINKNODE DATA MEMBERS POSITION>
		else 
		{
			for (int i = 0; i <= pos; i++)
			{
				if (i == pos)
				{
					TrackAhead = TrackNode;
					TrackPrevious = TrackNode->Prev;
					TrackNode = new NodeLink<T>;
					TrackPrevious->Next = TrackNode;
					TrackNode->Prev = TrackPrevious;
					TrackNode->Next = TrackAhead;
					TrackAhead->Prev = TrackNode;
					TrackNode->DATA = Data;
				}

				TrackNode = TrackNode->Next;
			}
		}
	}

	template<class T>
	inline void List<T>::InsertFirst(T Data)
	{
		NodeLink<T>* TrackNode = new NodeLink<T>;
		TrackNode->Prev = nullptr;
		TrackNode->Next = HeadNode;
		HeadNode->Prev = TrackNode;
		HeadNode = TrackNode;
		HeadNode->DATA = Data;
		//Iterator HeadTracker
		iterator_Head.Current = HeadNode;
	}

	template<class T>
	inline void List<T>::InsertLast(T Data)
	{
		NodeLink<T>* TrackNode = new NodeLink<T>;
		TrackNode->Next = nullptr;
		TrackNode->Prev = CurrNode;
		CurrNode->Next = TrackNode;
		CurrNode = TrackNode;
		NextLinkNode = CurrNode;
		PrevLinkNode = CurrNode; //To Remove PrevLink Node Later...just discovered its an unecessary pointer...****TO DO LATER****
		CurrNode->DATA = Data;
	//Iterator TaleTracker
		iterator_End.Current = CurrNode->Next;
	}

	template<class T>
	inline void List<T>::DeleteElement(int pos)
	{
		NodeLink<T>* TrackNode = HeadNode;
		NodeLink<T>* TrackAhead;
		NodeLink<T>* TrackPrevious;

		if (pos == 0)
		{
			PopFirst();
		}
		//??TO DO**** KEEP TRACK OF LENGTH OR NUMBER OF ELEMENT IN THE LIST*****
		//TO DO***IF (POSITION) IS >= NUMBER OF ELEMENT OF THE LIST INSERTED DATA IN LAST POSITION OF THE LIST CHANGE <CURRLINKNODE,PREVLINKNODE,&NEXTLINKNODE DATA MEMBERS POSITION>
		else
		{
			for (int i = 0; i <= pos; i++)
			{
				if (i == pos)
				{
					TrackAhead = TrackNode->Next;
					TrackPrevious = TrackNode->Prev;
					delete TrackNode;
					TrackPrevious->Next = TrackAhead;
					TrackAhead->Prev = TrackPrevious;
				}

				TrackNode = TrackNode->Next;
			}
		}
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

			iterator_Head.Current = HeadNode;
			iterator_End.Current = CurrNode->Next;
		}

		else
		{
			std::cerr << "Unable to Reverse just a single item on the List, would cause complications" << std::endl;
			assert(false);
		}
	}
}