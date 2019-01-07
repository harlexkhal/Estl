#pragma once

namespace Estl {

	template <class T>
	class NodeLink
	{
		T Data;
		NodeLink* Rlink;
		NodeLink* Llink;

		template<class T> friend class Btrees;
	};

	template <class T>
	class Btrees
	{
	
		Btrees();
		~Btrees();
		Btrees(const Btrees& Tree);
		Btrees operator=(const Btrees& Tree);
		bool IsEmpty();
		void InorderTraversal();
		void PreorderTraversal();
		void PostorderTraversal();
		int TreeHeight(const Btrees& Tree);
		int TreeNodeCount();
		int TreeLeavesCount();
		void DestroyTree();

		virtual void Insert(const T& m_Data) = 0;
		virtual void Delete(const T& m_Data) = 0;
		virtual void Search(const T& m_Data) = 0;
	

	protected:
		NodeLink<T>* root;

	private:
		void CopyTree(const Btrees& Tree);
		int Max(int x, int y);
	
	};



	
}