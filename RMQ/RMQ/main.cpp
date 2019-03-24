#include "simple_table.hpp"
#include "preprocessing.hpp"
#include "block_partition.hpp"
#include <iostream>

template<class C>
void test(std::ifstream &input)
{
    C table(input);
    table.fillTable(input);
    std::cout << table;

    size_t i, j;
    while ( 1 )
    {
        std::cin >> i >> j;
            std::cout << table.answer(i, j) << std::endl;
    }
}

int main()
{
    std::ifstream input("input.txt");
    test<BlockPartition<int>>(input);
}