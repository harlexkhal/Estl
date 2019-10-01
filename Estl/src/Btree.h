#pragma once

namespace Estl {

	template <class T>
	class Node
	{
		T Data;
		Node* Rlink;
		Node* Llink;

		template<class T> friend class Btree;
	};

	template <class T>
	class Btree
	{

	 public:
		Btree();
		~Btree();
		Btree(const Btree& Tree);
		Btree operator=(const Btree& Tree);
		bool IsEmpty();
		void InorderTraversal();
		void PreorderTraversal();
		void PostorderTraversal();
		int TreeHeight(const Btree& Tree);
		int TreeNodeCount();
		int TreeLeavesCount();
		void DestroyTree();

		void Insert(const T& m_Data);
		void Delete(const T& m_Data);
		void Search(const T& m_Data);
	

	protected:
		Node<T>* Root;
	private:
		void CopyTree(const Btree& Tree);
		int Max(int x, int y);
	
	};

	
}