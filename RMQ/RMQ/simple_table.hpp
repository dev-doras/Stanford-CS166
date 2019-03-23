#ifndef __SIMPLE_TABLE_HPP__
#define __SIMPLE_TABLE_HPP__

#include <fstream>
#include <iostream>

using size_t = decltype(sizeof(void*));

template<typename T>
class SimpleTable
{
public:
    T **table;
    int n;
public:
    SimpleTable(std::ifstream &input)
    {
        input >> n;

        table = new T*[n];
        for ( size_t j = 0; j < n; ++j )
        {
            table[j] = new T[j + 1];
        }
    }
    SimpleTable(int n) : n(n)
    {
        table = new T*[n];
        for ( size_t j = 0; j < n; ++j )
        {
            table[j] = new T[j + 1];
        }
    }
    ~SimpleTable()
    {
        if ( table != nullptr )
        {
            for ( size_t i = 0; i < n; ++i )
            {
                delete table[i];
            }
            delete table;
        }
    }

    //Receive input & preprocessing
    void fillTable(std::ifstream &input)
    {
        for ( size_t idx = 0; idx < n; ++idx )
        {
            input >> table[idx][idx];
        }
        for ( size_t j = 0; j < n; ++j )
        {
            for ( size_t i = 0; i < j; ++i )
            {
                table[j][i] = getMin(i, j);
            }
        }
    }

    T getMin(size_t front, size_t rear) const
    {
        T min = table[front][front];
        for ( size_t idx = front; idx <= rear; ++idx )
        {
            if ( min > table[idx][idx] )
            {
                min = table[idx][idx];
            }
        }
        return min;
    }

    T answer(size_t i, size_t j) const
    {
        return table[j][i];
    }

    friend std::ostream & operator<<(std::ostream &os, const SimpleTable<T> &obj)
    {
        for ( size_t j = 0; j < obj.n; ++j )
        {
            for ( size_t i = 0; i <= j; ++i )
            {
                os << obj.table[j][i] << ' ';
            }
            os << '\n';
        }
        return os;
    }
};


#endif