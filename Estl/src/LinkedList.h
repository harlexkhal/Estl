#pragma once
#include <cassert>
#include <iostream>



namespace Estl {
	

	template<class T>
	class NodeLink 
	{
	private:
		T DATA;
		NodeLink* Next;
		NodeLink* Prev;

		template<class T> friend class List;
	};

	template <class T>
	class List  {

	public:

		class Iterator
		{
		public:
			Iterator()
			{
				Current = nullptr;
			}

			Iterator(Iterator& it)
			{
				this->Current = it.Current;
			}

			void operator++()
			{   
				Current = Current->Next;
			}

			T operator*()const
			{
				if (Current == nullptr)
				{
					std::cerr << "Can't Access a nullptr" << std::endl; assert(false);
				}

				return Current->DATA;
			}


			NodeLink<T>* Current;
		};

	public:
		
		List();

		List(const List& list);

		bool IsEmpty();

		List<T>& operator=(const List& list);

		void PushBack(T m_Num);
		
		void PopFirst();

		void PopLast();

		T operator[](int pos);

		Iterator& Begin() {return iterator_Head;}

		Iterator& End()   {return iterator_End;}

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
		Iterator     iterator_Head;
		Iterator     iterator_End;
		void Copy(NodeLink<T> *&Head);

	};


	//****************************************
	//Basic List Iterator + Implementation...
	//****************************************

	
}