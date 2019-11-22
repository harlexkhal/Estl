#pragma once

namespace Estl {
	template <typename T>
	void SelectionSort(T *Array, int size)
	{
		for (int i = 0; i < size; i++) 
		{
			T smallest = Array[i];
			int position = i;

			for (int j = 0; j < size - i; j++)
			{
				if (smallest > Array[i + j])
				{
					smallest = Array[i + j];
					position = i + j;
				}
			}
			T TEMP = Array[i];
			Array[i] = smallest;
			Array[position] = TEMP;
		}
	}

	template <typename T>
	void BubbleSort(T* Array, int size)
	{
		for (int j = 1; j <= size - 1; j++) 
		{
			for (int i = 0; i < size - 1; i++) 
			{
				if (Array[i] > Array[i + 1]) 
				{
					T TEMP = Array[i];
					Array[i] = Array[i + 1];
					Array[i + 1] = TEMP;
				}
			}
		}	
	}
}
