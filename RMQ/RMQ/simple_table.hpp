#ifndef __SIMPLE_TABLE_HPP__
#define __SIMPLE_TABLE_HPP__

#include <fstream>
#include <iostream>

template<typename T>
T getMin(T* arr, int i, int j)
{
	T min_temp = arr[i];
	for ( size_t idx = i; idx < j + 1; ++idx )
	{
		if ( min_temp > arr[idx] )
			min_temp = arr[idx];
	}
	return min_temp;
}

template<typename T>
class SimpleTable
{
public:
	T **table;
	int n;
	T *arr;
private:
	SimpleTable() : table(nullptr), n(0), arr(nullptr)
	{
		//Do nothing
	}
public:
	SimpleTable(std::ifstream &input)
	{
		input >> n;

		table = new T*[n];
		for ( size_t j = 0; j < n; ++j )
		{
			table[j] = new T[j + 1];
		}
		arr = new T[n];

		fillArray(input);
	}
	SimpleTable(int n) : n(n)
	{
		table = new T*[n];
		for ( size_t j = 0; j < n; ++j )
		{
			table[j] = new T[j + 1];
		}
		arr = new T[n];
	}
	~SimpleTable()
	{
		if ( table != nullptr )
		{
			for ( size_t i = 0; i < n; ++i )
			{
				if ( table[i] == nullptr ) continue;
				delete table[i];
			}
		}
		if ( arr != nullptr )
		{
			delete arr;
		}
	}

	void fillTable()
	{
		for ( size_t j = 0; j < n; ++j )
		{
			for ( size_t i = 0; i < j + 1; ++i )
			{
				table[j][i] = getMin(arr, i, j);
			}
		}
	}

	T answer(size_t i, size_t j)
	{
		return table[j][i];
	}

	void fillArray(std::ifstream &input)
	{
		for ( size_t idx = 0; idx < n; ++idx )
		{
			input >> arr[idx];
		}
	}

	friend std::ostream & operator<<(std::ostream &os, const SimpleTable<T> &obj)
	{
		for ( size_t j = 0; j < obj.n; ++j )
		{
			for ( size_t i = 0; i < j + 1; ++i )
			{
				os << obj.table[j][i] << ' ';
			}
			os << '\n';
		}
		return os;
	}
};


#endif