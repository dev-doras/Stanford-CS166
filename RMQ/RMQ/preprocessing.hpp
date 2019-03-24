#ifndef __PREPROCESSING_H__
#define __PREPROCESSING_H__

#include <fstream>
#include <iostream>

template<typename T>
class PreProcessing
{
public:
    T **table;
    size_t n;

    PreProcessing(std::ifstream &input)
    {
        input >> n;
        table = new T*[n];
        for ( size_t idx = 0; idx < n; ++idx )
        {
            table[idx] = new T[idx + 1];
        }
    }
    ~PreProcessing()
    {
        if ( table == nullptr ) return;
        for ( size_t idx = 0; idx < n; ++idx ) delete table[idx];
        delete table;
    }

    //Receive input & preprocessing
    void fillTable(std::ifstream &input)
    {
        for ( size_t idx = 0; idx < n; ++idx ) input >> table[idx][idx];
        for ( size_t diff = 1; diff < n; ++diff )
        {
            for ( size_t idx = 0; idx < n - diff; ++idx )
            {
                table[idx + diff][idx] = (table[idx + diff][idx + 1] > table[idx + diff - 1][idx]) ? (table[idx + diff - 1][idx]) : (table[idx + diff][idx + 1]);
            }
        }
    }

    T answer(size_t i, size_t j) const
    {
        return table[j][i];
    }

    friend std::ostream & operator<<(std::ostream &os, const PreProcessing<T> &obj)
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