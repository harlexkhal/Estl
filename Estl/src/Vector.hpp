#pragma once

namespace Estl
{
	template <typename T>
	class Vector
	{
	public:
		explicit Vector(int Capacity): Capacity(Capacity)
		{
			size = 0;
			Array = new T[Capacity];
		}

		bool empty()
		{
			if (size == 0)
				return true;

			return false;
		}

        //Bad Code for Optimization cos it copies your data twice instead of at least once....This is just a Prototype
		void push_back(T data)
		{
			if (empty())
			{
				Array[0] = data;
				size++;
			}

			else if (size >= Capacity)
			{
				T* newArray = new T[size];

				for (int i = 0; i < size; i++)
				{
					newArray[i] = Array[i];
				}

				delete[] Array;
				Array = new T[size + 1];

				for (int i = 0; i < size; i++)
				{
					Array[i] = newArray[i];
				}

				delete[] newArray;

				for (int i = 0; i <= size; i++)
				{
					if (i == size)
					{
						Array[i] = data;
					}
				}
				size++;
			}

			else
			{
				for (int i = 0; i <= size; i++)
				{
					if (i == size)
					{
						Array[i] = data;
					}
				}
				size++;
			}
		}

		T& operator[](int index)
		{
			return Array[index];
		}

	private:
		int size;
		int Capacity;
		T* Array;

	};
}