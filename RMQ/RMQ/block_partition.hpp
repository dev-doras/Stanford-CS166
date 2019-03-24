#ifndef __BLOCK_PARTITION_H__
#define __BLOCK_PARTITION_H__

#include <fstream>
#include <iostream>
#include <cmath>

#define MODE_OPTIMIZE_SQRT
//#define MODE_OPTIMIZE_LOG

template<typename T>
class BlockPartition
{
public:
    size_t n, b;
    T *arr;
    T *blocks;

    BlockPartition(std::ifstream &input)
    {
        input >> n;
        arr = new T[n];

#ifdef MODE_OPTIMIZE_SQRT
        b = std::sqrt(n);
#elif defined MODE_OPTIMIZE_LOG
        b = std::log10(n);
#endif

        blocks = new T[(n - 1) / b + 1];
    }
    ~BlockPartition()
    {
        delete arr;
        delete blocks;
    }

    void fillTable(std::ifstream &input)
    {
        T block_min;
        for ( size_t idx = 0; idx < n; ++idx )
        {
            input >> arr[idx];

            // if entered a new block or found new block_minimun
            if ( idx % b == 0 || block_min > arr[idx] ) block_min = arr[idx];

            if ( (idx + 1) % b == 0 ) blocks[idx / b] = block_min; // if end of this block
        }
        blocks[(n - 1) / b] = block_min; // for the case ( n % b != 0 )
    }

    T answer(size_t i, size_t j)
    {
        T min = arr[i];
        size_t idx;

        // in the case ( n % b != 0 ) && j == end of arr
        if ( j == n - 1 )
        {
            for ( idx = i; idx <= j; )
            {
                if ( idx % b == 0 ) break;
                if ( min > arr[idx] ) min = arr[idx];
                ++idx;
            }
            for ( size_t block_idx = idx / b; block_idx <= (n - 1) / b; ++block_idx )
            {
                if ( min > blocks[block_idx] ) min = blocks[block_idx];
            }
            return min;
        }

        // for default case
        for ( idx = i; idx <= j; )
        {
            if ( idx % b == 0 && idx + b - 1 <= j )
            {
                if ( min > blocks[idx / b] ) min = blocks[idx / b];
                idx += b;
                continue;
            }
            else
            {
                if ( min > arr[idx] ) min = arr[idx];
                ++idx;
                continue;
            }
        }
        return min;
    }

    friend std::ostream & operator<<(std::ostream &os, const BlockPartition<T> &obj)
    {
        os << "n : " << obj.n << ", b : " << obj.b << '\n';
        for ( size_t idx = 0; idx <= (obj.n - 1) / obj.b; ++idx )
        {
            os << obj.blocks[idx] << '\t';
        }
        os << '\n';
        for ( size_t idx = 0; idx < obj.n; ++idx )
        {
            os << obj.arr[idx] << ' ';
        }
        os << '\n';
        return os;
    }
};

#endif